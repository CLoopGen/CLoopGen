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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base pointer arithmetic
    double *base_c = iv->c + idx[3] + n[2] + 1;
    int count = n[3] - n[2];
    for (i = 0; i < count; i++) {
        temp = base_c[i];
        nc += temp * temp;
    }
}
