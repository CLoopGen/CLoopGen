#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T2b, Tv, T1l, Te, T2o, Ty, T1k, Tt, T2d, TF, T1h, Tm, T2c, TC;
    E T1i, T1Z, T22, T2k, T2j, T1e, T1C, T19, T1B, T1S, T1V, T2h, T2g, TX, T1z;
    E TS, T1y;

    const INT skip_first_half = (i & 2); // Skip first half on every 2nd iteration
    const INT skip_second_half = (i & 4); // Skip second half on every 4th iteration

    if (!skip_first_half) {
        {
            E T1, T2, T3, T4, T5, T6;
            T1 = R0[0];
            T2 = R0[(rs[8])];
            T3 = T1 + T2;
            T4 = R0[(rs[4])];
            T5 = R0[(rs[12])];
            T6 = T4 + T5;
            T7 = T3 + T6;
            T2b = T3 - T6;
            Tv = T1 - T2;
            T1l = T4 - T5;
        }
        {
            E Ta, Tw, Td, Tx;
            {
                E T8, T9, Tb, Tc;
                T8 = R0[(rs[2])];
                T9 = R0[(rs[10])];
                Ta = T8 + T9;
                Tw = T8 - T9;
                Tb = R0[(rs[14])];
                Tc = R0[(rs[6])];
                Td = Tb + Tc;
                Tx = Tb - Tc;
            }
            Te = Ta + Td;
            T2o = Td - Ta;
            Ty = KP707106781 * (Tw + Tx);
            T1k = KP707106781 * (Tx - Tw);
        }
        {
            E Tp, TD, Ts, TE;
            {
                E Tn, To, Tq, Tr;
                Tn = R0[(rs[15])];
                To = R0[(rs[7])];
                Tp = Tn + To;
                TD = Tn - To;
                Tq = R0[(rs[3])];
                Tr = R0[(rs[11])];
                Ts = Tq + Tr;
                TE = Tq - Tr;
            }
            Tt = Tp + Ts;
            T2d = Tp - Ts;
            TF = (((KP923879532) * (TD)) + (KP382683432 * TE));
            T1h = ((KP382683432 * TD) - ((KP923879532) * (TE)));
        }
        {
            E Ti, TA, Tl, TB;
            {
                E Tg, Th, Tj, Tk;
                Tg = R0[(rs[1])];
                Th = R0[(rs[9])];
                Ti = Tg + Th;
                TA = Tg - Th;
                Tj = R0[(rs[5])];
                Tk = R0[(rs[13])];
                Tl = Tj + Tk;
                TB = Tj - Tk;
            }
            Tm = Ti + Tl;
            T2c = Ti - Tl;
            TC = ((KP923879532 * TA) - ((KP382683432) * (TB)));
            T1i = (((KP382683432) * (TA)) + (KP923879532 * TB));
        }
    } else {
        T7 = T2b = Tv = T1l = Te = T2o = Ty = T1k = Tt = T2d = TF = T1h = Tm = T2c = TC = T1i = 0;
    }

    {
        E T11, T1X, T1d, T1Y, T14, T20, T17, T21, T1a, T18;
        {
            E TZ, T10, T1b, T1c;
            TZ = R1[(rs[15])];
            T10 = R1[(rs[7])];
            T11 = TZ - T10;
            T1X = TZ + T10;
            T1b = R1[(rs[3])];
            T1c = R1[(rs[11])];
            T1d = T1b - T1c;
            T1Y = T1b + T1c;
        }
        {
            E T12, T13, T15, T16;
            T12 = R1[(rs[1])];
            T13 = R1[(rs[9])];
            T14 = T12 - T13;
            T20 = T12 + T13;
            T15 = R1[(rs[13])];
            T16 = R1[(rs[5])];
            T17 = T15 - T16;
            T21 = T15 + T16;
        }
        T1Z = T1X + T1Y;
        T22 = T20 + T21;
        T2k = T21 - T20;
        T2j = T1X - T1Y;
        T1a = KP707106781 * (T17 - T14);
        T1e = T1a - T1d;
        T1C = T1d + T1a;
        T18 = KP707106781 * (T14 + T17);
        T19 = T11 + T18;
        T1B = T11 - T18;
    }
    {
        E TK, T1Q, TW, T1R, TN, T1T, TQ, T1U, TT, TR;
        {
            E TI, TJ, TU, TV;
            TI = R1[0];
            TJ = R1[(rs[8])];
            TK = TI - TJ;
            T1Q = TI + TJ;
            TU = R1[(rs[4])];
            TV = R1[(rs[12])];
            TW = TU - TV;
            T1R = TU + TV;
        }
        {
            E TL, TM, TO, TP;
            TL = R1[(rs[2])];
            TM = R1[(rs[10])];
            TN = TL - TM;
            T1T = TL + TM;
            TO = R1[(rs[14])];
            TP = R1[(rs[6])];
            TQ = TO - TP;
            T1U = TO + TP;
        }
        T1S = T1Q + T1R;
        T1V = T1T + T1U;
        T2h = T1U - T1T;
        T2g = T1Q - T1R;
        TT = KP707106781 * (TQ - TN);
        TX = TT - TW;
        T1z = TW + TT;
        TR = KP707106781 * (TN + TQ);
        TS = TK + TR;
        T1y = TK - TR;
    }

    if (!skip_second_half) {
        {
            E Tf, Tu, T27, T28, T29, T2a;
            Tf = T7 + Te;
            Tu = Tm + Tt;
            T27 = Tf + Tu;
            T28 = T1S + T1V;
            T29 = T1Z + T22;
            T2a = T28 + T29;
            Cr[(csr[8])] = Tf - Tu;
            Ci[(csi[8])] = T29 - T28;
            Cr[(csr[16])] = T27 - T2a;
            Cr[0] = T27 + T2a;
        }
        {
            E T1P, T25, T24, T26, T1W, T23;
            T1P = T7 - Te;
            T25 = Tt - Tm;
            T1W = T1S - T1V;
            T23 = T1Z - T22;
            T24 = KP707106781 * (T1W + T23);
            T26 = KP707106781 * (T23 - T1W);
            Cr[(csr[12])] = T1P - T24;
            Ci[(csi[12])] = T26 - T25;
            Cr[(csr[4])] = T1P + T24;
            Ci[(csi[4])] = T25 + T26;
        }
        {
            E T2f, T2v, T2p, T2r, T2m, T2q, T2u, T2w, T2e, T2n;
            T2e = KP707106781 * (T2c + T2d);
            T2f = T2b + T2e;
            T2v = T2b - T2e;
            T2n = KP707106781 * (T2d - T2c);
            T2p = T2n - T2o;
            T2r = T2o + T2n;
            {
                E T2i, T2l, T2s, T2t;
                T2i = (((KP923879532) * (T2g)) + (KP382683432 * T2h));
                T2l = ((KP923879532 * T2j) - ((KP382683432) * (T2k)));
                T2m = T2i + T2l;
                T2q = T2l - T2i;
                T2s = ((KP923879532 * T2h) - ((KP382683432) * (T2g)));
                T2t = (((KP382683432) * (T2j)) + (KP923879532 * T2k));
                T2u = T2s + T2t;
                T2w = T2t - T2s;
            }
            Cr[(csr[14])] = T2f - T2m;
            Ci[(csi[14])] = T2u - T2r;
            Cr[(csr[2])] = T2f + T2m;
            Ci[(csi[2])] = T2r + T2u;
            Ci[(csi[6])] = T2p + T2q;
            Cr[(csr[6])] = T2v + T2w;
            Ci[(csi[10])] = T2q - T2p;
            Cr[(csr[10])] = T2v - T2w;
        }
        {
            E TH, T1t, T1s, T1u, T1g, T1o, T1n, T1p;
            {
                E Tz, TG, T1q, T1r;
                Tz = Tv + Ty;
                TG = TC + TF;
                TH = Tz + TG;
                T1t = Tz - TG;
                T1q = ((KP980785280 * TX) - ((KP195090322) * (TS)));
                T1r = (((KP195090322) * (T19)) + (KP980785280 * T1e));
                T1s = T1q + T1r;
                T1u = T1r - T1q;
            }
            {
                E TY, T1f, T1j, T1m;
                TY = (((KP980785280) * (TS)) + (KP195090322 * TX));
                T1f = ((KP980785280 * T19) - ((KP195090322) * (T1e)));
                T1g = TY + T1f;
                T1o = T1f - TY;
                T1j = T1h - T1i;
                T1m = T1k - T1l;
                T1n = T1j - T1m;
                T1p = T1m + T1j;
            }
            Cr[(csr[15])] = TH - T1g;
            Ci[(csi[15])] = T1s - T1p;
            Cr[(csr[1])] = TH + T1g;
            Ci[(csi[1])] = T1p + T1s;
            Ci[(csi[7])] = T1n + T1o;
            Cr[(csr[7])] = T1t + T1u;
            Ci[(csi[9])] = T1o - T1n;
            Cr[(csr[9])] = T1t - T1u;
        }
        {
            E T1x, T1N, T1M, T1O, T1E, T1I, T1H, T1J;
            {
                E T1v, T1w, T1K, T1L;
                T1v = Tv - Ty;
                T1w = T1i + T1h;
                T1x = T1v + T1w;
                T1N = T1v - T1w;
                T1K = ((KP831469612 * T1z) - ((KP555570233) * (T1y)));
                T1L = (((KP555570233) * (T1B)) + (KP831469612 * T1C));
                T1M = T1K + T1L;
                T1O = T1L - T1K;
            }
            {
                E T1A, T1D, T1F, T1G;
                T1A = (((KP831469612) * (T1y)) + (KP555570233 * T1z));
                T1D = ((KP831469612 * T1B) - ((KP555570233) * (T1C)));
                T1E = T1A + T1D;
                T1I = T1D - T1A;
                T1F = TF - TC;
                T1G = T1l + T1k;
                T1H = T1F - T1G;
                T1J = T1G + T1F;
            }
            Cr[(csr[13])] = T1x - T1E;
            Ci[(csi[13])] = T1M - T1J;
            Cr[(csr[3])] = T1x + T1E;
            Ci[(csi[3])] = T1J + T1M;
            Ci[(csi[5])] = T1H + T1I;
            Cr[(csr[5])] = T1N + T1O;
            Ci[(csi[11])] = T1I - T1H;
            Cr[(csr[11])] = T1N - T1O;
        }
    }
}
}
