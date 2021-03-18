#include <stdio.h>    // standard IO support
#include <unistd.h>   // pipe support
#include <stdlib.h>   // exit function
#include <sys/types.h>
#include <sys/wait.h>

// The producer will write data into the pipe whose write-end is given
// by pipe_write_end.

void producer (FILE *pipe_write_end) {
  int i;
  for (i = 1; i <= 100; i++) {
    // We write data to the pipe. Note the space in the format string
    // - this is necessary for stdio to flush the data to the pipe. If
    // you do not include the space the consumer will block waiting
    // for the complete data:
    fprintf(pipe_write_end, "%d ", i);
  }
  fclose(pipe_write_end);
  exit(0);
}


// The consumer will read data from the pipe whose read-end is given
// by pipe_read_end, and copy it to standard output.

void consumer (FILE *pipe_read_end) {
  while(1) {
    int k;
    int n = fscanf(pipe_read_end, "%d", &k);
    if (n == 1) {
      printf("consumer: got %d\n", k);
    } else {
      break;
    }
  }
  fclose(pipe_read_end);
  exit(0);
}


// main will build the pipes and fork two processes to produce and
// consume. The main process (parent) will wait for the producer and
// consumer to finish.

int main () {
  // The process ids of the producer and consumer processes.
  pid_t producer_id, consumer_id;
  
  // The pipe file descriptors.
  int pd[2];

  // The FILE abstraction from stdio that we will use to write and
  // read from the pipe.
  FILE *pipe_write_end, *pipe_read_end;

  // First, we need to build the pipe:
  pipe(pd);
  pipe_read_end  = fdopen(pd[0], "r");
  pipe_write_end = fdopen(pd[1], "w");
  
  // Second, we will fork the producer process:
  producer_id = fork();
  if (producer_id == 0) {
    // We close the pipe_read_end because the producer process will
    // not be reading from the pipe:
    fclose(pipe_read_end);

    // Now, we let the producer produce data:
    producer(pipe_write_end);
  }

  // Third, we fork the consumer process:
  consumer_id = fork();
  if (consumer_id == 0) {
    // We close the pipe_write_end because the consumer will not be
    // writing to the pipe:
    fclose(pipe_write_end);

    // Now, we let the consumer consume data:
    consumer(pipe_read_end);
  }

  // The parent process does not need to read or write from the pipe
  // so we close both:
  fclose(pipe_read_end);
  fclose(pipe_write_end);

  // Then, we wait for both processes to complete:
  wait(NULL);
  wait(NULL);

  return 0;
}
