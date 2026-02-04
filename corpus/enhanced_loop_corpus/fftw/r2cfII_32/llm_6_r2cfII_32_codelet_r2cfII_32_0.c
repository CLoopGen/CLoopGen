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
extern  E KP471396736;
extern  E KP881921264;
extern  E KP634393284;
extern  E KP773010453;
extern  E KP290284677;
extern  E KP956940335;
extern  E KP995184726;
extern  E KP098017140;
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
    E T5, T2D, T1z, T2q, Tc, T2C, T1C, T2n, Tm, T1k, T1J, T26, Tv, T1l, T1G;
    E T27, T15, T1r, T1Y, T2e, T1c, T1s, T1V, T2d, TK, T1o, T1R, T2b, TR, T1p;
    E T1O, T2a;
    E temp_R0_loads[16], temp_R1_loads[16];

    for (INT j = 0; j < 16; j++) {
        temp_R0_loads[j] = R0[(rs[j])];
        temp_R1_loads[j] = R1[(rs[j])];
    }

    {
        E T1, T2p, T4, T2o, T2, T3;
        T1 = temp_R0_loads[0];
        T2p = temp_R0_loads[8];
        T2 = temp_R0_loads[4];
        T3 = temp_R0_loads[12];
        T4 = KP707106781 * (T2 - T3);
        T2o = KP707106781 * (T2 + T3);
        T5 = T1 + T4;
        T2D = T2p - T2o;
        T1z = T1 - T4;
        T2q = T2o + T2p;
    }
    {
        E T8, T1A, Tb, T1B;
        {
            E T6, T7, T9, Ta;
            T6 = temp_R0_loads[2];
            T7 = temp_R0_loads[10];
            T8 = ((KP923879532 * T6) - ((KP382683432) * (T7)));
            T1A = (((KP382683432) * (T6)) + (KP923879532 * T7));
            T9 = temp_R0_loads[6];
            Ta = temp_R0_loads[14];
            Tb = ((KP382683432 * T9) - ((KP923879532) * (Ta)));
            T1B = (((KP923879532) * (T9)) + (KP382683432 * Ta));
        }
        Tc = T8 + Tb;
        T2C = Tb - T8;
        T1C = T1A - T1B;
        T2n = T1A + T1B;
    }
    {
        E Te, Tk, Th, Tj, Tf, Tg;
        Te = temp_R0_loads[1];
        Tk = temp_R0_loads[9];
        Tf = temp_R0_loads[5];
        Tg = temp_R0_loads[13];
        Th = KP707106781 * (Tf - Tg);
        Tj = KP707106781 * (Tf + Tg);
        {
            E Ti, Tl, T1H, T1I;
            Ti = Te + Th;
            Tl = Tj + Tk;
            Tm = ((KP980785280 * Ti) - ((KP195090322) * (Tl)));
            T1k = (((KP195090322) * (Ti)) + (KP980785280 * Tl));
            T1H = Tk - Tj;
            T1I = Te - Th;
            T1J = ((KP831469612 * T1H) - ((KP555570233) * (T1I)));
            T26 = (((KP831469612) * (T1I)) + (KP555570233 * T1H));
        }
    }
    {
        E Tq, Tt, Tp, Ts, Tn, To;
        Tq = temp_R0_loads[15];
        Tt = temp_R0_loads[7];
        Tn = temp_R0_loads[3];
        To = temp_R0_loads[11];
        Tp = KP707106781 * (Tn - To);
        Ts = KP707106781 * (Tn + To);
        {
            E Tr, Tu, T1E, T1F;
            Tr = Tp - Tq;
            Tu = Ts + Tt;
            Tv = (((KP980785280) * (Tr)) + (KP195090322 * Tu));
            T1l = ((KP195090322 * Tr) - ((KP980785280) * (Tu)));
            T1E = Tt - Ts;
            T1F = Tp + Tq;
            T1G = ((KP831469612 * T1E) - ((KP555570233) * (T1F)));
            T27 = (((KP831469612) * (T1F)) + (KP555570233 * T1E));
        }
    }
    {
        E TW, T1a, TV, T19, T10, T16, T13, T17, TT, TU;
        TW = temp_R1_loads[15];
        T1a = temp_R1_loads[7];
        TT = temp_R1_loads[3];
        TU = temp_R1_loads[11];
        TV = KP707106781 * (TT - TU);
        T19 = KP707106781 * (TT + TU);
        {
            E TY, TZ, T11, T12;
            TY = temp_R1_loads[1];
            TZ = temp_R1_loads[9];
            T10 = ((KP923879532 * TY) - ((KP382683432) * (TZ)));
            T16 = (((KP382683432) * (TY)) + (KP923879532 * TZ));
            T11 = temp_R1_loads[5];
            T12 = temp_R1_loads[13];
            T13 = ((KP382683432 * T11) - ((KP923879532) * (T12)));
            T17 = (((KP923879532) * (T11)) + (KP382683432 * T12));
        }
        {
            E TX, T14, T1W, T1X;
            TX = TV - TW;
            T14 = T10 + T13;
            T15 = TX + T14;
            T1r = TX - T14;
            T1W = T13 - T10;
            T1X = T1a - T19;
            T1Y = T1W - T1X;
            T2e = T1W + T1X;
        }
        {
            E T18, T1b, T1T, T1U;
            T18 = T16 + T17;
            T1b = T19 + T1a;
            T1c = T18 + T1b;
            T1s = T1b - T18;
            T1T = TV + TW;
            T1U = T16 - T17;
            T1V = T1T + T1U;
            T2d = T1U - T1T;
        }
    }
    {
        E Ty, TP, TB, TO, TF, TL, TI, TM, Tz, TA;
        Ty = temp_R1_loads[0];
        TP = temp_R1_loads[8];
        Tz = temp_R1_loads[4];
        TA = temp_R1_loads[12];
        TB = KP707106781 * (Tz - TA);
        TO = KP707106781 * (Tz + TA);
        {
            E TD, TE, TG, TH;
            TD = temp_R1_loads[2];
            TE = temp_R1_loads[10];
            TF = ((KP923879532 * TD) - ((KP382683432) * (TE)));
            TL = (((KP382683432) * (TD)) + (KP923879532 * TE));
            TG = temp_R1_loads[6];
            TH = temp_R1_loads[14];
            TI = ((KP382683432 * TG) - ((KP923879532) * (TH)));
            TM = (((KP923879532) * (TG)) + (KP382683432 * TH));
        }
        {
            E TC, TJ, T1P, T1Q;
            TC = Ty + TB;
            TJ = TF + TI;
            TK = TC + TJ;
            T1o = TC - TJ;
            T1P = TI - TF;
            T1Q = TP - TO;
            T1R = T1P - T1Q;
            T2b = T1P + T1Q;
        }
        {
            E TN, TQ, T1M, T1N;
            TN = TL + TM;
            TQ = TO + TP;
            TR = TN + TQ;
            T1p = TQ - TN;
            T1M = Ty - TB;
            T1N = TL - TM;
            T1O = T1M - T1N;
            T2a = T1M + T1N;
        }
    }
    {
        E Tx, T1f, T2s, T2u, T1e, T2l, T1i, T2t;
        {
            E Td, Tw, T2m, T2r;
            Td = T5 + Tc;
            Tw = Tm + Tv;
            Tx = Td - Tw;
            T1f = Td + Tw;
            T2m = T1l - T1k;
            T2r = T2n + T2q;
            T2s = T2m - T2r;
            T2u = T2m + T2r;
        }
        {
            E TS, T1d, T1g, T1h;
            TS = (((KP098017140) * (TK)) + (KP995184726 * TR));
            T1d = ((KP098017140 * T15) - ((KP995184726) * (T1c)));
            T1e = TS + T1d;
            T2l = T1d - TS;
            T1g = ((KP995184726 * TK) - ((KP098017140) * (TR)));
            T1h = (((KP995184726) * (T15)) + (KP098017140 * T1c));
            T1i = T1g + T1h;
            T2t = T1h - T1g;
        }
        Cr[(csr[8])] = Tx - T1e;
        Ci[(csi[8])] = T2t - T2u;
        Cr[(csr[7])] = Tx + T1e;
        Ci[(csi[7])] = T2t + T2u;
        Cr[(csr[15])] = T1f - T1i;
        Ci[(csi[15])] = T2l - T2s;
        Cr[0] = T1f + T1i;
        Ci[0] = T2l + T2s;
    }
    {
        E T29, T2h, T2M, T2O, T2g, T2J, T2k, T2N;
        {
            E T25, T28, T2K, T2L;
            T25 = T1z + T1C;
            T28 = T26 - T27;
            T29 = T25 + T28;
            T2h = T25 - T28;
            T2K = T1J + T1G;
            T2L = T2C + T2D;
            T2M = T2K - T2L;
            T2O = T2K + T2L;
        }
        {
            E T2c, T2f, T2i, T2j;
            T2c = (((KP956940335) * (T2a)) + (KP290284677 * T2b));
            T2f = ((KP956940335 * T2d) - ((KP290284677) * (T2e)));
            T2g = T2c + T2f;
            T2J = T2f - T2c;
            T2i = (((KP290284677) * (T2d)) + (KP956940335 * T2e));
            T2j = ((KP956940335 * T2b) - ((KP290284677) * (T2a)));
            T2k = T2i - T2j;
            T2N = T2j + T2i;
        }
        Cr[(csr[14])] = T29 - T2g;
        Ci[(csi[14])] = T2N - T2O;
        Cr[(csr[1])] = T29 + T2g;
        Ci[(csi[1])] = T2N + T2O;
        Cr[(csr[9])] = T2h - T2k;
        Ci[(csi[9])] = T2J - T2M;
        Cr[(csr[6])] = T2h + T2k;
        Ci[(csi[6])] = T2J + T2M;
    }
    {
        E T1n, T1v, T2y, T2A, T1u, T2v, T1y, T2z;
        {
            E T1j, T1m, T2w, T2x;
            T1j = T5 - Tc;
            T1m = T1k + T1l;
            T1n = T1j + T1m;
            T1v = T1j - T1m;
            T2w = Tv - Tm;
            T2x = T2q - T2n;
            T2y = T2w - T2x;
            T2A = T2w + T2x;
        }
        {
            E T1q, T1t, T1w, T1x;
            T1q = (((KP773010453) * (T1o)) + (KP634393284 * T1p));
            T1t = ((KP773010453 * T1r) - ((KP634393284) * (T1s)));
            T1u = T1q + T1t;
            T2v = T1t - T1q;
            T1w = (((KP634393284) * (T1r)) + (KP773010453 * T1s));
            T1x = ((KP773010453 * T1p) - ((KP634393284) * (T1o)));
            T1y = T1w - T1x;
            T2z = T1x + T1w;
        }
        Cr[(csr[12])] = T1n - T1u;
        Ci[(csi[12])] = T2z - T2A;
        Cr[(csr[3])] = T1n + T1u;
        Ci[(csi[3])] = T2z + T2A;
        Cr[(csr[11])] = T1v - T1y;
        Ci[(csi[11])] = T2v - T2y;
        Cr[(csr[4])] = T1v + T1y;
        Ci[(csi[4])] = T2v + T2y;
    }
    {
        E T1L, T21, T2G, T2I, T20, T2H, T24, T2B;
        {
            E T1D, T1K, T2E, T2F;
            T1D = T1z - T1C;
            T1K = T1G - T1J;
            T1L = T1D + T1K;
            T21 = T1D - T1K;
            T2E = T2C - T2D;
            T2F = T26 + T27;
            T2G = T2E - T2F;
            T2I = T2F + T2E;
        }
        {
            E T1S, T1Z, T22, T23;
            T1S = (((KP881921264) * (T1O)) + (KP471396736 * T1R));
            T1Z = (((KP881921264) * (T1V)) + (KP471396736 * T1Y));
            T20 = T1S - T1Z;
            T2H = T1S + T1Z;
            T22 = ((KP881921264 * T1Y) - ((KP471396736) * (T1V)));
            T23 = ((KP881921264 * T1R) - ((KP471396736) * (T1O)));
            T24 = T22 - T23;
            T2B = T23 + T22;
        }
        Cr[(csr[13])] = T1L - T20;
        Ci[(csi[13])] = T2B - T2G;
        Cr[(csr[2])] = T1L + T20;
        Ci[(csi[2])] = T2B + T2G;
        Cr[(csr[10])] = T21 - T24;
        Ci[(csi[10])] = T2I - T2H;
        Cr[(csr[5])] = T21 + T24;
        Ci[(csi[5])] = -(T2H + T2I);
    }
}
}
