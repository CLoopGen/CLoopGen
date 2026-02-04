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
// Variant 2: Strided Memory Access with Fixed Step
// Rewrite array accesses using a fixed stride pattern for better prefetching or cache alignment simulation
// Use a base pointer and constant stride (e.g., every 4th element) to simulate strided access

const size_t stride = 4;
size_t base_idx = 0;

for (m = 1; m <= lmax - 1; ++m) {
    idxmm += m + 1;
    twomm1 += 2.;
    pmm *= csphase * u * twomm1;

    base_idx = idxmm * stride;
    result_array[base_idx] = pmm;
    result_deriv_array[base_idx] = m * xbyu * pmm;
    result_deriv2_array[base_idx] = m * (uinv2 * m - (m + 1.)) * result_array[base_idx] - xbyu * result_deriv_array[base_idx];

    pm2 = pmm;
    k = idxmm + m + 1;
    pm1 = x * pmm * (2 * m + 1);

    base_idx = k * stride;
    result_array[base_idx] = pm1;
    result_deriv_array[base_idx] = -uinv * ((2 * m + 1) * pmm - (m + 1) * x * pm1);
    result_deriv2_array[base_idx] = (m * m * uinv2 - (m + 1.) * (m + 2.)) * result_array[base_idx] - xbyu * result_deriv_array[base_idx];

    for (l = m + 2; l <= lmax; ++l) {
        k += l;
        plm = ((2 * l - 1) * x * pm1 - (l + m - 1) * pm2) / (double)(l - m);

        base_idx = k * stride;
        result_array[base_idx] = plm;
        result_deriv_array[base_idx] = -uinv * ((l + m) * pm1 - l * x * plm);
        result_deriv2_array[base_idx] = (m * m * uinv2 - l * (l + 1.)) * result_array[base_idx] - xbyu * result_deriv_array[base_idx];

        pm2 = pm1;
        pm1 = plm;
    }
}
}
