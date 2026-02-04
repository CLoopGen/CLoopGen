#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int fft_bits;
int h;

void init_vars() {
    h = 1 << 20;  // Set h to approximately 1MB scale input
}