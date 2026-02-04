#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * 1024 * 1024 / sizeof(float))

float aafq[ARRAY_SIZE];
int Alphabet_size = ARRAY_SIZE;
float *null = NULL;
int x;

void init_vars() {
    null = (float *)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    if (!null) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        aafq[i] = (float)(i % 1000) / 100.0f;
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned int)(tv.tv_usec ^ tv.tv_sec));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        null[i] = 0.0f;
    }
}