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
    // Variant 2: Indirect array indexing using precomputed index arrays to simulate irregular memory access pattern
    int start_idx = idx[d];
    int size = n[d] + 1;
    int *index_map = (int*)alloca(size * sizeof(int));
    
    // Precompute reversed indices to create indirect access
    for (int k = 0; k < size; k++) {
        index_map[k] = start_idx + (n[d] - k);  // reverse order access
    }

    for (i = 0; i < size; i++) {
        int rev_i = n[d] - i;  // process from end to beginning
        ivr->c[start_idx + rev_i] = 0.;
        int tbase = rev_i * 33;
        for (j = rev_i; j <= n[d]; j++) {
            int mapped_j = index_map[n[d] - j];  // use reversed index mapping
            ivr->c[start_idx + rev_i] += Tright[tbase + j] * iv->c[mapped_j];
        }
    }
}
