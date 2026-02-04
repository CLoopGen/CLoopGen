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



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to access Tright and iv->c in a cache-friendly, sequential manner
    double *c_base = &(ivr->c[idx[d]]);
    double *iv_c_base = &(iv->c[idx[d]]);
    double temp;

    for (i = 0; i <= n[d]; i++) {
        temp = 0.;
        int base_idx = i * 33;
        for (j = i; j <= n[d]; j++) {
            temp += Tright[base_idx + j] * iv_c_base[j];
        }
        c_base[i] = temp;
    }
}
