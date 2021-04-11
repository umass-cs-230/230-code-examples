#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread routine prototype.
void *thread(void *vargp);

typedef struct Data {
  int niters;
  int cnt;
} Data;

int main(int argc, char **argv) {
  // Check input arguments.
  if (argc != 2) {
    printf("usage: %s <niters>\n", argv[0]);
    exit(0);
  }

  Data data = { atoi(argv[1]), 0 };

  // We are creating two threads, so we create two thread ids.
  pthread_t tid1, tid2;

  // Create threads and wait for them to finish.
  pthread_create(&tid1, NULL, thread, &data);
  pthread_create(&tid2, NULL, thread, &data);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  // Check the result.
  if (data.cnt != (2 * data.niters)) {
    printf("BOOM! cnt=%d\n", data.cnt);
    printf("It should have been %d\n", (2 * data.niters));
    printf("A difference of %d. Yikes!\n", (2 * data.niters) - data.cnt);
  } else {
    printf("OK cnt=%d\n", data.cnt);
  }
  exit(0);
}

// The thread routine.
// A thread will iterate from 0 to niters - 1 incrementing a globally
// shared count variable. Eventually this causes a problem :-(.
void *thread(void *vargp) {
  // Cast and dereference the void *.
  Data* data = (Data *) vargp;  

  for (int i = 0; i < data->niters; i++) {
    data->cnt++;
  }

  return NULL;
}
