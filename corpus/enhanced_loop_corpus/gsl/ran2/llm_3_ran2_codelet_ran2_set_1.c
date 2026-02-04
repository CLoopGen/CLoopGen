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
    // Variant 2: Strided memory access with step size 2 (unrolled pattern simulation)
    // First pass: even indices
    for (int j = 0; j < 32; j += 2) {
        long h = s / q1;
        long t = a1 * (s - h * q1) - h * r1;
        if (t < 0)
            t += m1;
        s = t;
        state->shuffle[31 - j] = s;
    }
    // Second pass: odd indices
    for (int j = 1; j < 32; j += 2) {
        long h = s / q1;
        long t = a1 * (s - h * q1) - h * r1;
        if (t < 0)
            t += m1;
        s = t;
        state->shuffle[31 - j] = s;
    }
}
