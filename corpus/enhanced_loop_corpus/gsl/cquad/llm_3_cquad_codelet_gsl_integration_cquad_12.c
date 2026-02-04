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

extern  double Tleft[1089];
extern  int n[4];
extern  int idx[4];
extern int i;
extern int j;
extern int d;
extern gsl_integration_cquad_ival *iv;
extern gsl_integration_cquad_ival *ivl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (strided) access using pointer arithmetic with precomputed strides and indirect indexing
    double *c_dest = &(ivl->c[idx[d]]);
    double *c_src = &(iv->c[idx[d]]);
    int n_d = n[d];
    for (i = 0; i <= n_d; i++) {
        double sum = 0.0;
        const double *T_ptr = &Tleft[i * 33 + i];
        const double *c_ptr = &c_src[i];
        int length = n_d - i + 1;
        for (j = 0; j < length; j++) {
            sum += T_ptr[j] * c_ptr[j];
        }
        c_dest[i] = sum;
    }
}
