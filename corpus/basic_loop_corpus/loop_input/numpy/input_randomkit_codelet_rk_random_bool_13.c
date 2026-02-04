#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef ptrdiff_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

npy_intp cnt = 10000000;
npy_intp i;
int bcnt;

void init_vars() {
    cnt = 10000000;
    i = 0;
    bcnt = 0;
}