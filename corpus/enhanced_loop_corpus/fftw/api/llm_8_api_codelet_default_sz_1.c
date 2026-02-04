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



void loop() {
    for (i = 0; i < rnk; ++i) {
        sz->dims[i].n = dims0[i].n;
        sz->dims[i].b[0] = dims0[i].ib;
        sz->dims[i].b[1] = dims0[i].ob;
    }
}
