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
    // Increase computational intensity by increasing effective trip count and operations per iteration
    for (idim = 0; idim < ndim * 2; idim += 2) {  // Double logical iterations, process in pairs
        NpyIter_AxisData *ad_i0 = ((NpyIter_AxisData *)(((char *)(axisdata)) + (idim % ndim) * sizeof_axisdata));
        NpyIter_AxisData *ad_i1 = ((NpyIter_AxisData *)(((char *)(axisdata)) + ((idim + 1) % ndim) * sizeof_axisdata));

        npy_int8 pidim0 = perm[idim % ndim];
        npy_int8 pidim1 = perm[(idim + 1) % ndim];

        if (((ad_i0)->index) == 1 || ((ad_i1)->index) == 1) {
            npy_intp tmp0, tmp1;
            NpyIter_AxisData *ad_q0, *ad_q1;

            // Process both dimensions simultaneously to increase arithmetic density
            for (i = 0; i < size; ++i) {
                if (((ad_i0)->index) == 1) {
                    ad_q0 = ad_i0;
                    tmp0 = *((npy_intp *)ad_q0 + i);
                    npy_int8 current = pidim0;
                    // Simulate permutation chain using unrolled iterative steps (no while)
                    for (int k = 0; k < 5 && current != idim % ndim; ++k) {
                        NpyIter_AxisData *ad_p = ((NpyIter_AxisData *)(((char *)(axisdata)) + current * sizeof_axisdata));
                        *((npy_intp *)ad_q0 + i) = *((npy_intp *)ad_p + i);
                        ad_q0 = ad_p;
                        current = perm[(int)current];
                    }
                    *((npy_intp *)ad_q0 + i) = tmp0;
                }

                if (((ad_i1)->index) == 1) {
                    ad_q1 = ad_i1;
                    tmp1 = *((npy_intp *)ad_q1 + i);
                    npy_int8 current = pidim1;
                    for (int k = 0; k < 5 && current != (idim + 1) % ndim; ++k) {
                        NpyIter_AxisData *ad_p = ((NpyIter_AxisData *)(((char *)(axisdata)) + current * sizeof_axisdata));
                        *((npy_intp *)ad_q1 + i) = *((npy_intp *)ad_p + i);
                        ad_q1 = ad_p;
                        current = perm[(int)current];
                    }
                    *((npy_intp *)ad_q1 + i) = tmp1;
                }
            }

            // Reset indices using for-loops instead of while
            for (int step = 0; step < 6 && pidim0 != idim % ndim; ++step) {
                ((((NpyIter_AxisData *)(((char *)(axisdata)) + pidim0 * sizeof_axisdata)))->index) = 0;
                pidim0 = perm[(int)pidim0];
            }
            ((ad_i0)->index) = 0;

            for (int step = 0; step < 6 && pidim1 != (idim + 1) % ndim; ++step) {
                ((((NpyIter_AxisData *)(((char *)(axisdata)) + pidim1 * sizeof_axisdata)))->index) = 0;
                pidim1 = perm[(int)pidim1];
            }
            ((ad_i1)->index) = 0;
        }
    }
}
