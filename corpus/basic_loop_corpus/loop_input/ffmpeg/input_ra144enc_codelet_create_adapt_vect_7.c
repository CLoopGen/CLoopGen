#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *vect;
int16_t *cb;
int lag;
int i;

#define DATA_SIZE_MB 64
#define TOTAL_SIZE (DATA_SIZE_MB * 1024 * 1024)

static float vect_buf[TOTAL_SIZE];
static int16_t cb_buf[TOTAL_SIZE];

void init_vars() {
    lag = 1000;
    vect = vect_buf;
    cb = cb_buf;
}