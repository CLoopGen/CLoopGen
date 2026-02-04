#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern int nd;
extern int j;
extern npy_intp size;
extern npy_intp i;
extern npy_bool *ptr;
extern npy_intp coords[64];
extern npy_intp dims_m1[64];
extern npy_intp *dptr[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather/scatter) access using index array
    npy_intp indices[64];
    npy_intp base_index = 0;

    for (i = 0; i < size; i++) {
        // Compute linear index from coordinates
        base_index = 0;
        npy_intp multiplier = 1;
        for (j = nd - 1; j >= 0; j--) {
            base_index += coords[j] * multiplier;
            multiplier *= (dims_m1[j] + 1);
        }

        if (*(ptr++)) {
            for (j = 0; j < nd; j++) {
                indices[j] = base_index + j; // Simulate scatter pattern
                ((npy_intp*)dptr[j])[indices[j]] = coords[j];
            }
        }

        for (j = nd - 1; j >= 0; j--) {
            if (coords[j] < dims_m1[j]) {
                coords[j]++;
                break;
            } else {
                coords[j] = 0;
            }
        }
    }
}
