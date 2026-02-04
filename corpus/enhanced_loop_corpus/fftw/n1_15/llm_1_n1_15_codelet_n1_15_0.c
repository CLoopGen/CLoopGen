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
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T5, T2l, Tx, TV, T1C, T20, Tl, Tq, Tr, TN, TS, TT, T2c, T2d, T2n;
    E T1O, T1P, T22, T1l, T1q, T1w, TZ, T10, T11, Ta, Tf, Tg, TC, TH, TI;
    E T2f, T2g, T2m, T1R, T1S, T21, T1a, T1f, T1v, TW, TX, TY;

    for (int factor = 0; factor < 2; ++factor) {
        if (factor == 0) {
            {
                E T1, T1z, T4, T1y, Tw, T1A, Tt, T1B;
                T1 = ri[0];
                T1z = ii[0];
                {
                    E T2, T3, Tu, Tv;
                    T2 = ri[(is[5])];
                    T3 = ri[(is[10])];
                    T4 = T2 + T3;
                    T1y = KP866025403 * (T3 - T2);
                    Tu = ii[(is[5])];
                    Tv = ii[(is[10])];
                    Tw = KP866025403 * (Tu - Tv);
                    T1A = Tu + Tv;
                }
                T5 = T1 + T4;
                T2l = T1z + T1A;
                Tt = ((T1) - ((KP500000000) * (T4)));
                Tx = Tt - Tw;
                TV = Tt + Tw;
                T1B = ((T1z) - ((KP500000000) * (T1A)));
                T1C = T1y + T1B;
                T20 = T1B - T1y;
            }
            {
                E Th, Tk, TJ, T1h, T1i, T1j, TM, T1k, Tm, Tp, TO, T1m, T1n, T1o, TR;
                E T1p;
                {
                    E Ti, Tj, TK, TL;
                    Th = ri[(is[6])];
                    Ti = ri[(is[11])];
                    Tj = ri[(is[1])];
                    Tk = Ti + Tj;
                    TJ = ((Th) - ((KP500000000) * (Tk)));
                    T1h = KP866025403 * (Tj - Ti);
                    T1i = ii[(is[6])];
                    TK = ii[(is[11])];
                    TL = ii[(is[1])];
                    T1j = TK + TL;
                    TM = KP866025403 * (TK - TL);
                    T1k = ((T1i) - ((KP500000000) * (T1j)));
                }
                {
                    E Tn, To, TP, TQ;
                    Tm = ri[(is[9])];
                    Tn = ri[(is[14])];
                    To = ri[(is[4])];
                    Tp = Tn + To;
                    TO = ((Tm) - ((KP500000000) * (Tp)));
                    T1m = KP866025403 * (To - Tn);
                    T1n = ii[(is[9])];
                    TP = ii[(is[14])];
                    TQ = ii[(is[4])];
                    T1o = TP + TQ;
                    TR = KP866025403 * (TP - TQ);
                    T1p = ((T1n) - ((KP500000000) * (T1o)));
                }
                Tl = Th + Tk;
                Tq = Tm + Tp;
                Tr = Tl + Tq;
                TN = TJ - TM;
                TS = TO - TR;
                TT = TN + TS;
                T2c = T1i + T1j;
                T2d = T1n + T1o;
                T2n = T2c + T2d;
                T1O = T1k - T1h;
                T1P = T1p - T1m;
                T22 = T1O + T1P;
                T1l = T1h + T1k;
                T1q = T1m + T1p;
                T1w = T1l + T1q;
                TZ = TJ + TM;
                T10 = TO + TR;
                T11 = TZ + T10;
            }
        } else {
            {
                E T6, T9, Ty, T16, T17, T18, TB, T19, Tb, Te, TD, T1b, T1c, T1d, TG;
                E T1e;
                {
                    E T7, T8, Tz, TA;
                    T6 = ri[(is[3])];
                    T7 = ri[(is[8])];
                    T8 = ri[(is[13])];
                    T9 = T7 + T8;
                    Ty = ((T6) - ((KP500000000) * (T9)));
                    T16 = KP866025403 * (T8 - T7);
                    T17 = ii[(is[3])];
                    Tz = ii[(is[8])];
                    TA = ii[(is[13])];
                    T18 = Tz + TA;
                    TB = KP866025403 * (Tz - TA);
                    T19 = ((T17) - ((KP500000000) * (T18)));
                }
                {
                    E Tc, Td, TE, TF;
                    Tb = ri[(is[12])];
                    Tc = ri[(is[2])];
                    Td = ri[(is[7])];
                    Te = Tc + Td;
                    TD = ((Tb) - ((KP500000000) * (Te)));
                    T1b = KP866025403 * (Td - Tc);
                    T1c = ii[(is[12])];
                    TE = ii[(is[2])];
                    TF = ii[(is[7])];
                    T1d = TE + TF;
                    TG = KP866025403 * (TE - TF);
                    T1e = ((T1c) - ((KP500000000) * (T1d)));
                }
                Ta = T6 + T9;
                Tf = Tb + Te;
                Tg = Ta + Tf;
                TC = Ty - TB;
                TH = TD - TG;
                TI = TC + TH;
                T2f = T17 + T18;
                T2g = T1c + T1d;
                T2m = T2f + T2g;
                T1R = T19 - T16;
                T1S = T1e - T1b;
                T21 = T1R + T1S;
                T1a = T16 + T19;
                T1f = T1b + T1e;
                T1v = T1a + T1f;
                TW = Ty + TB;
                TX = TD + TG;
                TY = TW + TX;
            }
        }
    }

    {
        E T2a, Ts, T29, T2i, T2k, T2e, T2h, T2j, T2b;
        T2a = KP559016994 * (Tg - Tr);
        Ts = Tg + Tr;
        T29 = ((T5) - ((KP250000000) * (Ts)));
        T2e = T2c - T2d;
        T2h = T2f - T2g;
        T2i = ((KP951056516 * T2e) - ((KP587785252) * (T2h)));
        T2k = (((KP951056516) * (T2h)) + (KP587785252 * T2e));
        ro[0] = T5 + Ts;
        T2j = T2a + T29;
        ro[(os[9])] = T2j - T2k;
        ro[(os[6])] = T2j + T2k;
        T2b = T29 - T2a;
        ro[(os[12])] = T2b - T2i;
        ro[(os[3])] = T2b + T2i;
    }
    {
        E T2q, T2o, T2p, T2u, T2w, T2s, T2t, T2v, T2r;
        T2q = KP559016994 * (T2m - T2n);
        T2o = T2m + T2n;
        T2p = ((T2l) - ((KP250000000) * (T2o)));
        T2s = Tl - Tq;
        T2t = Ta - Tf;
        T2u = ((KP951056516 * T2s) - ((KP587785252) * (T2t)));
        T2w = (((KP951056516) * (T2t)) + (KP587785252 * T2s));
        io[0] = T2l + T2o;
        T2v = T2q + T2p;
        io[(os[6])] = T2v - T2w;
        io[(os[9])] = T2w + T2v;
        T2r = T2p - T2q;
        io[(os[3])] = T2r - T2u;
        io[(os[12])] = T2u + T2r;
    }
    {
        E T1M, TU, T1L, T1U, T1W, T1Q, T1T, T1V, T1N;
        T1M = KP559016994 * (TI - TT);
        TU = TI + TT;
        T1L = ((Tx) - ((KP250000000) * (TU)));
        T1Q = T1O - T1P;
        T1T = T1R - T1S;
        T1U = ((KP951056516 * T1Q) - ((KP587785252) * (T1T)));
        T1W = (((KP951056516) * (T1T)) + (KP587785252 * T1Q));
        ro[(os[5])] = Tx + TU;
        T1V = T1M + T1L;
        ro[(os[14])] = T1V - T1W;
        ro[(os[11])] = T1V + T1W;
        T1N = T1L - T1M;
        ro[(os[2])] = T1N - T1U;
        ro[(os[8])] = T1N + T1U;
    }
    {
        E T25, T23, T24, T1Z, T28, T1X, T1Y, T27, T26;
        T25 = KP559016994 * (T21 - T22);
        T23 = T21 + T22;
        T24 = ((T20) - ((KP250000000) * (T23)));
        T1X = TN - TS;
        T1Y = TC - TH;
        T1Z = ((KP951056516 * T1X) - ((KP587785252) * (T1Y)));
        T28 = (((KP951056516) * (T1Y)) + (KP587785252 * T1X));
        io[(os[5])] = T20 + T23;
        T27 = T25 + T24;
        io[(os[11])] = T27 - T28;
        io[(os[14])] = T28 + T27;
        T26 = T24 - T25;
        io[(os[2])] = T1Z + T26;
        io[(os[8])] = T26 - T1Z;
    }
    {
        E T1x, T1D, T1E, T1I, T1J, T1G, T1H, T1K, T1F;
        T1x = KP559016994 * (T1v - T1w);
        T1D = T1v + T1w;
        T1E = ((T1C) - ((KP250000000) * (T1D)));
        T1G = TW - TX;
        T1H = TZ - T10;
        T1I = (((KP951056516) * (T1G)) + (KP587785252 * T1H));
        T1J = ((KP951056516 * T1H) - ((KP587785252) * (T1G)));
        io[(os[10])] = T1C + T1D;
        T1K = T1E - T1x;
        io[(os[7])] = T1J + T1K;
        io[(os[13])] = T1K - T1J;
        T1F = T1x + T1E;
        io[(os[1])] = T1F - T1I;
        io[(os[4])] = T1I + T1F;
    }
    {
        E T13, T12, T14, T1s, T1u, T1g, T1r, T1t, T15;
        T13 = KP559016994 * (TY - T11);
        T12 = TY + T11;
        T14 = ((TV) - ((KP250000000) * (T12)));
        T1g = T1a - T1f;
        T1r = T1l - T1q;
        T1s = (((KP951056516) * (T1g)) + (KP587785252 * T1r));
        T1u = ((KP951056516 * T1r) - ((KP587785252) * (T1g)));
        ro[(os[10])] = TV + T12;
        T1t = T14 - T13;
        ro[(os[7])] = T1t - T1u;
        ro[(os[13])] = T1t + T1u;
        T15 = T13 + T14;
        ro[(os[4])] = T15 - T1s;
        ro[(os[1])] = T15 + T1s;
    }
}
}
