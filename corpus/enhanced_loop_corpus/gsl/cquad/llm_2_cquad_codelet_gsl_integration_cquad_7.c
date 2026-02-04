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

extern  int n[4];
extern  int idx[4];
extern double temp;
extern int i;
extern gsl_integration_cquad_ival *iv;
extern double nc;
extern double ncdiff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern by reordering computations to access contiguous elements
    // Instead of strided access via idx[2]+i and idx[3]+i, we precompute base pointers for better spatial locality
    double *c_base_2 = &iv->c[idx[2]];
    double *c_base_3 = &iv->c[idx[3]];
    double sum_ncdiff = 0.0;
    double sum_nc = 0.0;

    for (i = 0; i <= n[2]; i++) {
        double t = c_base_2[i] - c_base_3[i];
        sum_ncdiff += t * t;
        sum_nc += c_base_3[i] * c_base_3[i];
    }
    ncdiff += sum_ncdiff;
    nc += sum_nc;
}
