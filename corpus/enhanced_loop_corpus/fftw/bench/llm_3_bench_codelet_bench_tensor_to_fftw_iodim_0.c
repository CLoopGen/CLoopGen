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
    // Variant 2: Strided memory access
    // Process every second element forward, then fill in the gaps backward to create strided pattern
    int stride = 2;
    int idx;

    // Forward pass: handle even indices
    for (i = 0; i < t->rnk; i += stride) {
        d[i].n = t->dims[i].n;
        d[i].is = t->dims[i].is;
        d[i].os = t->dims[i].os;
    }

    // Backward pass: handle odd indices if they exist
    for (i = (t->rnk % 2 == 0) ? t->rnk - 1 : t->rnk - 2; i > 0; i -= stride) {
        idx = i;
        d[idx].n = t->dims[idx].n;
        d[idx].is = t->dims[idx].is;
        d[idx].os = t->dims[idx].os;
    }
}
