#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct fftw_iodim64_do_not_use_me {
    ptrdiff_t n;
    ptrdiff_t is;
    ptrdiff_t os;
};

typedef struct fftw_iodim64_do_not_use_me fftw_iodim64;

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
fftw_iodim64 *dims;
int is = 2;
int os = 4;
int i;
tensor *x;

void init_vars() {
    dims = (fftw_iodim64*)aligned_alloc(64, rank * sizeof(fftw_iodim64));
    x = (tensor*)aligned_alloc(64, sizeof(tensor) + (rank - 1) * sizeof(iodim));

    x->rnk = rank;

    for (int j = 0; j < rank; ++j) {
        dims[j].n = 1000 + j;
        dims[j].is = 16 + j * 2;
        dims[j].os = 32 + j * 4;
    }
}