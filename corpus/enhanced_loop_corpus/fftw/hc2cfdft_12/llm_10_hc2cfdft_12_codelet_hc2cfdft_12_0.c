#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP250000000;
extern  E KP500000000;
extern  E KP433012701;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2, Rp = Rp + 2*ms, Ip = Ip + 2*ms, Rm = Rm - 2*ms, Im = Im - 2*ms, W = W + 44, (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;

    for (INT step = 0; step < 2; ++step) {
        INT idx_offset = step * ms;
        stride rs_offset = step ? rs + 1 : rs;
        E *Rp_local = Rp + idx_offset;
        E *Ip_local = Ip + idx_offset;
        E *Rm_local = Rm - idx_offset;
        E *Im_local = Im - idx_offset;
        E *W_local = W + step * 22;

        E Tm, T1t, T1d, T2j, Tj, T1Y, T1w, T1G, T1q, T2q, T1U, T2k, Tw, T1y, T17;
        E T2g, TP, T21, T1B, T1J, T12, T2u, T1P, T2h;

        {
            E Tk, Tl, T1k, T1m, T1n, T1o, T4, T1f, T8, T1h, Th, T1c, Td, T1a, T19, T1b;
            {
                E T2, T3, T6, T7;
                Tk = Ip_local[0];
                Tl = Im_local[0];
                T1k = Tk + Tl;
                T1m = Rp_local[0];
                T1n = Rm_local[0];
                T1o = T1m - T1n;
                T2 = Ip_local[(rs_offset[2])];
                T3 = Im_local[(rs_offset[2])];
                T4 = T2 - T3;
                T1f = T2 + T3;
                T6 = Rp_local[(rs_offset[2])];
                T7 = Rm_local[(rs_offset[2])];
                T8 = T6 + T7;
                T1h = T6 - T7;
                {
                    E Tf, Tg, Tb, Tc;
                    Tf = Rp_local[(rs_offset[4])];
                    Tg = Rm_local[(rs_offset[4])];
                    Th = Tf + Tg;
                    T1c = Tf - Tg;
                    Tb = Ip_local[(rs_offset[4])];
                    Tc = Im_local[(rs_offset[4])];
                    Td = Tb - Tc;
                    T1a = Tb + Tc;
                }
            }
            Tm = Tk - Tl;
            T1t = T1m + T1n;
            T19 = W_local[16];
            T1b = W_local[17];
            T1d = ((T19 * T1a) - (T1b * T1c));
            T2j = (T19 * T1c) + (T1b * T1a);
            {
                E T9, T1u, Ti, T1v;
                {
                    E T1, T5, Ta, Te;
                    T1 = W_local[6];
                    T5 = W_local[7];
                    T9 = (T1 * T4) - (T5 * T8);
                    T1u = (T1 * T8) + (T5 * T4);
                    Ta = W_local[14];
                    Te = W_local[15];
                    Ti = (Ta * Td) - (Te * Th);
                    T1v = (Ta * Th) + (Te * Td);
                }
                Tj = T9 + Ti;
                T1Y = KP433012701 * (T1v - T1u);
                T1w = T1u + T1v;
                T1G = KP433012701 * (T9 - Ti);
            }
            {
                E T1i, T1S, T1p, T1T;
                {
                    E T1e, T1g, T1j, T1l;
                    T1e = W_local[8];
                    T1g = W_local[9];
                    T1i = (T1e * T1f) - (T1g * T1h);
                    T1S = (T1e * T1h) + (T1g * T1f);
                    T1j = W_local[0];
                    T1l = W_local[1];
                    T1p = (T1j * T1k) - (T1l * T1o);
                    T1T = (T1j * T1o) + (T1l * T1k);
                }
                T1q = T1i + T1p;
                T2q = KP433012701 * (T1i - T1p);
                T1U = KP433012701 * (T1S - T1T);
                T2k = T1S + T1T;
            }
        }
        {
            E Tr, TT, Tv, TV, TA, TY, TE, T10, TN, T14, TJ, T16;
            {
                E Tp, Tq, TC, TD;
                Tp = Ip_local[(rs_offset[3])];
                Tq = Im_local[(rs_offset[3])];
                Tr = Tp - Tq;
                TT = Tp + Tq;
                {
                    E Tt, Tu, Ty, Tz;
                    Tt = Rp_local[(rs_offset[3])];
                    Tu = Rm_local[(rs_offset[3])];
                    Tv = Tt + Tu;
                    TV = Tt - Tu;
                    Ty = Ip_local[(rs_offset[5])];
                    Tz = Im_local[(rs_offset[5])];
                    TA = Ty - Tz;
                    TY = Ty + Tz;
                }
                TC = Rp_local[(rs_offset[5])];
                TD = Rm_local[(rs_offset[5])];
                TE = TC + TD;
                T10 = TC - TD;
                {
                    E TL, TM, TH, TI;
                    TL = Rp_local[(rs_offset[1])];
                    TM = Rm_local[(rs_offset[1])];
                    TN = TL + TM;
                    T14 = TM - TL;
                    TH = Ip_local[(rs_offset[1])];
                    TI = Im_local[(rs_offset[1])];
                    TJ = TH - TI;
                    T16 = TH + TI;
                }
            }
            {
                E To, Ts, T13, T15;
                To = W_local[10];
                Ts = W_local[11];
                Tw = (To * Tr) - (Ts * Tv);
                T1y = (To * Tv) + (Ts * Tr);
                T13 = W_local[5];
                T15 = W_local[4];
                T17 = (T13 * T14) + (T15 * T16);
                T2g = (T15 * T14) - (T13 * T16);
            }
            {
                E TF, T1z, TO, T1A;
                {
                    E Tx, TB, TG, TK;
                    Tx = W_local[18];
                    TB = W_local[19];
                    TF = (Tx * TA) - (TB * TE);
                    T1z = (Tx * TE) + (TB * TA);
                    TG = W_local[2];
                    TK = W_local[3];
                    TO = (TG * TJ) - (TK * TN);
                    T1A = (TG * TN) + (TK * TJ);
                }
                TP = TF + TO;
                T21 = KP433012701 * (T1A - T1z);
                T1B = T1z + T1A;
                T1J = KP433012701 * (TF - TO);
            }
            {
                E TW, T1O, T11, T1N;
                {
                    E TS, TU, TX, TZ;
                    TS = W_local[12];
                    TU = W_local[13];
                    TW = (TS * TT) - (TU * TV);
                    T1O = (TS * TV) + (TU * TT);
                    TX = W_local[20];
                    TZ = W_local[21];
                    T11 = (TX * TY) - (TZ * T10);
                    T1N = (TX * T10) + (TZ * TY);
                }
                T12 = TW + T11;
                T2u = KP433012701 * (T11 - TW);
                T1P = KP433012701 * (T1N - T1O);
                T2h = T1O + T1N;
            }
        }
        {
            E TR, T2f, T2m, T2o, T1s, T1E, T1D, T2n;
            {
                E Tn, TQ, T2i, T2l;
                Tn = Tj + Tm;
                TQ = Tw + TP;
                TR = Tn - TQ;
                T2f = TQ + Tn;
                T2i = T2g - T2h;
                T2l = T2j + T2k;
                T2m = T2i - T2l;
                T2o = T2i + T2l;
            }
            {
                E T18, T1r, T1x, T1C;
                T18 = T12 + T17;
                T1r = T1d + T1q;
                T1s = T18 - T1r;
                T1E = T18 + T1r;
                T1x = T1t + T1w;
                T1C = T1y + T1B;
                T1D = T1x + T1C;
                T2n = T1x - T1C;
            }
            Ip_local[(rs_offset[3])] = KP500000000 * (TR + T1s);
            Rp_local[(rs_offset[3])] = KP500000000 * (T2n - T2o);
            Im_local[(rs_offset[2])] = KP500000000 * (T1s - TR);
            Rm_local[(rs_offset[2])] = KP500000000 * (T2n + T2o);
            Rm_local[(rs_offset[5])] = KP500000000 * (T1D - T1E);
            Im_local[(rs_offset[5])] = KP500000000 * (T2m - T2f);
            Rp_local[0] = KP500000000 * (T1D + T1E);
            Ip_local[0] = KP500000000 * (T2f + T2m);
        }
        {
            E T1H, T2b, T2s, T2B, T2v, T2A, T1K, T2c, T1Q, T29, T1Z, T25, T22, T26, T1V, T28;
            {
                E T1F, T2r, T2t, T1I;
                T1F = (KP500000000 * T1t) - (KP250000000 * T1w);
                T1H = T1F - T1G;
                T2b = T1F + T1G;
                T2r = (KP250000000 * T2k) - (KP500000000 * T2j);
                T2s = T2q - T2r;
                T2B = T2q + T2r;
                T2t = (KP250000000 * T2h) + (KP500000000 * T2g);
                T2v = T2t - T2u;
                T2A = T2u + T2t;
                T1I = (KP500000000 * T1y) - (KP250000000 * T1B);
                T1K = T1I - T1J;
                T2c = T1I + T1J;
            }
            {
                E T1M, T1X, T20, T1R;
                T1M = (KP500000000 * T17) - (KP250000000 * T12);
                T1Q = T1M - T1P;
                T29 = T1P + T1M;
                T1X = (KP500000000 * Tm) - (KP250000000 * Tj);
                T1Z = T1X - T1Y;
                T25 = T1Y + T1X;
                T20 = (KP500000000 * Tw) - (KP250000000 * TP);
                T22 = T20 - T21;
                T26 = T21 + T20;
                T1R = (KP500000000 * T1d) - (KP250000000 * T1q);
                T1V = T1R - T1U;
                T28 = T1R + T1U;
            }
            {
                E T1L, T1W, T2p, T2w;
                T1L = T1H + T1K;
                T1W = T1Q + T1V;
                Rp_local[(rs_offset[2])] = T1L - T1W;
                Rm_local[(rs_offset[3])] = T1L + T1W;
                T2p = T22 + T1Z;
                T2w = T2s - T2v;
                Ip_local[(rs_offset[2])] = T2p + T2w;
                Im_local[(rs_offset[3])] = T2w - T2p;
            }
            {
                E T23, T24, T2x, T2y;
                T23 = T1Z - T22;
                T24 = T1V - T1Q;
                Ip_local[(rs_offset[5])] = T23 + T24;
                Im_local[0] = T24 - T23;
                T2x = T1H - T1K;
                T2y = T2v + T2s;
                Rm_local[0] = T2x - T2y;
                Rp_local[(rs_offset[5])] = T2x + T2y;
            }
            {
                E T27, T2a, T2z, T2C;
                T27 = T25 - T26;
                T2a = T28 - T29;
                Ip_local[(rs_offset[1])] = T27 + T2a;
                Im_local[(rs_offset[4])] = T2a - T27;
                T2z = T2b - T2c;
                T2C = T2A - T2B;
                Rm_local[(rs_offset[4])] = T2z - T2C;
                Rp_local[(rs_offset[1])] = T2z + T2C;
            }
            {
                E T2d, T2e, T2D, T2E;
                T2d = T2b + T2c;
                T2e = T29 + T28;
                Rm_local[(rs_offset[1])] = T2d - T2e;
                Rp_local[(rs_offset[4])] = T2d + T2e;
                T2D = T26 + T25;
                T2E = T2A + T2B;
                Ip_local[(rs_offset[4])] = T2D + T2E;
                Im_local[(rs_offset[1])] = T2E - T2D;
            }
        }
    }
}
}
