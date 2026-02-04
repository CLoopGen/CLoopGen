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
extern  E KP1_996053456;
extern  E KP062790519;
extern  E KP125581039;
extern  E KP998026728;
extern  E KP1_369094211;
extern  E KP728968627;
extern  E KP963507348;
extern  E KP876306680;
extern  E KP497379774;
extern  E KP968583161;
extern  E KP1_457937254;
extern  E KP684547105;
extern  E KP1_752613360;
extern  E KP481753674;
extern  E KP1_937166322;
extern  E KP248689887;
extern  E KP992114701;
extern  E KP250666467;
extern  E KP1_809654104;
extern  E KP425779291;
extern  E KP1_541026485;
extern  E KP637423989;
extern  E KP1_688655851;
extern  E KP535826794;
extern  E KP851558583;
extern  E KP904827052;
extern  E KP1_984229402;
extern  E KP125333233;
extern  E KP1_274847979;
extern  E KP770513242;
extern  E KP844327925;
extern  E KP1_071653589;
extern  E KP293892626;
extern  E KP475528258;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E TE, TR, T2i, T1z, TL, TS, TB, T2d, T1l, T1i, T2c, T9, T23, TZ, TW;
    E T22, Ti, T26, T16, T13, T25, Ts, T2a, T1e, T1b, T29, TP, TQ;

    // Early exit if a computed value meets threshold (introduced control dependency)
    TE = R0[0];
    if (TE < 0.0) continue;

    {
        E TK, T1y, TH, T1x;
        {
            E TI, TJ, TF, TG;
            TI = R0[(rs[10])];
            TJ = R1[(rs[2])];
            TK = TI - TJ;
            T1y = TI + TJ;
            TF = R0[(rs[5])];
            TG = R1[(rs[7])];
            TH = TF - TG;
            T1x = TF + TG;
        }
        TR = KP559016994 * (TH - TK);
        T2i = ((KP951056516 * T1y) - ((KP587785252) * (T1x)));
        T1z = (((KP951056516) * (T1x)) + (KP587785252 * T1y));
        TL = TH + TK;
        TS = ((TE) - ((KP250000000) * (TL)));
    }
    {
        E Tt, Tw, Tz, TA, T1k, T1j, T1g, T1h;
        Tt = R0[(rs[3])];
        {
            E Tu, Tv, Tx, Ty;
            Tu = R0[(rs[8])];
            Tv = R1[(rs[10])];
            Tw = Tu - Tv;
            Tx = R1[0];
            Ty = R1[(rs[5])];
            Tz = Tx + Ty;
            TA = Tw - Tz;
            T1k = Ty - Tx;
            T1j = Tu + Tv;
        }
        TB = Tt + TA;
        T2d = ((KP475528258 * T1k) - ((KP293892626) * (T1j)));
        T1l = (((KP475528258) * (T1j)) + (KP293892626 * T1k));
        T1g = ((Tt) - ((KP250000000) * (TA)));
        T1h = KP559016994 * (Tw + Tz);
        T1i = T1g + T1h;
        T2c = T1g - T1h;
    }
    {
        E T1, T4, T7, T8, TY, TX, TU, TV;
        T1 = R0[(rs[1])];
        {
            E T2, T3, T5, T6;
            T2 = R0[(rs[6])];
            T3 = R1[(rs[8])];
            T4 = T2 - T3;
            T5 = R0[(rs[11])];
            T6 = R1[(rs[3])];
            T7 = T5 - T6;
            T8 = T4 + T7;
            TY = T5 + T6;
            TX = T2 + T3;
        }
        T9 = T1 + T8;
        T23 = ((KP475528258 * TY) - ((KP293892626) * (TX)));
        TZ = (((KP475528258) * (TX)) + (KP293892626 * TY));
        TU = KP559016994 * (T4 - T7);
        TV = ((T1) - ((KP250000000) * (T8)));
        TW = TU + TV;
        T22 = TV - TU;
    }
    {
        E Ta, Td, Tg, Th, T15, T14, T11, T12;
        Ta = R0[(rs[4])];
        {
            E Tb, Tc, Te, Tf;
            Tb = R0[(rs[9])];
            Tc = R1[(rs[11])];
            Td = Tb - Tc;
            Te = R1[(rs[1])];
            Tf = R1[(rs[6])];
            Tg = Te + Tf;
            Th = Td - Tg;
            T15 = Tf - Te;
            T14 = Tb + Tc;
        }
        Ti = Ta + Th;
        T26 = ((KP475528258 * T15) - ((KP293892626) * (T14)));
        T16 = (((KP475528258) * (T14)) + (KP293892626 * T15));
        T11 = ((Ta) - ((KP250000000) * (Th)));
        T12 = KP559016994 * (Td + Tg);
        T13 = T11 + T12;
        T25 = T11 - T12;
    }
    {
        E Tk, Tn, Tq, Tr, T1d, T1c, T19, T1a;
        Tk = R0[(rs[2])];
        {
            E Tl, Tm, To, Tp;
            Tl = R0[(rs[7])];
            Tm = R1[(rs[9])];
            Tn = Tl - Tm;
            To = R0[(rs[12])];
            Tp = R1[(rs[4])];
            Tq = To - Tp;
            Tr = Tn + Tq;
            T1d = To + Tp;
            T1c = Tl + Tm;
        }
        Ts = Tk + Tr;
        T2a = ((KP475528258 * T1d) - ((KP293892626) * (T1c)));
        T1e = (((KP475528258) * (T1c)) + (KP293892626 * T1d));
        T19 = KP559016994 * (Tn - Tq);
        T1a = ((Tk) - ((KP250000000) * (Tr)));
        T1b = T19 + T1a;
        T29 = T1a - T19;
    }
    TP = TB - Ts;
    TQ = T9 - Ti;
    Ci[(csi[2])] = ((KP587785252 * TP) - ((KP951056516) * (TQ)));
    Ci[(csi[7])] = (((KP587785252) * (TQ)) + (KP951056516 * TP));
    {
        E TM, TD, TN, Tj, TC, TO;
        TM = TE + TL;
        Tj = T9 + Ti;
        TC = Ts + TB;
        TD = KP559016994 * (Tj - TC);
        TN = Tj + TC;
        Cr[(csr[12])] = TM + TN;
        TO = ((TM) - ((KP250000000) * (TN)));
        Cr[(csr[2])] = TD + TO;
        Cr[(csr[7])] = TO - TD;
    }
    {
        E TT, T1J, T1Y, T1U, T1X, T1P, T1V, T1M, T1W, T1A, T1B, T1r, T1C, T1v, T18;
        E T1n, T1o, T1G, T1D;
        TT = TR + TS;
        {
            E T1H, T1I, T1S, T1T;
            T1H = ((KP1_071653589 * TZ) - ((KP844327925) * (TW)));
            T1I = ((KP770513242 * T13) - ((KP1_274847979) * (T16)));
            T1J = T1H - T1I;
            T1Y = T1H + T1I;
            T1S = (((KP125333233) * (T1i)) + (KP1_984229402 * T1l));
            T1T = (((KP904827052) * (T1b)) + (KP851558583 * T1e));
            T1U = T1S - T1T;
            T1X = T1T + T1S;
        }
        {
            E T1N, T1O, T1K, T1L;
            T1N = (((KP535826794) * (TW)) + (KP1_688655851 * TZ));
            T1O = (((KP637423989) * (T13)) + (KP1_541026485 * T16));
            T1P = T1N - T1O;
            T1V = T1N + T1O;
            T1K = ((KP425779291 * T1b) - ((KP1_809654104) * (T1e)));
            T1L = ((KP250666467 * T1l) - ((KP992114701) * (T1i)));
            T1M = T1K - T1L;
            T1W = T1K + T1L;
        }
        {
            E T1p, T1q, T1t, T1u;
            T1p = (((KP844327925) * (T13)) + (KP1_071653589 * T16));
            T1q = (((KP248689887) * (TW)) + (KP1_937166322 * TZ));
            T1A = T1q + T1p;
            T1t = (((KP481753674) * (T1b)) + (KP1_752613360 * T1e));
            T1u = (((KP684547105) * (T1i)) + (KP1_457937254 * T1l));
            T1B = T1t + T1u;
            T1r = T1p - T1q;
            T1C = T1A + T1B;
            T1v = T1t - T1u;
        }
        {
            E T10, T17, T1f, T1m;
            T10 = ((KP968583161 * TW) - ((KP497379774) * (TZ)));
            T17 = ((KP535826794 * T13) - ((KP1_688655851) * (T16)));
            T18 = T10 + T17;
            T1f = ((KP876306680 * T1b) - ((KP963507348) * (T1e)));
            T1m = ((KP728968627 * T1i) - ((KP1_369094211) * (T1l)));
            T1n = T1f + T1m;
            T1o = T18 + T1n;
            T1G = T10 - T17;
            T1D = T1f - T1m;
        }
        {
            E T1R, T1Q, T20, T1Z;
            Cr[0] = TT + T1o;
            Ci[0] = -(T1z + T1C);
            T1R = KP559016994 * (T1P + T1M);
            T1Q = (((KP250000000) * (T1M - T1P)) + (TT));
            Cr[(csr[4])] = (((KP951056516) * (T1J)) + (T1Q)) + (((KP587785252) * (T1U)) + (T1R));
            Cr[(csr[9])] = (((KP951056516) * (T1U)) + (T1Q)) + (-(((KP587785252) * (T1J)) + (T1R)));
            T20 = KP559016994 * (T1Y + T1X);
            T1Z = (((KP250000000) * (T1X - T1Y)) + (T1z));
            Ci[(csi[9])] = (((KP587785252) * (T1V)) + (KP951056516 * T1W)) + T1Z - T20;
            Ci[(csi[4])] = (((KP587785252) * (T1W)) + (T1Z)) + ((T20) - ((KP951056516) * (T1V)));
            {
                E T1E, T1F, T1s, T1w;
                T1E = (((KP250000000) * (T1C)) - (T1z));
                T1F = KP559016994 * (T1B - T1A);
                Ci[(csi[5])] = (((KP951056516) * (T1D)) + (T1E)) + (-(((KP587785252) * (T1G)) + (T1F)));
                Ci[(csi[10])] = (((KP951056516) * (T1G)) + (KP587785252 * T1D)) + T1E + T1F;
                T1s = ((TT) - ((KP250000000) * (T1o)));
                T1w = KP559016994 * (T18 - T1n);
                Cr[(csr[5])] = (((KP587785252) * (T1r)) + (T1s)) + (((KP951056516) * (T1v)) - (T1w));
                Cr[(csr[10])] = T1w + (((KP587785252) * (T1v)) + (T1s)) - (KP951056516 * T1r);
            }
        }
    }
    {
        E T21, T2z, T2L, T2K, T2M, T2F, T2P, T2C, T2Q, T2l, T2o, T2p, T2w, T2u, T28;
        E T2f, T2g, T2s, T2h;
        T21 = TS - TR;
        {
            E T2x, T2y, T2I, T2J;
            T2x = ((KP1_071653589 * T2a) - ((KP844327925) * (T29)));
            T2y = ((KP998026728 * T2c) - ((KP125581039) * (T2d)));
            T2z = T2x + T2y;
            T2L = T2y - T2x;
            T2I = ((KP1_752613360 * T23) - ((KP481753674) * (T22)));
            T2J = (((KP904827052) * (T25)) + (KP851558583 * T26));
            T2K = T2I + T2J;
            T2M = T2I - T2J;
        }
        {
            E T2D, T2E, T2A, T2B;
            T2D = (((KP535826794) * (T29)) + (KP1_688655851 * T2a));
            T2E = (((KP062790519) * (T2c)) + (KP1_996053456 * T2d));
            T2F = T2D + T2E;
            T2P = T2E - T2D;
            T2A = (((KP876306680) * (T22)) + (KP963507348 * T23));
            T2B = ((KP1_809654104 * T26) - ((KP425779291) * (T25)));
            T2C = T2A + T2B;
            T2Q = T2A - T2B;
        }
        {
            E T2j, T2k, T2m, T2n;
            T2j = ((KP1_984229402 * T26) - ((KP125333233) * (T25)));
            T2k = (((KP684547105) * (T22)) + (KP1_457937254 * T23));
            T2l = T2j - T2k;
            T2m = ((KP1_274847979 * T2d) - ((KP770513242) * (T2c)));
            T2n = (((KP998026728) * (T29)) + (KP125581039 * T2a));
            T2o = T2m - T2n;
            T2p = T2l + T2o;
            T2w = T2k + T2j;
            T2u = T2n + T2m;
        }
        {
            E T24, T27, T2b, T2e;
            T24 = ((KP728968627 * T22) - ((KP1_369094211) * (T23)));
            T27 = (((KP992114701) * (T25)) + (KP250666467 * T26));
            T28 = T24 - T27;
            T2b = ((KP062790519 * T29) - ((KP1_996053456) * (T2a)));
            T2e = (((KP637423989) * (T2c)) + (KP1_541026485 * T2d));
            T2f = T2b - T2e;
            T2g = T28 + T2f;
            T2s = T24 + T27;
            T2h = T2b + T2e;
        }
        {
            E T2H, T2G, T2O, T2N;
            Cr[(csr[1])] = T21 + T2g;
            Ci[(csi[1])] = T2p - T2i;
            T2H = KP559016994 * (T2C - T2F);
            T2G = ((T21) - ((KP250000000) * (T2C + T2F)));
            Cr[(csr[8])] = (((KP951056516) * (T2z)) + (T2G)) + (-(((KP587785252) * (T2K)) + (T2H)));
            Cr[(csr[3])] = (((KP951056516) * (T2K)) + (KP587785252 * T2z)) + T2G + T2H;
            T2O = KP559016994 * (T2M + T2L);
            T2N = (((KP250000000) * (T2L - T2M)) + (T2i));
            Ci[(csi[3])] = T2N + (((KP587785252) * (T2P)) + (T2O)) - (KP951056516 * T2Q);
            Ci[(csi[8])] = (((KP587785252) * (T2Q)) + (T2N)) + (((KP951056516) * (T2P)) - (T2O));
            {
                E T2t, T2v, T2q, T2r;
                T2t = ((T21) - ((KP250000000) * (T2g)));
                T2v = KP559016994 * (T28 - T2f);
                Cr[(csr[6])] = (((KP951056516) * (T2u)) + (T2t)) + (-(((KP587785252) * (T2w)) + (T2v)));
                Cr[(csr[11])] = (((KP951056516) * (T2w)) + (T2v)) + (((KP587785252) * (T2u)) + (T2t));
                T2q = KP250000000 * T2p;
                T2r = KP559016994 * (T2l - T2o);
                Ci[(csi[6])] = (((KP951056516) * (T2h)) - (T2i + T2q)) + (-(((KP587785252) * (T2s)) + (T2r)));
                Ci[(csi[11])] = (((KP951056516) * (T2s)) + (KP587785252 * T2h)) + T2r - (T2i + T2q);
            }
        }
    }
}
}
