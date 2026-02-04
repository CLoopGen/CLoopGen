#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
int ndim = 1000000; // Large enough to take ~0.01s
NpyIter_AxisData *axisdata;
npy_intp sizeof_axisdata = sizeof(NpyIter_AxisData);

void init_vars() {
    axisdata = (NpyIter_AxisData *)aligned_alloc(64, ndim * sizeof_axisdata);
    if (!axisdata) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < ndim; ++i) {
        axisdata[i].shape = 1;
        axisdata[i].index = -1;
        axisdata[i].ad_flexdata = 0;
    }
}