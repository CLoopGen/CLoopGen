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
    npy_intp *shape_ptr = &axisdata->shape;
    npy_intp *flexdata_ptr = &(axisdata)->ad_flexdata + nop;
    for (idim = 0; idim < ndim; ++idim, 
         shape_ptr = (npy_intp*)(((char*)shape_ptr) + sizeof_axisdata),
         flexdata_ptr = (npy_intp*)(((char*)flexdata_ptr) + sizeof_axisdata)) {
        npy_intp shape = *shape_ptr;
        if (shape == 1) {
            *flexdata_ptr = 0;
        } else {
            *flexdata_ptr = indexstride;
        }
        indexstride *= shape;
    }
}
