#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct fftw_iodim_do_not_use_me {
    int n;
    int is;
    int os;
};

typedef struct fftw_iodim_do_not_use_me fftw_iodim;

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

int rank = 8;
fftw_iodim *dims;
int is = 4;
int os = 8;
int i;
tensor *x;

void init_vars() {
    // Allocate and initialize fftw_iodim array
    dims = (fftw_iodim*)calloc(rank, sizeof(fftw_iodim));
    for (int idx = 0; idx < rank; ++idx) {
        dims[idx].n = 65536 >> (idx); // decreasing sizes: 65536, 32768, ...
        if (dims[idx].n == 0) dims[idx].n = 1;
        dims[idx].is = 2 + idx;
        dims[idx].os = 3 + idx;
    }

    // Allocate tensor x with sufficient space for rank dimensions
    size_t tensor_size = sizeof(tensor) + (rank - 1) * sizeof(iodim);
    x = (tensor*)malloc(tensor_size);
    x->rnk = rank;

    // Ensure warm-up and realistic timing by simulating ~0.01s of work
    // The loop does simple arithmetic per dimension, so we adjust rank to be moderate
    // and individual values are set to plausible sizes.
}