#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp multi_index[64];
extern int idim;
extern int ndim;
extern npy_intp *shape;
extern npy_intp value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp accumulated = 1;
    for (idim = ndim - 1; idim >= 0; --idim) {
        npy_intp current_mod = value % (shape[idim] * accumulated);
        multi_index[idim] = (current_mod / accumulated);
        accumulated *= shape[idim];
    }
}
