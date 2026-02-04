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
for (m = mb; m < me; m += 1, cr += ms, ci -= ms, W += 6) {
    E Tf = W[0], Ti = W[1], Tg = W[2], Tj = W[3], TF = W[4], TG = W[5];
    E TP = Tf * Tg + Ti * Tj;
    E TR = Tf * Tj - Ti * Tg;
    E TH = Tf * TF + Ti * TG;
    E TL = Tf * TG - Ti * TF;
    E TT = TP * TF + TR * TG;
    E T15 = TP * TG - TR * TF;
    E KP = KP707106781;

    E c0 = cr[0], c3r = cr[rs[3]], c2r = cr[rs[2]], c1r = cr[rs[1]], c4r = cr[rs[4]], c5r = cr[rs[5]], c6r = cr[rs[6]], c7r = cr[rs[7]];
    E i0 = ci[0], i3 = ci[rs[3]], i1 = ci[rs[1]], i2 = ci[rs[2]], i4 = ci[rs[4]], i5 = ci[rs[5]], i6 = ci[rs[6]], i7 = ci[rs[7]];

    E T3 = c0 + i3, TU = c0 - i3;
    E Tv = i5 - c6r, TV = i5 + c6r;
    E T6 = c2r + i1, T16 = c2r - i1;
    E Ts = i7 - c4r, T17 = i7 + c4r;
    E T7 = T3 + T6, T1f = TU + TV, T1i = T17 - T16, Tw = Ts + Tv;
    E TI = T3 - T6, TW = TU - TV, T18 = T16 + T17, TM = Ts - Tv;

    E Ta = c1r + i2, TX = c1r - i2;
    E TC = i4 - c7r, T11 = i4 + c7r;
    E Td = i0 + c3r, T10 = i0 - c3r;
    E Tz = i6 - c5r, TY = i6 + c5r;
    E Te = Ta + Td, T19 = TX + TY, T1a = T10 + T11, TD = Tz + TC;
    E TJ = TC - Tz, TZ = TX - TY, T12 = T10 - T11, TN = Ta - Td;

    cr[0] = T7 + Te;
    ci[0] = Tw + TD;
    E Tm = T7 - Te, TE = Tw - TD;
    cr[rs[4]] = Tf * Tm - Ti * TE;
    ci[rs[4]] = Ti * Tm + Tf * TE;

    E TQ = TI + TJ, TS = TN + TM;
    cr[rs[2]] = TP * TQ - TR * TS;
    ci[rs[2]] = TP * TS + TR * TQ;

    E TK = TI - TJ, TO = TM - TN;
    cr[rs[6]] = TH * TK - TL * TO;
    ci[rs[6]] = TH * TO + TL * TK;

    E T1g = KP * (T19 + T1a);
    E T1h = T1f - T1g, T1l = T1f + T1g;
    E T1j = KP * (TZ - T12);
    E T1k = T1i + T1j, T1m = T1i - T1j;
    cr[rs[3]] = Tg * T1h - Tj * T1k;
    ci[rs[3]] = Tg * T1k + Tj * T1h;
    cr[rs[7]] = TF * T1l - TG * T1m;
    ci[rs[7]] = TF * T1m + TG * T1l;

    E T13 = KP * (TZ + T12);
    E T14 = TW - T13, T1d = TW + T13;
    E T1b = KP * (T19 - T1a);
    E T1c = T18 - T1b, T1e = T18 + T1b;
    cr[rs[5]] = TT * T14 - T15 * T1c;
    ci[rs[5]] = T15 * T14 + TT * T1c;
    cr[rs[1]] = Tf * T1d - Ti * T1e;
    ci[rs[1]] = Ti * T1d + Tf * T1e;
}
}
