#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

uint8_t unscaled_luma[64];
uint8_t unscaled_chroma[64];
int luma[64];
int chroma[64];
double f;

void init_vars() {
    for (int i = 0; i < 64; i++) {
        unscaled_luma[i] = (i * 37) % 256;
        unscaled_chroma[i] = (i * 99) % 256;
    }
    f = 1.75;
}

void loop();