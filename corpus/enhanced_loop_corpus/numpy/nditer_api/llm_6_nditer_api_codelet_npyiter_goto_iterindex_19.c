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

extern int idim;
extern int ndim;
extern NpyIter_AxisData *axisdata;
extern npy_intp sizeof_axisdata;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_index = 0;
    for (idim = 0; idim < ndim; ++idim) {
        temp_index += ((axisdata)->index);
        ((axisdata)->index) = 0;
        axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata));
    }
    // Introduce a post-loop use of accumulated data to create a WAW and RAW dependency on loop iterations
    if (ndim > 0) {
        axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) - (ndim) * sizeof_axisdata));
        ((axisdata)->index) = temp_index;
    }
}
