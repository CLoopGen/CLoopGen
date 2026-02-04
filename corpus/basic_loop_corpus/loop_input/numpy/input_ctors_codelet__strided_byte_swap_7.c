#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

void *p;
npy_intp stride;
npy_intp n;
char *a;

static char data[131072]; // 128 KB of data to target ~0.01 sec runtime

void init_vars() {
    p = data;
    stride = 1;
    n = 131072;
    a = NULL;
}