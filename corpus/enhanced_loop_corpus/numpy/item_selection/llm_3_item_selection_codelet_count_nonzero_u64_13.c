#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef size_t npy_uintp;

extern  char *data;
extern npy_intp bstride;
extern npy_uintp len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (scatter/gather style)
    // Simulates non-contiguous, indexed access using an auxiliary index array
    npy_intp *indices = (npy_intp*)malloc(len * sizeof(npy_intp));
    if (!indices) return;
    for (npy_intp i = 0; i < len; ++i) {
        indices[i] = i * bstride; // Precomputed offsets
    }
    char *base = data;
    for (npy_uintp j = 0; j < len; ++j) {
        volatile char dummy = *(base + indices[j]); // Indirect access through index
    }
    free(indices);
    len = 0; // Ensure loop does not re-execute
}
