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
extern int nop;
extern npy_intp indexstride;
extern NpyIter_AxisData *axisdata;
extern npy_intp sizeof_axisdata;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    NpyIter_AxisData *current_axis = (NpyIter_AxisData *)(((char *)(axisdata)) + (-ndim + 1) * sizeof_axisdata);
    for (idim = 0; idim < ndim; ++idim, current_axis = ((NpyIter_AxisData *)(((char *)(current_axis)) + sizeof_axisdata))) {
        npy_intp shape = current_axis->shape;
        Py_intptr_t *flexdata_base = &(current_axis->ad_flexdata);
        flexdata_base[nop] = (shape == 1) ? 0 : indexstride;
        indexstride *= shape;
    }
}
