#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int subbands;
int bitneed[2][8];
int slicecount;
int bitslice;
int ch;
int sb;

void init_vars() {
    subbands = 8;
    bitslice = 10;
    slicecount = 0;
    ch = 0;
    sb = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            bitneed[i][j] = 15 + (i * j) % 20;
        }
    }
}