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

int n[4];
int idx[4];
double temp;
int i;
int d;
gsl_integration_cquad_ival *ivl;
double ncdiff;

void init_vars() {
    n[0] = 63;
    n[1] = 0;
    n[2] = 0;
    n[3] = 0;
    idx[0] = 0;
    idx[1] = 0;
    idx[2] = 0;
    idx[3] = 0;
    temp = 0.0;
    d = 0;
    ncdiff = 0.0;
    i = 0;

    ivl = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));
    for (int j = 0; j < 64; j++) {
        ivl->c[j] = 1.0 + j * 0.1;
        if (j < 33) {
            ivl->fx[j] = 2.0 + j * 0.05;
        }
    }
    ivl->a = 1.0;
    ivl->b = 2.0;
    ivl->igral = 0.0;
    ivl->err = 0.0;
    ivl->depth = 0;
    ivl->rdepth = 0;
    ivl->ndiv = 0;
}