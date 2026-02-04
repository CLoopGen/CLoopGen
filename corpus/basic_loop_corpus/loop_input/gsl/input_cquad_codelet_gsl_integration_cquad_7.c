#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <stdint.h>

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
gsl_integration_cquad_ival *iv;
double nc;
double ncdiff;

void init_vars() {
    n[0] = 10;
    n[1] = 20;
    n[2] = 62; // Ensures i goes from 0 to 62 inclusive -> max index used: idx[x] + 62
    n[3] = 30;

    idx[0] = 0;
    idx[1] = 0;
    idx[2] = 0;
    idx[3] = 1; // So that idx[3] + i <= 1 + 62 = 63, but c has size 64 -> valid

    iv = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));
    if (!iv) exit(1);

    for (int j = 0; j < 64; j++) {
        iv->c[j] = j + 1.5;
    }

    temp = 0.0;
    nc = 0.0;
    ncdiff = 0.0;
    i = 0;
}