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
extern  E KP998026728;
extern  E KP125581039;
extern  E KP1_996053456;
extern  E KP062790519;
extern  E KP809016994;
extern  E KP309016994;
extern  E KP1_369094211;
extern  E KP728968627;
extern  E KP963507348;
extern  E KP876306680;
extern  E KP497379774;
extern  E KP968583161;
extern  E KP684547105;
extern  E KP1_457937254;
extern  E KP481753674;
extern  E KP1_752613360;
extern  E KP248689887;
extern  E KP1_937166322;
extern  E KP992114701;
extern  E KP250666467;
extern  E KP425779291;
extern  E KP1_809654104;
extern  E KP1_274847979;
extern  E KP770513242;
extern  E KP844327925;
extern  E KP1_071653589;
extern  E KP125333233;
extern  E KP1_984229402;
extern  E KP904827052;
extern  E KP851558583;
extern  E KP637423989;
extern  E KP1_541026485;
extern  E KP535826794;
extern  E KP1_688655851;
extern  E KP293892626;
extern  E KP475528258;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T8, T1j, T1V, T1l, T7, T9, Ta, T12, T2u, T1O, T19, T1P, Ti, T2r, T1K;
    E Tp, T1L, Tx, T2q, T1H, TE, T1I, TN, T2t, T1R, TU, T1S, T6, T1k, T3;
    E T2s, T2v;

    if (!(i & 1)) continue;

    T8 = R0[0];
    {
        E T4, T5, T1, T2;
        T4 = R0[(rs[5])];
        T5 = R1[(rs[7])];
        T6 = T4 + T5;
        T1k = T4 - T5;
        T1 = R1[(rs[2])];
        T2 = R0[(rs[10])];
        T3 = T1 + T2;
        T1j = T1 - T2;
    }
    T1V = KP951056516 * T1k;
    T1l = (((KP951056516) * (T1j)) + (KP587785252 * T1k));
    T7 = KP559016994 * (T3 - T6);
    T9 = T3 + T6;
    Ta = ((T8) - ((KP250000000) * (T9)));
    {
        E T16, T13, T14, TY, T17, T11, T15, T18;
        T16 = R1[(rs[1])];
        {
            E TW, TX, TZ, T10;
            TW = R0[(rs[4])];
            TX = R1[(rs[11])];
            T13 = TW + TX;
            TZ = R1[(rs[6])];
            T10 = R0[(rs[9])];
            T14 = TZ + T10;
            TY = TW - TX;
            T17 = T13 + T14;
            T11 = TZ - T10;
        }
        T12 = (((KP475528258) * (TY)) + (KP293892626 * T11));
        T2u = T16 + T17;
        T1O = ((KP475528258 * T11) - ((KP293892626) * (TY)));
        T15 = KP559016994 * (T13 - T14);
        T18 = ((T16) - ((KP250000000) * (T17)));
        T19 = T15 + T18;
        T1P = T18 - T15;
    }
    {
        E Tm, Tj, Tk, Te, Tn, Th, Tl, To;
        Tm = R1[0];
        {
            E Tc, Td, Tf, Tg;
            Tc = R0[(rs[3])];
            Td = R1[(rs[10])];
            Tj = Tc + Td;
            Tf = R1[(rs[5])];
            Tg = R0[(rs[8])];
            Tk = Tf + Tg;
            Te = Tc - Td;
            Tn = Tj + Tk;
            Th = Tf - Tg;
        }
        Ti = (((KP475528258) * (Te)) + (KP293892626 * Th));
        T2r = Tm + Tn;
        T1K = ((KP475528258 * Th) - ((KP293892626) * (Te)));
        Tl = KP559016994 * (Tj - Tk);
        To = ((Tm) - ((KP250000000) * (Tn)));
        Tp = Tl + To;
        T1L = To - Tl;
    }
    {
        E TB, Ty, Tz, Tt, TC, Tw, TA, TD;
        TB = R0[(rs[2])];
        {
            E Tr, Ts, Tu, Tv;
            Tr = R1[(rs[4])];
            Ts = R0[(rs[12])];
            Ty = Tr + Ts;
            Tu = R0[(rs[7])];
            Tv = R1[(rs[9])];
            Tz = Tu + Tv;
            Tt = Tr - Ts;
            TC = Ty + Tz;
            Tw = Tu - Tv;
        }
        Tx = (((KP475528258) * (Tt)) + (KP293892626 * Tw));
        T2q = TB + TC;
        T1H = ((KP475528258 * Tw) - ((KP293892626) * (Tt)));
        TA = KP559016994 * (Ty - Tz);
        TD = ((TB) - ((KP250000000) * (TC)));
        TE = TA + TD;
        T1I = TD - TA;
    }
    {
        E TR, TO, TP, TJ, TS, TM, TQ, TT;
        TR = R0[(rs[1])];
        {
            E TH, TI, TK, TL;
            TH = R1[(rs[3])];
            TI = R0[(rs[11])];
            TO = TH + TI;
            TK = R0[(rs[6])];
            TL = R1[(rs[8])];
            TP = TK + TL;
            TJ = TH - TI;
            TS = TO + TP;
            TM = TK - TL;
        }
        TN = (((KP475528258) * (TJ)) + (KP293892626 * TM));
        T2t = TR + TS;
        T1R = ((KP475528258 * TM) - ((KP293892626) * (TJ)));
        TQ = KP559016994 * (TO - TP);
        TT = ((TR) - ((KP250000000) * (TS)));
        TU = TQ + TT;
        T1S = TT - TQ;
    }
    T2s = T2q - T2r;
    T2v = T2t - T2u;
    Ci[(csi[5])] = ((KP951056516 * T2s) - ((KP587785252) * (T2v)));
    Ci[(csi[10])] = (((KP587785252) * (T2s)) + (KP951056516 * T2v));
    {
        E T2z, T2y, T2A, T2w, T2x, T2B;
        T2z = T8 + T9;
        T2w = T2r + T2q;
        T2x = T2t + T2u;
        T2y = KP559016994 * (T2w - T2x);
        T2A = T2w + T2x;
        Cr[0] = T2z + T2A;
        T2B = ((T2z) - ((KP250000000) * (T2A)));
        Cr[(csr[5])] = T2y + T2B;
        Cr[(csr[10])] = T2B - T2y;
    }
    {
        E Tb, Tq, TF, TG, T1E, T1F, T1G, T1B, T1C, T1D, TV, T1a, T1b, T1o, T1r;
        E T1s, T1z, T1x, T1e, T1h, T1i, T1u, T1t;
        Tb = T7 + Ta;
        Tq = (((KP1_688655851) * (Ti)) + (KP535826794 * Tp));
        TF = (((KP1_541026485) * (Tx)) + (KP637423989 * TE));
        TG = Tq - TF;
        T1E = (((KP851558583) * (TN)) + (KP904827052 * TU));
        T1F = (((KP1_984229402) * (T12)) + (KP125333233 * T19));
        T1G = T1E + T1F;
        T1B = ((KP1_071653589 * Ti) - ((KP844327925) * (Tp)));
        T1C = ((KP770513242 * TE) - ((KP1_274847979) * (Tx)));
        T1D = T1B + T1C;
        TV = ((KP1_809654104 * TN) - ((KP425779291) * (TU)));
        T1a = ((KP250666467 * T12) - ((KP992114701) * (T19)));
        T1b = TV + T1a;
        {
            E T1m, T1n, T1p, T1q;
            T1m = (((KP1_937166322) * (Ti)) + (KP248689887 * Tp));
            T1n = (((KP1_071653589) * (Tx)) + (KP844327925 * TE));
            T1o = T1m + T1n;
            T1p = (((KP1_752613360) * (TN)) + (KP481753674 * TU));
            T1q = (((KP1_457937254) * (T12)) + (KP684547105 * T19));
            T1r = T1p + T1q;
            T1s = T1o + T1r;
            T1z = T1q - T1p;
            T1x = T1n - T1m;
        }
        {
            E T1c, T1d, T1f, T1g;
            T1c = ((KP968583161 * Tp) - ((KP497379774) * (Ti)));
            T1d = ((KP535826794 * TE) - ((KP1_688655851) * (Tx)));
            T1e = T1c + T1d;
            T1f = ((KP876306680 * TU) - ((KP963507348) * (TN)));
            T1g = ((KP728968627 * T19) - ((KP1_369094211) * (T12)));
            T1h = T1f + T1g;
            T1i = T1e + T1h;
            T1u = T1f - T1g;
            T1t = T1d - T1c;
        }
        Cr[(csr[1])] = Tb + T1i;
        Ci[(csi[1])] = -(T1l + T1s);
        Cr[(csr[4])] = Tb + TG + T1b;
        Ci[(csi[4])] = T1l + T1D - T1G;
        Ci[(csi[9])] = (((KP309016994) * (T1D)) + (T1l)) + (((KP587785252) * (T1a - TV)) + (KP809016994 * T1G)) - (KP951056516 * (Tq + TF));
        Cr[(csr[9])] = (((KP309016994) * (TG)) + (Tb)) + (((KP951056516) * (T1B - T1C)) + (KP587785252 * (T1F - T1E))) - (KP809016994 * T1b);
        {
            E T1v, T1w, T1y, T1A;
            T1v = (((KP250000000) * (T1s)) - (T1l));
            T1w = KP559016994 * (T1r - T1o);
            Ci[(csi[11])] = (((KP587785252) * (T1t)) + (KP951056516 * T1u)) + T1v - T1w;
            Ci[(csi[6])] = (((KP951056516) * (T1t)) + (T1v)) + ((T1w) - ((KP587785252) * (T1u)));
            T1y = ((Tb) - ((KP250000000) * (T1i)));
            T1A = KP559016994 * (T1e - T1h);
            Cr[(csr[11])] = (((KP587785252) * (T1x)) + (T1y)) + (-(((KP951056516) * (T1z)) + (T1A)));
            Cr[(csr[6])] = (((KP951056516) * (T1x)) + (T1A)) + (((KP587785252) * (T1z)) + (T1y));
        }
    }
    {
        E T1W, T1X, T1J, T1M, T1N, T21, T22, T23, T1Q, T1T, T1U, T1Y, T1Z, T20, T26;
        E T29, T2a, T2k, T2j, T2l, T2m, T2d, T2o, T2i;
        T1W = ((T1V) - ((KP587785252) * (T1j)));
        T1X = Ta - T7;
        T1J = ((KP1_984229402 * T1H) - ((KP125333233) * (T1I)));
        T1M = (((KP1_457937254) * (T1K)) + (KP684547105 * T1L));
        T1N = T1J - T1M;
        T21 = ((KP062790519 * T1S) - ((KP1_996053456) * (T1R)));
        T22 = (((KP1_541026485) * (T1O)) + (KP637423989 * T1P));
        T23 = T21 - T22;
        T1Q = ((KP1_274847979 * T1O) - ((KP770513242) * (T1P)));
        T1T = (((KP125581039) * (T1R)) + (KP998026728 * T1S));
        T1U = T1Q - T1T;
        T1Y = ((KP728968627 * T1L) - ((KP1_369094211) * (T1K)));
        T1Z = (((KP250666467) * (T1H)) + (KP992114701 * T1I));
        T20 = T1Y - T1Z;
        {
            E T24, T25, T27, T28;
            T24 = ((KP1_752613360 * T1K) - ((KP481753674) * (T1L)));
            T25 = (((KP851558583) * (T1H)) + (KP904827052 * T1I));
            T26 = T24 - T25;
            T27 = ((KP1_071653589 * T1R) - ((KP844327925) * (T1S)));
            T28 = ((KP125581039 * T1O) - ((KP998026728) * (T1P)));
            T29 = T27 + T28;
            T2a = T26 + T29;
            T2k = T27 - T28;
            T2j = T24 + T25;
        }
        {
            E T2b, T2c, T2g, T2h;
            T2b = ((KP1_809654104 * T1H) - ((KP425779291) * (T1I)));
            T2c = (((KP963507348) * (T1K)) + (KP876306680 * T1L));
            T2l = T2c + T2b;
            T2g = (((KP1_688655851) * (T1R)) + (KP535826794 * T1S));
            T2h = (((KP1_996053456) * (T1O)) + (KP062790519 * T1P));
            T2m = T2g + T2h;
            T2d = T2b - T2c;
            T2o = T2l + T2m;
            T2i = T2g - T2h;
        }
        Ci[(csi[2])] = T1W + T2a;
        Cr[(csr[2])] = T1X + T2o;
        Ci[(csi[3])] = T1N + T1U - T1W;
        Cr[(csr[3])] = T1X + T20 + T23;
        Cr[(csr[8])] = (((KP309016994) * (T20)) + (T1X)) + (-(((KP809016994) * (T23)) + (KP587785252 * (T1T + T1Q)))) - (KP951056516 * (T1M + T1J));
        Ci[(csi[8])] = ((KP309016994 * T1N) - ((KP587785252) * (T21 + T22))) + (-(((KP809016994) * (T1U)) + (KP951056516 * (T1Y + T1Z)))) - T1W;
        {
            E T2e, T2f, T2n, T2p;
            T2e = KP559016994 * (T26 - T29);
            T2f = ((T1W) - ((KP250000000) * (T2a)));
            Ci[(csi[7])] = (((KP951056516) * (T2d)) + (T2e)) + ((T2f) - ((KP587785252) * (T2i)));
            Ci[(csi[12])] = (((KP587785252) * (T2d)) + (T2f)) + (((KP951056516) * (T2i)) - (T2e));
            T2n = KP559016994 * (T2l - T2m);
            T2p = ((T1X) - ((KP250000000) * (T2o)));
            Cr[(csr[7])] = (((KP951056516) * (T2j)) + (KP587785252 * T2k)) + T2n + T2p;
            Cr[(csr[12])] = (((KP587785252) * (T2j)) + (T2p)) + (-(((KP951056516) * (T2k)) + (T2n)));
        }
    }
}
}
