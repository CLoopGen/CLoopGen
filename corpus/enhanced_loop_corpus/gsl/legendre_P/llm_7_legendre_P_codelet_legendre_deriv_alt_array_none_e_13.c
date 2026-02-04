#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  double x;
extern  double csphase;
extern double result_array[];
extern double result_deriv_array[];
extern  double u;
extern  double uinv;
extern  double xbyu;
extern size_t l;
extern size_t m;
extern size_t k;
extern size_t idxmm;
extern double plm;
extern double pmm;
extern double pm1;
extern double pm2;
extern double twomm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_pmm = pmm;
for (m = 1; m <= lmax - 1; ++m) {
    idxmm += m + 1;
    twomm1 += 2.;
    pmm = prev_pmm * csphase * u * twomm1;
    result_array[idxmm] = pmm;
    result_deriv_array[idxmm] = m * xbyu * pmm;
    double local_pm2 = prev_pmm;
    double local_pm1 = x * pmm * (2 * m + 1);
    size_t local_k = idxmm + m + 1;
    result_array[local_k] = local_pm1;
    result_deriv_array[local_k] = -uinv * ((2 * m + 1) * pmm - (m + 1) * x * local_pm1);
    for (l = m + 2; l <= lmax; ++l) {
        local_k += l;
        double plm_new = ((2 * l - 1) * x * local_pm1 - (l + m - 1) * local_pm2) / (double)(l - m);
        result_array[local_k] = plm_new;
        result_deriv_array[local_k] = -uinv * ((l + m) * local_pm1 - l * x * plm_new);
        local_pm2 = local_pm1;
        local_pm1 = plm_new;
    }
    prev_pmm = pmm;
}
}
