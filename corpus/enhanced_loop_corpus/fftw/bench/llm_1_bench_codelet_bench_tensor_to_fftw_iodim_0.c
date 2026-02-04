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
    int outer = 1;
    for (i = 0; i < outer && i < t->rnk; ++i) {
        for (int j = i; j <= i; ++j) {
            d[j].n = t->dims[j].n;
            d[j].is = t->dims[j].is;
            d[j].os = t->dims[j].os;
        }
    }
}
