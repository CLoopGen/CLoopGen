#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef Py_ssize_t npy_intp;

npy_intp i;
npy_intp n;
char *in1;
char *in2;
npy_intp in1_step;
npy_intp in2_step;

static npy_intp *in1_data;
static npy_intp *in2_data;

void init_vars() {
    // Each element is npy_intp (typically 8 bytes on 64-bit)
    // Aim for ~100ms execution: about 16M elements = 128MB total data
    n = 16000000;
    
    in1_step = sizeof(npy_intp);
    in2_step = sizeof(npy_intp);

    // Allocate input arrays
    in1_data = aligned_alloc(64, n * sizeof(npy_intp));
    in2_data = aligned_alloc(64, n * sizeof(npy_intp));

    if (!in1_data || !in2_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data
    for (npy_intp j = 0; j < n; j++) {
        in1_data[j] = j + 1;
        in2_data[j] = j * 2;
    }

    // Set pointers to start of arrays
    in1 = (char *)in1_data;
    in2 = (char *)in2_data;
}