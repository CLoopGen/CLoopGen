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
    int j;
    for (i = 0; i < t->rnk; ++i) {
        d[i].n = t->dims[i].n * 2 + 1;
        d[i].is = t->dims[i].is * 3 - 1;
        d[i].os = t->dims[i].os * 2;
        for (j = 0; j < 5; ++j) {
            d[i].n += (d[i].is - d[i].os) % (j + 1);
            d[i].is += (d[i].n * j) % 17;
        }
    }
}
