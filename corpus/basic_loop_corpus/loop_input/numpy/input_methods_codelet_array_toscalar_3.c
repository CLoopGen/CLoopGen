#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp multi_index[64];
int idim;
int ndim;

void init_vars() {
    ndim = 64;
}

void loop();