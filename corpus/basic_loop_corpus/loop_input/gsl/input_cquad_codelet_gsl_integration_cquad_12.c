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

double Tleft[1089];
int n[4];
int idx[4];
int i;
int j;
int d;
gsl_integration_cquad_ival *iv;
gsl_integration_cquad_ival *ivl;

void init_vars() {
    // Set data size parameters to achieve ~0.01s runtime
    // Inner loop: roughly (n[d]+1)*(n[d]+1)/2 operations per outer loop
    // We want around 10-20 million operations for ~0.01s on modern CPU
    // Choose n[d] ~ 512 gives about 130k iterations, each with ~256 avg inner steps -> ~33M ops
    
    n[0] = 512;
    n[1] = 256;
    n[2] = 128;
    n[3] = 64;
    
    // Ensure index calculations stay within bounds: idx[d] + n[d] < 64
    // So set idx[d] such that idx[d] + n[d] <= 63
    // For d=0: idx[0] <= 63 - 512 -> invalid, so we must scale down problem
    // Need to reduce n[d] so that idx[d] + n[d] < 64
    // Maximum allowed n[d] is 63 if idx[d]=0. Let's use smaller arrays.
    
    // Revised: use smaller working set within c[64]
    n[0] = 32;
    n[1] = 31;
    n[2] = 30;
    n[3] = 29;
    
    idx[0] = 0;
    idx[1] = 10;
    idx[2] = 20;
    idx[3] = 30;
    
    // Validate: max access = idx[0] + n[0] = 0+32 = 32 < 64 -> safe
    //           idx[3] + n[3] = 30+29 = 59 < 64 -> safe
    
    d = 0; // default value used in loop
    
    // Allocate and initialize iv and ivl
    iv = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));
    ivl = (gsl_integration_cquad_ival*)calloc(1, sizeof(gsl_integration_cquad_ival));
    
    // Initialize Tleft: size 1089 = 33*33, matches j <= n[d] <= 32 and i*33+j indexing
    for (int k = 0; k < 1089; k++) {
        Tleft[k] = 1.0 / (1.0 + k % 34); // non-zero values
    }
    
    // Initialize input vector c in iv
    for (int k = 0; k < 64; k++) {
        iv->c[k] = (k % 7) * 0.1;
    }
}