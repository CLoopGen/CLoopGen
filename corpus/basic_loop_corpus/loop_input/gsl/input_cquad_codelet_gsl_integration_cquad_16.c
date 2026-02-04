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
gsl_integration_cquad_ival *ivr;
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

    d = 0;
    temp = 0.0;
    ncdiff = 0.0;

    ivr = (gsl_integration_cquad_ival*)malloc(sizeof(gsl_integration_cquad_ival));
    if (!ivr) exit(1);

    ivr->a = 1.0;
    ivr->b = 2.0;
    ivr->igral = 0.0;
    ivr->err = 0.0;
    ivr->depth = 0;
    ivr->rdepth = 0;
    ivr->ndiv = 0;

    for (int j = 0; j < 64; j++) {
        ivr->c[j] = (double)(j + 1);
        if (j < 33) {
            ivr->fx[j] = (double)(j + 0.5);
        }
    }
}