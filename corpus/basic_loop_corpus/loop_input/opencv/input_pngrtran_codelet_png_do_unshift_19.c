#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int shift[4];
int channels = 4;
int bit_depth = 16;
int c;
int have_shift;

void init_vars() {
    for (int i = 0; i < 4; ++i) {
        shift[i] = rand() % 32 - 10;
    }
    channels = 4;
    bit_depth = 16;
    c = 0;
    have_shift = 0;
}