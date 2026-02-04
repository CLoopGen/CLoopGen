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
    ptrdiff_t temp_n;
    for (i = 0; i < rnk; ++i) {
        temp_n = n[i];
        dims[i].n = temp_n;
        dims[i].ib = temp_n;
        dims[i].ob = temp_n;
    }
}
