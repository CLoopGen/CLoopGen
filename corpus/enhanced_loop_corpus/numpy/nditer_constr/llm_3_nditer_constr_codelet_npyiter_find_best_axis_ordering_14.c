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
extern npy_intp sizeof_axisdata;
extern NpyIter_AxisData *ad_i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process every second axis, forward)
    npy_intp stride_factor = 2;
    npy_intp total_steps = (ndim + stride_factor - 1) / stride_factor;
    NpyIter_AxisData *current_ad_i = ad_i;

    for (idim = 0; idim < total_steps; ++idim, current_ad_i = ((NpyIter_AxisData *)(((char *)(current_ad_i)) + stride_factor * sizeof_axisdata))) {
        ((current_ad_i)->index) = 1;
    }
}
