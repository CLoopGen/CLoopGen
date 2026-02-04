#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ssize_t Py_ssize_t;
typedef intptr_t Py_intptr_t;

typedef Py_ssize_t npy_intp;
typedef Py_ssize_t Py_ssize_t;
typedef Py_intptr_t Py_intptr_t;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};

typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

npy_intp *outshape;
int ndim = 100000;
int idim;
int sizeof_axisdata = sizeof(NpyIter_AxisData);
NpyIter_AxisData *axisdata;

void init_vars() {
    outshape = (npy_intp *)calloc(ndim, sizeof(npy_intp));
    axisdata = (NpyIter_AxisData *)calloc(ndim, sizeof(NpyIter_AxisData));

    for (int i = 0; i < ndim; ++i) {
        axisdata[i].shape = (npy_intp)(i + 1);
        axisdata[i].index = 0;
        axisdata[i].ad_flexdata = 0;
    }
}