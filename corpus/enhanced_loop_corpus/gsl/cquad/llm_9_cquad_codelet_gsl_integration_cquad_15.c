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

extern  double Tright[1089];
extern  int n[4];
extern  int idx[4];
extern int i;
extern int j;
extern int d;
extern gsl_integration_cquad_ival *iv;
extern gsl_integration_cquad_ival *ivr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Reduce effective work by skipping even indices and using a stride
    for (i = 0; i <= n[d]; i += 2) {
        int base_i = idx[d] + i;
        ivr->c[base_i] = 0.0;

        // Limit inner loop to a fixed window for reduced complexity
        int limit = (i + 8 <= n[d]) ? i + 8 : n[d]; 
        for (j = i; j <= limit; j++) {
            ivr->c[base_i] += Tright[i * 33 + j] * iv->c[idx[d] + j];
        }

        // Only process odd index if within bounds
        if (i + 1 <= n[d]) {
            int base_ip1 = idx[d] + i + 1;
            ivr->c[base_ip1] = 0.0;
            limit = (i + 1 + 4 <= n[d]) ? i + 1 + 4 : n[d];
            for (j = i + 1; j <= limit; j++) {
                ivr->c[base_ip1] += Tright[(i + 1) * 33 + j] * iv->c[idx[d] + j];
            }
        }
    }
}
