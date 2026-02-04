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



void loop(){
    for (i = 0; i < rank; ++i) {
        if (dims[i].n <= 0) continue;
        x->dims[i].n = dims[i].n;
        x->dims[i].is = (dims[i].is > 0) ? dims[i].is * is : -dims[i].is * is;
        x->dims[i].os = (dims[i].os > 0) ? dims[i].os * os : -dims[i].os * os;
    }
}
