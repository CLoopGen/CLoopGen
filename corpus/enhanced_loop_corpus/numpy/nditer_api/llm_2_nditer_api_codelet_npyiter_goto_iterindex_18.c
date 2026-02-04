#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp istrides;
extern npy_intp nstrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp *indices = (npy_intp*)malloc(nstrides * sizeof(npy_intp));
    for (npy_intp i = 0; i < nstrides; ++i) {
        indices[i] = i * 2; // Strided index pattern
    }
    for (istrides = 0; istrides < nstrides; ++istrides) {
        istrides = indices[istrides]; // Indirect access via precomputed strided indices
        // Access pattern is now indirect and strided
        if (istrides >= nstrides) break;
    }
    free(indices);
}
