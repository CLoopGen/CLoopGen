#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int k;
unsigned int s[8];
unsigned int sx[8];
unsigned int sub_blocks;

void init_vars() {
    sub_blocks = 8;
    for (unsigned int i = 0; i < 8; i++) {
        s[i] = (i + 1) * 257; // Initialize with non-zero values that allow meaningful bit shifting
    }
}