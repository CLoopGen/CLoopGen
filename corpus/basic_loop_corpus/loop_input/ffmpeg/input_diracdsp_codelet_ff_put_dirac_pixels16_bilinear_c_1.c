#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int x;
uint8_t *s0;
uint8_t *s1;
uint8_t *s2;
uint8_t *s3;
uint8_t *w;

#define DATA_SIZE (16 * 1024 * 1024) // 16MB to ensure ~0.01s runtime

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_s0[DATA_SIZE];
static uint8_t internal_s1[DATA_SIZE];
static uint8_t internal_s2[DATA_SIZE];
static uint8_t internal_s3[DATA_SIZE];
static uint8_t internal_w[4];

void init_vars() {
    dst = internal_dst;
    s0 = internal_s0;
    s1 = internal_s1;
    s2 = internal_s2;
    s3 = internal_s3;
    w = internal_w;

    for (int i = 0; i < DATA_SIZE; i++) {
        internal_s0[i] = rand() % 256;
        internal_s1[i] = rand() % 256;
        internal_s2[i] = rand() % 256;
        internal_s3[i] = rand() % 256;
    }

    for (int i = 0; i < 4; i++) {
        internal_w[i] = rand() % 256;
    }
}