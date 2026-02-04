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

extern npy_intp flat_index;
extern int idim;
extern int ndim;
extern int nop;
extern npy_intp iterindex;
extern npy_intp factor;
extern NpyIter_AxisData *axisdata;
extern npy_intp sizeof_axisdata;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idim = 0; idim < ndim; ++idim) {
    npy_intp i, shape, iterstride;
    iterstride = (&(axisdata)->ad_flexdata + 0)[nop];
    shape = ((axisdata)->shape);
    if (iterstride == 0) {
        i = 0;
    } else if (iterstride < 0) {
        i = shape - (flat_index / (-iterstride)) % shape - 1;
    } else {
        i = (flat_index / iterstride) % shape;
    }
    iterindex += factor * i;
    factor *= shape;
    axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata));
}
}
