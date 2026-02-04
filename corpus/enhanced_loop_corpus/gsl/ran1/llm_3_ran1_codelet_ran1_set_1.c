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
for (i = 32 - 1; i >= 0; i -= 2) {
    long h1 = s / q;
    long t1 = a * (s - h1 * q) - h1 * r;
    if (t1 < 0)
        t1 += m;
    s = t1;
    state->shuffle[i] = s;

    if (i - 1 >= 0) {
        long h2 = s / q;
        long t2 = a * (s - h2 * q) - h2 * r;
        if (t2 < 0)
            t2 += m;
        s = t2;
        state->shuffle[i - 1] = s;
    }
}
}
