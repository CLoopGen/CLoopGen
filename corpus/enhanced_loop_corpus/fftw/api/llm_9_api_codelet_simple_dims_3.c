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

extern int rnk;
extern  ptrdiff_t *n;
extern fftw_mpi_ddim *dims;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < rnk * 2; i += 2) {
        ptrdiff_t val = n[i / 2];
        dims[i / 2].n = val;
        dims[i / 2].ib = val;
        dims[i / 2].ob = val;
    }
}
