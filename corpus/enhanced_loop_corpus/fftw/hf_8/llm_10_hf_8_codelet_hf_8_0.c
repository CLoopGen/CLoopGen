#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 1, cr += ms, ci -= ms, W += 14) {
    E T7, T1f, TH, T19, TF, T12, TR, TU, Ti, T1e, TK, T16, Tu, T13, TM;
    E TP;

    // Reduced arithmetic: combine repeated loads and reuse common subexpressions
    const E c0 = cr[0], i0 = ci[0];
    const E c1 = cr[rs[1]], i1 = ci[rs[1]];
    const E c2 = cr[rs[2]], i2 = ci[rs[2]];
    const E c3 = cr[rs[3]], i3 = ci[rs[3]];
    const E c4 = cr[rs[4]], i4 = ci[rs[4]];
    const E c5 = cr[rs[5]], i5 = ci[rs[5]];
    const E c6 = cr[rs[6]], i6 = ci[rs[6]];
    const E c7 = cr[rs[7]], i7 = ci[rs[7]];

    const E w0 = W[0], w1 = W[1];
    const E w2 = W[2], w3 = W[3];
    const E w4 = W[4], w5 = W[5];
    const E w6 = W[6], w7 = W[7];
    const E w8 = W[8], w9 = W[9];
    const E w10 = W[10], w11 = W[11];
    const E w12 = W[12], w13 = W[13];

    // Precompute complex multiplications
    const E r4 = w6 * c4 + w7 * i4;
    const E i4_ = w6 * i4 - w7 * c4;

    T7 = c0 + r4;
    T1f = i0 - i4_;
    TH = c0 - r4;
    T19 = i0 + i4_;

    const E r7 = w12 * c7 + w13 * i7;
    const E i7_ = w12 * i7 - w13 * c7;
    const E r3 = w4 * c3 + w5 * i3;
    const E i3_ = w4 * i3 - w5 * c3;

    TF = r7 + r3;
    T12 = i7_ + i3_;
    TR = r7 - r3;
    TU = i7_ - i3_;

    const E r2 = w2 * c2 + w3 * i2;
    const E i2_ = w2 * i2 - w3 * c2;
    const E r6 = w10 * c6 + w11 * i6;
    const E i6_ = w10 * i6 - w11 * c6;

    Ti = r2 + r6;
    T1e = r2 - r6;
    TK = i2_ - i6_;
    T16 = i2_ + i6_;

    const E r1 = w0 * c1 + w1 * i1;
    const E i1_ = w0 * i1 - w1 * c1;
    const E r5 = w8 * c5 + w9 * i5;
    const E i5_ = w8 * i5 - w9 * c5;

    Tu = r1 + r5;
    T13 = i1_ + i5_;
    TM = r1 - r5;
    TP = i1_ - i5_;

    // Final butterfly stages with reduced redundancy
    const E Tj = T7 + Ti;
    const E TG = Tu + TF;
    ci[rs[3]] = Tj - TG;
    cr[0] = Tj + TG;

    const E T1b = TF - Tu;
    const E T1c = T19 - T16;
    cr[rs[6]] = T1b - T1c;
    ci[rs[5]] = T1b + T1c;

    const E TX = TH - TK;
    const E T1i = T1f - T1e;
    const E SY = TM - TP;
    const E SZ = TR + TU;
    const E T10 = KP707106781 * (SY + SZ);
    const E T1h = KP707106781 * (SZ - SY);

    cr[rs[3]] = TX - T10;
    ci[rs[6]] = T1h + T1i;
    ci[0] = TX + T10;
    cr[rs[5]] = T1h - T1i;

    const E T15 = T13 + T12;
    const E T1a = T16 + T19;
    cr[rs[4]] = T15 - T1a;
    ci[rs[7]] = T15 + T1a;

    const E T11 = T7 - Ti;
    const E T14 = T12 - T13;
    cr[rs[2]] = T11 - T14;
    ci[rs[1]] = T11 + T14;

    const E TL = TH + TK;
    const E T1g = T1e + T1f;
    const E SQ = TM + TP;
    const E SV = TR - TU;
    const E TW = KP707106781 * (SQ + SV);
    const E T1d = KP707106781 * (SV - SQ);

    ci[rs[2]] = TL - TW;
    ci[rs[4]] = T1d + T1g;
    cr[rs[1]] = TL + TW;
    cr[rs[7]] = T1d - T1g;
}
}
