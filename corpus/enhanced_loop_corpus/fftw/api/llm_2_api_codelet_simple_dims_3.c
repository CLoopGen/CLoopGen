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
    // Variant 1: Consecutive memory access with reversed loop order
    for (i = rnk - 1; i >= 0; --i) {
        ptrdiff_t idx = i;
        dims[idx].n = n[idx];
        dims[idx].ib = n[idx];
        dims[idx].ob = n[idx];
    }
}
