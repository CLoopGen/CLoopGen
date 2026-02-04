#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

uint16_t off = 42;
npy_intp cnt = 65536; // Approximately 128KB of output data (65536 * 2 bytes)
uint16_t *out = NULL;
npy_intp i;

void init_vars() {
    out = (uint16_t *)aligned_alloc(_Alignof(uint16_t), cnt * sizeof(uint16_t));
    if (!out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}