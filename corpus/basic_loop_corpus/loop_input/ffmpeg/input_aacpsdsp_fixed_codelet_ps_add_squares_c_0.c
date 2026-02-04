#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef int INTFLOAT;
typedef unsigned int UINTFLOAT;

INTFLOAT *dst;
INTFLOAT (*src)[2];
int n;
int i;

void init_vars() {
    n = 67108864;  // ~256MB of data: n elements of src[2] (each 8 bytes) + dst (4 bytes per element) => ~856 MB total
    size_t dst_size = n * sizeof(INTFLOAT);
    size_t src_size = n * 2 * sizeof(INTFLOAT);

    dst = (INTFLOAT *)aligned_alloc(32, dst_size);
    src = (INTFLOAT (*)[2])aligned_alloc(32, src_size);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < n; idx++) {
        dst[idx] = rand() % 100;
        src[idx][0] = rand() % 100;
        src[idx][1] = rand() % 100;
    }

    i = 0;
}