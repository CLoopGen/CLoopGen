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
for (m = 1; m <= lmax - 1; ++m) {
    idxmm += m + 1;
    twomm1 += 2.;
    pmm *= csphase * u * twomm1;

    // Introduce early termination condition based on magnitude threshold
    if (pmm < 1e-10 && m > 5) {
        continue;
    }

    result_array[idxmm] = pmm;
    result_deriv_array[idxmm] = m * xbyu * pmm;
    result_deriv2_array[idxmm] = m * (uinv2 * m - (m + 1.)) * result_array[idxmm] - xbyu * result_deriv_array[idxmm];
    pm2 = pmm;
    k = idxmm + m + 1;
    pm1 = x * pmm * (2 * m + 1);

    if (pm1 > -1e10 && pm1 < 1e10) {
        result_array[k] = pm1;
        result_deriv_array[k] = -uinv * ((2 * m + 1) * pmm - (m + 1) * x * pm1);
        result_deriv2_array[k] = (m * m * uinv2 - (m + 1.) * (m + 2.)) * result_array[k] - xbyu * result_deriv_array[k];
    } else {
        result_array[k] = 0.0;
        result_deriv_array[k] = 0.0;
        result_deriv2_array[k] = 0.0;
    }

    for (l = m + 2; l <= lmax; ++l) {
        k += l;
        plm = ((2 * l - 1) * x * pm1 - (l + m - 1) * pm2) / (double)(l - m);

        // Skip update if value is diverging numerically
        if (plm != plm || plm > 1e30 || plm < -1e30) {
            result_array[k] = 0.0;
            result_deriv_array[k] = 0.0;
            result_deriv2_array[k] = 0.0;
            pm2 = pm1;
            pm1 = 0.0;
        } else {
            result_array[k] = plm;
            result_deriv_array[k] = -uinv * ((l + m) * pm1 - l * x * plm);
            result_deriv2_array[k] = (m * m * uinv2 - l * (l + 1.)) * result_array[k] - xbyu * result_deriv_array[k];
            pm2 = pm1;
            pm1 = plm;
        }
    }
}
}
