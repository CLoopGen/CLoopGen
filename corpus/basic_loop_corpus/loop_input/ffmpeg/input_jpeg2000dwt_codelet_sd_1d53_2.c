#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    p = (int*)aligned_alloc(_Alignof(int), data_size);
    if (!p) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(int); idx++) {
        p[idx] = rand() % 1000;
    }

    i0 = 0;
    i1 = (data_size / sizeof(int)) - 3; // ensures 2*i+2 is in bounds when i reaches (i1+1)>>1 - 1
}