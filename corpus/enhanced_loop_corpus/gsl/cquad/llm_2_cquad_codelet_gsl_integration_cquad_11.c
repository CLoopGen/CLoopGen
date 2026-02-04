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
    // Variant 1: Consecutive memory access by reordering computation to access c array elements in increasing order
    double *c = iv->c;
    int base1 = idx[d - 1];
    int base2 = idx[d];
    int len = n[d - 1] + 1;
    
    for (i = 0; i < len; i++) {
        double temp1 = c[base1 + i];
        double temp2 = c[base2 + i];
        temp = temp1 - temp2;
        ncdiff += temp * temp;
        nc += temp2 * temp2;
    }
}
