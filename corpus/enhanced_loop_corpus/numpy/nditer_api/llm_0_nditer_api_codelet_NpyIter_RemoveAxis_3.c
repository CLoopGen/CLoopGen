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
        if (perm[idim] == axis) {
            xdim = idim;
            break;
        } else if (-1 - perm[idim] == axis) {
            npy_intp *strides = (&(axisdata_del)->ad_flexdata + 0);
            npy_intp shape = ((axisdata_del)->shape), offset;
            xdim = idim;
            for (iop = 0; iop < nop; ++iop) {
                offset = (shape - 1) * strides[iop];
                baseoffsets[iop] += offset;
                resetdataptr[iop] += offset;
            }
            break;
        }
        axisdata_del = ((NpyIter_AxisData *)(((char *)(axisdata_del)) + (1) * sizeof_axisdata));
    }
    // Additional outer control to simulate increased nesting depth via dual pass logic
    if (xdim == -1) {
        for (idim = 0; idim < ndim; ++idim) {
            if (perm[idim] == axis || -1 - perm[idim] == axis) {
                xdim = idim;
                break;
            }
            axisdata_del = ((NpyIter_AxisData *)(((char *)(axisdata_del)) + (1) * sizeof_axisdata));
        }
    }
}
