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

struct fftw_iodim_do_not_use_me {
    int n;
    int is;
    int os;
};


typedef struct fftw_iodim_do_not_use_me fftw_iodim;

extern bench_tensor *t;
extern fftw_iodim *d;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependence by making each iteration depend on the previous one (WAW and RAW)
    // This creates a sequential dependency chain across iterations via a temporary variable.
    int prev_n = 1;
    for (i = 0; i < t->rnk; ++i) {
        d[i].n = t->dims[i].n * prev_n;  // RAW: uses prev_n from prior iteration
        d[i].is = t->dims[i].is;
        d[i].os = t->dims[i].os;
        prev_n = d[i].n;  // WAW: write to prev_n used in next iteration
    }
}
