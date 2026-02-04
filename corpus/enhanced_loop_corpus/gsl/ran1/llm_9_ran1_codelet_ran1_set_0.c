#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  long m;
extern  long a;
extern  long q;
extern  long r;
extern unsigned long s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced trip count with simplified computation
for (i = 0; i < 4; i++) {
    long h = s / q;
    long t = a * s - h * (a * q + r);
    if (t < 0)
        t += m;
    else if (t >= m)
        t -= m;
    s = t;

    // Lighter dependency chain with minimal branching
    s = (s & (m - 1)) + (s >> 63 & m); // Assumes m is power of two for masking effect
}
}
