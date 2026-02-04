#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long x;
    unsigned long y;
    unsigned long n;
    unsigned long shuffle[32];
} ran2_state_t;

extern  long m1;
extern  long a1;
extern  long q1;
extern  long r1;
extern unsigned long s;
extern ran2_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce trip count and unroll the loop partially for lower computational load
for (i = 31; i >= 24; i -= 4) {
    // Unroll x4: manually replicate loop body for four iterations with decreasing i
    long h0 = s / q1;
    long t0 = a1 * (s - h0 * q1) - h0 * r1;
    s = (t0 < 0) ? t0 + m1 : t0;
    state->shuffle[i] = s;

    long h1 = s / q1;
    long t1 = a1 * (s - h1 * q1) - h1 * r1;
    s = (t1 < 0) ? t1 + m1 : t1;
    state->shuffle[i-1] = s;

    long h2 = s / q1;
    long t2 = a1 * (s - h2 * q1) - h2 * r1;
    s = (t2 < 0) ? t2 + m1 : t2;
    state->shuffle[i-2] = s;

    long h3 = s / q1;
    long t3 = a1 * (s - h3 * q1) - h3 * r1;
    s = (t3 < 0) ? t3 + m1 : t3;
    state->shuffle[i-3] = s;
}
}
