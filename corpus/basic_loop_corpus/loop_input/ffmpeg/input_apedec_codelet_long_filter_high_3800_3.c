#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *buffer;
int order;
int i;
int32_t delay[256];

void init_vars() {
    order = 256;
    buffer = (int32_t*)malloc(order * sizeof(int32_t));
    if (!buffer) {
        exit(1);
    }
    for (i = 0; i < order; i++) {
        buffer[i] = i * 2;
        delay[i] = 0;
    }
}