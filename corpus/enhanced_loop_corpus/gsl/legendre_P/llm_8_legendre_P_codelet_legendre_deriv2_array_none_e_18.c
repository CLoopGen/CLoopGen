#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t lmax;
extern  double x;
extern  double csphase;
extern double result_array[];
extern double result_deriv_array[];
extern double result_deriv2_array[];
extern  double u;
extern  double uinv;
extern  double uinv2;
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
    size_t local_idxmm = idxmm + m + 1;
    double local_twomm1 = twomm1 + 2.;
    double local_pmm = prev_pmm * csphase * u * local_twomm1;
    result_array[local_idxmm] = local_pmm;
    result_deriv_array[local_idxmm] = m * xbyu * local_pmm;
    result_deriv2_array[local_idxmm] = m * (uinv2 * m - (m + 1.)) * result_array[local_idxmm] - xbyu * result_deriv_array[local_idxmm];
    double local_pm2 = local_pmm;
    size_t local_k = local_idxmm + m + 1;
    double local_pm1 = x * local_pmm * (2 * m + 1);
    result_array[local_k] = local_pm1;
    result_deriv_array[local_k] = -uinv * ((2 * m + 1) * local_pmm - (m + 1) * x * local_pm1);
    result_deriv2_array[local_k] = (m * m * uinv2 - (m + 1.) * (m + 2.)) * result_array[local_k] - xbyu * result_deriv_array[local_k];
    for (size_t local_l = m + 2; local_l <= lmax; ++local_l) {
        local_k += local_l;
        double local_plm = ((2 * local_l - 1) * x * local_pm1 - (local_l + m - 1) * local_pm2) / (double)(local_l - m);
        result_array[local_k] = local_plm;
        result_deriv_array[local_k] = -uinv * ((local_l + m) * local_pm1 - local_l * x * local_plm);
        result_deriv2_array[local_k] = (m * m * uinv2 - local_l * (local_l + 1.)) * result_array[local_k] - xbyu * result_deriv_array[local_k];
        local_pm2 = local_pm1;
        local_pm1 = local_plm;
    }
    idxmm = local_idxmm;
    twomm1 = local_twomm1;
    prev_pmm = local_pmm;
}
}
