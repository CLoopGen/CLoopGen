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

    // Control path 1: Skip first block under certain condition
    if (!(v & 1)) goto skip_first_block;

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

skip_first_block:

    // Always execute the remaining blocks
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
    {
        E T2Z, TK, T30, T38, T3a, T34, T37, T39, T31;
        T2Z = KP559016994 * (TG - TJ);
        TK = TG + TJ;
        T30 = ((TD) - ((KP250000000) * (TK)));
        T34 = T32 - T33;
        T37 = T35 - T36;
        T38 = (((KP951056516) * (T34)) + (KP587785252 * T37));
        T3a = ((KP951056516 * T37) - ((KP587785252) * (T34)));
        ro[0] = TD + TK;
        T39 = T30 - T2Z;
        ro[(os[12])] = T39 - T3a;
        ro[(os[8])] = T39 + T3a;
        T31 = T2Z + T30;
        ro[(os[4])] = T31 - T38;
        ro[(os[16])] = T31 + T38;
    }
    {
        E T3g, T3i, T3j, T3d, T3m, T3b, T3c, T3l, T3k;
        T3g = KP559016994 * (T3e - T3f);
        T3i = T3e + T3f;
        T3j = ((T3h) - ((KP250000000) * (T3i)));
        T3b = TE - TF;
        T3c = TH - TI;
        T3d = (((KP951056516) * (T3b)) + (KP587785252 * T3c));
        T3m = ((KP951056516 * T3c) - ((KP587785252) * (T3b)));
        io[0] = T3h + T3i;
        T3l = T3j - T3g;
        io[(os[8])] = T3l - T3m;
        io[(os[12])] = T3m + T3l;
        T3k = T3g + T3j;
        io[(os[4])] = T3d + T3k;
        io[(os[16])] = T3k - T3d;
    }
    {
        E T23, T1c, T24, T2c, T2e, T28, T2b, T2d, T25;
        T23 = KP559016994 * (T10 - T1b);
        T1c = T10 + T1b;
        T24 = ((TP) - ((KP250000000) * (T1c)));
        T28 = T26 - T27;
        T2b = T29 - T2a;
        T2c = (((KP951056516) * (T28)) + (KP587785252 * T2b));
        T2e = ((KP951056516 * T2b) - ((KP587785252) * (T28)));
        io[(os[5])] = TP + T1c;
        T2d = T24 - T23;
        io[(os[13])] = T2d - T2e;
        io[(os[17])] = T2d + T2e;
        T25 = T23 + T24;
        io[(os[1])] = T25 - T2c;
        io[(os[9])] = T25 + T2c;
    }
    {
        E T2k, T2m, T2n, T2h, T2p, T2f, T2g, T2q, T2o;
        T2k = KP559016994 * (T2i - T2j);
        T2m = T2i + T2j;
        T2n = ((T2l) - ((KP250000000) * (T2m)));
        T2f = TU - TZ;
        T2g = T15 - T1a;
        T2h = (((KP951056516) * (T2f)) + (KP587785252 * T2g));
        T2p = ((KP951056516 * T2g) - ((KP587785252) * (T2f)));
        ro[(os[5])] = T2l + T2m;
        T2q = T2n - T2k;
        ro[(os[13])] = T2p + T2q;
        ro[(os[17])] = T2q - T2p;
        T2o = T2k + T2n;
        ro[(os[1])] = T2h + T2o;
        ro[(os[9])] = T2o - T2h;
    }
    {
        E T1m, T1k, T1l, T1K, T1M, T1y, T1J, T1L, T1n;
        T1m = KP559016994 * (T1g - T1j);
        T1k = T1g + T1j;
        T1l = ((T1d) - ((KP250000000) * (T1k)));
        T1y = T1s - T1x;
        T1J = T1D - T1I;
        T1K = ((KP951056516 * T1y) - ((KP587785252) * (T1J)));
        T1M = (((KP951056516) * (T1J)) + (KP587785252 * T1y));
        io[(os[15])] = T1d + T1k;
        T1L = T1m + T1l;
        io[(os[11])] = T1L - T1M;
        io[(os[19])] = T1L + T1M;
        T1n = T1l - T1m;
        io[(os[3])] = T1n - T1K;
        io[(os[7])] = T1n + T1K;
    }
    {
        E T1Z, T1X, T1Y, T1P, T21, T1N, T1O, T22, T20;
        T1Z = KP559016994 * (T1V - T1W);
        T1X = T1V + T1W;
        T1Y = ((T1U) - ((KP250000000) * (T1X)));
        T1N = T1h - T1i;
        T1O = T1e - T1f;
        T1P = ((KP951056516 * T1N) - ((KP587785252) * (T1O)));
        T21 = (((KP951056516) * (T1O)) + (KP587785252 * T1N));
        ro[(os[15])] = T1U + T1X;
        T22 = T1Z + T1Y;
        ro[(os[11])] = T21 + T22;
        ro[(os[19])] = T22 - T21;
        T20 = T1Y - T1Z;
        ro[(os[3])] = T1P + T20;
        ro[(os[7])] = T20 - T1P;
    }
}
}
