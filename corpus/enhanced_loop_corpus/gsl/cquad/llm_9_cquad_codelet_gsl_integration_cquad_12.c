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
    // Reduce effective trip count by processing every other index, but increase operations per iteration
    for (i = 0; i <= n[d]; i += 2) {
        double temp1 = 0.0, temp2 = 0.0;
        int idx_i1 = idx[d] + i;
        int idx_i2 = idx[d] + i + 1;
        int ni = n[d];

        if (i + 1 <= ni) {
            // Process two iterations of outer loop simultaneously
            for (j = i; j <= ni; j++) {
                temp1 += Tleft[i * 33 + j] * iv->c[idx_i1 + (j - i)];
                if (i + 1 <= j) {
                    temp2 += Tleft[(i+1) * 33 + j] * iv->c[idx_i2 + (j - i - 1)];
                }
            }
            ivl->c[idx_i1] = temp1;
            ivl->c[idx_i2] = temp2;
        } else {
            // Handle last odd iteration
            for (j = i; j <= ni; j++) {
                temp1 += Tleft[i * 33 + j] * iv->c[idx_i1 + (j - i)];
            }
            ivl->c[idx_i1] = temp1;
        }
    }
}
