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
    char *axis_bytes = (char *)axisdata;
    shape = ((NpyIter_AxisData *)axis_bytes)->shape;
    iterstride = (*(Py_intptr_t *)(axis_bytes + offsetof(NpyIter_AxisData, ad_flexdata) + sizeof(Py_intptr_t) * nop));
    if (iterstride == 0) {
        i = 0;
    } else if (iterstride > 0) {
        i = (flat_index / iterstride) % shape;
    } else {
        i = shape - 1 - ((flat_index / (-iterstride)) % shape);
    }
    iterindex += factor * i;
    factor *= shape;
    axisdata = (NpyIter_AxisData *)(axis_bytes + sizeof_axisdata);
}
}
