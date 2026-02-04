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
    for (i = n[d - 1] + 1; i <= n[d]; i++) {
        if (idx[d] + i >= 0) {
            temp = iv->c[idx[d] + i];
            nc += temp * temp;
        }
    }
}
