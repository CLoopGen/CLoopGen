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
    // Variant 1: Consecutive memory access by reordering computation to access Tleft and c in a more sequential pattern
    double temp;
    int base_idx = idx[d];
    int n_d = n[d];
    for (i = 0; i <= n_d; i++) {
        temp = 0.;
        int tleft_offset = i * 33;
        for (j = i; j <= n_d; j++) {
            temp += Tleft[tleft_offset + j] * iv->c[base_idx + j];
        }
        ivl->c[base_idx + i] = temp;
    }
}
