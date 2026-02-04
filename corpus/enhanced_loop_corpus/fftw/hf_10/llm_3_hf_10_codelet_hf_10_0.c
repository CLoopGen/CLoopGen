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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1R, TT, T1C, TF, TQ, TR, T1o, T1p, T1P, TX, TY, TZ, T1d, T1g;
    E T1x, Ti, Tt, Tu, T1r, T1s, T1O, TU, TV, TW, T16, T19, T1y;

    // Convert strided access into precomputed linear index array for better locality
    INT idx[10];
    #define LOAD_IDX(i) idx[i] = (rs)[i]
    LOAD_IDX(0); LOAD_IDX(1); LOAD_IDX(2); LOAD_IDX(3); LOAD_IDX(4);
    LOAD_IDX(5); LOAD_IDX(6); LOAD_IDX(7); LOAD_IDX(8); LOAD_IDX(9);

    R *cr_ptr = cr;
    R *ci_ptr = ci;
    R *W_ptr = W;

    // Flatten all memory accesses using computed offsets to encourage consecutive usage patterns
    E cr_vals[10], ci_vals[10];
    #define FETCH(n,i) do { \
        if ((i) <= 9 && (i) >= 0) { \
            cr_vals[i] = cr_ptr[idx[i]]; \
            ci_vals[i] = ci_ptr[idx[i]]; \
        } \
    } while(0)

    FETCH(0,0); FETCH(1,1); FETCH(2,2); FETCH(3,3); FETCH(4,4);
    FETCH(5,5); FETCH(6,6); FETCH(7,7); FETCH(8,8); FETCH(9,9);

    E W_vals[18];
    for (INT widx = 0; widx < 18; ++widx) W_vals[widx] = W_ptr[widx];

    {
        E T1 = cr_vals[0], T1A = ci_vals[0];
        E T3 = cr_vals[5], T5 = ci_vals[5];
        E T2 = W_vals[8], T4 = W_vals[9];
        E T6 = T2 * T3 + T4 * T5;
        E T1B = T2 * T5 - T4 * T3;
        T7 = T1 - T6;
        T1R = T1B + T1A;
        TT = T1 + T6;
        T1C = T1A - T1B;
    }
    {
        E Tz = cr_vals[4]*W_vals[6] + ci_vals[4]*W_vals[7];
        E T1b = W_vals[6]*ci_vals[4] - W_vals[7]*cr_vals[4];
        E TP = cr_vals[1]*W_vals[0] + ci_vals[1]*W_vals[1];
        E T1e = W_vals[0]*ci_vals[1] - W_vals[1]*cr_vals[1];
        E TE = cr_vals[9]*W_vals[16] + ci_vals[9]*W_vals[17];
        E T1c = W_vals[16]*ci_vals[9] - W_vals[17]*cr_vals[9];
        E TK = cr_vals[6]*W_vals[10] + ci_vals[6]*W_vals[11];
        E T1f = W_vals[10]*ci_vals[6] - W_vals[11]*cr_vals[6];

        TF = Tz - TE;
        TQ = TK - TP;
        TR = TF + TQ;
        T1o = T1b + T1c;
        T1p = T1f + T1e;
        T1P = T1o + T1p;
        TX = Tz + TE;
        TY = TK + TP;
        TZ = TX + TY;
        T1d = T1b - T1c;
        T1g = T1e - T1f;
        T1x = T1g - T1d;
    }
    {
        E Tc = cr_vals[2]*W_vals[2] + ci_vals[2]*W_vals[3];
        E T14 = W_vals[2]*ci_vals[2] - W_vals[3]*cr_vals[2];
        E Ts = cr_vals[3]*W_vals[4] + ci_vals[3]*W_vals[5];
        E T18 = W_vals[4]*ci_vals[3] - W_vals[5]*cr_vals[3];
        E Th = cr_vals[7]*W_vals[12] + ci_vals[7]*W_vals[13];
        E T15 = W_vals[12]*ci_vals[7] - W_vals[13]*cr_vals[7];
        E Tn = cr_vals[8]*W_vals[14] + ci_vals[8]*W_vals[15];
        E T17 = W_vals[14]*ci_vals[8] - W_vals[15]*cr_vals[8];

        Ti = Tc - Th;
        Tt = Tn - Ts;
        Tu = Ti + Tt;
        T1r = T14 + T15;
        T1s = T17 + T18;
        T1O = T1r + T1s;
        TU = Tc + Th;
        TV = Tn + Ts;
        TW = TU + TV;
        T16 = T14 - T15;
        T19 = T17 - T18;
        T1y = T16 + T19;
    }
    {
        E T11 = KP559016994 * (Tu - TR);
        E TS = Tu + TR;
        E T12 = T7 - KP250000000 * TS;
        E T1a = T16 - T19;
        E T1h = T1d + T1g;
        E T1i = KP951056516 * T1a + KP587785252 * T1h;
        E T1k = KP951056516 * T1h - KP587785252 * T1a;
        ci_ptr[idx[4]] = T7 + TS;
        E T1j = T12 - T11;
        ci_ptr[idx[2]] = T1j - T1k;
        cr_ptr[idx[3]] = T1j + T1k;
        E T13 = T11 + T12;
        ci_ptr[idx[0]] = T13 - T1i;
        cr_ptr[idx[1]] = T13 + T1i;
    }
    {
        E T1m = KP559016994 * (TW - TZ);
        E T10 = TW + TZ;
        E T1l = TT - KP250000000 * T10;
        E T1q = T1o - T1p;
        E T1t = T1r - T1s;
        E T1u = KP951056516 * T1q - KP587785252 * T1t;
        E T1w = KP951056516 * T1t + KP587785252 * T1q;
        cr_ptr[idx[0]] = TT + T10;
        E T1v = T1m + T1l;
        cr_ptr[idx[4]] = T1v - T1w;
        ci_ptr[idx[3]] = T1v + T1w;
        E T1n = T1l - T1m;
        cr_ptr[idx[2]] = T1n - T1u;
        ci_ptr[idx[1]] = T1n + T1u;
    }
    {
        E T1H = KP559016994 * (T1y + T1x);
        E T1z = T1x - T1y;
        E T1G = KP250000000 * T1z + T1C;
        E T1D = Ti - Tt;
        E T1E = TQ - TF;
        E T1F = KP587785252 * T1D + KP951056516 * T1E;
        E T1J = KP587785252 * T1E - KP951056516 * T1D;
        cr_ptr[idx[5]] = T1z - T1C;
        E T1K = T1H + T1G;
        cr_ptr[idx[9]] = T1J - T1K;
        ci_ptr[idx[8]] = T1J + T1K;
        E T1I = T1G - T1H;
        cr_ptr[idx[7]] = T1F - T1I;
        ci_ptr[idx[6]] = T1F + T1I;
    }
    {
        E T1Q = KP559016994 * (T1O - T1P);
        E T1S = T1O + T1P;
        E T1T = T1R - KP250000000 * T1S;
        E T1L = TU - TV;
        E T1M = TX - TY;
        E T1N = KP951056516 * T1L + KP587785252 * T1M;
        E T1V = KP951056516 * T1M - KP587785252 * T1L;
        ci_ptr[idx[9]] = T1S + T1R;
        E T1W = T1T - T1Q;
        cr_ptr[idx[8]] = T1V - T1W;
        ci_ptr[idx[7]] = T1V + T1W;
        E T1U = T1Q + T1T;
        cr_ptr[idx[6]] = T1N - T1U;
        ci_ptr[idx[5]] = T1N + T1U;
    }
}
}
