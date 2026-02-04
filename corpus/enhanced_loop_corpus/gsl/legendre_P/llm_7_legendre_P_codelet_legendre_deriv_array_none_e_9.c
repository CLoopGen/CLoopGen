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
    double new_pmm = prev_pmm * csphase * u * twomm1;
    result_array[idxmm] = new_pmm;
    result_deriv_array[idxmm] = m * xbyu * new_pmm;
    double local_pm2 = new_pmm;
    size_t base_k = idxmm + m + 1;
    double local_pm1 = x * new_pmm * (2 * m + 1);
    result_array[base_k] = local_pm1;
    result_deriv_array[base_k] = -uinv * ((2 * m + 1) * new_pmm - (m + 1) * x * local_pm1);
    for (l = m + 2; l <= lmax; ++l) {
        size_t current_k = base_k + l;
        double next_plm = ((2 * l - 1) * x * local_pm1 - (l + m - 1) * local_pm2) / (double)(l - m);
        result_array[current_k] = next_plm;
        result_deriv_array[current_k] = -uinv * ((l + m) * local_pm1 - l * x * next_plm);
        local_pm2 = local_pm1;
        local_pm1 = next_plm;
    }
    prev_pmm = new_pmm;
}
}
