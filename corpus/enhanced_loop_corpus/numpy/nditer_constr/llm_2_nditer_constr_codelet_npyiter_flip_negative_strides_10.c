#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_uint8;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

struct NpyIter_InternalOnly {
    int itflags;
    npy_uint8 ndim;
    int nop;
    int maskop;
    npy_intp itersize;
    npy_intp iterstart;
    npy_intp iterend;
    npy_intp iterindex;
    char iter_flexdata[];
};


typedef struct NpyIter_InternalOnly NpyIter;

typedef intptr_t Py_intptr_t;

struct NpyIter_AxisData_tag {
    npy_intp shape;
    npy_intp index;
    Py_intptr_t ad_flexdata;
};


typedef struct NpyIter_AxisData_tag NpyIter_AxisData;

typedef signed char npy_int8;

extern NpyIter *iter;
extern int idim;
extern int ndim;
extern int iop;
extern int nop;
extern npy_intp istrides;
extern npy_intp nstrides;
extern NpyIter_AxisData *axisdata;
extern npy_intp *baseoffsets;
extern npy_intp sizeof_axisdata;
extern int any_flipped;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 0; idim < ndim; ++idim, axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata))) {
        npy_intp *strides = (&(axisdata)->ad_flexdata + 0);
        int any_negative = 0;
        npy_intp consecutive_stride = strides[0];
        for (iop = 1; iop < nop; ++iop) {
            if (strides[iop] != consecutive_stride) {
                any_negative = 1;
                break;
            }
        }
        if (!any_negative && nop > 0) {
            for (istrides = 0; istrides < nstrides; ++istrides) {
                baseoffsets[istrides] += (axisdata)->shape * strides[istrides];
            }
            ((npy_int8 *)(iter->iter_flexdata + (0)))[idim] = 2;
            any_flipped = 1;
        }
    }
}
