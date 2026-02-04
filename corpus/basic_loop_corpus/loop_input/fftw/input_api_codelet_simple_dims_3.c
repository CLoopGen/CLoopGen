#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct fftw_mpi_ddim_do_not_use_me {
    ptrdiff_t n;
    ptrdiff_t ib;
    ptrdiff_t ob;
};

typedef struct fftw_mpi_ddim_do_not_use_me fftw_mpi_ddim;

int rnk = 256;

ptrdiff_t *n;
fftw_mpi_ddim *dims;
int i;

void init_vars() {
    n = (ptrdiff_t *)malloc(rnk * sizeof(ptrdiff_t));
    dims = (fftw_mpi_ddim *)malloc(rnk * sizeof(fftw_mpi_ddim));

    for (int j = 0; j < rnk; ++j) {
        n[j] = 1048576 / rnk;
    }
}