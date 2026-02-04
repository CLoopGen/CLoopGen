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

static bench_iodim *dims;
static bench_tensor tensor_storage;
bench_tensor *t = &tensor_storage;
int *n;
int i;

void init_vars() {
    t->rnk = 65536;
    dims = (bench_iodim*)calloc(t->rnk, sizeof(bench_iodim));
    n = (int*)malloc(t->rnk * sizeof(int));
    if (!dims || !n) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int idx = 0; idx < t->rnk; ++idx) {
        dims[idx].n = rand() % 1000 + 1;
        dims[idx].is = rand() % 1000 + 1;
        dims[idx].os = rand() % 1000 + 1;
    }
    t->dims = dims;
}