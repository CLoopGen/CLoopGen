#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024) // 64 MB for ~0.01 sec runtime estimate

uint8_t *dst;
int x;
uint8_t *s0;
uint8_t *s1;
uint8_t *s2;
uint8_t *s3;
uint8_t *w;

static uint8_t dst_data[DATA_SIZE];
static uint8_t s0_data[DATA_SIZE];
static uint8_t s1_data[DATA_SIZE];
static uint8_t s2_data[DATA_SIZE];
static uint8_t s3_data[DATA_SIZE];
static uint8_t w_data[4];

void init_vars() {
    dst = dst_data;
    s0 = s0_data;
    s1 = s1_data;
    s2 = s2_data;
    s3 = s3_data;
    w = w_data;

    for (size_t i = 0; i < DATA_SIZE; i++) {
        dst[i] = rand() % 256;
        s0[i] = rand() % 256;
        s1[i] = rand() % 256;
        s2[i] = rand() % 256;
        s3[i] = rand() % 256;
    }

    for (int i = 0; i < 4; i++) {
        w[i] = rand() % 256;
    }
}