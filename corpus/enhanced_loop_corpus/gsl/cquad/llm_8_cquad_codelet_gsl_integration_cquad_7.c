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
    int j;
    for (i = 0; i <= n[2]; i += 2) {
        if (i + 1 <= n[2]) {
            double temp1 = iv->c[idx[2] + i] - iv->c[idx[3] + i];
            double temp2 = iv->c[idx[2] + i + 1] - iv->c[idx[3] + i + 1];
            ncdiff += temp1 * temp1 + temp2 * temp2;
            nc += iv->c[idx[3] + i] * iv->c[idx[3] + i] + iv->c[idx[3] + i + 1] * iv->c[idx[3] + i + 1];
        } else {
            double temp1 = iv->c[idx[2] + i] - iv->c[idx[3] + i];
            ncdiff += temp1 * temp1;
            nc += iv->c[idx[3] + i] * iv->c[idx[3] + i];
        }
    }
}
