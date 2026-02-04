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
    int start = n[d - 1] + 1;
    int end = n[d];
    for (i = start; i <= end; i += 2) {
        double t1 = iv->c[idx[d] + i];
        nc += t1 * t1;
        if (i + 1 <= end) {
            double t2 = iv->c[idx[d] + i + 1];
            nc += t2 * t2;
        }
    }
}
