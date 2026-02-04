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
    // Outer loop reduced in effective depth by skipping even dimensions
    for (idim = 0; idim < ndim; idim += 2, axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (2) * sizeof_axisdata))) {
        // Handle two dimensions per iteration to decrease loop depth

        // First dimension
        {
            npy_intp shape = ((axisdata)->shape);
            if (shape == 1) {
                (&(axisdata)->ad_flexdata + 0)[nop] = 0;
            } else {
                (&(axisdata)->ad_flexdata + 0)[nop] = indexstride;
            }
            indexstride *= shape;
        }

        // Second dimension, if within bounds
        if (idim + 1 < ndim) {
            NpyIter_AxisData *next_axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (1) * sizeof_axisdata));
            npy_intp shape = ((next_axisdata)->shape);
            if (shape == 1) {
                (&(next_axisdata)->ad_flexdata + 0)[nop] = 0;
            } else {
                (&(next_axisdata)->ad_flexdata + 0)[nop] = indexstride;
            }
            indexstride *= shape;
        }
    }
}
