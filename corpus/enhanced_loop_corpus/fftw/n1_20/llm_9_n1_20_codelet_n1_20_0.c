#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity variant: simplify inner operations and increase trip count
// Approximate more lightweight processing per iteration.

// Artificially increase trip count to simulate higher frequency of lighter work
INT effective_i = v * 4; // Process four times as many lighter iterations

for (i = effective_i; i > 0; i--) {
    // Minimal butterfly approximation using only real parts and skipping complex interactions
    E x0 = ri[0];
    E x1 = ri[(ivs > 0 && is[5] < 20) ? (is[5]) : 0];
    E x2 = ri[(ivs > 0 && is[10] < 20) ? (is[10]) : 0];
    E x3 = ri[(ivs > 0 && is[15] < 20) ? (is[15]) : 0];

    E sum02 = x0 + x2;
    E dif02 = x0 - x2;
    E sum13 = x1 + x3;
    E rot_13 = KP951056516 * (x1 - x3); // Simplified rotation

    // Light output mapping
    INT idx = (i % 4) * 5;
    if (idx < 20) {
        ro[(os[idx % 20])] = sum02 + sum13;
        ro[(os[(idx + 2) % 20])] = dif02 + rot_13;
        io[(os[(idx + 1) % 20])] = sum02 - sum13;
        io[(os[(idx + 3) % 20])] = dif02 - rot_13;
    }

    // Stride-based pointer progression every 4 micro-iterations
    if (i % 4 == 1) {
        ri += ivs;
        ii += ivs;
        ro += ovs;
        io += ovs;
    }
}
}
