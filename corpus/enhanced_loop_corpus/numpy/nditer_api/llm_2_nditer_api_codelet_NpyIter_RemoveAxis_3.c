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



void loop() {
    for (idim = 0; idim < ndim; ++idim) {
        npy_int8 perm_val = perm[idim]; // Cache permuted value for reuse
        if (perm_val == axis) {
            xdim = idim;
            break;
        } else if (-1 - perm_val == axis) {
            // Use a strided access pattern: process every 2nd element in strides
            npy_intp *strides = &(axisdata_del->ad_flexdata);
            npy_intp shape = axisdata_del->shape;
            npy_intp offset;
            xdim = idim;

            // Strided memory access: only even indices of operands
            for (iop = 0; iop < nop; iop += 2) {
                offset = (shape - 1) * strides[iop];
                baseoffsets[iop] += offset;
                resetdataptr[iop] += offset;
                // Handle odd index if exists
                if (iop + 1 < nop) {
                    offset = (shape - 1) * strides[iop + 1];
                    baseoffsets[iop + 1] += offset;
                    resetdataptr[iop + 1] += offset;
                }
            }
            break;
        }
        axisdata_del = (NpyIter_AxisData *)(((char *)axisdata_del) + sizeof_axisdata);
    }
}
