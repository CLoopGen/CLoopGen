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
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T18, TE, TF, T1B, T1A, T1f, T1t, Ti, Tl, TJ, T1i, Tt, TA, T1w;
    E T1v, T1p, T1E, TM, TO;
    if (1) {
        {
            E T1, T2, TH, TI;
            T1 = cr[0];
            T2 = ci[(rs[4])];
            T3 = T1 + T2;
            T18 = T1 - T2;
            {
                E T6, T19, Tg, T1d, T9, T1a, Td, T1c;
                {
                    E T4, T5, Te, Tf;
                    T4 = cr[(rs[2])];
                    T5 = ci[(rs[2])];
                    T6 = T4 + T5;
                    T19 = T4 - T5;
                    Te = ci[(rs[3])];
                    Tf = cr[(rs[1])];
                    Tg = Te + Tf;
                    T1d = Te - Tf;
                }
                {
                    E T7, T8, Tb, Tc;
                    T7 = ci[(rs[1])];
                    T8 = cr[(rs[3])];
                    T9 = T7 + T8;
                    T1a = T7 - T8;
                    Tb = cr[(rs[4])];
                    Tc = ci[0];
                    Td = Tb + Tc;
                    T1c = Tb - Tc;
                }
                TE = T6 - T9;
                TF = Td - Tg;
                T1B = T1c - T1d;
                T1A = T19 - T1a;
                {
                    E T1b, T1e, Ta, Th;
                    T1b = T19 + T1a;
                    T1e = T1c + T1d;
                    T1f = T1b + T1e;
                    T1t = KP559016994 * (T1b - T1e);
                    Ta = T6 + T9;
                    Th = Td + Tg;
                    Ti = Ta + Th;
                    Tl = KP559016994 * (Ta - Th);
                }
            }
            TH = ci[(rs[9])];
            TI = cr[(rs[5])];
            TJ = TH - TI;
            T1i = TH + TI;
            {
                E Tp, T1j, Tz, T1n, Ts, T1k, Tw, T1m;
                {
                    E Tn, To, Tx, Ty;
                    Tn = ci[(rs[7])];
                    To = cr[(rs[7])];
                    Tp = Tn - To;
                    T1j = Tn + To;
                    Tx = ci[(rs[8])];
                    Ty = cr[(rs[6])];
                    Tz = Tx - Ty;
                    T1n = Tx + Ty;
                }
                {
                    E Tq, Tr, Tu, Tv;
                    Tq = ci[(rs[6])];
                    Tr = cr[(rs[8])];
                    Ts = Tq - Tr;
                    T1k = Tq + Tr;
                    Tu = ci[(rs[5])];
                    Tv = cr[(rs[9])];
                    Tw = Tu - Tv;
                    T1m = Tu + Tv;
                }
                Tt = Tp - Ts;
                TA = Tw - Tz;
                T1w = T1m + T1n;
                T1v = T1j + T1k;
                {
                    E T1l, T1o, TK, TL;
                    T1l = T1j - T1k;
                    T1o = T1m - T1n;
                    T1p = T1l + T1o;
                    T1E = KP559016994 * (T1l - T1o);
                    TK = Tp + Ts;
                    TL = Tw + Tz;
                    TM = TK + TL;
                    TO = KP559016994 * (TK - TL);
                }
            }
        }
        cr[0] = T3 + Ti;
        ci[0] = TJ + TM;
        {
            E T1g, T1q, T17, T1h;
            T1g = T18 + T1f;
            T1q = T1i + T1p;
            T17 = W[8];
            T1h = W[9];
            cr[(rs[5])] = ((T17 * T1g) - ((T1h) * (T1q)));
            ci[(rs[5])] = (((T1h) * (T1g)) + (T17 * T1q));
        }
        {
            E TB, TG, T11, TX, TP, T10, Tm, TW, TN, Tk;
            TB = ((KP587785252 * Tt) - ((KP951056516) * (TA)));
            TG = ((KP587785252 * TE) - ((KP951056516) * (TF)));
            T11 = (((KP951056516) * (TE)) + (KP587785252 * TF));
            TX = (((KP951056516) * (Tt)) + (KP587785252 * TA));
            TN = ((TJ) - ((KP250000000) * (TM)));
            TP = TN - TO;
            T10 = TO + TN;
            Tk = ((T3) - ((KP250000000) * (Ti)));
            Tm = Tk - Tl;
            TW = Tl + Tk;
            {
                E TC, TQ, Tj, TD;
                TC = Tm - TB;
                TQ = TG + TP;
                Tj = W[2];
                TD = W[3];
                cr[(rs[2])] = ((Tj * TC) - ((TD) * (TQ)));
                ci[(rs[2])] = (((TD) * (TC)) + (Tj * TQ));
            }
            {
                E T14, T16, T13, T15;
                T14 = TW - TX;
                T16 = T11 + T10;
                T13 = W[10];
                T15 = W[11];
                cr[(rs[6])] = ((T13 * T14) - ((T15) * (T16)));
                ci[(rs[6])] = (((T15) * (T14)) + (T13 * T16));
            }
            {
                E TS, TU, TR, TT;
                TS = Tm + TB;
                TU = TP - TG;
                TR = W[14];
                TT = W[15];
                cr[(rs[8])] = ((TR * TS) - ((TT) * (TU)));
                ci[(rs[8])] = (((TT) * (TS)) + (TR * TU));
            }
            {
                E TY, T12, TV, TZ;
                TY = TW + TX;
                T12 = T10 - T11;
                TV = W[6];
                TZ = W[7];
                cr[(rs[4])] = ((TV * TY) - ((TZ) * (T12)));
                ci[(rs[4])] = (((TZ) * (TY)) + (TV * T12));
            }
        }
        {
            E T1x, T1C, T1Q, T1N, T1F, T1R, T1u, T1M, T1D, T1s;
            T1x = ((KP587785252 * T1v) - ((KP951056516) * (T1w)));
            T1C = ((KP587785252 * T1A) - ((KP951056516) * (T1B)));
            T1Q = (((KP951056516) * (T1A)) + (KP587785252 * T1B));
            T1N = (((KP951056516) * (T1v)) + (KP587785252 * T1w));
            T1D = ((T1i) - ((KP250000000) * (T1p)));
            T1F = T1D - T1E;
            T1R = T1E + T1D;
            T1s = ((T18) - ((KP250000000) * (T1f)));
            T1u = T1s - T1t;
            T1M = T1t + T1s;
            {
                E T1y, T1G, T1r, T1z;
                T1y = T1u - T1x;
                T1G = T1C + T1F;
                T1r = W[12];
                T1z = W[13];
                cr[(rs[7])] = ((T1r * T1y) - ((T1z) * (T1G)));
                ci[(rs[7])] = (((T1r) * (T1G)) + (T1z * T1y));
            }
            {
                E T1U, T1W, T1T, T1V;
                T1U = T1M + T1N;
                T1W = T1R - T1Q;
                T1T = W[16];
                T1V = W[17];
                cr[(rs[9])] = ((T1T * T1U) - ((T1V) * (T1W)));
                ci[(rs[9])] = (((T1T) * (T1W)) + (T1V * T1U));
            }
            {
                E T1I, T1K, T1H, T1J;
                T1I = T1u + T1x;
                T1K = T1F - T1C;
                T1H = W[4];
                T1J = W[5];
                cr[(rs[3])] = ((T1H * T1I) - ((T1J) * (T1K)));
                ci[(rs[3])] = (((T1H) * (T1K)) + (T1J * T1I));
            }
            {
                E T1O, T1S, T1L, T1P;
                T1O = T1M - T1N;
                T1S = T1Q + T1R;
                T1L = W[0];
                T1P = W[1];
                cr[(rs[1])] = ((T1L * T1O) - ((T1P) * (T1S)));
                ci[(rs[1])] = (((T1L) * (T1S)) + (T1P * T1O));
            }
        }
    }
}
}
