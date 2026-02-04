#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

bench_iodim *dst;
bench_iodim *src;
int rnk;
int i;

void init_vars() {
    rnk = 1 << 20; // Approximately 1 million elements

    src = (bench_iodim*)aligned_alloc(32, rnk * sizeof(bench_iodim));
    dst = (bench_iodim*)aligned_alloc(32, rnk * sizeof(bench_iodim));

    for (int idx = 0; idx < rnk; ++idx) {
        src[idx].n = idx;
        src[idx].is = idx * 2;
        src[idx].os = idx * 3;
    }
}