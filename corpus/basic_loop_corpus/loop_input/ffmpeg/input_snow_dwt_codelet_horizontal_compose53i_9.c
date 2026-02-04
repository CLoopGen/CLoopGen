#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *b;
IDWTELEM *temp;
int width2;
int w2;
int x;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure loop runtime around 0.01s
    width2 = data_size / sizeof(IDWTELEM) / 4;  // Each iteration accesses two elements from b and writes two to temp

    w2 = width2; // Ensure b[x + w2] stays in bounds: x < width2 => x + w2 < width2 + w2 <= total length of b

    b = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * width2 * 2);
    temp = (IDWTELEM*)aligned_alloc(32, sizeof(IDWTELEM) * width2 * 2);

    for (int i = 0; i < width2 * 2; i++) {
        b[i] = (IDWTELEM)(i & 0xFF);
    }
    for (int i = 0; i < width2 * 2; i++) {
        temp[i] = 0;
    }
}