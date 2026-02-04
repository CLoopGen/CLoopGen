#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

void *p;
npy_intp stride;
npy_intp n;
int size;
char *a;
char *b;
char c;
int j;
int m;

char *memory_pool;

void init_vars() {
    size = 128;
    m = size / 2;
    stride = size;
    n = 200000;
    size_t total_size = (size_t)(n + 1) * (size_t)stride;
    memory_pool = (char *)aligned_alloc(64, total_size);
    if (!memory_pool) {
        exit(1);
    }
    p = memory_pool;
    a = NULL;
    b = NULL;
    c = 0;
    j = 0;
}