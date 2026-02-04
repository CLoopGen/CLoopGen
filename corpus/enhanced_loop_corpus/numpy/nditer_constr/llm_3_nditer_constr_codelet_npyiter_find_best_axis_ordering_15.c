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



void loop() {
    for (idim = 0; idim < ndim; ++idim) {
        ad_i = (NpyIter_AxisData *)(((char *)axisdata) + idim * sizeof_axisdata);
        if (ad_i->index == 1) {
            npy_int8 pidim = perm[idim];
            npy_intp tmp;
            NpyIter_AxisData *ad_p, *ad_q;

            if (pidim != idim) {
                // Change memory access pattern: precompute base pointers to enable consecutive-like access
                NpyIter_AxisData *base_ptrs[ndim];
                for (int d = 0; d < ndim; ++d) {
                    base_ptrs[d] = (NpyIter_AxisData *)(((char *)axisdata) + d * sizeof_axisdata);
                }

                for (i = 0; i < size; ++i) {
                    pidim = perm[idim];
                    ad_q = ad_i;
                    tmp = ((npy_intp *)ad_q)[i];

                    // Unroll and flatten the chain traversal with direct lookups via precomputed pointers
                    for (int iter = 0; iter < ndim; ++iter) {
                        if (pidim == idim) break;
                        ad_p = base_ptrs[pidim];
                        ((npy_intp *)ad_q)[i] = ((npy_intp *)ad_p)[i];
                        ad_q = ad_p;
                        pidim = perm[(int)pidim];
                    }
                    ((npy_intp *)ad_q)[i] = tmp;
                }

                // Reset indices using precomputed pointers and for-loop
                pidim = perm[idim];
                for (int iter = 0; iter < ndim; ++iter) {
                    if (pidim == idim) break;
                    base_ptrs[pidim]->index = 0;
                    pidim = perm[(int)pidim];
                }
            }
            ad_i->index = 0;
        }
    }
}
