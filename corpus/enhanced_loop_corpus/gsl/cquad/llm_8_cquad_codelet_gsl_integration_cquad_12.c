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

extern  double Tleft[1089];
extern  int n[4];
extern  int idx[4];
extern int i;
extern int j;
extern int d;
extern gsl_integration_cquad_ival *iv;
extern gsl_integration_cquad_ival *ivl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= n[d]; i++) {
        double sum1 = 0.0, sum2 = 0.0;
        int limit = n[d] + 1;
        // Unroll loop by 2 to increase computational intensity
        for (j = i; j + 1 < limit; j += 2) {
            sum1 += Tleft[i * 33 + j] * iv->c[idx[d] + j];
            sum2 += Tleft[i * 33 + j + 1] * iv->c[idx[d] + j + 1];
        }
        // Handle remaining element if any
        if (j < limit) {
            sum1 += Tleft[i * 33 + j] * iv->c[idx[d] + j];
        }
        ivl->c[idx[d] + i] = sum1 + sum2;
    }
}
