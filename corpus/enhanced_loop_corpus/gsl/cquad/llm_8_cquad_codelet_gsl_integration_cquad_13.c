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
extern gsl_integration_cquad_ival *ivl;
extern double ncdiff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    ncdiff = 0.0;
    for (i = 0; i <= n[0]; i += 2) {
        double diff1 = ivl->c[i] - ivl->c[idx[d] + i];
        ncdiff += diff1 * diff1;
        if (i + 1 <= n[0]) {
            double diff2 = ivl->c[i+1] - ivl->c[idx[d] + i+1];
            ncdiff += diff2 * diff2;
        }
    }
}
