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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 28); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 28 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    for (INT inner = 0; inner < 1; ++inner) {
        E T1q, T2Q, Td, T1n, T2T, T3l, T13, T1k, T1l, T2E, T2F, T3j, T1H, T1T, T2k;
        E T2w, T2f, T2v, T1M, T1U, Tu, TL, TM, T2H, T2I, T3i, T1w, T1Q, T29, T2t;
        E T24, T2s, T1B, T1R;
        {
            E T1, T2R, T6, T1o, Tb, T1p, Tc, T2S;
            T1 = cr[0];
            T2R = ci[0];
            {
                E T3, T5, T2, T4;
                T3 = cr[(rs[5])];
                T5 = ci[(rs[5])];
                T2 = W[8];
                T4 = W[9];
                T6 = (((T2) * (T3)) + (T4 * T5));
                T1o = ((T2 * T5) - ((T4) * (T3)));
            }
            {
                E T8, Ta, T7, T9;
                T8 = cr[(rs[10])];
                Ta = ci[(rs[10])];
                T7 = W[18];
                T9 = W[19];
                Tb = (((T7) * (T8)) + (T9 * Ta));
                T1p = ((T7 * Ta) - ((T9) * (T8)));
            }
            T1q = KP866025403 * (T1o - T1p);
            T2Q = KP866025403 * (Tb - T6);
            Tc = T6 + Tb;
            Td = T1 + Tc;
            T1n = ((T1) - ((KP500000000) * (Tc)));
            T2S = T1o + T1p;
            T2T = ((T2R) - ((KP500000000) * (T2S)));
            T3l = T2S + T2R;
        }
        {
            E TR, T2c, T18, T2h, TW, T1E, T11, T1F, T12, T2d, T1d, T1J, T1i, T1K, T1j;
            E T2i;
            {
                E TO, TQ, TN, TP;
                TO = cr[(rs[6])];
                TQ = ci[(rs[6])];
                TN = W[10];
                TP = W[11];
                TR = (((TN) * (TO)) + (TP * TQ));
                T2c = ((TN * TQ) - ((TP) * (TO)));
            }
            {
                E T15, T17, T14, T16;
                T15 = cr[(rs[9])];
                T17 = ci[(rs[9])];
                T14 = W[16];
                T16 = W[17];
                T18 = (((T14) * (T15)) + (T16 * T17));
                T2h = ((T14 * T17) - ((T16) * (T15)));
            }
            {
                E TT, TV, TS, TU;
                TT = cr[(rs[11])];
                TV = ci[(rs[11])];
                TS = W[20];
                TU = W[21];
                TW = (((TS) * (TT)) + (TU * TV));
                T1E = ((TS * TV) - ((TU) * (TT)));
            }
            {
                E TY, T10, TX, TZ;
                TY = cr[(rs[1])];
                T10 = ci[(rs[1])];
                TX = W[0];
                TZ = W[1];
                T11 = (((TX) * (TY)) + (TZ * T10));
                T1F = ((TX * T10) - ((TZ) * (TY)));
            }
            T12 = TW + T11;
            T2d = T1E + T1F;
            {
                E T1a, T1c, T19, T1b;
                T1a = cr[(rs[14])];
                T1c = ci[(rs[14])];
                T19 = W[26];
                T1b = W[27];
                T1d = (((T19) * (T1a)) + (T1b * T1c));
                T1J = ((T19 * T1c) - ((T1b) * (T1a)));
            }
            {
                E T1f, T1h, T1e, T1g;
                T1f = cr[(rs[4])];
                T1h = ci[(rs[4])];
                T1e = W[6];
                T1g = W[7];
                T1i = (((T1e) * (T1f)) + (T1g * T1h));
                T1K = ((T1e * T1h) - ((T1g) * (T1f)));
            }
            T1j = T1d + T1i;
            T2i = T1J + T1K;
            {
                E T1D, T1G, T2g, T2j;
                T13 = TR + T12;
                T1k = T18 + T1j;
                T1l = T13 + T1k;
                T2E = T2c + T2d;
                T2F = T2h + T2i;
                T3j = T2E + T2F;
                T1D = ((TR) - ((KP500000000) * (T12)));
                T1G = KP866025403 * (T1E - T1F);
                T1H = T1D - T1G;
                T1T = T1D + T1G;
                T2g = KP866025403 * (T1d - T1i);
                T2j = ((T2h) - ((KP500000000) * (T2i)));
                T2k = T2g - T2j;
                T2w = T2g + T2j;
                {
                    E T2b, T2e, T1I, T1L;
                    T2b = KP866025403 * (T11 - TW);
                    T2e = ((T2c) - ((KP500000000) * (T2d)));
                    T2f = T2b + T2e;
                    T2v = T2e - T2b;
                    T1I = ((T18) - ((KP500000000) * (T1j)));
                    T1L = KP866025403 * (T1J - T1K);
                    T1M = T1I - T1L;
                    T1U = T1I + T1L;
                }
            }
        }
        {
            E Ti, T21, Tz, T26, Tn, T1t, Ts, T1u, Tt, T22, TE, T1y, TJ, T1z, TK;
            E T27;
            {
                E Tf, Th, Te, Tg;
                Tf = cr[(rs[3])];
                Th = ci[(rs[3])];
                Te = W[4];
                Tg = W[5];
                Ti = (((Te) * (Tf)) + (Tg * Th));
                T21 = ((Te * Th) - ((Tg) * (Tf)));
            }
            {
                E Tw, Ty, Tv, Tx;
                Tw = cr[(rs[12])];
                Ty = ci[(rs[12])];
                Tv = W[22];
                Tx = W[23];
                Tz = (((Tv) * (Tw)) + (Tx * Ty));
                T26 = ((Tv * Ty) - ((Tx) * (Tw)));
            }
            {
                E Tk, Tm, Tj, Tl;
                Tk = cr[(rs[8])];
                Tm = ci[(rs[8])];
                Tj = W[14];
                Tl = W[15];
                Tn = (((Tj) * (Tk)) + (Tl * Tm));
                T1t = ((Tj * Tm) - ((Tl) * (Tk)));
            }
            {
                E Tp, Tr, To, Tq;
                Tp = cr[(rs[13])];
                Tr = ci[(rs[13])];
                To = W[24];
                Tq = W[25];
                Ts = (((To) * (Tp)) + (Tq * Tr));
                T1u = ((To * Tr) - ((Tq) * (Tp)));
            }
            Tt = Tn + Ts;
            T22 = T1t + T1u;
            {
                E TB, TD, TA, TC;
                TB = cr[(rs[2])];
                TD = ci[(rs[2])];
                TA = W[2];
                TC = W[3];
                TE = (((TA) * (TB)) + (TC * TD));
                T1y = ((TA * TD) - ((TC) * (TB)));
            }
            {
                E TG, TI, TF, TH;
                TG = cr[(rs[7])];
                TI = ci[(rs[7])];
                TF = W[12];
                TH = W[13];
                TJ = (((TF) * (TG)) + (TH * TI));
                T1z = ((TF * TI) - ((TH) * (TG)));
            }
            TK = TE + TJ;
            T27 = T1y + T1z;
            {
                E T1s, T1v, T25, T28;
                Tu = Ti + Tt;
                TL = Tz + TK;
                TM = Tu + TL;
                T2H = T21 + T22;
                T2I = T26 + T27;
                T3i = T2H + T2I;
                T1s = ((Ti) - ((KP500000000) * (Tt)));
                T1v = KP866025403 * (T1t - T1u);
                T1w = T1s - T1v;
                T1Q = T1s + T1v;
                T25 = KP866025403 * (TJ - TE);
                T28 = ((T26) - ((KP500000000) * (T27)));
                T29 = T25 + T28;
                T2t = T28 - T25;
                {
                    E T20, T23, T1x, T1A;
                    T20 = KP866025403 * (Ts - Tn);
                    T23 = ((T21) - ((KP500000000) * (T22)));
                    T24 = T20 + T23;
                    T2s = T23 - T20;
                    T1x = ((Tz) - ((KP500000000) * (TK)));
                    T1A = KP866025403 * (T1y - T1z);
                    T1B = T1x - T1A;
                    T1R = T1x + T1A;
                }
            }
        }
        {
            E T2C, T1m, T2B, T2K, T2M, T2G, T2J, T2L, T2D;
            T2C = KP559016994 * (TM - T1l);
            T1m = TM + T1l;
            T2B = ((Td) - ((KP250000000) * (T1m)));
            T2G = T2E - T2F;
            T2J = T2H - T2I;
            T2K = ((KP951056516 * T2G) - ((KP587785252) * (T2J)));
            T2M = (((KP951056516) * (T2J)) + (KP587785252 * T2G));
            cr[0] = Td + T1m;
            T2L = T2C + T2B;
            ci[(rs[5])] = T2L - T2M;
            cr[(rs[6])] = T2L + T2M;
            T2D = T2B - T2C;
            ci[(rs[2])] = T2D - T2K;
            cr[(rs[3])] = T2D + T2K;
        }
        {
            E T3k, T3m, T3n, T3h, T3p, T3f, T3g, T3q, T3o;
            T3k = KP559016994 * (T3i - T3j);
            T3m = T3i + T3j;
            T3n = ((T3l) - ((KP250000000) * (T3m)));
            T3f = T1k - T13;
            T3g = Tu - TL;
            T3h = ((KP587785252 * T3f) - ((KP951056516) * (T3g)));
            T3p = (((KP587785252) * (T3g)) + (KP951056516 * T3f));
            ci[(rs[14])] = T3m + T3l;
            T3q = T3n - T3k;
            cr[(rs[12])] = T3p - T3q;
            ci[(rs[11])] = T3p + T3q;
            T3o = T3k + T3n;
            cr[(rs[9])] = T3h - T3o;
            ci[(rs[8])] = T3h + T3o;
        }
        {
            E T2y, T2A, T1r, T1O, T2p, T2q, T2z, T2r;
            {
                E T2u, T2x, T1C, T1N;
                T2u = T2s - T2t;
                T2x = T2v - T2w;
                T2y = (((KP951056516) * (T2u)) + (KP587785252 * T2x));
                T2A = ((KP951056516 * T2x) - ((KP587785252) * (T2u)));
                T1r = T1n - T1q;
                T1C = T1w + T1B;
                T1N = T1H + T1M;
                T1O = T1C + T1N;
                T2p = KP559016994 * (T1C - T1N);
                T2q = ((T1r) - ((KP250000000) * (T1O)));
            }
            cr[(rs[5])] = T1r + T1O;
            T2z = T2q - T2p;
            cr[(rs[2])] = T2z - T2A;
            ci[(rs[6])] = T2z + T2A;
            T2r = T2p + T2q;
            ci[0] = T2r - T2y;
            ci[(rs[3])] = T2r + T2y;
        }
        {
            E T35, T3d, T39, T3a, T38, T3b, T3e, T3c;
            {
                E T33, T34, T36, T37;
                T33 = T1w - T1B;
                T34 = T1H - T1M;
                T35 = (((KP951056516) * (T33)) + (KP587785252 * T34));
                T3d = ((KP951056516 * T34) - ((KP587785252) * (T33)));
                T39 = T2T - T2Q;
                T36 = T2v + T2w;
                T37 = T2s + T2t;
                T3a = T37 + T36;
                T38 = KP559016994 * (T36 - T37);
                T3b = ((T39) - ((KP250000000) * (T3a)));
            }
            ci[(rs[9])] = T3a + T39;
            T3e = T38 + T3b;
            cr[(rs[8])] = T3d - T3e;
            ci[(rs[12])] = T3d + T3e;
            T3c = T38 - T3b;
            cr[(rs[11])] = T35 + T3c;
            cr[(rs[14])] = T3c - T35;
        }
        {
            E T2X, T31, T2U, T2P, T2Y, T2Z, T32, T30;
            {
                E T2V, T2W, T2N, T2O;
                T2V = T1T - T1U;
                T2W = T1Q - T1R;
                T2X = ((KP951056516 * T2V) - ((KP587785252) * (T2W)));
                T31 = (((KP951056516) * (T2W)) + (KP587785252 * T2V));
                T2U = T2Q + T2T;
                T2N = T2k - T2f;
                T2O = T24 + T29;
                T2P = T2N - T2O;
                T2Y = (((KP250000000) * (T2P)) + (T2U));
                T2Z = KP559016994 * (T2O + T2N);
            }
            cr[(rs[10])] = T2P - T2U;
            T32 = T2Z + T2Y;
            ci[(rs[10])] = T31 + T32;
            ci[(rs[13])] = T32 - T31;
            T30 = T2Y - T2Z;
            cr[(rs[13])] = T2X - T30;
            ci[(rs[7])] = T2X + T30;
        }
        {
            E T2m, T2o, T1P, T1W, T1X, T1Y, T1Z, T2n;
            {
                E T2a, T2l, T1S, T1V;
                T2a = T24 - T29;
                T2l = T2f + T2k;
                T2m = (((KP951056516) * (T2a)) + (KP587785252 * T2l));
                T2o = ((KP951056516 * T2l) - ((KP587785252) * (T2a)));
                T1P = T1n + T1q;
                T1S = T1Q + T1R;
                T1V = T1T + T1U;
                T1W = T1S + T1V;
                T1X = KP559016994 * (T1S - T1V);
                T1Y = ((T1P) - ((KP250000000) * (T1W)));
            }
            ci[(rs[4])] = T1P + T1W;
            T1Z = T1X + T1Y;
            cr[(rs[4])] = T1Z - T2m;
            cr[(rs[1])] = T1Z + T2m;
            T2n = T1Y - T1X;
            cr[(rs[7])] = T2n - T2o;
            ci[(rs[1])] = T2n + T2o;
        }
    }
}
}
