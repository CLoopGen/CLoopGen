#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int dst_size = 16777216; // 16M elements, ~128MB total data (assuming double arrays)

int64_t index2 = 0x100000000LL; // Ensure initial shift >>32 gives valid index

int64_t incr = 0x200000000LL; // Increment by 2 when shifted right by 32

double *dst;
double *src;
int dst_index;

void init_vars() {
    dst = aligned_alloc(32, dst_size * sizeof(double));
    src = aligned_alloc(32, (dst_size * 2) * sizeof(double)); // Larger to accommodate index2 shifts

    for (int i = 0; i < dst_size; i++) {
        dst[i] = 0.0;
    }
    for (int i = 0; i < dst_size * 2; i++) {
        src[i] = (double)(i + 1) * 0.5;
    }

    dst_index = 0;
}