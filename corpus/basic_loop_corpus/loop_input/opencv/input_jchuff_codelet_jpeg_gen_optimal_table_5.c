#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char UINT8;

UINT8 bits[33];
int bit_pos[33];
int p;
int i;

void init_vars() {
    p = 0;
    for (int idx = 1; idx <= 32; idx++) {
        bits[idx] = 1000000 / 32; 
    }
}