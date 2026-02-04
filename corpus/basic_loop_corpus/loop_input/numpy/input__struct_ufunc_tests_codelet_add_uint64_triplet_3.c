#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp i;
npy_intp is1 = 1;
npy_intp is2 = 1;
npy_intp os = 1;
npy_intp n;
char *i1;
char *i2;
char *op;

static char *i1_buffer;
static char *i2_buffer;
static char *op_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec on modern CPU
    n = data_size;

    i1_buffer = (char *)aligned_alloc(64, data_size);
    i2_buffer = (char *)aligned_alloc(64, data_size);
    op_buffer = (char *)aligned_alloc(64, data_size);

    if (!i1_buffer || !i2_buffer || !op_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    i1 = i1_buffer;
    i2 = i2_buffer;
    op = op_buffer;
}