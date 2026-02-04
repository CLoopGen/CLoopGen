#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int tmp[16];

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        tmp[j] = rand() % 100;
    }
    i = 0;
}