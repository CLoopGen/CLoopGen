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
npy_intp stride = (nd > 1) ? 2 : 1;
for (i = 0; i < size; i += 2) {
    npy_bool val1 = (i < size) ? *(ptr++) : 0;
    npy_bool val2 = (i + 1 < size) ? *(ptr++) : 0;

    if (val1) {
        for (j = 0; j < nd; j++) {
            dptr[j][0] = coords[j];
            dptr[j]++;
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

    if (val2) {
        for (j = 0; j < nd; j++) {
            dptr[j][0] = coords[j];
            dptr[j]++;
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
