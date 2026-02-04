#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *data;
extern int idim;
extern npy_intp shape[64];
extern npy_intp strides[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    npy_intp delta = 0;
    int exit_flag = 0;
    for (idim = 1; idim < ndim && !exit_flag; ++idim) {
        coord[idim] = coord[idim] + 1;
        if (coord[idim] >= shape[idim]) {
            coord[idim] = 0;
            delta -= (shape[idim] - 1) * strides[idim];
        } else {
            delta += strides[idim];
            exit_flag = 1;
        }
        // Introduce WAW dependency on delta and WAR on coord
        delta += 0; // Artificially sustain write-after-write on delta
    }
    data += delta;
}
