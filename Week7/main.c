#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_STUDENTS 4
#define SLICES_PER_PIZZA 6

int slices_left = SLICES_PER_PIZZA;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* student(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (slices_left == 0) {
            printf("Student %d: Ordering pizza\n", id);
            sleep(5);
            slices_left = SLICES_PER_PIZZA;
        }
        slices_left--;
        printf("Student %d: Eating slice, %d slices left\n", id + 1, slices_left + 1);
        pthread_mutex_unlock(&mutex);
        sleep(1);

    }
}

int main() {

    pthread_t students[NUM_STUDENTS];
    int ids[NUM_STUDENTS];
    for (int i = 0; i < NUM_STUDENTS; i++) {
        ids[i] = i;
        pthread_create(&students[i], NULL, student, &ids[i]);
    }
    for (int i = 0; i < NUM_STUDENTS; i++) {
        pthread_join(students[i], NULL);
    }
    return 0;
}
