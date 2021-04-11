#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread routine prototype.
void *thread(void *vargp);

int main(int argc, char **argv) {
  // We are creating two threads, so we create two thread ids.
  pthread_t tid1, tid2;

  printf("Hello from the main thread.\n");

  // Create two threads and save their IDs.
  printf("Creating thread 1.\n");
  pthread_create(&tid1, NULL, thread, NULL);
  printf("Creating thread 2.\n");
  pthread_create(&tid2, NULL, thread, NULL);

  // Wait and join two threads.
  printf("Main thread is going to wait on peer threads.\n");
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("Peer threads have completed.\n");

  return EXIT_SUCCESS;
}

void *thread(void *vargp) {
  // This thread gets the thread ID of the calling thread. Unlike the
  // process ID of a process, the thread ID is only unique to the
  // process that created it.
  pthread_t tid = pthread_self();
  printf("Hello from thread %u.\n", (unsigned int)tid);
  return NULL;
}
