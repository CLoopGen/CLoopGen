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
gsl_integration_cquad_ival *iv;
double nc;

void init_vars() {
    // Set d to a valid index (1, 2, or 3) so that d-1 is in bounds
    d = 2;

    // Set reasonable bounds for the loop: n[d-1] and n[d]
    n[1] = 0;
    n[2] = 1000000;  // ~1M iterations to target ~0.01 sec runtime
    n[0] = 0;
    n[3] = 0;

    // Ensure idx[d] + i access stays within iv->c bounds [64]
    // So idx[2] must be <= 63 - max(i), where i goes up to n[2] - n[1] = 1000000
    // But we cannot safely index iv->c with such large offset.
    // Therefore, we reinterpret: likely idx[d] is an offset into a larger array?
    // But iv->c is fixed size 64. So the only safe assumption is that idx[d] is small
    // and i runs over small range. Adjust problem accordingly.

    // Let's re-scale: make n[2] small enough so that idx[d] + i < 64
    n[2] = 50;  // now i from n[1]+1=1 to 50 -> 50 iterations

    // Then set idx[2] to base offset, say 10, so indices 11..60 -> cap at 60
    idx[0] = 0;
    idx[1] = 0;
    idx[2] = 10;
    idx[3] = 0;

    // Allocate iv
    iv = (gsl_integration_cquad_ival*)malloc(sizeof(gsl_integration_cquad_ival));
    if (!iv) exit(1);

    // Initialize c array to avoid NaNs, etc.
    for (int j = 0; j < 64; j++) {
        iv->c[j] = (double)(j + 1);
    }

    // Initialize other fields to plausible values
    iv->a = 1.0;
    iv->b = 2.0;
    for (int j = 0; j < 33; j++) iv->fx[j] = 0.0;
    iv->igral = 0.0;
    iv->err = 0.0;
    iv->depth = 0;
    iv->rdepth = 0;
    iv->ndiv = 0;

    // Initialize temp and nc
    temp = 0.0;
    nc = 0.0;
}