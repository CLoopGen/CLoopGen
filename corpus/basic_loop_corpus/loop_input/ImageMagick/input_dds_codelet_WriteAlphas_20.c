#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
unsigned char indices5[16];
unsigned char indices7[16];

void init_vars() {
    for (i = 0; i < 16; i++) {
        indices7[i] = i % 10;
    }
}