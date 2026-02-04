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
    // Variant 1: Consecutive (reverse order) memory access
    // Accessing the arrays from last to first index for better cache behavior in some contexts
    int idx;
    for (i = t->rnk - 1; i >= 0; --i) {
        idx = i;
        d[idx].n = t->dims[idx].n;
        d[idx].is = t->dims[idx].is;
        d[idx].os = t->dims[idx].os;
    }
}
