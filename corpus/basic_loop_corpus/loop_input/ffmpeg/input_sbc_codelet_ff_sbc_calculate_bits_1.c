#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int (*bits)[8];
int subbands = 8;
int bitneed[2][8];
int bitslice;
int ch;
int sb;

void init_vars() {
    bitslice = 5;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            bitneed[i][j] = rand() % 32;
        }
    }

    bits = calloc(2, sizeof(int[8]));
    if (!bits) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}