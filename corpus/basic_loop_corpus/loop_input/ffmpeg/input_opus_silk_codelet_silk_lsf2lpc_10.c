#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float lpcf[16];
int order = 16;
int i;
int16_t lpc[16];

void init_vars() {
    for (int j = 0; j < 16; j++) {
        lpc[j] = (int16_t)(rand() % 8192) - 4096;
    }
    order = 16;
}