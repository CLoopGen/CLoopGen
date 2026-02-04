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



void loop(){
    double temp[1090]; // Local buffer to accumulate results and break WAW dependencies
    int base_idx = idx[d];
    int n_d = n[d];
    
    // Initialize temp array to zero
    for (i = 0; i <= n_d; i++) {
        temp[i] = 0.0;
    }

    // Reverse loop order to change dependency traversal (loop-carried dependency removed via independence)
    for (i = n_d; i >= 0; i--) {
        for (j = i; j <= n_d; j++) {
            temp[base_idx + i] += Tright[i * 33 + j] * iv->c[base_idx + j];
        }
    }

    // Final write to ivr->c with no conflicting writes (WAW eliminated by separation)
    for (i = 0; i <= n_d; i++) {
        ivr->c[base_idx + i] = temp[i];
    }
}
