#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned int sequence_count;
    double last_denominator_inv;
    int last_numerator_vec[40];
    int v_direction[30][40];
} sobol_state_t;

int primitive_polynomials[40];
int degree_table[40];
int v_init[8][40];
unsigned int dimension;
sobol_state_t *s_state;
unsigned int i_dim;
int j;
int k;
int ell;

void init_vars() {
    dimension = 40;

    for (int i = 0; i < 40; i++) {
        primitive_polynomials[i] = 3 + i; 
        degree_table[i] = (i < 30) ? (i % 5 + 1) : (i % 4 + 1);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 40; j++) {
            v_init[i][j] = (i + 1) * (j + 1);
        }
    }

    s_state = (sobol_state_t*)calloc(dimension, sizeof(sobol_state_t));
    if (!s_state) {
        exit(1);
    }

    for (unsigned int d = 0; d < dimension; d++) {
        s_state[d].sequence_count = 0;
        s_state[d].last_denominator_inv = 1.0;
        for (int i = 0; i < 40; i++) {
            s_state[d].last_numerator_vec[i] = 0;
        }
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 40; j++) {
                s_state[d].v_direction[i][j] = 0;
            }
        }
    }
}