#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *p;
int *nb_times;
char *times_str1;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec on modern CPU
    times_str1 = (char *)malloc(data_size);
    if (!times_str1) {
        exit(1);
    }

    // Fill with mostly printable chars, include some commas
    for (size_t i = 0; i < data_size - 1; i++) {
        times_str1[i] = (rand() % 100) == 0 ? ',' : 'a' + (rand() % 26);
    }
    times_str1[data_size - 1] = '\0'; // Ensure null termination

    nb_times = (int *)malloc(sizeof(int));
    if (!nb_times) {
        free(times_str1);
        exit(1);
    }
    *nb_times = 0;

    p = NULL;
}