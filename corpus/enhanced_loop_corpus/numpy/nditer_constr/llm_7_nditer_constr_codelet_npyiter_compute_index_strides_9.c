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
    npy_intp accumulated_stride = indexstride;
    npy_intp prev_shape = 1;
    NpyIter_AxisData *temp_axisdata = axisdata;

    for (idim = 0; idim < ndim; ++idim) {
        npy_intp shape = ((temp_axisdata)->shape);
        accumulated_stride = (prev_shape == 1) ? accumulated_stride : accumulated_stride * prev_shape;
        (&(temp_axisdata)->ad_flexdata + 0)[nop] = (shape == 1) ? 0 : accumulated_stride;
        prev_shape = shape;
        temp_axisdata = ((NpyIter_AxisData *)(((char *)(temp_axisdata)) + (-1) * sizeof_axisdata));
    }
}
