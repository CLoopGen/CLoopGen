#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;
typedef unsigned char npy_bool;

npy_intp *dims;
int nd = 25600000; // Large enough to make loop take ~0.01s
int i;
npy_bool not_cf_contig;
npy_bool nod;

void init_vars() {
    dims = (npy_intp*)malloc(nd * sizeof(npy_intp));
    if (!dims) {
        exit(1);
    }
    for (int j = 0; j < nd; j++) {
        dims[j] = (j % 2 == 0) ? 1 : 2; // Alternate between 1 and non-1 to trigger logic
    }
    i = 0;
    not_cf_contig = 0;
    nod = 0;
}