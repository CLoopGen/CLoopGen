#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned long x;
    unsigned long n;
    unsigned long shuffle[32];
} ran1_state_t;

extern  long m;
extern  long a;
extern  long q;
extern  long r;
extern unsigned long s;
extern ran1_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long prev_s = s;
    for (i = 32 - 1; i >= 0; i--) {
        long h = prev_s / q;
        long t = a * (prev_s - h * q) - h * r;
        if (t < 0)
            t += m;
        state->shuffle[i] = t;
        prev_s = t;
    }
}
