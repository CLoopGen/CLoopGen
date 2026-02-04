#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 16
#define DATA_SIZE_MB 64
#define LOOP_COUNT (DATA_SIZE_MB * 1024 * 1024 / (ARRAY_SIZE * sizeof(float)))

int16_t isf_mean[16];

float *isf_q;
float *isf_past;

int i;
float tmp;

void init_vars() {
    isf_q = (float *)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    isf_past = (float *)aligned_alloc(32, ARRAY_SIZE * sizeof(float));

    if (!isf_q || !isf_past) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        isf_mean[idx] = (int16_t)(idx + 1); 
        isf_q[idx] = 1.0f / (idx + 1);
        isf_past[idx] = 0.5f / (idx + 1);
    }

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int iter = 0; iter < LOOP_COUNT; iter++) {
        for (i = 0; i < 16; i++) {
            tmp = isf_q[i];
            isf_q[i] += isf_mean[i] * (1.F / (1 << 15));
            isf_q[i] += (1. / 3.) * isf_past[i];
            isf_past[i] = tmp;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    if (elapsed < 0.008 || elapsed > 0.015) {
        float scale = 0.01 / elapsed;
        LOOP_COUNT_ADJUSTED: ;
        int new_loop_count = (int)(LOOP_COUNT * scale);
        if (new_loop_count < 1) new_loop_count = 1;
    }
}