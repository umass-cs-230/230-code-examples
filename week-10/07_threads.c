#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread routine prototype.
void *thread(void *vargp);

int main(int argc, char **argv) {
  pthread_t tid;
  int i;
  for (i = 0; i < 100; i++) {
    pthread_create(&tid, NULL, thread, (void *)&i);
  }
}

void *thread(void *vargp) {
  // Does this code create a "race condition"?
  // Race Test:
  //  (1) If there is no race, then each thread would get a different
  //      value of i (received from the main thread).
  //  (2) If there is no race, the set of values printed to stdout
  //      would consist of one output for each value from 0 to 99.
  int i = *((int *)vargp);
  pthread_detach(pthread_self());
  printf("%d\n", i);
  return NULL;
}
