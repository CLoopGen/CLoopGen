#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int decode_precision;
int i;
int idx;
int val;
int alpha_val;

void init_vars() {
    val = 10000000;
    idx = 0;
    decode_precision = 10;
    alpha_val = 0xFFFF;
    dst = (uint16_t*)calloc(val, sizeof(uint16_t));
    if (!dst) {
        exit(1);
    }
}