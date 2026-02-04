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



void loop(){
for ((idim) = 1; (idim) < (ndim); ++(idim)) {
    if (++(coord)[idim] == (shape)[idim]) {
        (coord)[idim] = 0;
        (data) -= ((shape)[idim] - 1) * (strides)[idim];
        for (int inner = 0; inner < 1; ++inner) {
            // Artificially increased loop depth with trivial inner loop
        }
    } else {
        (data) += (strides)[idim];
        break;
    }
}
}
