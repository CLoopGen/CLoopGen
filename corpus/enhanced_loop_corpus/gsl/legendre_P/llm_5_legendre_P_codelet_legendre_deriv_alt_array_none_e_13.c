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
for (m = 1; m <= lmax - 1; ++m) {
    if (m % 2 == 0) {
        idxmm += m + 1;
        twomm1 += 2.;
        pmm *= csphase * u * twomm1;
        result_array[idxmm] = pmm;
        result_deriv_array[idxmm] = m * xbyu * pmm;
        pm2 = pmm;
        k = idxmm + m + 1;
        pm1 = x * pmm * (2 * m + 1);
        result_array[k] = pm1;
        result_deriv_array[k] = -uinv * ((2 * m + 1) * pmm - (m + 1) * x * pm1);
        for (l = m + 2; l <= lmax; ++l) {
            k += l;
            plm = ((2 * l - 1) * x * pm1 - (l + m - 1) * pm2) / (double)(l - m);
            result_array[k] = plm;
            result_deriv_array[k] = -uinv * ((l + m) * pm1 - l * x * plm);
            pm2 = pm1;
            pm1 = plm;
        }
    } else {
        idxmm += m + 1;
        twomm1 += 2.;
        pmm *= csphase * u * twomm1;
        result_array[idxmm] = pmm;
        result_deriv_array[idxmm] = 0.0;
        pm2 = pmm;
        k = idxmm + m + 1;
        pm1 = x * pmm * (2 * m + 1);
        result_array[k] = pm1;
        result_deriv_array[k] = -uinv * (2 * m + 1) * pmm;
        for (l = m + 2; l <= lmax; ++l) {
            k += l;
            plm = ((2 * l - 1) * x * pm1 - (l + m - 1) * pm2) / (double)(l - m);
            result_array[k] = plm;
            if (l < lmax - 5) {
                result_deriv_array[k] = -uinv * ((l + m) * pm1 - l * x * plm);
            } else {
                result_deriv_array[k] = 0.5 * -uinv * ((l + m) * pm1 - l * x * plm);
            }
            pm2 = pm1;
            pm1 = plm;
        }
    }
}
}
