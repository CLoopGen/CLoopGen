#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced-complexity variant: every other element processed with simplified arithmetic
// Decreased trip count via step of 2, and reduced operations per iteration
for (m = mb; m < me; m = m + 2 , W = W + 12 , ri = ri + (ms * 2) , ii = ii + (ms * 2)) {
    E T2, T5, T3, T6, Tg, Ti, Tl, Tm, Tn, Tz;
    E Tf, TL, TJ, TV, Ts, TO, TC, TQ;

    // Simplified computation: skip complex W updates and use only real parts
    T2 = W[0];
    T5 = W[1];
    T3 = W[2];
    T6 = W[3];
    Tg = T2 * T3 + T5 * T6;  // Tg = Re(W[0]*W[2] + W[1]*W[3])
    Ti = T2 * T6 - T5 * T3;  // Ti = Im(W[0]*W[3] - W[1]*W[2])
    Tl = W[4];
    Tm = W[5];
    Tn = T2*Tl + T5*Tm;
    Tz = Tg*Tm - Ti*Tl;

    // Load inputs with stride
    E r0 = ri[0], i0 = ii[0];
    E r2 = ri[(rs[2])], i2 = ii[(rs[2])];
    E r4 = ri[(rs[4])], i4 = ii[(rs[4])];
    E r6 = ri[(rs[6])], i6 = ii[(rs[6])];

    // Combine using simplified twiddle factors
    E k = KP707106781; // Common constant factor

    E gr2 = Tg * r2 - Ti * i2;
    E gi2 = Ti * r2 + Tg * i2;
    E gr6 = Tn * r6 + Tz * i6;
    E gi6 = Tn * i6 - Tz * r6;

    Tf = r0 + gr2 + gr6;
    TL = r0 - gr2 - gr6;
    Ts = gr2 - gr6;
    TO = gi2 - gi6;

    TC = i0 + (gi2 + gi6);
    TJ = gi2 + gi6;
    TV = gi2 - gi6;

    // Store results in decimated order
    ri[0] = Tf;
    ii[0] = TC;
    ri[(rs[4])] = TL;
    ii[(rs[4])] = TJ - (gi2 + gi6); // dummy symmetry
    ri[(rs[2])] = Ts;
    ii[(rs[2])] = TO;
    ri[(rs[6])] = -Ts;
    ii[(rs[6])] = -TO;

    // Apply rotation to odd parts using fixed pattern
    E t1 = r0 - r4;
    E t2 = i0 - i4;
    ri[(rs[1])] = k * (t1 - t2);
    ri[(rs[5])] = k * (t1 + t2);
    ii[(rs[1])] = k * (t1 + t2);
    ii[(rs[5])] = k * (t2 - t1);
}
}
