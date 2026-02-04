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

static bench_iodim sz_dims[100000];
static bench_iodim x_dims[100000];
static bench_tensor sz_storage;
static bench_tensor x_storage;

bench_tensor *sz = &sz_storage;
bench_tensor *x = &x_storage;
int i;
int rnk;

void init_vars() {
    sz->rnk = 100000;
    sz->dims = sz_dims;
    x->rnk = 0;
    x->dims = x_dims;

    for (int idx = 0; idx < sz->rnk; ++idx) {
        sz->dims[idx].n = (idx % 3) + 1;
        sz->dims[idx].is = idx * 2;
        sz->dims[idx].os = idx * 3;
    }
}