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

static bench_iodim dims_array[1024];
bench_tensor *x;
int i;

void init_vars() {
    x = (bench_tensor *)malloc(sizeof(bench_tensor));
    x->rnk = 1024;
    x->dims = dims_array;

    for (int j = 0; j < x->rnk; ++j) {
        x->dims[j].n = 2;
        x->dims[j].is = 1;
        x->dims[j].os = 1;
    }

    x->dims[x->rnk - 1].is = 4;
    x->dims[x->rnk - 1].os = 8;
}