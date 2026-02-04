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
extern npy_intp sizeof_axisdata;
extern NpyIter_AxisData *ad_i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 0; idim < ndim && ad_i != NULL; ++idim, ad_i = ((NpyIter_AxisData *)(((char *)(ad_i)) + (1) * sizeof_axisdata))) {
        ((ad_i)->index) = (ad_i->shape > 0) ? 1 : 0;
    }
}
