#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int divisions;
int *sizes;
int *startaddr;
int largestSize;

void init_vars() {
    divisions = 65536;

    sizes = (int*)aligned_alloc(32, divisions * sizeof(int));
    startaddr = (int*)aligned_alloc(32, (divisions + 1) * sizeof(int));

    for (int i = 0; i < divisions; i++) {
        sizes[i] = rand() % 4096 + 1;
    }

    startaddr[0] = 1000;
    largestSize = 0;
}