#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

typedef struct {
    int rnk;
    bench_iodim *dims;
} bench_tensor;

extern bench_tensor *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element forward and backward)
    int stride = 2;
    int i;
    // Forward pass with stride
    for (i = 0; i < x->rnk; i += stride) {
        int s = x->dims[i].is;
        x->dims[i].is = x->dims[i].os;
        x->dims[i].os = s;
    }
    // Backward pass for remaining odd indices if rnk is odd
    for (i = (x->rnk % 2 == 0) ? x->rnk - 1 : x->rnk - 2; i > 0; i -= stride) {
        int s = x->dims[i].is;
        x->dims[i].is = x->dims[i].os;
        x->dims[i].os = s;
    }
}
