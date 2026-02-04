#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w2;
int x;
int32_t *b;
int32_t *temp;

void init_vars() {
    w2 = 16384; // Controls the array size and loop bound

    b = (int32_t*)aligned_alloc(32, sizeof(int32_t) * w2 * 2);
    temp = (int32_t*)aligned_alloc(32, sizeof(int32_t) * w2 * 2);

    for (int i = 0; i < w2 * 2; i++) {
        b[i] = rand() % 1000;
        temp[i] = 0;
    }
}