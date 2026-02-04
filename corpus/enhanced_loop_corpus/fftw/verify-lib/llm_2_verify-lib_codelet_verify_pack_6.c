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
    // Variant 1: Consecutive memory access by reversing iteration order and accessing struct fields in a more cache-friendly manner
    int rnk = x->rnk;
    bench_iodim *dims = x->dims;
    for (i = 1; i < rnk; ++i) {
        dims[rnk - i - 1].is = dims[rnk - i].is * dims[rnk - i].n;
        dims[rnk - i - 1].os = dims[rnk - i].os * dims[rnk - i].n;
    }
}
