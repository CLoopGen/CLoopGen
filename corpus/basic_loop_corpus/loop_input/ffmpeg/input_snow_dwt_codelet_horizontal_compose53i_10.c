#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB of data

IDWTELEM *b;
IDWTELEM *temp;
int width;
int x;

void init_vars() {
    width = DATA_SIZE / sizeof(IDWTELEM);
    b = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);
    temp = (IDWTELEM*)aligned_alloc(32, DATA_SIZE);

    for (int i = 0; i < width; i++) {
        b[i] = rand() % 100;
        temp[i] = rand() % 100;
    }

    x = 0;
}