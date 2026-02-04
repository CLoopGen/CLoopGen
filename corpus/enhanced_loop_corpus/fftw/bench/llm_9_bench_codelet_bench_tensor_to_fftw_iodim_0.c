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
    if (t->rnk <= 0) return;
    d[0].n = t->dims[0].n;
    d[0].is = t->dims[0].is;
    d[0].os = t->dims[0].os;
    for (i = 1; i < t->rnk; i += 2) {
        d[i].n = t->dims[i].n;
        d[i].is = t->dims[i].is;
        d[i].os = t->dims[i].os;
        if (i + 1 < t->rnk) {
            d[i+1].n = t->dims[i+1].n + t->dims[i].n;
            d[i+1].is = t->dims[i+1].is + t->dims[i].is;
            d[i+1].os = t->dims[i+1].os + t->dims[i].os;
        }
    }
}
