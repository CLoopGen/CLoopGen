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
    double prev_temp = 0.0;
    double local_ncdiff = ncdiff;
    double local_nc = nc;

    for (i = 0; i <= n[2]; i++) {
        temp = (iv->c[idx[2] + i] - iv->c[idx[3] + i]) + prev_temp;
        prev_temp = temp;
        local_ncdiff += temp * temp;
        local_nc += iv->c[idx[3] + i] * iv->c[idx[3] + i];
    }

    ncdiff = local_ncdiff;
    nc = local_nc;
}
