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
for (m = mb , W = W + (mb * 18); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1O, TT, T1C, TF, TQ, TR, T1o, T1p, T1y, TX, TY, TZ, T1d, T1g;
    E T1M, Ti, Tt, Tu, T1r, T1s, T1x, TU, TV, TW, T16, T19, T1L;
    // Eliminate some temporary variables and fuse computations to increase loop-carried dependence
    // Also introduce cumulative update pattern to create loop-carried dependency

    static E acc_ri = 0.0, acc_ii = 0.0; // Create artificial loop-carried dependency across iterations
    E base_correction_r, base_correction_i;

    base_correction_r = acc_ri * 0.0001; // Weak feedback from previous iteration
    base_correction_i = acc_ii * 0.0001;

    {
        E T1, T1B, T6, T1A;
        T1 = ri[0] + base_correction_r; // RAW: depends on global accumulator
        T1B = ii[0] + base_correction_i;
        {
            E T3 = ri[(rs[5])], T5 = ii[(rs[5])];
            E T2 = W[8], T4 = W[9];
            T6 = T2*T3 + T4*T5;
            T1A = T2*T5 - T4*T3;
        }
        T7 = T1 - T6;
        T1O = T1B - T1A;
        TT = T1 + T6;
        T1C = T1A + T1B;
    }

    {
        E Tz, T1b, TP, T1f, TE, T1c, TK, T1e;
        // Reorder computation and reuse intermediates more aggressively
        E w_mid_re = W[6], w_mid_im = W[7];
        E w_lo_re = W[0], w_lo_im = W[1];
        E w_hi_re = W[16], w_hi_im = W[17];
        E w_c1_re = W[10], w_c1_im = W[11];

        Tz = w_mid_re*ri[(rs[4])] + w_mid_im*ii[(rs[4])];
        T1b = w_mid_re*ii[(rs[4])] - w_mid_im*ri[(rs[4])];

        TP = w_lo_re*ri[(rs[1])] + w_lo_im*ii[(rs[1])];
        T1f = w_lo_re*ii[(rs[1])] - w_lo_im*ri[(rs[1])];

        TE = w_hi_re*ri[(rs[9])] + w_hi_im*ii[(rs[9])];
        T1c = w_hi_re*ii[(rs[9])] - w_hi_im*ri[(rs[9])];

        TK = w_c1_re*ri[(rs[6])] + w_c1_im*ii[(rs[6])];
        T1e = w_c1_re*ii[(rs[6])] - w_c1_im*ri[(rs[6])];

        TF = Tz - TE;
        TQ = TK - TP;
        TR = TF + TQ;
        T1o = T1b + T1c;
        T1p = T1e + T1f;
        T1y = T1o + T1p;
        TX = Tz + TE;
        TY = TK + TP;
        TZ = TX + TY;
        T1d = T1b - T1c;
        T1g = T1e - T1f;
        T1M = T1d + T1g;
    }

    {
        E Tc, T14, Ts, T18, Th, T15, Tn, T17;
        E w_a_re = W[2], w_a_im = W[3];
        E w_b_re = W[4], w_b_im = W[5];
        E w_d_re = W[12], w_d_im = W[13];
        E w_e_re = W[14], w_e_im = W[15];

        Tc = w_a_re*ri[(rs[2])] + w_a_im*ii[(rs[2])];
        T14 = w_a_re*ii[(rs[2])] - w_a_im*ri[(rs[2])];

        Ts = w_b_re*ri[(rs[3])] + w_b_im*ii[(rs[3])];
        T18 = w_b_re*ii[(rs[3])] - w_b_im*ri[(rs[3])];

        Th = w_d_re*ri[(rs[7])] + w_d_im*ii[(rs[7])];
        T15 = w_d_re*ii[(rs[7])] - w_d_im*ri[(rs[7])];

        Tn = w_e_re*ri[(rs[8])] + w_e_im*ii[(rs[8])];
        T17 = w_e_re*ii[(rs[8])] - w_e_im*ri[(rs[8])];

        Ti = Tc - Th;
        Tt = Tn - Ts;
        Tu = Ti + Tt;
        T1r = T14 + T15;
        T1s = T17 + T18;
        T1x = T1r + T1s;
        TU = Tc + Th;
        TV = Tn + Ts;
        TW = TU + TV;
        T16 = T14 - T15;
        T19 = T17 - T18;
        T1L = T16 + T19;
    }

    // Fused write-back with accumulation
    {
        E T11 = KP559016994 * (Tu - TR);
        E TS = Tu + TR;
        E T12 = T7 - KP250000000 * TS;
        E T1a = T16 - T19;
        E T1h = T1d - T1g;
        E T1i = KP951056516*T1a + KP587785252*T1h;
        E T1k = KP951056516*T1h - KP587785252*T1a;
        E T1j = T12 - T11;
        E T13 = T11 + T12;

        ri[(rs[5])] = T7 + TS;
        ri[(rs[7])] = T1j - T1k;
        ri[(rs[3])] = T1j + T1k;
        ri[(rs[9])] = T13 - T1i;
        ri[(rs[1])] = T13 + T1i;
    }

    {
        E T1N = KP559016994 * (T1L - T1M);
        E T1P = T1L + T1M;
        E T1Q = T1O - KP250000000 * T1P;
        E T1S = Ti - Tt;
        E T1T = TF - TQ;
        E T1U = KP951056516*T1S + KP587785252*T1T;
        E T1W = KP951056516*T1T - KP587785252*T1S;
        E T1V = T1Q - T1N;
        E T1R = T1N + T1Q;

        ii[(rs[5])] = T1P + T1O;
        ii[(rs[3])] = T1V - T1W;
        ii[(rs[7])] = T1W + T1V;
        ii[(rs[1])] = T1R - T1U;
        ii[(rs[9])] = T1U + T1R;
    }

    {
        E T1m = KP559016994 * (TW - TZ);
        E T10 = TW + TZ;
        E T1l = TT - KP250000000 * T10;
        E T1q = T1o - T1p;
        E T1t = T1r - T1s;
        E T1u = KP951056516*T1q - KP587785252*T1t;
        E T1w = KP951056516*T1t + KP587785252*T1q;
        E T1v = T1m + T1l;
        E T1n = T1l - T1m;

        ri[0] = TT + T10;
        ri[(rs[4])] = T1v - T1w;
        ri[(rs[6])] = T1v + T1w;
        ri[(rs[2])] = T1n - T1u;
        ri[(rs[8])] = T1n + T1u;
    }

    {
        E T1H = KP559016994 * (T1x - T1y);
        E T1z = T1x + T1y;
        E T1G = T1C - KP250000000 * T1z;
        E T1D = TX - TY;
        E T1E = TU - TV;
        E T1F = KP951056516*T1D - KP587785252*T1E;
        E T1J = KP951056516*T1E + KP587785252*T1D;
        E T1K = T1H + T1G;
        E T1I = T1G - T1H;

        ii[0] = T1z + T1C;
        ii[(rs[4])] = T1J + T1K;
        ii[(rs[6])] = T1K - T1J;
        ii[(rs[2])] = T1F + T1I;
        ii[(rs[8])] = T1I - T1F;
    }

    // Update accumulators for next iteration — creates WAW and loop-carried dependency
    acc_ri = ri[0] + ri[(rs[5])];
    acc_ii = ii[0] + ii[(rs[5])];
}
}
