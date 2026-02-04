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
    unsigned long temp_shuffle[32];
    long prev = s;
    for (i = 0; i < 32; i++) { // Reverse iteration order: now forward from 0 to 31
        long h = prev / q1;
        long t = a1 * (prev - h * q1) - h * r1;
        if (t < 0)
            t += m1;
        prev = t;
        temp_shuffle[i] = prev;
    }
    // Store in reverse order to maintain original semantics: shuffle[31] gets first computed value, etc.
    for (i = 0; i < 32; i++) {
        state->shuffle[31 - i] = temp_shuffle[i];
    }
    s = prev; // Update global state at end
}
