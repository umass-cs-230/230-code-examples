#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread routine prototype.
void *thread(void *vargp);

// Global shared variable.
volatile int cnt = 0;
// A variable declared as "volatile" tells that compiler that the value
// of that variable could change at any time. For example, another thread
// could access that variable at any time. The effect of this is that
// the compile should always load and store the value from the stack and
// refrain from keeping the value in a register.

int main(int argc, char **argv) {
  // The number of iterations.
  int niters;

  // We are creating two threads, so we create two thread ids.
  pthread_t tid1, tid2;

  // Check input arguments.
  if (argc != 2) {
    printf("usage: %s <niters>\n", argv[0]);
    exit(0);
  }

  // Convert the string form of the number of iterations argument to an int.
  niters = atoi(argv[1]);

  // Create threads and wait for them to finish.
  pthread_create(&tid1, NULL, thread, &niters);
  pthread_create(&tid2, NULL, thread, &niters);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  // Check the result.
  if (cnt != (2 * niters)) {
    printf("BOOM! cnt=%d\n", cnt);
    printf("It should have been %d\n", (2 * niters));
    printf("A difference of %d. Yikes!\n", (2 * niters) - cnt);
  } else {
    printf("OK cnt=%d\n", cnt);
  }
  exit(0);
}

// The thread routine.
// A thread will iterate from 0 to niters - 1 incrementing a globally
// shared count variable. Eventually this causes a problem :-(.
void *thread(void *vargp) {
  // Cast and dereference the void *.
  int niters = *((int *)(vargp));
  int i;

  for (i = 0; i < niters; i++) {
    cnt++;
  }

  return NULL;
}
