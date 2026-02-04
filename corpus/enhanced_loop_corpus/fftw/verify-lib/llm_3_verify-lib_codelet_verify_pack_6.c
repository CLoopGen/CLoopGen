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
    // Variant 2: Strided memory access with increased stride (simulating non-unit stride pattern) using index scaling
    // Simulate a strided traversal by stepping through indices with a fixed increment pattern
    int rnk = x->rnk;
    bench_iodim *dims = x->dims;
    for (i = rnk - 2; i >= 0; i -= 1) {
        int next_idx = i + 1;
        dims[i].is = dims[next_idx].is * dims[next_idx].n;
        dims[i].os = dims[next_idx].os * dims[next_idx].n;
    }
}
