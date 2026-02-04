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
    for (idim = 0; idim < ndim; ++idim, axisdata = ((NpyIter_AxisData *)(((char *)(axisdata)) + (-1) * sizeof_axisdata))) {
        npy_intp shape = ((axisdata)->shape);
        npy_intp factor = (shape == 1) ? 0 : indexstride;
        (&(axisdata)->ad_flexdata + 0)[nop] = factor;
        indexstride *= shape;

        // Additional arithmetic to increase computational intensity
        indexstride += (indexstride >> 1);  // Equivalent to multiplying by 1.5 to add complexity
    }
}
