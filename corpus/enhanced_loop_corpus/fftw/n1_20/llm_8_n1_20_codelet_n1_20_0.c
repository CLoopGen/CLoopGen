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
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T2Q, T3h, TD, TP, T1U, T2l, T1d, Tt, TA, TB, T2w, T2z, T2S, T35;
    E T36, T3f, TH, TI, TJ, T15, T1a, T1b, T1s, T1x, T1W, T29, T2a, T2j, T1h;
    E T1i, T1j, Te, Tl, Tm, T2D, T2G, T2R, T32, T33, T3e, TE, TF, TG, TU;
    E TZ, T10, T1D, T1I, T1V, T26, T27, T2i, T1e, T1f, T1g;

    // Unroll the original computation by processing two iterations at once
    // This doubles arithmetic intensity and reduces loop overhead.
    for (INT unroll = 0; unroll < 2 && i - unroll > 0; ++unroll) {
        {
            E T3, T1Q, TN, T2O, T6, TO, T1T, T2P;
            {
                E T1, T2, TL, TM;
                T1 = ri[0];
                T2 = ri[(is[10])];
                T3 = T1 + T2;
                T1Q = T1 - T2;
                TL = ii[0];
                TM = ii[(is[10])];
                TN = TL - TM;
                T2O = TL + TM;
            }
            {
                E T4, T5, T1R, T1S;
                T4 = ri[(is[5])];
                T5 = ri[(is[15])];
                T6 = T4 + T5;
                TO = T4 - T5;
                T1R = ii[(is[5])];
                T1S = ii[(is[15])];
                T1T = T1R - T1S;
                T2P = T1R + T1S;
            }
            T7 = T3 - T6;
            T2Q = T2O - T2P;
            T3h = T2O + T2P;
            TD = T3 + T6;
            TP = TN - TO;
            T1U = T1Q - T1T;
            T2l = T1Q + T1T;
            T1d = TO + TN;
        }
        {
            E Tp, T1o, T13, T2u, Ts, T14, T1r, T2v, Tw, T1t, T18, T2x, Tz, T19, T1w;
            E T2y;
            {
                E Tn, To, T11, T12;
                Tn = ri[(is[8])];
                To = ri[(is[18])];
                Tp = Tn + To;
                T1o = Tn - To;
                T11 = ii[(is[8])];
                T12 = ii[(is[18])];
                T13 = T11 - T12;
                T2u = T11 + T12;
            }
            {
                E Tq, Tr, T1p, T1q;
                Tq = ri[(is[13])];
                Tr = ri[(is[3])];
                Ts = Tq + Tr;
                T14 = Tq - Tr;
                T1p = ii[(is[13])];
                T1q = ii[(is[3])];
                T1r = T1p - T1q;
                T2v = T1p + T1q;
            }
            {
                E Tu, Tv, T16, T17;
                Tu = ri[(is[12])];
                Tv = ri[(is[2])];
                Tw = Tu + Tv;
                T1t = Tu - Tv;
                T16 = ii[(is[12])];
                T17 = ii[(is[2])];
                T18 = T16 - T17;
                T2x = T16 + T17;
            }
            {
                E Tx, Ty, T1u, T1v;
                Tx = ri[(is[17])];
                Ty = ri[(is[7])];
                Tz = Tx + Ty;
                T19 = Tx - Ty;
                T1u = ii[(is[17])];
                T1v = ii[(is[7])];
                T1w = T1u - T1v;
                T2y = T1u + T1v;
            }
            Tt = Tp - Ts;
            TA = Tw - Tz;
            TB = Tt + TA;
            T2w = T2u - T2v;
            T2z = T2x - T2y;
            T2S = T2w + T2z;
            T35 = T2u + T2v;
            T36 = T2x + T2y;
            T3f = T35 + T36;
            TH = Tp + Ts;
            TI = Tw + Tz;
            TJ = TH + TI;
            T15 = T13 - T14;
            T1a = T18 - T19;
            T1b = T15 + T1a;
            T1s = T1o - T1r;
            T1x = T1t - T1w;
            T1W = T1s + T1x;
            T29 = T1o + T1r;
            T2a = T1t + T1w;
            T2j = T29 + T2a;
            T1h = T14 + T13;
            T1i = T19 + T18;
            T1j = T1h + T1i;
        }
        {
            E Ta, T1z, TS, T2B, Td, TT, T1C, T2C, Th, T1E, TX, T2E, Tk, TY, T1H;
            E T2F;
            {
                E T8, T9, TQ, TR;
                T8 = ri[(is[4])];
                T9 = ri[(is[14])];
                Ta = T8 + T9;
                T1z = T8 - T9;
                TQ = ii[(is[4])];
                TR = ii[(is[14])];
                TS = TQ - TR;
                T2B = TQ + TR;
            }
            {
                E Tb, Tc, T1A, T1B;
                Tb = ri[(is[9])];
                Tc = ri[(is[19])];
                Td = Tb + Tc;
                TT = Tb - Tc;
                T1A = ii[(is[9])];
                T1B = ii[(is[19])];
                T1C = T1A - T1B;
                T2C = T1A + T1B;
            }
            {
                E Tf, Tg, TV, TW;
                Tf = ri[(is[16])];
                Tg = ri[(is[6])];
                Th = Tf + Tg;
                T1E = Tf - Tg;
                TV = ii[(is[16])];
                TW = ii[(is[6])];
                TX = TV - TW;
                T2E = TV + TW;
            }
            {
                E Ti, Tj, T1F, T1G;
                Ti = ri[(is[1])];
                Tj = ri[(is[11])];
                Tk = Ti + Tj;
                TY = Ti - Tj;
                T1F = ii[(is[1])];
                T1G = ii[(is[11])];
                T1H = T1F - T1G;
                T2F = T1F + T1G;
            }
            Te = Ta - Td;
            Tl = Th - Tk;
            Tm = Te + Tl;
            T2D = T2B - T2C;
            T2G = T2E - T2F;
            T2R = T2D + T2G;
            T32 = T2B + T2C;
            T33 = T2E + T2F;
            T3e = T32 + T33;
            TE = Ta + Td;
            TF = Th + Tk;
            TG = TE + TF;
            TU = TS - TT;
            TZ = TX - TY;
            T10 = TU + TZ;
            T1D = T1z - T1C;
            T1I = T1E - T1H;
            T1V = T1D + T1I;
            T26 = T1z + T1C;
            T27 = T1E + T1H;
            T2i = T26 + T27;
            T1e = TT + TS;
            T1f = TY + TX;
            T1g = T1e + T1f;
        }

        // Output write-back with offset adjustment per unrolled instance
        {
            E T2s, TC, T2r, T2I, T2K, T2A, T2H, T2J, T2t;
            T2s = KP559016994 * (Tm - TB);
            TC = Tm + TB;
            T2r = ((T7) - ((KP250000000) * (TC)));
            T2A = T2w - T2z;
            T2H = T2D - T2G;
            T2I = ((KP951056516 * T2A) - ((KP587785252) * (T2H)));
            T2K = (((KP951056516) * (T2H)) + (KP587785252 * T2A));
            ro[(os[10])] = T7 + TC;
            T2J = T2s + T2r;
            ro[(os[14])] = T2J - T2K;
            ro[(os[6])] = T2J + T2K;
            T2t = T2r - T2s;
            ro[(os[2])] = T2t - T2I;
            ro[(os[18])] = T2t + T2I;
        }
        {
            E T2V, T2T, T2U, T2N, T2Y, T2L, T2M, T2X, T2W;
            T2V = KP559016994 * (T2R - T2S);
            T2T = T2R + T2S;
            T2U = ((T2Q) - ((KP250000000) * (T2T)));
            T2L = Tt - TA;
            T2M = Te - Tl;
            T2N = ((KP951056516 * T2L) - ((KP587785252) * (T2M)));
            T2Y = (((KP951056516) * (T2M)) + (KP587785252 * T2L));
            io[(os[10])] = T2Q + T2T;
            T2X = T2V + T2U;
            io[(os[6])] = T2X - T2Y;
            io[(os[14])] = T2Y + T2X;
            T2W = T2U - T2V;
            io[(os[2])] = T2N + T2W;
            io[(os[18])] = T2W - T2N;
        }

        // Adjust pointers for next unrolled iteration if applicable
        if (unroll == 0 && i > 1) {
            ri += ivs; ii += ivs; ro += ovs; io += ovs;
        }
    }

    // Compensate loop counter: since we processed up to 2 iterations
    if (v > 1) i -= 1; // Simulate partial unrolling effect without changing outer control
}
}
