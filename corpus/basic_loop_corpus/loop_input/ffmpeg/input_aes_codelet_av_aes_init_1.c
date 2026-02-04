#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int j;
uint8_t log8[256];
uint8_t alog8[512];

void init_vars() {
    i = 0;
    j = 1;

    for (int idx = 0; idx < 256; idx++) {
        log8[idx] = 0;
    }

    for (int idx = 0; idx < 512; idx++) {
        alog8[idx] = 0;
    }
}