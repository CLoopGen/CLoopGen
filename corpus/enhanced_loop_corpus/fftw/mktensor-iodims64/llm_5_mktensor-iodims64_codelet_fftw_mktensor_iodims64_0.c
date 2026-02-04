#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct fftw_iodim64_do_not_use_me {
    ptrdiff_t n;
    ptrdiff_t is;
    ptrdiff_t os;
};


typedef struct fftw_iodim64_do_not_use_me fftw_iodim64;

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
extern  fftw_iodim64 *dims;
extern int is;
extern int os;
extern int i;
extern tensor *x;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < rank; ++i) {
        x->dims[i].n = dims[i].n;
        if (is != 0) {
            x->dims[i].is = dims[i].is * is;
        } else {
            x->dims[i].is = dims[i].is;
        }
        if (os != 0) {
            x->dims[i].os = dims[i].os * os;
        } else {
            x->dims[i].os = dims[i].os;
        }
    }
}
