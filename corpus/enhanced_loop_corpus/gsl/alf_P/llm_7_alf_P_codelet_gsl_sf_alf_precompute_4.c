#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  size_t mmax;
extern double *alm;
extern double *sqrts;
extern size_t l;
extern size_t m;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_k = k;
    for (m = 0; m <= mmax; ++m) {
        size_t m_flag = (m > 0) ? 2 : 0;
        local_k += m_flag;
        for (l = m + 2; l <= lmax; ++l) {
            size_t write_idx = 2 * local_k;
            double factor1 = sqrts[2 * l + 1] / sqrts[l + m];
            double factor2 = sqrts[2 * l - 1] / sqrts[l - m];
            alm[write_idx] = factor1 * factor2;
            double ratio1 = sqrts[l + m - 1] / sqrts[l + m];
            double ratio2 = sqrts[l - m - 1] / sqrts[l - m];
            double norm = sqrts[2 * l + 1] / sqrts[2 * l - 3];
            alm[write_idx + 1] = -ratio1 * ratio2 * norm;
            local_k++;
        }
    }
    k = local_k;
}
