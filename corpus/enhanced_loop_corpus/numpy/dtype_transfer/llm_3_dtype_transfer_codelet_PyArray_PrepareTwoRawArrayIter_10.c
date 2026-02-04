#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern npy_intp *out_shape;
extern npy_intp *out_stridesA;
extern npy_intp *out_stridesB;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Indirect Indexing
    // Use an auxiliary index array to access shape and stride elements indirectly,
    // simulating non-contiguous or reordered dimension processing (e.g., based on stride size).
    // This can improve vectorization or reflect runtime-determined access patterns.

    npy_intp *index_map = (npy_intp*)alloca(ndim * sizeof(npy_intp));
    for (j = 0; j < ndim; ++j) {
        index_map[j] = j;
    }

    // Simple bubble sort on index_map based on out_stridesA (ascending)
    for (int k = 1; k < ndim - 1; ++k) {
        for (int l = 1; l < ndim - k; ++l) {
            if (out_stridesA[index_map[l]] > out_stridesA[index_map[l + 1]]) {
                npy_intp temp = index_map[l];
                index_map[l] = index_map[l + 1];
                index_map[l + 1] = temp;
            }
        }
    }

    for (j = 1; j < ndim; ++j) {
        int idx = index_map[j];  // Indirect access via permutation
        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[idx];
            out_stridesA[i] = out_stridesA[idx];
            out_stridesB[i] = out_stridesB[idx];
        } else if (out_shape[idx] == 1) {
            continue;
        } else if (out_stridesA[i] * out_shape[i] == out_stridesA[idx] && out_stridesB[i] * out_shape[i] == out_stridesB[idx]) {
            out_shape[i] *= out_shape[idx];
        } else {
            ++i;
            out_shape[i] = out_shape[idx];
            out_stridesA[i] = out_stridesA[idx];
            out_stridesB[i] = out_stridesB[idx];
        }
    }
}
