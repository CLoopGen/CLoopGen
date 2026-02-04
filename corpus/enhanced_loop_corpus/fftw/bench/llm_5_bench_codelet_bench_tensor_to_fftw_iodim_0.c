#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

typedef struct {
    int rnk;
    bench_iodim *dims;
} bench_tensor;

struct fftw_iodim_do_not_use_me {
    int n;
    int is;
    int os;
};


typedef struct fftw_iodim_do_not_use_me fftw_iodim;

extern bench_tensor *t;
extern fftw_iodim *d;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = t->rnk;
for (i = 0; i < limit; ++i) {
    d[i].n = t->dims[i].n;
    if (t->dims[i].is >= 0) {
        d[i].is = t->dims[i].is;
    } else {
        d[i].is = 1;
    }
    d[i].os = t->dims[i].os;
}
}
