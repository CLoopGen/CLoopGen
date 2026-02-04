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

extern npy_intp *outshape;
extern int ndim;
extern int idim;
extern int sizeof_axisdata;
extern NpyIter_AxisData *axisdata;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 0; idim < ndim; ++idim) {
        outshape[idim] = ((axisdata)->shape);
        outshape[idim] *= 2; // Additional arithmetic operation to increase computational intensity
        axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata));
    }
}
