#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *ringbuffer;
int mult;
float *dst;
uint32_t modulo;
int wr;
int n_read;
int j;

#define RINGBUFFER_SIZE (1 << 20)
#define DST_SIZE (RINGBUFFER_SIZE)

void init_vars() {
    ringbuffer = (float *)calloc(RINGBUFFER_SIZE, sizeof(float));
    dst = (float *)malloc(DST_SIZE * sizeof(float));
    mult = 1;
    modulo = RINGBUFFER_SIZE - 1;
    wr = 0;
    n_read = RINGBUFFER_SIZE >> 4;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}