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
    for (i = 0; i < rnk && dims != NULL; ++i) {
        ptrdiff_t val = n[i];
        dims[i].n = val;
        if (val % 2 == 0) {
            dims[i].ib = val;
            dims[i].ob = val;
        } else {
            dims[i].ib = val + 1;
            dims[i].ob = val - 1;
        }
    }
}
