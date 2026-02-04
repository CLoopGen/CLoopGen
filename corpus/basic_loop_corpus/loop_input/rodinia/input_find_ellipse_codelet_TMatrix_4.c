#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int N;
int *aindex;
int i;

void init_vars() {
    N = 67108864; // 64M elements, roughly 256MB for int array (assuming 4 bytes per int)
    aindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!aindex) {
        exit(1);
    }
    i = 0;
}