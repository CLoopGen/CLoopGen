#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int step;
ptrdiff_t stride;
int sum_p1p0;
int sum_q1q0;
uint8_t *ptr;
int i;

#define DATA_SIZE (64 * 1024 * 1024)

static uint8_t data[DATA_SIZE];

void init_vars() {
    step = 1;
    stride = 4 * step;
    src = data + 2 * step;
    sum_p1p0 = 0;
    sum_q1q0 = 0;
    ptr = NULL;
    i = 0;
}