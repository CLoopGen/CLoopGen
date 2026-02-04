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
    int idim1, idim2;
    for (idim1 = 0; idim1 < ndim; ++idim1) {
        ad_i = ((NpyIter_AxisData *)(((char *)(axisdata)) + (idim1) * sizeof_axisdata));
        if (((ad_i)->index) == 1) {
            npy_int8 pidim = perm[idim1];
            npy_intp tmp;
            NpyIter_AxisData *ad_p, *ad_q;
            if (pidim != idim1) {
                for (i = 0; i < size; ++i) {
                    pidim = perm[idim1];
                    ad_q = ad_i;
                    tmp = *((npy_intp *)ad_q + i);
                    for (idim2 = 0; idim2 < ndim; ++idim2) {
                        if (pidim == idim1) break;
                        ad_p = ((NpyIter_AxisData *)(((char *)(axisdata)) + (pidim) * sizeof_axisdata));
                        *((npy_intp *)ad_q + i) = *((npy_intp *)ad_p + i);
                        ad_q = ad_p;
                        pidim = perm[(int)pidim];
                    }
                    *((npy_intp *)ad_q + i) = tmp;
                }
                pidim = perm[idim1];
                for (idim2 = 0; idim2 < ndim; ++idim2) {
                    if (pidim == idim1) break;
                    ((((NpyIter_AxisData *)(((char *)(axisdata)) + (pidim) * sizeof_axisdata)))->index) = 0;
                    pidim = perm[(int)pidim];
                }
            }
            ((ad_i)->index) = 0;
        }
    }
}
