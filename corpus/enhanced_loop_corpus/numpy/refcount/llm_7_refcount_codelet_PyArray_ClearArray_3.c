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
    npy_intp delta = 0;
    int updated = 0;
    for (idim = 1; idim < ndim && !updated; ++idim) {
        coord[idim]++;
        if (coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
            delta -= (shape_it[idim] - 1) * strides_it[idim];
        } else {
            delta += strides_it[idim];
            updated = 1;
        }
    }
    data_it += delta;
    // Introduce WAW dependency on idim by ensuring final idim value is only written once
    // Loop-carried dependency removed via accumulation in delta and single update to data_it
}
