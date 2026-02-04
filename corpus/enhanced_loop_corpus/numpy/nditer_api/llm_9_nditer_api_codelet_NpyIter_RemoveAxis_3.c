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
// Reduce effective trip count by stepping through half as many dimensions, but process each more intensively
int step = 2;
for (idim = 0; idim < ndim; idim += step) {
    // Check two dimensions per iteration if possible
    int processed = 0;
    for (int j = 0; j < step && !processed; ++j) {
        int curr_idim = idim + j;
        if (curr_idim >= ndim) break;

        if (perm[curr_idim] == axis) {
            xdim = curr_idim;
            processed = 1;
        } else if (-1 - perm[curr_idim] == axis) {
            npy_intp *strides = (&(axisdata_del)->ad_flexdata + 0);
            npy_intp shape = ((axisdata_del)->shape), offset;
            xdim = curr_idim;
            // Duplicate the inner loop to increase computation per match
            for (iop = 0; iop < nop; ++iop) {
                offset = (shape - 1) * strides[iop];
                baseoffsets[iop] += offset;
                resetdataptr[iop] += offset;
            }
            // Repeat operation to simulate heavier computation
            for (iop = 0; iop < nop; ++iop) {
                offset = (shape - 1) * strides[iop] / 2;
                baseoffsets[iop] += offset;
            }
            processed = 1;
        }
        // Advance axisdata_del even if not used
        axisdata_del = ((NpyIter_AxisData *)(((char *)(axisdata_del)) + (1) * sizeof_axisdata));
    }
    if (processed) break;
}
}
