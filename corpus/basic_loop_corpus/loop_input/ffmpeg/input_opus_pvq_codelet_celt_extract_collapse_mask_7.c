#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *iy;
uint32_t B = 20;
int i;
int j;
int N0 = 50000;
uint32_t collapse_mask;

void init_vars() {
    size_t total_size = B * N0 * sizeof(int);
    iy = (int*)aligned_alloc(_Alignof(int), total_size);
    if (!iy) {
        exit(1);
    }
    for (size_t idx = 0; idx < B * N0; ++idx) {
        iy[idx] = rand() % 2;
    }
    collapse_mask = 0;
}