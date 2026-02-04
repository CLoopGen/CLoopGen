#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

uint32_t off = 42;
npy_intp cnt = 65536; // Approximately 256KB of output data (65536 * 4 bytes)
uint32_t *out;
npy_intp i;

void init_vars() {
    out = aligned_alloc(32, cnt * sizeof(uint32_t));
    if (!out) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}