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
extern  E KP1_913880671;
extern  E KP580569354;
extern  E KP942793473;
extern  E KP1_763842528;
extern  E KP1_546020906;
extern  E KP1_268786568;
extern  E KP196034280;
extern  E KP1_990369453;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP1_961570560;
extern  E KP390180644;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T2i, T2F, Tz, T1k, T1I, T1Z, T1x, Te, T22, T2E, T2j, T1f, T1y, TK;
    E T1J, Tm, T2B, TW, T1a, T1C, T1L, T28, T2l, Tt, T2A, T17, T1b, T1F, T1M;
    E T2d, T2m;
    // Introduce temporary arrays to break RAW/WAR dependencies and allow reordering
    E temp_Cr[16], temp_Ci[16];
    for (INT j = 0; j < 16; j++) {
        temp_Cr[j] = Cr[(csr[j])];
        temp_Ci[j] = Ci[(csi[j])];
    }
    {
        E T3, Tv, T1j, T2h, T6, T1g, Ty, T2g;
        {
            E T1, T2, T1h, T1i;
            T1 = temp_Cr[0];
            T2 = temp_Cr[15];
            T3 = T1 + T2;
            Tv = T1 - T2;
            T1h = temp_Ci[0];
            T1i = temp_Ci[15];
            T1j = T1h + T1i;
            T2h = T1i - T1h;
        }
        {
            E T4, T5, Tw, Tx;
            T4 = temp_Cr[8];
            T5 = temp_Cr[7];
            T6 = T4 + T5;
            T1g = T4 - T5;
            Tw = temp_Ci[8];
            Tx = temp_Ci[7];
            Ty = Tw + Tx;
            T2g = Tw - Tx;
        }
        T7 = T3 + T6;
        T2i = T2g + T2h;
        T2F = T2h - T2g;
        Tz = Tv - Ty;
        T1k = T1g + T1j;
        T1I = T1g - T1j;
        T1Z = T3 - T6;
        T1x = Tv + Ty;
    }
    {
        E Ta, TA, TD, T21, Td, TF, TI, T20;
        {
            E T8, T9, TB, TC;
            T8 = temp_Cr[4];
            T9 = temp_Cr[11];
            Ta = T8 + T9;
            TA = T8 - T9;
            TB = temp_Ci[4];
            TC = temp_Ci[11];
            TD = TB + TC;
            T21 = TB - TC;
        }
        {
            E Tb, Tc, TG, TH;
            Tb = temp_Cr[3];
            Tc = temp_Cr[12];
            Td = Tb + Tc;
            TF = Tb - Tc;
            TG = temp_Ci[3];
            TH = temp_Ci[12];
            TI = TG + TH;
            T20 = TH - TG;
        }
        Te = Ta + Td;
        T22 = T20 - T21;
        T2E = T21 + T20;
        T2j = Ta - Td;
        {
            E T1d, T1e, TE, TJ;
            T1d = TA + TD;
            T1e = TF + TI;
            T1f = KP707106781 * (T1d - T1e);
            T1y = KP707106781 * (T1d + T1e);
            TE = TA - TD;
            TJ = TF - TI;
            TK = KP707106781 * (TE + TJ);
            T1J = KP707106781 * (TE - TJ);
        }
    }
    {
        E Ti, TM, TU, T25, Tl, TR, TP, T26, TQ, TV;
        {
            E Tg, Th, TS, TT;
            Tg = temp_Cr[2];
            Th = temp_Cr[13];
            Ti = Tg + Th;
            TM = Tg - Th;
            TS = temp_Ci[2];
            TT = temp_Ci[13];
            TU = TS + TT;
            T25 = TS - TT;
        }
        {
            E Tj, Tk, TN, TO;
            Tj = temp_Cr[10];
            Tk = temp_Cr[5];
            Tl = Tj + Tk;
            TR = Tj - Tk;
            TN = temp_Ci[10];
            TO = temp_Ci[5];
            TP = TN + TO;
            T26 = TN - TO;
        }
        Tm = Ti + Tl;
        T2B = T26 + T25;
        TQ = TM - TP;
        TV = TR + TU;
        TW = ((KP923879532 * TQ) - ((KP382683432) * (TV)));
        T1a = (((KP382683432) * (TQ)) + (KP923879532 * TV));
        {
            E T1A, T1B, T24, T27;
            T1A = TM + TP;
            T1B = TU - TR;
            T1C = ((KP382683432 * T1A) - ((KP923879532) * (T1B)));
            T1L = (((KP923879532) * (T1A)) + (KP382683432 * T1B));
            T24 = Ti - Tl;
            T27 = T25 - T26;
            T28 = T24 - T27;
            T2l = T24 + T27;
        }
    }
    {
        E Tp, TX, T15, T2a, Ts, T12, T10, T2b, T11, T16;
        {
            E Tn, To, T13, T14;
            Tn = temp_Cr[1];
            To = temp_Cr[14];
            Tp = Tn + To;
            TX = Tn - To;
            T13 = temp_Ci[1];
            T14 = temp_Ci[14];
            T15 = T13 + T14;
            T2a = T14 - T13;
        }
        {
            E Tq, Tr, TY, TZ;
            Tq = temp_Cr[6];
            Tr = temp_Cr[9];
            Ts = Tq + Tr;
            T12 = Tq - Tr;
            TY = temp_Ci[6];
            TZ = temp_Ci[9];
            T10 = TY + TZ;
            T2b = TY - TZ;
        }
        Tt = Tp + Ts;
        T2A = T2b + T2a;
        T11 = TX - T10;
        T16 = T12 - T15;
        T17 = (((KP923879532) * (T11)) + (KP382683432 * T16));
        T1b = ((KP923879532 * T16) - ((KP382683432) * (T11)));
        {
            E T1D, T1E, T29, T2c;
            T1D = TX + T10;
            T1E = T12 + T15;
            T1F = ((KP382683432 * T1D) - ((KP923879532) * (T1E)));
            T1M = (((KP923879532) * (T1D)) + (KP382683432 * T1E));
            T29 = Tp - Ts;
            T2c = T2a - T2b;
            T2d = T29 + T2c;
            T2m = T2c - T29;
        }
    }
    {
        E Tf, Tu, T2L, T2M, T2N, T2O;
        Tf = T7 + Te;
        Tu = Tm + Tt;
        T2L = Tf - Tu;
        T2M = T2B + T2A;
        T2N = T2F - T2E;
        T2O = T2M + T2N;
        R0[0] = KP2_000000000 * (Tf + Tu);
        R0[(rs[8])] = KP2_000000000 * (T2N - T2M);
        R0[(rs[4])] = KP1_414213562 * (T2L + T2O);
        R0[(rs[12])] = KP1_414213562 * (T2O - T2L);
    }
    {
        E T2t, T2x, T2w, T2y;
        {
            E T2r, T2s, T2u, T2v;
            T2r = T1Z - T22;
            T2s = KP707106781 * (T2m - T2l);
            T2t = T2r + T2s;
            T2x = T2r - T2s;
            T2u = T2j + T2i;
            T2v = KP707106781 * (T28 - T2d);
            T2w = T2u - T2v;
            T2y = T2v + T2u;
        }
        R0[(rs[3])] = (((KP1_662939224) * (T2t)) + (KP1_111140466 * T2w));
        R0[(rs[15])] = ((KP390180644 * T2y) - ((KP1_961570560) * (T2x)));
        R0[(rs[11])] = ((KP1_662939224 * T2w) - ((KP1_111140466) * (T2t)));
        R0[(rs[7])] = (((KP390180644) * (T2x)) + (KP1_961570560 * T2y));
    }
    {
        E T2D, T2J, T2I, T2K;
        {
            E T2z, T2C, T2G, T2H;
            T2z = T7 - Te;
            T2C = T2A - T2B;
            T2D = T2z + T2C;
            T2J = T2z - T2C;
            T2G = T2E + T2F;
            T2H = Tm - Tt;
            T2I = T2G - T2H;
            T2K = T2H + T2G;
        }
        R0[(rs[2])] = (((KP1_847759065) * (T2D)) + (KP765366864 * T2I));
        R0[(rs[14])] = ((KP765366864 * T2K) - ((KP1_847759065) * (T2J)));
        R0[(rs[10])] = ((KP1_847759065 * T2I) - ((KP765366864) * (T2D)));
        R0[(rs[6])] = (((KP765366864) * (T2J)) + (KP1_847759065 * T2K));
    }
    {
        E T19, T1n, T1m, T1o;
        {
            E TL, T18, T1c, T1l;
            TL = Tz + TK;
            T18 = TW + T17;
            T19 = TL + T18;
            T1n = TL - T18;
            T1c = T1a + T1b;
            T1l = T1f + T1k;
            T1m = T1c + T1l;
            T1o = T1c - T1l;
        }
        R1[0] = ((KP1_990369453 * T19) - ((KP196034280) * (T1m)));
        R1[(rs[12])] = ((KP1_268786568 * T1o) - ((KP1_546020906) * (T1n)));
        R1[(rs[8])] = -((((KP196034280) * (T19)) + (KP1_990369453 * T1m)));
        R1[(rs[4])] = (((KP1_268786568) * (T1n)) + (KP1_546020906 * T1o));
    }
    {
        E T1r, T1v, T1u, T1w;
        {
            E T1p, T1q, T1s, T1t;
            T1p = Tz - TK;
            T1q = T1b - T1a;
            T1r = T1p + T1q;
            T1v = T1p - T1q;
            T1s = T1f - T1k;
            T1t = TW - T17;
            T1u = T1s - T1t;
            T1w = T1t + T1s;
        }
        R1[(rs[2])] = (((KP1_763842528) * (T1r)) + (KP942793473 * T1u));
        R1[(rs[14])] = ((KP580569354 * T1w) - ((KP1_913880671) * (T1v)));
        R1[(rs[10])] = ((KP1_763842528 * T1u) - ((KP942793473) * (T1r)));
        R1[(rs[6])] = (((KP580569354) * (T1v)) + (KP1_913880671 * T1w));
    }
    {
        E T1T, T1X, T1W, T1Y;
        {
            E T1R, T1S, T1U, T1V;
            T1R = T1x + T1y;
            T1S = T1L + T1M;
            T1T = T1R - T1S;
            T1X = T1R + T1S;
            T1U = T1J + T1I;
            T1V = T1C - T1F;
            T1W = T1U - T1V;
            T1Y = T1V + T1U;
        }
        R1[(rs[3])] = (((KP1_546020906) * (T1T)) + (KP1_268786568 * T1W));
        R1[(rs[15])] = ((KP196034280 * T1Y) - ((KP1_990369453) * (T1X)));
        R1[(rs[11])] = ((KP1_546020906 * T1W) - ((KP1_268786568) * (T1T)));
        R1[(rs[7])] = (((KP196034280) * (T1X)) + (KP1_990369453 * T1Y));
    }
    {
        E T2f, T2p, T2o, T2q;
        {
            E T23, T2e, T2k, T2n;
            T23 = T1Z + T22;
            T2e = KP707106781 * (T28 + T2d);
            T2f = T23 + T2e;
            T2p = T23 - T2e;
            T2k = T2i - T2j;
            T2n = KP707106781 * (T2l + T2m);
            T2o = T2k - T2n;
            T2q = T2n + T2k;
        }
        R0[(rs[1])] = (((KP1_961570560) * (T2f)) + (KP390180644 * T2o));
        R0[(rs[13])] = ((KP1_111140466 * T2q) - ((KP1_662939224) * (T2p)));
        R0[(rs[9])] = ((KP1_961570560 * T2o) - ((KP390180644) * (T2f)));
        R0[(rs[5])] = (((KP1_111140466) * (T2p)) + (KP1_662939224 * T2q));
    }
    {
        E T1H, T1P, T1O, T1Q;
        {
            E T1z, T1G, T1K, T1N;
            T1z = T1x - T1y;
            T1G = T1C + T1F;
            T1H = T1z + T1G;
            T1P = T1z - T1G;
            T1K = T1I - T1J;
            T1N = T1L - T1M;
            T1O = T1K - T1N;
            T1Q = T1N + T1K;
        }
        R1[(rs[1])] = (((KP1_913880671) * (T1H)) + (KP580569354 * T1O));
        R1[(rs[13])] = ((KP942793473 * T1Q) - ((KP1_763842528) * (T1P)));
        R1[(rs[9])] = ((KP1_913880671 * T1O) - ((KP580569354) * (T1H)));
        R1[(rs[5])] = (((KP942793473) * (T1P)) + (KP1_763842528 * T1Q));
    }
}
}
