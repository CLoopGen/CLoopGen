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

typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT b[2];
} ddim;

typedef struct {
    int rnk;
    ddim dims[1];
} dtensor;

extern int rnk;
extern  fftw_mpi_ddim *dims0;
extern dtensor *sz;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic for improved locality
    ddim *dims_ptr = sz->dims;
    fftw_mpi_ddim *dims0_ptr = dims0;
    for (i = 0; i < rnk; ++i) {
        dims_ptr[i].n = dims0_ptr[i].n;
    }
}
