#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

float *buf;
int i;
int max;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(float))

static float buf_data[DATA_SIZE];

void init_vars() {
    buf = buf_data;
    i = 0;
    max = 0;

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        buf[idx] = (float)(rand() % 1000);
    }
}