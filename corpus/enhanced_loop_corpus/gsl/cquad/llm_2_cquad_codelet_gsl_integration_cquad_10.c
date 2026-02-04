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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing c in increasing order with stride 1
    int start = idx[d] + n[d - 1] + 1;
    int end = idx[d] + n[d];
    for (int j = start; j <= end; j++) {
        temp = iv->c[j];
        nc += temp * temp;
    }
}
