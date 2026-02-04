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

double Tright[1089]; // 33*33 = 1089
int n[4] = {30, 30, 30, 30}; // ensures j <= 30, within bounds of idx[d]+j <= 63 (since c has size 64)
int idx[4] = {0, 16, 32, 48}; // chosen so that idx[d] + n[d] <= 63 for each d
int i;
int j;
int d = 1; // choose d such that n[d]=30 and idx[d]=16 -> access c[16..46], valid in [0..63]
gsl_integration_cquad_ival *iv;
gsl_integration_cquad_ival *ivr;

void init_vars() {
    // Allocate memory for iv and ivr
    iv = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));
    ivr = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));

    // Initialize Tright with non-zero values to simulate realistic data
    for (int k = 0; k < 1089; k++) {
        Tright[k] = (double)(k % 100) / 100.0;
    }

    // Initialize iv->c with non-zero values
    for (int k = 0; k < 64; k++) {
        iv->c[k] = (double)(k % 50) / 10.0;
    }
}