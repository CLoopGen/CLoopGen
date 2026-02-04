#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

uint8_t off = 42;
npy_intp cnt = 67108864; // ~64 million elements, approx 64 MB
uint8_t *out = NULL;
npy_intp i;

void init_vars() {
    out = (uint8_t *)malloc(cnt * sizeof(uint8_t));
    if (!out) {
        exit(1);
    }
}