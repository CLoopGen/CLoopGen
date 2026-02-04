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
    for (i = 0; i <= n[d]; i++) {
        if (i % 2 == 0) {
            ivl->c[idx[d] + i] = 0.;
            for (j = i; j <= n[d]; j++)
                ivl->c[idx[d] + i] += Tleft[i * 33 + j] * iv->c[idx[d] + j];
        } else {
            ivl->c[idx[d] + i] = 0.;
        }
    }
}
