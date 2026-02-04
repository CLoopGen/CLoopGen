#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double a;
    double b;
    double c[64];
    double fx[33];
    double igral;
    double err;
    int depth;
    int rdepth;
    int ndiv;
} gsl_integration_cquad_ival;

extern  double Tright[1089];
extern  int n[4];
extern  int idx[4];
extern int i;
extern int j;
extern int d;
extern gsl_integration_cquad_ival *iv;
extern gsl_integration_cquad_ival *ivr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i <= n[d]; i++) {
        double sum1 = 0.0, sum2 = 0.0;
        int base_idx = idx[d] + i;
        int trip_count = n[d] - i + 1;
        int j_start = i + (trip_count % 2); // Adjust start to allow dual accumulation

        // Unroll by 2 and use two accumulators to increase computational intensity
        for (j = i; j < j_start; j++) {
            sum1 += Tright[i * 33 + j] * iv->c[idx[d] + j];
        }
        for (j = j_start; j <= n[d]; j += 2) {
            if (j + 1 <= n[d]) {
                sum1 += Tright[i * 33 + j] * iv->c[idx[d] + j];
                sum2 += Tright[i * 33 + (j + 1)] * iv->c[idx[d] + (j + 1)];
            } else {
                sum1 += Tright[i * 33 + j] * iv->c[idx[d] + j];
            }
        }
        ivr->c[base_idx] = sum1 + sum2;
    }
}
