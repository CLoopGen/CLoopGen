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

static bench_iodim *dims_buffer;
bench_tensor *x;
int i;

void init_vars() {
    x = (bench_tensor *)malloc(sizeof(bench_tensor));
    if (!x) exit(1);

    x->rnk = 10000000; // Adjusted to achieve ~0.01 sec runtime on modern CPU

    dims_buffer = (bench_iodim *)calloc(x->rnk, sizeof(bench_iodim));
    if (!dims_buffer) exit(1);

    for (int j = 0; j < x->rnk; ++j) {
        dims_buffer[j].n = j + 1;
        dims_buffer[j].is = j * 2;
        dims_buffer[j].os = j * 3;
    }

    x->dims = dims_buffer;
}