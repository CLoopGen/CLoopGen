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
    for (idim = 1; idim < ndim && idim < 32; idim += 2) {
        npy_intp stride1 = strides[idim];
        npy_intp shape1 = shape[idim];
        npy_intp stride2 = (idim + 1 < ndim) ? strides[idim + 1] : 0;
        npy_intp shape2 = (idim + 1 < ndim) ? shape[idim + 1] : 1;

        // Process two dimensions per iteration to increase computational intensity
        npy_intp prev_coord1 = ++coord[idim];
        if (prev_coord1 == shape1) {
            coord[idim] = 0;
            data -= (shape1 - 1) * stride1;
        } else {
            data += stride1;
            break;
        }

        if (idim + 1 < ndim) {
            npy_intp prev_coord2 = ++coord[idim + 1];
            if (prev_coord2 == shape2) {
                coord[idim + 1] = 0;
                data -= (shape2 - 1) * stride2;
            } else {
                data += stride2;
                break;
            }
        }
    }
}
