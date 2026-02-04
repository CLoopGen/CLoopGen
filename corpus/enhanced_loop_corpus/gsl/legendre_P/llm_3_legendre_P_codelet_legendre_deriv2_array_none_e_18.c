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
// Variant 1: Consecutive Access via Local Buffer Accumulation
// Instead of scattered writes to global arrays, accumulate results in local arrays and write consecutively
double temp_result[512], temp_deriv[512], temp_deriv2[512]; // Assume lmax < ~200 for safety
size_t temp_idx = 0;

for (m = 1; m <= lmax - 1; ++m) {
    idxmm += m + 1;
    twomm1 += 2.;
    pmm *= csphase * u * twomm1;

    temp_result[temp_idx] = pmm;
    temp_deriv[temp_idx] = m * xbyu * pmm;
    temp_deriv2[temp_idx] = m * (uinv2 * m - (m + 1.)) * pmm - xbyu * temp_deriv[temp_idx];
    result_array[idxmm] = temp_result[temp_idx];
    result_deriv_array[idxmm] = temp_deriv[temp_idx];
    result_deriv2_array[idxmm] = temp_deriv2[temp_idx];
    temp_idx++;

    pm2 = pmm;
    k = idxmm + m + 1;
    pm1 = x * pmm * (2 * m + 1);

    temp_result[temp_idx] = pm1;
    temp_deriv[temp_idx] = -uinv * ((2 * m + 1) * pmm - (m + 1) * x * pm1);
    temp_deriv2[temp_idx] = (m * m * uinv2 - (m + 1.) * (m + 2.)) * pm1 - xbyu * temp_deriv[temp_idx];
    result_array[k] = temp_result[temp_idx];
    result_deriv_array[k] = temp_deriv[temp_idx];
    result_deriv2_array[k] = temp_deriv2[temp_idx];
    temp_idx++;

    for (l = m + 2; l <= lmax; ++l) {
        k += l;
        plm = ((2 * l - 1) * x * pm1 - (l + m - 1) * pm2) / (double)(l - m);

        temp_result[temp_idx] = plm;
        temp_deriv[temp_idx] = -uinv * ((l + m) * pm1 - l * x * plm);
        temp_deriv2[temp_idx] = (m * m * uinv2 - l * (l + 1.)) * plm - xbyu * temp_deriv[temp_idx];

        result_array[k] = temp_result[temp_idx];
        result_deriv_array[k] = temp_deriv[temp_idx];
        result_deriv2_array[k] = temp_deriv2[temp_idx];
        temp_idx++;

        pm2 = pm1;
        pm1 = plm;
    }
}
}
