#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct {
    double xdbl[12];
    double carry;
    unsigned int ir;
    unsigned int jr;
    unsigned int ir_old;
    unsigned int pr;
} ranlxd_state_t;

double one_bit = 1.0 / 281474976710656.0;  // 2^-48
ranlxd_state_t *state;
int ibit = 0;
int jbit = 19;
int k;
int l;
int xbit[31];
double x;
double y;

void init_vars() {
    state = (ranlxd_state_t*)calloc(1, sizeof(ranlxd_state_t));
    if (!state) exit(1);
    
    // Initialize xbit with a non-zero seed pattern (avoid all zeros)
    for (int i = 0; i < 31; ++i) {
        xbit[i] = (i * i + 1) % 2;
    }
    
    // Ensure ibit and jbit are within bounds
    ibit = 0;
    jbit = 19;  // commonly used offset in lagged Fibonacci
    
    // Initialize state fields
    state->carry = 0.0;
    state->ir = 0;
    state->jr = 0;
    state->ir_old = 0;
    state->pr = 0;
    
    // Warm up the generator a bit to avoid degenerate initial states
    for (int warmup = 0; warmup < 100; ++warmup) {
        int temp = (xbit[ibit] + xbit[jbit]) % 2;
        xbit[ibit] = temp;
        ibit = (ibit + 1) % 31;
        jbit = (jbit + 1) % 31;
    }
    
    // Reset loop indices
    k = 0;
    l = 0;
    x = 0.0;
    y = 0.0;
}