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
    // Set d to valid index in [0,3]
    d = 2;

    // Ensure n[0]+1 <= n[d], set meaningful range
    n[0] = 0;
    n[1] = 1000;
    n[2] = 200000;  // ~16MB of data accessed: 200k iterations * 64*sizeof(double) ~ 100MB virtual access pattern
    n[3] = 3000;

    // idx[d] + i must be within [0,63] for ivr->c[idx[d]+i]
    idx[2] = 0;  // so index i from 1 to n[2] will access c[1..200000] -> but we must bound by 63

    // Adjust loop bounds to not exceed array size
    n[2] = 60;  // now i goes from 1 to 60, idx[2]=0 => accesses c[1] to c[60], safe within c[64]

    // Allocate and initialize ivr
    ivr = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));
    if (!ivr) exit(1);

    // Initialize c array to avoid NaNs or extreme values affecting performance
    for (int j = 0; j < 64; j++) {
        ivr->c[j] = (double)(j + 1) * 0.1;
    }

    // Initialize other fields to sane values
    ivr->a = 1.0;
    ivr->b = 2.0;
    for (int j = 0; j < 33; j++) ivr->fx[j] = 0.5;
    ivr->igral = 0.0;
    ivr->err = 0.0;
    ivr->depth = 1;
    ivr->rdepth = 1;
    ivr->ndiv = 1;

    // Initialize scalars
    temp = 0.0;
    ncdiff = 0.0;
    i = 0;
}