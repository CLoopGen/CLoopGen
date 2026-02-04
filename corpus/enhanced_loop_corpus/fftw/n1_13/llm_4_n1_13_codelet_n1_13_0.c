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
extern  E KP2_000000000;
extern  E KP083333333;
extern  E KP251768516;
extern  E KP075902986;
extern  E KP132983124;
extern  E KP258260390;
extern  E KP1_732050807;
extern  E KP300238635;
extern  E KP011599105;
extern  E KP156891391;
extern  E KP256247671;
extern  E KP174138601;
extern  E KP575140729;
extern  E KP503537032;
extern  E KP113854479;
extern  E KP265966249;
extern  E KP387390585;
extern  E KP866025403;
extern  E KP300462606;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T1q, Tt, Tu, To, T22, T20, T24, TF, TH, TA, TI, T1X, T25, T2a;
    E T2d, T18, T1n, T2k, T2n, T1l, T1r, T1f, T1o, T2h, T2m;
    T1 = ri[0];
    T1q = ii[0];

    if (T1 > KP500000000) {
        E Tf, Tp, Tb, TC, Tx, T6, TB, Tw, Ti, Tq, Tl, Tr, Tm, Ts, Td;
        E Te, Tc, Tn;
        Td = ri[(is[8])];
        Te = ri[(is[5])];
        Tf = Td + Te;
        Tp = Td - Te;
        {
            E T7, T8, T9, Ta;
            T7 = ri[(is[12])];
            T8 = ri[(is[10])];
            T9 = ri[(is[4])];
            Ta = T8 + T9;
            Tb = T7 + Ta;
            TC = T8 - T9;
            Tx = ((T7) - ((KP500000000) * (Ta)));
        }
        {
            E T2, T3, T4, T5;
            T2 = ri[(is[1])];
            T3 = ri[(is[3])];
            T4 = ri[(is[9])];
            T5 = T3 + T4;
            T6 = T2 + T5;
            TB = T3 - T4;
            Tw = ((T2) - ((KP500000000) * (T5)));
        }
        {
            E Tg, Th, Tj, Tk;
            Tg = ri[(is[11])];
            Th = ri[(is[6])];
            Ti = Tg + Th;
            Tq = Tg - Th;
            Tj = ri[(is[7])];
            Tk = ri[(is[2])];
            Tl = Tj + Tk;
            Tr = Tj - Tk;
        }
        Tm = Ti + Tl;
        Ts = Tq + Tr;
        Tt = Tp + Ts;
        Tu = T6 - Tb;
        Tc = T6 + Tb;
        Tn = Tf + Tm;
        To = Tc + Tn;
        T22 = KP300462606 * (Tc - Tn);
        {
            E T1Y, T1Z, TD, TE;
            T1Y = TB + TC;
            T1Z = Tq - Tr;
            T20 = T1Y - T1Z;
            T24 = T1Y + T1Z;
            TD = KP866025403 * (TB - TC);
            TE = ((Tp) - ((KP500000000) * (Ts)));
            TF = TD - TE;
            TH = TD + TE;
        }
        {
            E Ty, Tz, T1V, T1W;
            Ty = Tw - Tx;
            Tz = KP866025403 * (Ti - Tl);
            TA = Ty + Tz;
            TI = Ty - Tz;
            T1V = Tw + Tx;
            T1W = ((Tf) - ((KP500000000) * (Tm)));
            T1X = T1V - T1W;
            T25 = T1V + T1W;
        }

        {
            E TZ, T2b, TV, T1i, T1a, TQ, T1h, T19, T12, T1d, T15, T1c, T16, T2c, TX;
            E TY, TW, T17;
            TX = ii[(is[8])];
            TY = ii[(is[5])];
            TZ = TX + TY;
            T2b = TX - TY;
            {
                E TR, TS, TT, TU;
                TR = ii[(is[12])];
                TS = ii[(is[10])];
                TT = ii[(is[4])];
                TU = TS + TT;
                TV = ((TR) - ((KP500000000) * (TU)));
                T1i = TR + TU;
                T1a = TS - TT;
            }
            {
                E TM, TN, TO, TP;
                TM = ii[(is[1])];
                TN = ii[(is[3])];
                TO = ii[(is[9])];
                TP = TN + TO;
                TQ = ((TM) - ((KP500000000) * (TP)));
                T1h = TM + TP;
                T19 = TN - TO;
            }
            {
                E T10, T11, T13, T14;
                T10 = ii[(is[11])];
                T11 = ii[(is[6])];
                T12 = T10 + T11;
                T1d = T10 - T11;
                T13 = ii[(is[7])];
                T14 = ii[(is[2])];
                T15 = T13 + T14;
                T1c = T13 - T14;
            }
            T16 = T12 + T15;
            T2c = T1d + T1c;
            T2a = T1h - T1i;
            T2d = T2b + T2c;
            TW = TQ + TV;
            T17 = ((TZ) - ((KP500000000) * (T16)));
            T18 = TW - T17;
            T1n = TW + T17;
            {
                E T2i, T2j, T1j, T1k;
                T2i = TQ - TV;
                T2j = KP866025403 * (T15 - T12);
                T2k = T2i + T2j;
                T2n = T2i - T2j;
                T1j = T1h + T1i;
                T1k = TZ + T16;
                T1l = KP300462606 * (T1j - T1k);
                T1r = T1j + T1k;
            }
            {
                E T1b, T1e, T2f, T2g;
                T1b = T19 + T1a;
                T1e = T1c - T1d;
                T1f = T1b + T1e;
                T1o = T1e - T1b;
                T2f = ((T2b) - ((KP500000000) * (T2c)));
                T2g = KP866025403 * (T1a - T19);
                T2h = T2f - T2g;
                T2m = T2g + T2f;
            }
        }
        ro[0] = T1 + To;
        io[0] = T1q + T1r;
        {
            E T1D, T1N, T1y, T1x, T1E, T1O, Tv, TK, T1J, T1Q, T1m, T1R, T1t, T1I, TG;
            E TJ;
            {
                E T1B, T1C, T1v, T1w;
                T1B = (((KP387390585) * (T1f)) + (KP265966249 * T18));
                T1C = (((KP113854479) * (T1o)) + (KP503537032 * T1n));
                T1D = T1B + T1C;
                T1N = T1C - T1B;
                T1y = (((KP575140729) * (Tu)) + (KP174138601 * Tt));
                T1v = ((KP256247671 * TI) - ((KP156891391) * (TH)));
                T1w = (((KP011599105) * (TF)) + (KP300238635 * TA));
                T1x = T1v - T1w;
                T1E = T1y + T1x;
                T1O = KP1_732050807 * (T1v + T1w);
            }
            Tv = ((KP575140729 * Tt) - ((KP174138601) * (Tu)));
            TG = ((KP011599105 * TA) - ((KP300238635) * (TF)));
            TJ = (((KP256247671) * (TH)) + (KP156891391 * TI));
            TK = TG - TJ;
            T1J = KP1_732050807 * (TJ + TG);
            T1Q = Tv - TK;
            {
                E T1g, T1H, T1p, T1s, T1G;
                T1g = ((KP258260390 * T18) - ((KP132983124) * (T1f)));
                T1H = T1l - T1g;
                T1p = ((KP075902986 * T1n) - ((KP251768516) * (T1o)));
                T1s = ((T1q) - ((KP083333333) * (T1r)));
                T1G = T1s - T1p;
                T1m = (((KP2_000000000) * (T1g)) + (T1l));
                T1R = T1H + T1G;
                T1t = (((KP2_000000000) * (T1p)) + (T1s));
                T1I = T1G - T1H;
            }
            {
                E TL, T1u, T1P, T1S;
                TL = (((KP2_000000000) * (TK)) + (Tv));
                T1u = T1m + T1t;
                io[(os[1])] = TL + T1u;
                io[(os[12])] = T1u - TL;
                {
                    E T1z, T1A, T1T, T1U;
                    T1z = (((KP2_000000000) * (T1x)) - (T1y));
                    T1A = T1t - T1m;
                    io[(os[5])] = T1z + T1A;
                    io[(os[8])] = T1A - T1z;
                    T1T = T1R - T1Q;
                    T1U = T1O + T1N;
                    io[(os[4])] = T1T - T1U;
                    io[(os[10])] = T1U + T1T;
                }
                T1P = T1N - T1O;
                T1S = T1Q + T1R;
                io[(os[3])] = T1P + T1S;
                io[(os[9])] = T1S - T1P;
                {
                    E T1L, T1M, T1F, T1K;
                    T1L = T1J + T1I;
                    T1M = T1E + T1D;
                    io[(os[6])] = T1L - T1M;
                    io[(os[11])] = T1M + T1L;
                    T1F = T1D - T1E;
                    T1K = T1I - T1J;
                    io[(os[2])] = T1F + T1K;
                    io[(os[7])] = T1K - T1F;
                }
            }
        }
        {
            E T2y, T2I, T2J, T2K, T2B, T2L, T2e, T2p, T2u, T2G, T23, T2F, T28, T2t, T2l;
            E T2o;
            {
                E T2w, T2x, T2z, T2A;
                T2w = (((KP387390585) * (T20)) + (KP265966249 * T1X));
                T2x = ((KP113854479 * T24) - ((KP503537032) * (T25)));
                T2y = T2w + T2x;
                T2I = T2w - T2x;
                T2J = (((KP575140729) * (T2a)) + (KP174138601 * T2d));
                T2z = ((KP011599105 * T2m) - ((KP300238635) * (T2n)));
                T2A = ((KP256247671 * T2k) - ((KP156891391) * (T2h)));
                T2K = T2z + T2A;
                T2B = KP1_732050807 * (T2z - T2A);
                T2L = T2J + T2K;
            }
            T2e = ((KP174138601 * T2a) - ((KP575140729) * (T2d)));
            T2l = (((KP256247671) * (T2h)) + (KP156891391 * T2k));
            T2o = (((KP300238635) * (T2m)) + (KP011599105 * T2n));
            T2p = T2l - T2o;
            T2u = T2e - T2p;
            T2G = KP1_732050807 * (T2o + T2l);
            {
                E T21, T2r, T26, T27, T2s;
                T21 = ((KP258260390 * T1X) - ((KP132983124) * (T20)));
                T2r = T22 - T21;
                T26 = (((KP251768516) * (T24)) + (KP075902986 * T25));
                T27 = ((T1) - ((KP083333333) * (To)));
                T2s = T27 - T26;
                T23 = (((KP2_000000000) * (T21)) + (T22));
                T2F = T2s - T2r;
                T28 = (((KP2_000000000) * (T26)) + (T27));
                T2t = T2r + T2s;
            }
            {
                E T29, T2q, T2N, T2O;
                T29 = T23 + T28;
                T2q = (((KP2_000000000) * (T2p)) + (T2e));
                ro[(os[12])] = T29 - T2q;
                ro[(os[1])] = T29 + T2q;
                {
                    E T2v, T2C, T2P, T2Q;
                    T2v = T2t - T2u;
                    T2C = T2y - T2B;
                    ro[(os[10])] = T2v - T2C;
                    ro[(os[4])] = T2v + T2C;
                    T2P = T28 - T23;
                    T2Q = (((KP2_000000000) * (T2K)) - (T2J));
                    ro[(os[5])] = T2P - T2Q;
                    ro[(os[8])] = T2P + T2Q;
                }
                T2N = T2F - T2G;
                T2O = T2L - T2I;
                ro[(os[11])] = T2N - T2O;
                ro[(os[6])] = T2N + T2O;
                {
                    E T2H, T2M, T2D, T2E;
                    T2H = T2F + T2G;
                    T2M = T2I + T2L;
                    ro[(os[7])] = T2H - T2M;
                    ro[(os[2])] = T2H + T2M;
                    T2D = T2t + T2u;
                    T2E = T2y + T2B;
                    ro[(os[3])] = T2D - T2E;
                    ro[(os[9])] = T2D + T2E;
                }
            }
        }
    } else {
        ro[0] = T1;
        io[0] = T1q;
        for (INT j = 1; j < 13; ++j) {
            ro[j * ovs] = 0.0;
            io[j * ovs] = 0.0;
        }
    }
}
}
