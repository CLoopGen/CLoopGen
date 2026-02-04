#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *histogram;
size_t hsize;
int x;

void init_vars() {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    hsize = 1;
    do {
        hsize *= 2;
        if (hsize > (256U << 20)) break;

        histogram = (float*)calloc(hsize, sizeof(float));
        if (!histogram) continue;

        for (size_t i = 0; i < hsize; i++) {
            histogram[i] = 1.0f;
        }

        x = 0;
        while (x < (int)(hsize - 1)) {
            histogram[x + 1] += histogram[x];
            histogram[x] /= hsize;
            x++;
        }

        free(histogram);
        histogram = NULL;

        clock_gettime(CLOCK_MONOTONIC, &end);
        long elapsed_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
        if (elapsed_ns >= 10e6) break;
    } while (1);

    histogram = (float*)calloc(hsize, sizeof(float));
    if (!histogram) {
        hsize = 1048576;
        histogram = (float*)calloc(hsize, sizeof(float));
    }

    for (size_t i = 0; i < hsize; i++) {
        histogram[i] = 1.0f + (i % 1000);
    }
    x = 0;
}