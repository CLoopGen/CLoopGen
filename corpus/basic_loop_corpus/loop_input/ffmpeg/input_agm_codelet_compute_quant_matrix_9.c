#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

uint8_t unscaled_luma[64];
uint8_t unscaled_chroma[64];
int luma[64];
int chroma[64];
double f;

void init_vars() {
    f = 1.5;
    for (int i = 0; i < 64; i++) {
        unscaled_luma[i] = (i * 7) % 251;
        unscaled_chroma[i] = (i * 11) % 251;
        luma[i] = 0;
        chroma[i] = 0;
    }
}