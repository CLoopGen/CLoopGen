#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp is0;
npy_intp is1;
npy_intp os;
npy_intp n;
char *i0;
char *i1;
char *o;
int k;

static char *buf_i0;
static char *buf_i1;
static char *buf_o;

void init_vars(void);

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 iterations/sec -> aim for ~1e7 iterations
    n = 10000000;

    is0 = 1;
    is1 = 1;
    os = 1;

    npy_intp total_size_i0 = n * labs(is0) + 64;
    npy_intp total_size_i1 = n * labs(is1) + 64;
    npy_intp total_size_o = n * labs(os) + 64;

    buf_i0 = (char *)aligned_alloc(64, total_size_i0);
    buf_i1 = (char *)aligned_alloc(64, total_size_i1);
    buf_o  = (char *)aligned_alloc(64, total_size_o);

    if (!buf_i0 || !buf_i1 || !buf_o) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    i0 = buf_i0 + 32;
    i1 = buf_i1 + 32;
    o  = buf_o  + 32;

    k = 0;
}