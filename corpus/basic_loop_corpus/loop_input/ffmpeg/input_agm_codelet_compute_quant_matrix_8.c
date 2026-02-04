#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double qscale = 0.5;

int luma[64];
int chroma[64];

void init_vars() {
    qscale = 0.5;
    for (int i = 0; i < 64; i++) {
        luma[i] = 16;
        chroma[i] = 16;
    }
}