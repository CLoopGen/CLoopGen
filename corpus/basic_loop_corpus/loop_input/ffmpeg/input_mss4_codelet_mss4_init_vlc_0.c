#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *lens;
uint8_t bits[162];
uint16_t codes[162];
int i;
int j;
int prefix;
int max_bits;
int idx;

void init_vars() {
    lens = (uint8_t*)calloc(16, sizeof(uint8_t));
    if (!lens) {
        exit(1);
    }

    lens[0] = 1;
    for (int k = 1; k < 16; k++) {
        lens[k] = (k * 1000) / 16;
    }

    for (int k = 0; k < 16; k++) {
        if (idx + lens[k] > 162) {
            lens[k] = 162 - idx;
        }
        for (int j = 0; j < lens[k]; j++) {
            bits[idx] = 0;
            codes[idx] = 0;
            idx++;
        }
    }

    idx = 0;
    prefix = 0;
    max_bits = 0;
}