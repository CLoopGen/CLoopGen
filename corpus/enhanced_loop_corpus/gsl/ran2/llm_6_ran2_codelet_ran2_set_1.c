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
    long local_s = s;
    for (i = 32 - 1; i >= 0; i--) {
        long h = local_s / q1;
        long t = a1 * (local_s - h * q1) - h * r1;
        if (t < 0)
            t += m1;
        local_s = t;
        state->shuffle[i] = local_s;
    }
    s = local_s; // Update global s only after loop completes (eliminates WAW and WAR dependencies across iterations)
}
