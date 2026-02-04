#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE 64000000

float *work;
float *data;
float c;
float g;
int i;

void init_vars() {
    work = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));
    data = (float*)aligned_alloc(32, DATA_SIZE * sizeof(float));

    if (!work || !data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        work[idx] = (float)(rand() % 100) / 10.0f;
        data[idx] = (float)(rand() % 100) / 10.0f;
    }

    c = 0.0f;
    g = 0.0f;
    i = 0;
}