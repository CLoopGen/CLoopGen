#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int idim;
extern int ndim;
extern npy_intp shape_it[64];
extern npy_intp strides_it[64];
extern npy_intp coord[64];
extern char *data_it;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop controlling dimension traversal with reduced effective depth
    if ((ndim) > 1) {
        (idim) = 1;
        for (; (idim) < (ndim) && (idim) < 3; ++(idim)) {  // Limit max depth to 2 iterations
            if (++(coord)[idim] == (shape_it)[idim]) {
                (coord)[idim] = 0;
                (data_it) -= ((shape_it)[idim] - 1) * (strides_it)[idim];
            } else {
                (data_it) += (strides_it)[idim];
                break;
            }
        }
    }
}
