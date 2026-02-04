#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int length;
int i;
int64_t sum;

int16_t *a;
int16_t *b;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    const size_t target_bytes = 64 * 1024 * 1024; 
    length = target_bytes / (2 * sizeof(int16_t));

    a = aligned_alloc(32, length * sizeof(int16_t));
    b = aligned_alloc(32, length * sizeof(int16_t));

    if (!a || !b) {
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < length; j++) {
        a[j] = (int16_t)(j % 500);
        b[j] = (int16_t)((j + 10) % 450);
    }

    sum = 0;

    clock_gettime(CLOCK_MONOTONIC, &end);
    long elapsed_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    double elapsed_s = elapsed_ns / 1e9;

    if (elapsed_s < 0.008) {
        double factor = 0.01 / (elapsed_s > 0 ? elapsed_s : 1e-9);
        int new_length = (int)(length * factor);
        if (new_length > length) {
            free(a);
            free(b);
            length = new_length;
            a = aligned_alloc(32, length * sizeof(int16_t));
            b = aligned_alloc(32, length * sizeof(int16_t));
            if (!a || !b) {
                exit(EXIT_FAILURE);
            }
            for (int j = 0; j < length; j++) {
                a[j] = (int16_t)(j % 500);
                b[j] = (int16_t)((j + 10) % 450);
            }
            sum = 0;
        }
    }
}