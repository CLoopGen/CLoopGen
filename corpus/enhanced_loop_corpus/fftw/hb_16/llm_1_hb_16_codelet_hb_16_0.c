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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 30); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 30 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T2K, T2W, Tw, T17, T1S, T2k, T1w, Te, TD, T1x, T10, T2n, T2L, T1Z;
    E T2X, Tm, T1z, TN, T19, T2e, T2p, T2P, T2Z, Tt, T1A, TW, T1a, T27, T2q;
    E T2S, T30;

    for (INT unroll_factor = 0; unroll_factor < 2 && m + unroll_factor < me; unroll_factor++) {
        INT current_m = m + unroll_factor;
        R *current_cr = cr + (unroll_factor * ms);
        R *current_ci = ci - (unroll_factor * ms);
        R *current_W = W + (unroll_factor * 30);

        #define CR(idx) current_cr[(idx)]
        #define CI(idx) current_ci[(rs[idx])]
        #define CW(idx) current_W[(idx)]

        {
            E T3, T1Q, T16, T1R, T6, T2i, T13, T2j;
            {
                E T1 = CR(0), T2 = CI(7);
                T3 = T1 + T2;
                T1Q = T1 - T2;
                E T14 = CI(11), T15 = CR(12);
                T16 = T14 - T15;
                T1R = T14 + T15;
            }
            {
                E T4 = CR(4), T5 = CI(3);
                T6 = T4 + T5;
                T2i = T4 - T5;
                E T11 = CI(15), T12 = CR(8);
                T13 = T11 - T12;
                T2j = T11 + T12;
            }
            T7 = T3 + T6;
            T2K = T1Q + T1R;
            T2W = T2j - T2i;
            Tw = T3 - T6;
            T17 = T13 - T16;
            T1S = T1Q - T1R;
            T2k = T2i + T2j;
            T1w = T13 + T16;
        }
        {
            E Ta, T1T, TC, T1U, Td, T1W, Tz, T1X;
            {
                E T8 = CR(2), T9 = CI(5);
                Ta = T8 + T9;
                T1T = T8 - T9;
                E TA = CI(13), TB = CR(10);
                TC = TA - TB;
                T1U = TA + TB;
            }
            {
                E Tb = CI(1), Tc = CR(6);
                Td = Tb + Tc;
                T1W = Tb - Tc;
                E Tx = CI(9), Ty = CR(14);
                Tz = Tx - Ty;
                T1X = Tx + Ty;
            }
            Te = Ta + Td;
            TD = Tz - TC;
            T1x = TC + Tz;
            T10 = Ta - Td;
            {
                E T2l = T1T + T1U, T2m = T1W + T1X;
                T2n = KP707106781 * (T2l - T2m);
                T2L = KP707106781 * (T2l + T2m);
                E T1V = T1T - T1U, T1Y = T1W - T1X;
                T1Z = KP707106781 * (T1V + T1Y);
                T2X = KP707106781 * (T1V - T1Y);
            }
        }
        {
            E Ti, T2b, TL, T2c, Tl, T28, TI, T29, TF, TM;
            {
                E Tg = CR(1), Th = CI(6);
                Ti = Tg + Th;
                T2b = Tg - Th;
                E TJ = CI(10), TK = CR(13);
                TL = TJ - TK;
                T2c = TJ + TK;
            }
            {
                E Tj = CR(5), Tk = CI(2);
                Tl = Tj + Tk;
                T28 = Tj - Tk;
                E TG = CI(14), TH = CR(9);
                TI = TG - TH;
                T29 = TG + TH;
            }
            Tm = Ti + Tl;
            T1z = TI + TL;
            TF = Ti - Tl;
            TM = TI - TL;
            TN = TF - TM;
            T19 = TF + TM;
            {
                E T2a = T28 + T29, T2d = T2b - T2c;
                T2e = (KP923879532 * T2a) + (KP382683432 * T2d);
                T2p = (KP923879532 * T2d) - (KP382683432 * T2a);
                E T2N = T2b + T2c, T2O = T29 - T28;
                T2P = (KP382683432 * T2N) - (KP923879532 * T2O);
                T2Z = (KP382683432 * T2O) + (KP923879532 * T2N);
            }
        }
        {
            E Tp, T24, TU, T25, Ts, T21, TR, T22, TO, TV;
            {
                E Tn = CI(0), To = CR(7);
                Tp = Tn + To;
                T24 = Tn - To;
                E TS = CI(12), TT = CR(11);
                TU = TS - TT;
                T25 = TS + TT;
            }
            {
                E Tq = CR(3), Tr = CI(4);
                Ts = Tq + Tr;
                T21 = Tq - Tr;
                E TP = CI(8), TQ = CR(15);
                TR = TP - TQ;
                T22 = TP + TQ;
            }
            Tt = Tp + Ts;
            T1A = TR + TU;
            TO = Tp - Ts;
            TV = TR - TU;
            TW = TO + TV;
            T1a = TV - TO;
            {
                E T23 = T21 - T22, T26 = T24 - T25;
                T27 = (KP923879532 * T23) - (KP382683432 * T26);
                T2q = (KP382683432 * T23) + (KP923879532 * T26);
                E T2Q = T24 + T25, T2R = T21 + T22;
                T2S = (KP382683432 * T2Q) - (KP923879532 * T2R);
                T30 = (KP382683432 * T2R) + (KP923879532 * T2Q);
            }
        }

        {
            E Tf = T7 + Te, Tu = Tm + Tt;
            E T1u = Tf - Tu, T1y = T1w + T1x, T1B = T1z + T1A, T1C = T1y - T1B;
            current_cr[0] = Tf + Tu;
            current_ci[0] = T1y + T1B;
            E T1t = CW(14), T1v = CW(15);
            current_cr[rs[8]] = (T1t * T1u) - (T1v * T1C);
            current_ci[rs[8]] = (T1v * T1u) + (T1t * T1C);
        }

        {
            E T2M = T2K - T2L, T2T = T2P + T2S;
            E T2U = T2M - T2T, T34 = T2M + T2T;
            E T2Y = T2W + T2X, T31 = T2Z - T30;
            E T32 = T2Y - T31, T36 = T2Y + T31;
            E T2J = CW(20), T2V = CW(21);
            current_cr[rs[11]] = (T2J * T2U) - (T2V * T32);
            current_ci[rs[11]] = (T2V * T2U) + (T2J * T32);
            E T33 = CW(4), T35 = CW(5);
            current_cr[rs[3]] = (T33 * T34) - (T35 * T36);
            current_ci[rs[3]] = (T35 * T34) + (T33 * T36);
        }

        {
            E T38 = T2K + T2L, T39 = T2Z + T30;
            E T3a = T38 - T39, T3g = T38 + T39;
            E T3c = T2W - T2X, T3d = T2P - T2S;
            E T3e = T3c + T3d, T3i = T3c - T3d;
            E T37 = CW(12), T3b = CW(13);
            current_cr[rs[7]] = (T37 * T3a) - (T3b * T3e);
            current_ci[rs[7]] = (T37 * T3e) + (T3b * T3a);
            E T3f = CW(28), T3h = CW(29);
            current_cr[rs[15]] = (T3f * T3g) - (T3h * T3i);
            current_ci[rs[15]] = (T3f * T3i) + (T3h * T3g);
        }

        {
            E TE = Tw + TD, TX = KP707106781 * (TN + TW);
            E TY = TE - TX, T1e = TE + TX;
            E T18 = T10 + T17, T1b = KP707106781 * (T19 + T1a);
            E T1c = T18 - T1b, T1g = T18 + T1b;
            E Tv = CW(18), TZ = CW(19);
            current_cr[rs[10]] = (Tv * TY) - (TZ * T1c);
            current_ci[rs[10]] = (TZ * TY) + (Tv * T1c);
            E T1d = CW(2), T1f = CW(3);
            current_cr[rs[2]] = (T1d * T1e) - (T1f * T1g);
            current_ci[rs[2]] = (T1f * T1e) + (T1d * T1g);
        }

        {
            E T1i = Tw - TD, T1j = KP707106781 * (T1a - T19);
            E T1k = T1i - T1j, T1q = T1i + T1j;
            E T1m = T17 - T10, T1n = KP707106781 * (TN - TW);
            E T1o = T1m - T1n, T1s = T1m + T1n;
            E T1h = CW(26), T1l = CW(27);
            current_cr[rs[14]] = (T1h * T1k) - (T1l * T1o);
            current_ci[rs[14]] = (T1h * T1o) + (T1l * T1k);
            E T1p = CW(10), T1r = CW(11);
            current_cr[rs[6]] = (T1p * T1q) - (T1r * T1s);
            current_ci[rs[6]] = (T1p * T1s) + (T1r * T1q);
        }

        {
            E T20 = T1S - T1Z, T2f = T27 - T2e;
            E T2g = T20 - T2f, T2u = T20 + T2f;
            E T2o = T2k - T2n, T2r = T2p - T2q;
            E T2s = T2o - T2r, T2w = T2o + T2r;
            E T1P = CW(24), T2h = CW(25);
            current_cr[rs[13]] = (T1P * T2g) - (T2h * T2s);
            current_ci[rs[13]] = (T2h * T2g) + (T1P * T2s);
            E T2t = CW(8), T2v = CW(9);
            current_cr[rs[5]] = (T2t * T2u) - (T2v * T2w);
            current_ci[rs[5]] = (T2v * T2u) + (T2t * T2w);
        }

        {
            E T2y = T1S + T1Z, T2z = T2p + T2q;
            E T2A = T2y - T2z, T2G = T2y + T2z;
            E T2C = T2k + T2n, T2D = T2e + T27;
            E T2E = T2C - T2D, T2I = T2C + T2D;
            E T2x = CW(16), T2B = CW(17);
            current_cr[rs[9]] = (T2x * T2A) - (T2B * T2E);
            current_ci[rs[9]] = (T2x * T2E) + (T2B * T2A);
            E T2F = CW(0), T2H = CW(1);
            current_cr[rs[1]] = (T2F * T2G) - (T2H * T2I);
            current_ci[rs[1]] = (T2F * T2I) + (T2H * T2G);
        }

        {
            E T1E = T7 - Te, T1F = T1A - T1z;
            E T1G = T1E - T1F, T1M = T1E + T1F;
            E T1I = T1w - T1x, T1J = Tm - Tt;
            E T1K = T1I - T1J, T1O = T1J + T1I;
            E T1D = CW(22), T1H = CW(23);
            current_cr[rs[12]] = (T1D * T1G) - (T1H * T1K);
            current_ci[rs[12]] = (T1D * T1K) + (T1H * T1G);
            E T1L = CW(6), T1N = CW(7);
            current_cr[rs[4]] = (T1L * T1M) - (T1N * T1O);
            current_ci[rs[4]] = (T1L * T1O) + (T1N * T1M);
        }

        #undef CR
        #undef CI
        #undef CW

        if (unroll_factor == 1) break;
    }
}
}
