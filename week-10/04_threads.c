#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_THREADS 12
#define LOOP_MAX 1000000

// Thread routine prototype.
void *thread(void *vargp);

int main(int argc, char **argv) {
  // We are creating two threads, so we create two thread ids.
  pthread_t tid[MAX_THREADS];

  printf("Hello from the main thread.\n");

  // Create two threads and save their IDs.
  for (int i = 0; i < MAX_THREADS; i++) {
    int status = pthread_create(&tid[i], NULL, thread, (void *)i);
    if (status != 0) {
      perror("Creating thread");
      exit(EXIT_FAILURE);
    }
  }

  // The main thread exits, leaving the peer threads running.
  printf("Main thread exiting, leaving peer threads to have fun.\n");
  pthread_exit(NULL);
}

void *thread(void *vargp) {
  // Detach from main thread and self reap.
  pthread_detach(pthread_self());

  int thread_count = (int)vargp;

  // This thread gets the thread ID of the calling thread. Unlike the
  // process ID of a process, the thread ID is only unique to the
  // process that created it.
  pthread_t tid = pthread_self();
  printf("Hello from thread %u; I am thread #%d.\n", (unsigned int)tid,
         thread_count);

  for (int i = 0; i < LOOP_MAX; i++) {
    // do lots of nothing for fun.
  }

  printf("Peer thread exiting.\n");
  pthread_exit((void *)thread_count);

  return NULL;
}
