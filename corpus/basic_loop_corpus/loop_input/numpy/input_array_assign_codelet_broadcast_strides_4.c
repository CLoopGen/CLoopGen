#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp *out_strides;
int idim;
int idim_start;

void init_vars() {
    idim_start = 10000000; // Adjusted for ~0.01 sec runtime
    out_strides = (npy_intp *)calloc(idim_start, sizeof(npy_intp));
}

void loop(); // Forward declaration

// Ensure the loop function can be linked externally
// The actual loop implementation is provided elsewhere