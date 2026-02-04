#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int order = 16;
int k;

int32_t p[9] = {0};
int32_t q[9] = {0};
int32_t lpc32[16] = {0};

void init_vars() {
    order = 16;
    for (int i = 0; i < 9; i++) {
        p[i] = rand() % 1000;
        q[i] = rand() % 1000;
    }
    for (int i = 0; i < 16; i++) {
        lpc32[i] = 0;
    }
    k = 0;
}