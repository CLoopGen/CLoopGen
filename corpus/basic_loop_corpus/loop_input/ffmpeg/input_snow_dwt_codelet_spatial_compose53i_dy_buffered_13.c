#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

int width;
IDWTELEM *b0;
IDWTELEM *b1;
IDWTELEM *b2;
IDWTELEM *b3;
int x;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~128 MB of total data (each element is 2 bytes)
    width = data_size / sizeof(IDWTELEM);

    b0 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b1 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b2 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));
    b3 = (IDWTELEM *)aligned_alloc(32, width * sizeof(IDWTELEM));

    for (int i = 0; i < width; i++) {
        b0[i] = rand() % 100;
        b1[i] = rand() % 100;
        b2[i] = rand() % 100;
        b3[i] = rand() % 100;
    }
}