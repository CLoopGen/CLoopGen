#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char kxor[64] = {0};

void init_vars() {
    for (size_t i = 0; i < sizeof(kxor); i++) {
        kxor[i] = rand() % 256;
    }
}