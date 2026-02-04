#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t size;
    size_t i;
    size_t terms_used;
    double sum_plain;
    double *q_num;
    double *q_den;
    double *dsum;
} gsl_sum_levin_utrunc_workspace;

extern  size_t n;
extern gsl_sum_levin_utrunc_workspace *w;
extern double factor;
extern double ratio;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // This variant accesses elements in reverse order but with a stride of 2,
    // processing two iterations per loop step to modify access pattern.
    double *q_den = w->q_den;
    double *q_num = w->q_num;
    double f = factor;
    size_t j;

    // Handle odd n to ensure we start at valid index
    size_t start = (n % 2 == 1) ? n - 1 : n - 2;

    for (j = start; j >= 1; j -= 2) {
        double c1 = f * (j + 1) / (n + 1);
        double c2 = f * (j)     / (n + 1);
        double next_f1 = f * ratio;
        double next_f2 = next_f1 * ratio;

        q_den[j] = q_den[j + 1] - c1 * q_den[j];
        q_num[j] = q_num[j + 1] - c1 * q_num[j];

        q_den[j-1] = q_den[j] - c2 * q_den[j-1];
        q_num[j-1] = q_num[j] - c2 * q_num[j-1];

        f = next_f2;
    }

    // Handle leftover element at j=0 if needed
    if (n > 0 && (n % 2 == 1)) {
        double c0 = f * (0 + 1) / (n + 1);
        q_den[0] = q_den[1] - c0 * q_den[0];
        q_num[0] = q_num[1] - c0 * q_num[0];
    }
}
