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

int idim;
int ndim = 8;
int nop = 2;
npy_intp indexstride;
NpyIter_AxisData *axisdata;
npy_intp sizeof_axisdata = sizeof(NpyIter_AxisData);

NpyIter_AxisData axisdata_buffer[32];

void init_vars() {
    idim = 0;
    ndim = 8;
    nop = 2;
    indexstride = 1;
    sizeof_axisdata = sizeof(NpyIter_AxisData);
    axisdata = axisdata_buffer;

    for (int i = 0; i < ndim; ++i) {
        axisdata_buffer[i].shape = (i < 4) ? 1024 : 16;
        axisdata_buffer[i].index = 0;
        axisdata_buffer[i].ad_flexdata = 0;
    }
}