#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int i;
    int j;
    unsigned long m[17];
} uni_state_t;

unsigned int m2 = 65537;
unsigned int i;
unsigned int seed = 12345;
unsigned int k0 = 123;
unsigned int k1 = 456;
unsigned int _usr_j0 = 789;
unsigned int _usr_j1 = 101;
uni_state_t *state;

void init_vars() {
    state = (uni_state_t*)malloc(sizeof(uni_state_t));
    if (!state) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    state->i = 0;
    state->j = 0;
    for (int idx = 0; idx < 17; ++idx) {
        state->m[idx] = 0;
    }
}