#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 2

// Thread routine prototype.
void *thread(void *vargp);

int main(int argc, char **argv) {
  // We are creating two threads, so we create two thread ids.
  pthread_t tid[MAX_THREADS];

  printf("Hello from the main thread.\n");

  // Create two threads and save their IDs.
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_create(&tid[i], NULL, thread, (void *)i);
  }

  // Wait and join two threads.
  printf("Main thread is going to wait on peer threads.\n");
  for (int i = 0; i < MAX_THREADS; i++) {
    int retval = -1;
    pthread_join(tid[i], (void *)&retval);
    printf("Main thread joined on peer thread %d/%d.\n", i, retval);
  }
  printf("Peer threads have completed.\n");

  return EXIT_SUCCESS;
}

void *thread(void *vargp) {
  int thread_count = (int)vargp;

  // This thread gets the thread ID of the calling thread. Unlike the
  // process ID of a process, the thread ID is only unique to the
  // process that created it.
  pthread_t tid = pthread_self();
  printf("Hello from thread %u; I am thread #%d.\n", (unsigned int)tid,
         thread_count);

  pthread_exit((void *)thread_count);

  return NULL;
}
