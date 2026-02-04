#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

extern bench_iodim *dst;
extern  bench_iodim *src;
extern int rnk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access, processing every second element forward then backward
    int stride = 2;
    // Forward pass: even indices
    for (i = 0; i < rnk; i += stride)
        dst[i] = src[i];
    // Backward pass: odd indices
    for (i = (rnk % 2 == 0) ? rnk - 1 : rnk - 2; i > 0; i -= stride)
        dst[i] = src[i];
}
