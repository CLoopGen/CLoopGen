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
    if (d <= 0 || d >= 4) return;
    for (i = 0; i <= n[d - 1]; i++) {
        double diff = iv->c[idx[d - 1] + i] - iv->c[idx[d] + i];
        ncdiff += diff * diff;
        nc += iv->c[idx[d] + i] * iv->c[idx[d] + i];
    }
}
