#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int sequence_count;
    double last_denominator_inv;
    int last_numerator_vec[40];
    int v_direction[30][40];
} sobol_state_t;

extern  int primitive_polynomials[40];
extern  int degree_table[40];
extern  int v_init[8][40];
extern unsigned int dimension;
extern sobol_state_t *s_state;
extern unsigned int i_dim;
extern int j;
extern int k;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i_dim = 1; i_dim < dimension; i_dim++) {
    const int poly_index = i_dim;
    const int degree_i = degree_table[poly_index];
    int includ[8];
    int p_i = primitive_polynomials[poly_index];
    for (k = degree_i - 1; k >= 0; k--) {
        includ[k] = (p_i & 1);
        p_i >>= 1;
    }
    for (j = 0; j < degree_i; j++) {
        s_state->v_direction[j][i_dim] = v_init[j][i_dim];
    }
    if (degree_i > 0) {
        for (j = degree_i; j < 30; j++) {
            int newv = s_state->v_direction[j - degree_i][i_dim];
            ell = 1;
            for (k = 0; k < degree_i; k++) {
                ell <<= 1;
                newv ^= includ[k] ? (ell * s_state->v_direction[j - k - 1][i_dim]) : 0;
            }
            s_state->v_direction[j][i_dim] = newv;
        }
    }
}
}
