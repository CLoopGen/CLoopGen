#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef intptr_t Py_intptr_t;

typedef Py_ssize_t npy_intp;

typedef struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
} NpyIter_AxisData;

npy_intp flat_index = 123456;
int idim = 0;
int ndim = 4;
int nop = 1;
npy_intp iterindex = 0;
npy_intp factor = 1;
NpyIter_AxisData *axisdata = NULL;
npy_intp sizeof_axisdata = sizeof(NpyIter_AxisData);

static NpyIter_AxisData axisdata_buffer[64];

void init_vars() {
    flat_index = 123456;
    idim = 0;
    ndim = 4;
    nop = 1;
    iterindex = 0;
    factor = 1;
    
    for (int i = 0; i < ndim; ++i) {
        axisdata_buffer[i].shape = 64 + i * 16;
        axisdata_buffer[i].index = 0;
        axisdata_buffer[i].ad_flexdata = 0;
        ((Py_intptr_t*)(&(axisdata_buffer[i]).ad_flexdata))[nop] = (i % 2) ? -16 : 16;
    }
    
    axisdata = axisdata_buffer;
    sizeof_axisdata = sizeof(NpyIter_AxisData);
}