#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct _ZeroCrossing {
    double tau;
    double histogram[256];
    short crossings[256];
} ZeroCrossing;

ZeroCrossing *zero_crossing;
size_t number_crossings;
ssize_t i;
ssize_t j;
ssize_t k;
ssize_t l;
ssize_t center;
ssize_t correct;
ssize_t count;
ssize_t left;
ssize_t right;

void init_vars() {
    const size_t target_data_size = 16 * 1024 * 1024; // Aim for ~16MB of data
    const size_t element_size = sizeof(ZeroCrossing);
    number_crossings = target_data_size / element_size;
    if (number_crossings < 2) number_crossings = 2;

    zero_crossing = (ZeroCrossing*)calloc(number_crossings, sizeof(ZeroCrossing));
    if (!zero_crossing) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));

    for (size_t idx = 0; idx < number_crossings; idx++) {
        zero_crossing[idx].tau = (double)(rand()) / RAND_MAX;
        for (int h = 0; h < 256; h++) {
            zero_crossing[idx].histogram[h] = (double)(rand()) / RAND_MAX;
            if (rand() % 8 == 0) {
                zero_crossing[idx].crossings[h] = (short)(rand() % 32767);
            } else {
                zero_crossing[idx].crossings[h] = 0;
            }
        }
    }

    i = j = k = l = center = correct = count = left = right = 0;
}