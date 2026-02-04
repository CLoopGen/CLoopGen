#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct fftw_iodim_do_not_use_me {
    int n;
    int is;
    int os;
};


typedef struct fftw_iodim_do_not_use_me fftw_iodim;

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

extern int rank;
extern  fftw_iodim *dims;
extern int is;
extern int os;
extern int i;
extern tensor *x;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    INT temp_is, temp_os;
    for (i = 0; i < rank; ++i) {
        temp_is = dims[i].is * is;
        temp_os = dims[i].os * os;
        x->dims[i].n = dims[i].n;
        x->dims[i].is = temp_is;
        x->dims[i].os = temp_os;
    }
}
