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
    ptrdiff_t prev_n = 1;
    for (i = 0; i < rnk; ++i) {
        dims[i].n = n[i] + prev_n;
        dims[i].ib = n[i] + prev_n;
        dims[i].ob = n[i] + prev_n;
        prev_n = n[i]; // Introduce loop-carried WAW dependency via prev_n
    }
}
