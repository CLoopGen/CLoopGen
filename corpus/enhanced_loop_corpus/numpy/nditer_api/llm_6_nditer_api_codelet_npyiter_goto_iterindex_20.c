#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef intptr_t Py_intptr_t;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};


typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

extern npy_intp iterindex;
extern int idim;
extern int ndim;
extern char **dataptrs;
extern NpyIter_AxisData *axisdata;
extern npy_intp sizeof_axisdata;
extern npy_intp istrides;
extern npy_intp nstrides;
extern npy_intp i;
extern npy_intp shape;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 0; idim < ndim; ++idim, axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata))) {
        shape = ((axisdata)->shape);
        npy_intp temp_iterindex = iterindex;
        iterindex /= shape;
        npy_intp local_index = temp_iterindex - iterindex * shape;
        ((axisdata)->index) = local_index;
        npy_intp *strides = (&(axisdata)->ad_flexdata + 0);
        for (istrides = 0; istrides < nstrides; ++istrides) {
            dataptrs[istrides] += local_index * strides[istrides];
        }
    }
}
