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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Tm, Tc, Tk, T9, Td, Te, TM, TO, Tg, Tp;
    E Tv, Tx, Tr;
    // Cache W values in local array to reduce memory access dependencies
    E W_cache[6];
    for (INT i = 0; i < 6; i++) W_cache[i] = W[i];
    
    T2 = W_cache[0];
    T5 = W_cache[1];
    T3 = W_cache[2];
    T6 = W_cache[3];
    T9 = W_cache[4];
    Td = W_cache[5];

    E T4 = T2 * T3;
    E Tb = T5 * T3;
    E T7 = T5 * T6;
    E Ta = T2 * T6;
    T8 = T4 - T7;
    Tm = Ta - Tb;
    Tc = Ta + Tb;
    Tk = T4 + T7;

    Te = T8 * T9 + Tc * Td;
    TM = T3 * T9 + T6 * Td;
    TO = T3 * Td - T6 * T9;
    Tg = T8 * Td - Tc * T9;
    Tp = Tk * T9 + Tm * Td;
    Tv = T2 * T9 + T5 * Td;
    Tx = T2 * Td - T5 * T9;
    Tr = Tk * Td - Tm * T9;

    // Reorder computation blocks to eliminate some false dependencies
    // by using temporaries and delaying stores until end of loop body
    E out_ri[10], out_ii[10];
    INT idxs[10] = {0,1,2,3,4,5,6,7,8,9};
    for(INT i = 0; i < 10; i++) { out_ri[i] = 0; out_ii[i] = 0; }

    E T1 = ri[0], T1F = ii[0];
    E Tf = ri[rs[5]], Th = ii[rs[5]];
    E Ti = Te * Tf + Tg * Th;
    E T1E = Te * Th - Tg * Tf;
    E Tj = T1 - Ti;
    E T1S = T1F - T1E;
    E TX = T1 + Ti;
    E T1G = T1E + T1F;

    // Load all required inputs first to break WAR hazards
    E inputs_ri[10], inputs_ii[10];
    for(INT i = 0; i < 10; i++) {
        INT offset = (i <= 9) ? rs[i] : 0;
        inputs_ri[i] = (i==0)?ri[0]:ri[offset];
        inputs_ii[i] = (i==0)?ii[0]:ii[offset];
    }

    // Now compute all intermediate values without any store interference
    E TH = T8 * inputs_ri[4] + Tc * inputs_ii[4];
    E T1f = T8 * inputs_ii[4] - Tc * inputs_ri[4];
    E TT = T2 * inputs_ri[1] + T5 * inputs_ii[1];
    E T1j = T2 * inputs_ii[1] - T5 * inputs_ri[1];
    E TK = T9 * inputs_ri[9] + Td * inputs_ii[9];
    E T1g = T9 * inputs_ii[9] - Td * inputs_ri[9];
    E TQ = TM * inputs_ri[6] + TO * inputs_ii[6];
    E T1i = TM * inputs_ii[6] - TO * inputs_ri[6];

    E TL = TH - TK;
    E TU = TQ - TT;
    E TV = TL + TU;
    E T1s = T1f + T1g;
    E T1t = T1i + T1j;
    E T1C = T1s + T1t;
    E T11 = TH + TK;
    E T12 = TQ + TT;
    E T13 = T11 + T12;
    E T1h = T1f - T1g;
    E T1k = T1i - T1j;
    E T1Q = T1h + T1k;

    E To = Tk * inputs_ri[2] + Tm * inputs_ii[2];
    E T18 = Tk * inputs_ii[2] - Tm * inputs_ri[2];
    E TC = T3 * inputs_ri[3] + T6 * inputs_ii[3];
    E T1c = T3 * inputs_ii[3] - T6 * inputs_ri[3];
    E Tt = Tp * inputs_ri[7] + Tr * inputs_ii[7];
    E T19 = Tp * inputs_ii[7] - Tr * inputs_ri[7];
    E Tz = Tv * inputs_ri[8] + Tx * inputs_ii[8];
    E T1b = Tv * inputs_ii[8] - Tx * inputs_ri[8];

    E Tu = To - Tt;
    E TD = Tz - TC;
    E TE = Tu + TD;
    E T1v = T18 + T19;
    E T1w = T1b + T1c;
    E T1B = T1v + T1w;
    E TY = To + Tt;
    E TZ = Tz + TC;
    E T10 = TY + TZ;
    E T1a = T18 - T19;
    E T1d = T1b - T1c;
    E T1P = T1a + T1d;

    // Final computations and output assignments
    E T15 = KP559016994 * (TE - TV);
    E TW = TE + TV;
    E T16 = Tj - KP250000000 * TW;
    E T1e = T1a - T1d;
    E T1l = T1h - T1k;
    E T1m = KP951056516 * T1e + KP587785252 * T1l;
    E T1o = KP951056516 * T1l - KP587785252 * T1e;

    out_ri[idxs[5]] = Tj + TW;
    E T1n = T16 - T15;
    out_ri[idxs[7]] = T1n - T1o;
    out_ri[idxs[3]] = T1n + T1o;
    E T17 = T15 + T16;
    out_ri[idxs[9]] = T17 - T1m;
    out_ri[idxs[1]] = T17 + T1m;

    E T1R = KP559016994 * (T1P - T1Q);
    E T1T = T1P + T1Q;
    E T1U = T1S - KP250000000 * T1T;
    E T1W = Tu - TD;
    E T1X = TL - TU;
    E T1Y = KP951056516 * T1W + KP587785252 * T1X;
    E T20 = KP951056516 * T1X - KP587785252 * T1W;

    out_ii[idxs[5]] = T1T + T1S;
    E T1Z = T1U - T1R;
    out_ii[idxs[3]] = T1Z - T20;
    out_ii[idxs[7]] = T20 + T1Z;
    E T1V = T1R + T1U;
    out_ii[idxs[1]] = T1V - T1Y;
    out_ii[idxs[9]] = T1Y + T1V;

    E T1q = KP559016994 * (T10 - T13);
    E T14 = T10 + T13;
    E T1p = TX - KP250000000 * T14;
    E T1u = T1s - T1t;
    E T1x = T1v - T1w;
    E T1y = KP951056516 * T1u - KP587785252 * T1x;
    E T1A = KP951056516 * T1x + KP587785252 * T1u;

    out_ri[idxs[0]] = TX + T14;
    E T1z = T1q + T1p;
    out_ri[idxs[4]] = T1z - T1A;
    out_ri[idxs[6]] = T1z + T1A;
    E T1r = T1p - T1q;
    out_ri[idxs[2]] = T1r - T1y;
    out_ri[idxs[8]] = T1r + T1y;

    E T1L = KP559016994 * (T1B - T1C);
    E T1D = T1B + T1C;
    E T1K = T1G - KP250000000 * T1D;
    E T1H = T11 - T12;
    E T1I = TY - TZ;
    E T1J = KP951056516 * T1H - KP587785252 * T1I;
    E T1N = KP951056516 * T1I + KP587785252 * T1H;

    out_ii[idxs[0]] = T1D + T1G;
    E T1O = T1L + T1K;
    out_ii[idxs[4]] = T1N + T1O;
    out_ii[idxs[6]] = T1O - T1N;
    E T1M = T1K - T1L;
    out_ii[idxs[2]] = T1J + T1M;
    out_ii[idxs[8]] = T1M - T1J;

    // Perform all stores at the end to eliminate intra-loop WAW and WAR hazards
    for(INT i = 0; i < 10; i++) {
        if (i == 0) {
            ri[0] = out_ri[0];
            ii[0] = out_ii[0];
        } else {
            INT offset = rs[i];
            ri[offset] = out_ri[i];
            ii[offset] = out_ii[i];
        }
    }
}
}
