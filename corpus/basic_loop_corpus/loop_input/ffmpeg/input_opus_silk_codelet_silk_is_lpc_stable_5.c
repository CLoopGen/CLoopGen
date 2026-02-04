#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t lpc[16];
int order = 16;
int k;
int DC_resp;
int32_t *row;

void init_vars() {
    row = (int32_t*)aligned_alloc(32, sizeof(int32_t) * 16);
    for (int i = 0; i < 16; i++) {
        lpc[i] = (int16_t)(i * 3);
    }
    DC_resp = 0;
}