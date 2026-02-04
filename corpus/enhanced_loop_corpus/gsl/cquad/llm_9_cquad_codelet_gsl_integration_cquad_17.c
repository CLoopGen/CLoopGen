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
extern gsl_integration_cquad_ival *ivr;
extern double ncdiff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum1 = 0.0, sum2 = 0.0;
    int start = n[0] + 1;
    int end = n[d];
    for (i = start; i <= end; i++) {
        double val = ivr->c[idx[d] + i];
        sum1 += val * val;
        sum2 += val;
    }
    ncdiff += sum1 + sum2;
}
