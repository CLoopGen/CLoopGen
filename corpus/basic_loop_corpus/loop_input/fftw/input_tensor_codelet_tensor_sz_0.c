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

static bench_iodim dims_buffer[10];
bench_tensor *sz;
int i;
size_t n;

void init_vars() {
    for (int j = 0; j < 10; ++j) {
        dims_buffer[j].n = 100 + j;
        dims_buffer[j].is = 1;
        dims_buffer[j].os = 4;
    }

    sz = (bench_tensor*)malloc(sizeof(bench_tensor));
    sz->rnk = 5;
    sz->dims = dims_buffer;

    i = 0;
    n = 1;
}