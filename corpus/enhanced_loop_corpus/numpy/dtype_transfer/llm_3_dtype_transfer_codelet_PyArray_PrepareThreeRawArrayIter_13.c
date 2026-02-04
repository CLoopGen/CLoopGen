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
extern npy_intp *out_stridesC;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Indirect Indexing
    // Use an auxiliary index array to simulate indirect access, changing the memory access pattern
    // to a strided and potentially non-contiguous layout. This models scenarios like gathered tensor dimensions.
    npy_intp *index_map = (npy_intp*)alloca(ndim * sizeof(npy_intp));
    for (j = 0; j < ndim; ++j) {
        index_map[j] = j; // Identity map initially; could be randomized or reordered in real use cases
    }

    for (j = 1; j < ndim; ++j) {
        npy_intp mapped_j = index_map[j]; // Indirect access via index map

        if (out_shape[i] == 1) {
            out_shape[i] = out_shape[mapped_j];
            out_stridesA[i] = out_stridesA[mapped_j];
            out_stridesB[i] = out_stridesB[mapped_j];
            out_stridesC[i] = out_stridesC[mapped_j];
        } else if (out_shape[mapped_j] == 1) {
            continue;
        } else if (out_stridesA[i] * out_shape[i] == out_stridesA[mapped_j] &&
                   out_stridesB[i] * out_shape[i] == out_stridesB[mapped_j] &&
                   out_stridesC[i] * out_shape[i] == out_stridesC[mapped_j]) {
            out_shape[i] *= out_shape[mapped_j];
        } else {
            ++i;
            out_shape[i] = out_shape[mapped_j];
            out_stridesA[i] = out_stridesA[mapped_j];
            out_stridesB[i] = out_stridesB[mapped_j];
            out_stridesC[i] = out_stridesC[mapped_j];
        }
    }
}
