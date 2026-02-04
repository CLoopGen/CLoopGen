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
int ndim = 1000000;
npy_intp sizeof_axisdata = sizeof(NpyIter_AxisData);
NpyIter_AxisData *ad_i;

void init_vars() {
    ad_i = (NpyIter_AxisData *)calloc(ndim, sizeof_axisdata);
    if (!ad_i) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}