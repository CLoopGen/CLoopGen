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

extern int idim;
extern int ndim;
extern npy_int8 *perm;
extern NpyIter_AxisData *axisdata;
extern npy_intp sizeof_axisdata;
extern npy_intp i;
extern npy_intp size;
extern NpyIter_AxisData *ad_i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idim = 0; idim < ndim; ++idim) {
    ad_i = ((NpyIter_AxisData *)(((char *)(axisdata)) + (idim) * sizeof_axisdata));
    npy_int8 pidim = perm[idim];
    npy_intp tmp;
    NpyIter_AxisData *ad_p, *ad_q;
    if (((ad_i)->index) == 1 && pidim != idim) {
        for (i = 0; i < size; ++i) {
            ad_q = ad_i;
            tmp = *((npy_intp *)ad_q + i);
            npy_int8 current = pidim;
            for (npy_intp step = 0; step < ndim && current != idim; ++step) {
                ad_p = ((NpyIter_AxisData *)(((char *)(axisdata)) + (current) * sizeof_axisdata));
                *((npy_intp *)ad_q + i) = *((npy_intp *)ad_p + i);
                ad_q = ad_p;
                current = perm[(int)current];
            }
            *((npy_intp *)ad_q + i) = tmp;
        }
        npy_int8 reset_idx = pidim;
        for (npy_intp step = 0; step < ndim && reset_idx != idim; ++step) {
            ((((NpyIter_AxisData *)(((char *)(axisdata)) + (reset_idx) * sizeof_axisdata)))->index) = 0;
            reset_idx = perm[(int)reset_idx];
        }
    }
    ((ad_i)->index) = 0;
}
}
