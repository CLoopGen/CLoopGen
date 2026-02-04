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
// Variant with reduced computational intensity: unroll inner loop by factor of 2 and reduce arithmetic operations
for (m = 1; m <= lmax - 1; m += 2) {
    // Update index and recurrence term
    idxmm += m + 1;
    twomm1 += 2.;
    pmm *= csphase * u * twomm1;

    // Store value and derivative at current m
    result_array[idxmm] = pmm;
    result_deriv_array[idxmm] = m * xbyu * pmm;

    pm2 = pmm;
    k = idxmm + m + 1;
    pm1 = x * pmm * (2 * m + 1);

    result_array[k] = pm1;
    result_deriv_array[k] = -uinv * ((2 * m + 1) * pmm - (m + 1) * x * pm1);

    // Partially unrolled inner loop: process two iterations at once if possible
    for (l = m + 2; l <= lmax; l += 2) {
        size_t k1 = k + l;
        double plm1 = ((2 * l - 1) * x * pm1 - (l + m - 1) * pm2) / (double)(l - m);
        result_array[k1] = plm1;
        result_deriv_array[k1] = -uinv * ((l + m) * pm1 - l * x * plm1);

        double pm2_next = pm1;
        double pm1_next = plm1;

        if (l + 1 >= lmax) {
            pm2 = pm1_next;
            pm1 = plm1;
            k = k1;
            break;
        }

        size_t k2 = k1 + l + 1;
        double plm2 = ((2 * (l + 1) - 1) * x * pm1_next - (l + 1 + m - 1) * pm2_next) / (double)(l + 1 - m);
        result_array[k2] = plm2;
        result_deriv_array[k2] = -uinv * ((l + 1 + m) * pm1_next - (l + 1) * x * plm2);

        // Update for next outer step
        pm2 = pm1_next;
        pm1 = plm2;
        k = k2;
    }
}
}
