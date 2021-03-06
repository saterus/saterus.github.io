#include <stdio.h>
#include <pthread.h>

int AMOUNT_OF_WORK = 10000;

void* do_work(void* arg) {
  int* value = (int*) arg;

  for(int i = 0; i < AMOUNT_OF_WORK; i++) {
    *value += 1;
  }

  return 0; // zero is success
}

int main(void) {
  int counter = 0;
  printf("Counter: %d\n", counter);

  pthread_t worker_a;
  pthread_t worker_b;

  pthread_create(&worker_a, NULL, do_work, &counter);
  pthread_create(&worker_b, NULL, do_work, &counter);

  pthread_join(worker_a, NULL);
  pthread_join(worker_b, NULL);

  printf("Counter: %d\n", counter);
}
