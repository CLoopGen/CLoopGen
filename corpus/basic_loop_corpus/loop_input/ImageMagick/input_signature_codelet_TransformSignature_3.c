#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
unsigned int W[64];

void init_vars() {
    for (int j = 0; j < 16; j++) {
        W[j] = (unsigned int)(j * 2654435761U);
    }
    for (int j = 16; j < 64; j++) {
        W[j] = 0U;
    }
    i = 16;
}