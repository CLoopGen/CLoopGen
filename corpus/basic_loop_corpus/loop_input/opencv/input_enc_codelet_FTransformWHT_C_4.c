#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t tmp[16];
int i;

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        tmp[j] = rand() % 1000;
    }
    i = 0;
}