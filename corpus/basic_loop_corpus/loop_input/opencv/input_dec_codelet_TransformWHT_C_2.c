#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tmp[16];
int i;

const int a0 = 42;
const int a1 = 17;
const int a2 = 93;
const int a3 = 64;

void init_vars() {
    for (int j = 0; j < 16; ++j) {
        tmp[j] = j * 10;
    }
    i = 0;
}