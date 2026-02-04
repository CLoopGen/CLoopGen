#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef signed char npy_int8;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef intptr_t Py_intptr_t;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};


typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

extern int axis;
extern int idim;
extern int ndim;
extern int iop;
extern int nop;
extern int xdim;
extern npy_int8 *perm;
extern NpyIter_AxisData *axisdata_del;
extern npy_intp sizeof_axisdata;
extern npy_intp *baseoffsets;
extern char **resetdataptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idim = 0; idim < ndim; ++idim) {
    npy_int8 p = perm[idim];
    int match = (p == axis);
    int neg_match = (!match) && (-1 - p == axis);

    if (match) {
        xdim = idim;
        break;
    }
    if (neg_match) {
        npy_intp *strides = &(axisdata_del->ad_flexdata);
        npy_intp shape = axisdata_del->shape;
        xdim = idim;
        for (iop = 0; iop < nop; ++iop) {
            npy_intp offset = (shape - 1) * strides[iop];
            baseoffsets[iop] += offset;
            resetdataptr[iop] += offset;
        }
        break;
    }
    axisdata_del = (NpyIter_AxisData *)(((char *)axisdata_del) + sizeof_axisdata);
}
}
