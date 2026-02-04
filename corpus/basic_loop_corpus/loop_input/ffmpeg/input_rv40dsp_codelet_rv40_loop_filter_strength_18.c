#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int step;
ptrdiff_t stride;
int sum_p1p2;
int sum_q1q2;
uint8_t *ptr;
int i;

static uint8_t data[1 << 20]; // 1MB of data

void init_vars() {
    src = data;
    step = 1;
    stride = 4;
    sum_p1p2 = 0;
    sum_q1q2 = 0;
    ptr = NULL;
    i = 0;

    for (int idx = 0; idx < (1 << 20); idx++) {
        data[idx] = rand() & 0xFF;
    }
}