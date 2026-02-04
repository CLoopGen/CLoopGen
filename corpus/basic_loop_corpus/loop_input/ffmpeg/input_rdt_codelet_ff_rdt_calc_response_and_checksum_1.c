#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
unsigned char buf[64];
unsigned char xor_table[37];

void init_vars() {
    for (int j = 0; j < 64; j++) {
        buf[j] = (unsigned char)(j * 31);
    }
    for (int j = 0; j < 37; j++) {
        xor_table[j] = (unsigned char)(j * 17);
    }
}