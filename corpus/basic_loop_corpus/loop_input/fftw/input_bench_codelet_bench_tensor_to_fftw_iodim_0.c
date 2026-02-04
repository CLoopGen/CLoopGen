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

bench_tensor *t;
fftw_iodim *d;
int i;

void init_vars() {
    t = (bench_tensor *)malloc(sizeof(bench_tensor));
    t->rnk = 1000000 / sizeof(bench_iodim); // ~1MB of data
    t->dims = (bench_iodim *)malloc(t->rnk * sizeof(bench_iodim));

    for (int j = 0; j < t->rnk; ++j) {
        t->dims[j].n = j + 1;
        t->dims[j].is = (j + 1) * 2;
        t->dims[j].os = (j + 1) * 3;
    }

    d = (fftw_iodim *)malloc(t->rnk * sizeof(fftw_iodim));
}