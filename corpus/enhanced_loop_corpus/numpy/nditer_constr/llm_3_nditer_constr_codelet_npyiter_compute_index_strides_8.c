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
    NpyIter_AxisData *base_axisdata = axisdata;
    for (idim = 0; idim < ndim; ++idim) {
        npy_intp offset = idim * (sizeof_axisdata / sizeof(NpyIter_AxisData));
        NpyIter_AxisData *current = (NpyIter_AxisData*)(((char*)base_axisdata) + offset);
        npy_intp shape = current->shape;
        ((&current->ad_flexdata)[nop]) = (shape == 1) ? 0 : indexstride;
        indexstride *= shape;
    }
}
