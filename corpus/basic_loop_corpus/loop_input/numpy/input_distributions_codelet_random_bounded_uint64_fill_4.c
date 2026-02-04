#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

uint64_t off = 0xdeadbeefcafebabeULL;
npy_intp cnt = 16777216; // ~128MB of data (16M * 8 bytes)
uint64_t *out = NULL;
npy_intp i;

void init_vars() {
    out = (uint64_t *)aligned_alloc(64, cnt * sizeof(uint64_t));
    if (!out) {
        exit(1);
    }
}