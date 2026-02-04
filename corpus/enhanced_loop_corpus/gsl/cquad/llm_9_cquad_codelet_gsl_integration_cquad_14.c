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
double temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
int start = n[0] + 1;
int end = n[d];
int stride = 3;

for (i = start; i <= end; i += stride) {
    temp1 = ivl->c[idx[d] + i];
    ncdiff += temp1 * temp1;

    if (i + 1 <= end) {
        temp2 = ivl->c[idx[d] + i + 1];
        ncdiff += temp2 * temp2;
    }

    if (i + 2 <= end) {
        temp3 = ivl->c[idx[d] + i + 2];
        ncdiff += temp3 * temp3;
    }
}
}
