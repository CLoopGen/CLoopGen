#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (1 << 20) // 1MB of data: 2^20 bytes

float aafq[DATA_SIZE / sizeof(float)];
int Alphabet_size = DATA_SIZE / sizeof(float);
float *null;
int x;

void init_vars() {
    null = (float *)malloc(DATA_SIZE);
    if (!null) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < Alphabet_size; i++) {
        aafq[i] = (float)(i % 100) / 10.0f;
    }

    memset(null, 0, DATA_SIZE);
}