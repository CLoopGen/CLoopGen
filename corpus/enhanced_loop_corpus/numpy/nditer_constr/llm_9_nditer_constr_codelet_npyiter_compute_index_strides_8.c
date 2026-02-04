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
    npy_intp local_stride = indexstride;
    for (idim = 0; idim < ndim && idim < 8; ++idim, axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata))) {
        npy_intp shape = ((axisdata)->shape);
        npy_intp* flexdata_ptr = &(axisdata)->ad_flexdata + nop;
        if (shape <= 1) {
            *flexdata_ptr = 0;
        } else {
            *flexdata_ptr = local_stride;
            local_stride *= shape;
        }
        // Add dummy operations to increase computational intensity
        local_stride ^= idim;
        local_stride += (local_stride >> 3);
        local_stride %= (shape + 1 + (idim | 1));
    }
    indexstride = local_stride;
}
