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
extern int d;
extern gsl_integration_cquad_ival *iv;
extern double nc;
extern double ncdiff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (d >= 1 && d < 4) {
        int idx_prev = idx[d - 1];
        int idx_curr = idx[d];
        double ncdiff_accum = ncdiff;
        double nc_accum = nc;
        for (i = 0; i <= n[d - 1]; i++) {
            double diff = iv->c[idx_prev + i] - iv->c[idx_curr + i];
            nc_accum += iv->c[idx_curr + i] * iv->c[idx_curr + i];
            ncdiff_accum += diff * diff;
        }
        ncdiff = ncdiff_accum;
        nc = nc_accum;
    }
}
