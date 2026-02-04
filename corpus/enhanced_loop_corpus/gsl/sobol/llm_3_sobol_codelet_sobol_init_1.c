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
for (i_dim = 1; i_dim < dimension; i_dim += 2) { // Strided access over dimensions
    const int poly_indices[2] = {i_dim, (i_dim + 1 < dimension) ? i_dim + 1 : i_dim};
    for (int d = 0; d < 2; d++) {
        const int poly_index = poly_indices[d];
        const int degree_i = degree_table[poly_index];
        int includ[8];
        int p_i = primitive_polynomials[poly_index];
        for (k = degree_i - 1; k >= 0; k--) {
            includ[k] = ((p_i % 2) == 1);
            p_i /= 2;
        }
        for (j = 0; j < degree_i; j++) {
            s_state->v_direction[j][poly_index] = v_init[j][poly_index];
        }
        for (j = degree_i; j < 30; j++) {
            int newv = s_state->v_direction[j - degree_i][poly_index];
            ell = 1;
            for (k = 0; k < degree_i; k++) {
                ell *= 2;
                if (includ[k]) {
                    newv ^= (ell * s_state->v_direction[j - k - 1][poly_index]);
                }
            }
            s_state->v_direction[j][poly_index] = newv;
        }
        if (d == 1 && poly_index == i_dim) break; // Avoid double processing at boundary
    }
}
}
