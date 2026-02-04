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
if (n[0] >= 0) {
    for (i = 0; i <= n[0]; i += 2) {
        temp = ivr->c[i] - ivr->c[idx[d] + i];
        ncdiff += temp * temp;
        if (i + 1 <= n[0]) {
            temp = ivr->c[i + 1] - ivr->c[idx[d] + i + 1];
            ncdiff += temp * temp;
        }
    }
}
}
