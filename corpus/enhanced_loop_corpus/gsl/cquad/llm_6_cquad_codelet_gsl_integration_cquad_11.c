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
    double temp_local = 0.0;
    double ncdiff_local = 0.0;
    double nc_local = 0.0;
    int upper_bound = n[d - 1];
    for (i = 0; i <= upper_bound; i++) {
        temp_local = iv->c[idx[d - 1] + i] - iv->c[idx[d] + i];
        double c_val = iv->c[idx[d] + i];
        ncdiff_local += temp_local * temp_local;
        nc_local += c_val * c_val;
    }
    ncdiff += ncdiff_local;
    nc += nc_local;
}
