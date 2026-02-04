#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

typedef struct fftw_mpi_ddim_do_not_use_me {
    ptrdiff_t n;
    ptrdiff_t ib;
    ptrdiff_t ob;
} fftw_mpi_ddim;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

int rnk = 256;
fftw_mpi_ddim *dims0;
dtensor *sz;
int i;

void init_vars() {
    dims0 = (fftw_mpi_ddim*)aligned_alloc(64, rnk * sizeof(fftw_mpi_ddim));
    sz = (dtensor*)aligned_alloc(64, sizeof(dtensor) + (rnk - 1) * sizeof(ddim));

    for (int j = 0; j < rnk; ++j) {
        dims0[j].n = (ptrdiff_t)(j + 1) * 1000;
        sz->dims[j].n = 0;
        sz->dims[j].b[0] = 0;
        sz->dims[j].b[1] = 0;
    }
    sz->rnk = rnk;
}