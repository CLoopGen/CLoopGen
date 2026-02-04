#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int luma[64];
int chroma[64];
double f;

void init_vars() {
    f = 0.5;
    for (int i = 0; i < 64; i++) {
        luma[i] = 0;
        chroma[i] = 0;
    }
}