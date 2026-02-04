#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int newlistsize = 0;
int *sizes;

void init_vars() {
    sizes = (int*)aligned_alloc(32, (1 << 10) * sizeof(int));
    for (int i = 0; i < (1 << 10); i++) {
        sizes[i] = i + 1;
    }
}