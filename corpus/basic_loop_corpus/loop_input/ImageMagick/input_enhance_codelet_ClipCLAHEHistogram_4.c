#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double clip_limit;
size_t *histogram;
ssize_t cumulative_excess;
ssize_t step;
size_t *p;
size_t *q;

#define DATA_SIZE (64 * 1024)

static size_t data_buffer[DATA_SIZE];

void init_vars() {
    clip_limit = 100.0;
    step = 1;
    histogram = data_buffer;
    q = histogram + DATA_SIZE;
    cumulative_excess = 5000;

    for (size_t i = 0; i < DATA_SIZE; i++) {
        data_buffer[i] = 90 + (i % 21); 
    }
}