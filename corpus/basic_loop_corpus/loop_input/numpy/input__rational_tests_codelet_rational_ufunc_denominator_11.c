#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

typedef struct {
    int n;
    int dmm;
} rational;

npy_intp is = sizeof(rational);
npy_intp os = sizeof(rational);
npy_intp n = 1000000;
char *i;
char *o;
int k;

void init_vars() {
    i = aligned_alloc(64, n * sizeof(rational));
    o = aligned_alloc(64, n * sizeof(rational));

    for (npy_intp idx = 0; idx < n; idx++) {
        rational *r = (rational *)(i + idx * sizeof(rational));
        r->n = idx;
        r->dmm = idx + 1;
    }
}