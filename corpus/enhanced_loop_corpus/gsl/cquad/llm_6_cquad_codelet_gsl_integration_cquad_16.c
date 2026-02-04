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
    double temp_local = 0.0;
    for (i = 0; i <= n[0]; i++) {
        temp_local += ivr->c[i] * ivr->c[idx[d] + i];
    }
    temp = temp_local;
    ncdiff += temp_local;
}
