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
    double temp_val;
    int j = idx[2];
    int k = idx[3];
    double *c_ptr = iv->c;
    double sum_ncdiff = 0.0;
    double sum_nc = 0.0;

    for (i = 0; i <= n[2]; i++) {
        temp_val = c_ptr[j + i] - c_ptr[k + i];
        sum_ncdiff += temp_val * temp_val;
        sum_nc += c_ptr[k + i] * c_ptr[k + i];
    }

    ncdiff += sum_ncdiff;
    nc += sum_nc;
}
