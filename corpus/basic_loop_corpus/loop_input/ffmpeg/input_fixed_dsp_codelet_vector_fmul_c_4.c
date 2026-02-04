#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *dst;
int *src0;
int *src1;
int len;
int i;
int64_t accu;

void init_vars() {
    len = 67108864; // Approximately 256MB of input data (3 arrays of int, each 256MB / 3 ~ 85.3MB -> 21M elements)

    src0 = (int *)aligned_alloc(32, len * sizeof(int));
    src1 = (int *)aligned_alloc(32, len * sizeof(int));
    dst  = (int *)aligned_alloc(32, len * sizeof(int));

    for (int j = 0; j < len; j++) {
        src0[j] = rand() % 1000 - 500;
        src1[j] = rand() % 1000 - 500;
    }

    i = 0;
    accu = 0;
}