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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 1) {
    W = W + ((m == mb) ? (mb - 1) * 30 : 30);
    for (INT step = 0; step < 1; step++) {
        E T7, T2K, T2W, Tw, T17, T1S, T2k, T1w, Te, TD, T1x, T10, T2n, T2L, T1Z;
        E T2X, Tm, T1z, TN, T19, T2e, T2p, T2P, T2Z, Tt, T1A, TW, T1a, T27, T2q;
        E T2S, T30;
        {
            E T3, T1Q, T13, T2j, T6, T2i, T16, T1R;
            {
                E T1, T2, T11, T12;
                T1 = Rp[0];
                T2 = Rm[(rs[7])];
                T3 = T1 + T2;
                T1Q = T1 - T2;
                T11 = Ip[0];
                T12 = Im[(rs[7])];
                T13 = T11 - T12;
                T2j = T11 + T12;
            }
            {
                E T4, T5, T14, T15;
                T4 = Rp[(rs[4])];
                T5 = Rm[(rs[3])];
                T6 = T4 + T5;
                T2i = T4 - T5;
                T14 = Ip[(rs[4])];
                T15 = Im[(rs[3])];
                T16 = T14 - T15;
                T1R = T14 + T15;
            }
            T7 = T3 + T6;
            T2K = T1Q + T1R;
            T2W = T2j - T2i;
            Tw = T3 - T6;
            T17 = T13 - T16;
            T1S = T1Q - T1R;
            T2k = T2i + T2j;
            T1w = T13 + T16;
        }
        {
            E Ta, T1T, TC, T1U, Td, T1W, Tz, T1X;
            {
                E T8, T9, TA, TB;
                T8 = Rp[(rs[2])];
                T9 = Rm[(rs[5])];
                Ta = T8 + T9;
                T1T = T8 - T9;
                TA = Ip[(rs[2])];
                TB = Im[(rs[5])];
                TC = TA - TB;
                T1U = TA + TB;
            }
            {
                E Tb, Tc, Tx, Ty;
                Tb = Rm[(rs[1])];
                Tc = Rp[(rs[6])];
                Td = Tb + Tc;
                T1W = Tb - Tc;
                Tx = Ip[(rs[6])];
                Ty = Im[(rs[1])];
                Tz = Tx - Ty;
                T1X = Tx + Ty;
            }
            Te = Ta + Td;
            TD = Tz - TC;
            T1x = TC + Tz;
            T10 = Ta - Td;
            {
                E T2l, T2m, T1V, T1Y;
                T2l = T1T + T1U;
                T2m = T1W + T1X;
                T2n = KP707106781 * (T2l - T2m);
                T2L = KP707106781 * (T2l + T2m);
                T1V = T1T - T1U;
                T1Y = T1W - T1X;
                T1Z = KP707106781 * (T1V + T1Y);
                T2X = KP707106781 * (T1V - T1Y);
            }
        }
        {
            E Ti, T2b, TI, T29, Tl, T28, TL, T2c, TF, TM;
            {
                E Tg, Th, TG, TH;
                Tg = Rp[(rs[1])];
                Th = Rm[(rs[6])];
                Ti = Tg + Th;
                T2b = Tg - Th;
                TG = Ip[(rs[1])];
                TH = Im[(rs[6])];
                TI = TG - TH;
                T29 = TG + TH;
            }
            {
                E Tj, Tk, TJ, TK;
                Tj = Rp[(rs[5])];
                Tk = Rm[(rs[2])];
                Tl = Tj + Tk;
                T28 = Tj - Tk;
                TJ = Ip[(rs[5])];
                TK = Im[(rs[2])];
                TL = TJ - TK;
                T2c = TJ + TK;
            }
            Tm = Ti + Tl;
            T1z = TI + TL;
            TF = Ti - Tl;
            TM = TI - TL;
            TN = TF - TM;
            T19 = TF + TM;
            {
                E T2a, T2d, T2N, T2O;
                T2a = T28 + T29;
                T2d = T2b - T2c;
                T2e = (((KP923879532) * (T2a)) + (KP382683432 * T2d));
                T2p = ((KP923879532 * T2d) - ((KP382683432) * (T2a)));
                T2N = T2b + T2c;
                T2O = T29 - T28;
                T2P = ((KP382683432 * T2N) - ((KP923879532) * (T2O)));
                T2Z = (((KP382683432) * (T2O)) + (KP923879532 * T2N));
            }
        }
        {
            E Tp, T24, TR, T22, Ts, T21, TU, T25, TO, TV;
            {
                E Tn, To, TP, TQ;
                Tn = Rm[0];
                To = Rp[(rs[7])];
                Tp = Tn + To;
                T24 = Tn - To;
                TP = Ip[(rs[7])];
                TQ = Im[0];
                TR = TP - TQ;
                T22 = TP + TQ;
            }
            {
                E Tq, Tr, TS, TT;
                Tq = Rp[(rs[3])];
                Tr = Rm[(rs[4])];
                Ts = Tq + Tr;
                T21 = Tq - Tr;
                TS = Ip[(rs[3])];
                TT = Im[(rs[4])];
                TU = TS - TT;
                T25 = TS + TT;
            }
            Tt = Tp + Ts;
            T1A = TR + TU;
            TO = Tp - Ts;
            TV = TR - TU;
            TW = TO + TV;
            T1a = TV - TO;
            {
                E T23, T26, T2Q, T2R;
                T23 = T21 - T22;
                T26 = T24 - T25;
                T27 = ((KP923879532 * T23) - ((KP382683432) * (T26)));
                T2q = (((KP382683432) * (T23)) + (KP923879532 * T26));
                T2Q = T24 + T25;
                T2R = T21 + T22;
                T2S = ((KP382683432 * T2Q) - ((KP923879532) * (T2R)));
                T30 = (((KP382683432) * (T2R)) + (KP923879532 * T2Q));
            }
        }
        {
            E Tf, Tu, T1u, T1y, T1B, T1C, T1t, T1v;
            Tf = T7 + Te;
            Tu = Tm + Tt;
            T1u = Tf - Tu;
            T1y = T1w + T1x;
            T1B = T1z + T1A;
            T1C = T1y - T1B;
            Rp[0] = Tf + Tu;
            Rm[0] = T1y + T1B;
            T1t = W[14];
            T1v = W[15];
            Rp[(rs[4])] = ((T1t * T1u) - ((T1v) * (T1C)));
            Rm[(rs[4])] = (((T1v) * (T1u)) + (T1t * T1C));
        }
        {
            E T2U, T34, T32, T36;
            {
                E T2M, T2T, T2Y, T31;
                T2M = T2K - T2L;
                T2T = T2P + T2S;
                T2U = T2M - T2T;
                T34 = T2M + T2T;
                T2Y = T2W + T2X;
                T31 = T2Z - T30;
                T32 = T2Y - T31;
                T36 = T2Y + T31;
            }
            {
                E T2J, T2V, T33, T35;
                T2J = W[20];
                T2V = W[21];
                Ip[(rs[5])] = ((T2J * T2U) - ((T2V) * (T32)));
                Im[(rs[5])] = (((T2V) * (T2U)) + (T2J * T32));
                T33 = W[4];
                T35 = W[5];
                Ip[(rs[1])] = ((T33 * T34) - ((T35) * (T36)));
                Im[(rs[1])] = (((T35) * (T34)) + (T33 * T36));
            }
        }
        {
            E T3a, T3g, T3e, T3i;
            {
                E T38, T39, T3c, T3d;
                T38 = T2K + T2L;
                T39 = T2Z + T30;
                T3a = T38 - T39;
                T3g = T38 + T39;
                T3c = T2W - T2X;
                T3d = T2P - T2S;
                T3e = T3c + T3d;
                T3i = T3c - T3d;
            }
            {
                E T37, T3b, T3f, T3h;
                T37 = W[12];
                T3b = W[13];
                Ip[(rs[3])] = ((T37 * T3a) - ((T3b) * (T3e)));
                Im[(rs[3])] = (((T37) * (T3e)) + (T3b * T3a));
                T3f = W[28];
                T3h = W[29];
                Ip[(rs[7])] = ((T3f * T3g) - ((T3h) * (T3i)));
                Im[(rs[7])] = (((T3f) * (T3i)) + (T3h * T3g));
            }
        }
        {
            E TY, T1e, T1c, T1g;
            {
                E TE, TX, T18, T1b;
                TE = Tw + TD;
                TX = KP707106781 * (TN + TW);
                TY = TE - TX;
                T1e = TE + TX;
                T18 = T10 + T17;
                T1b = KP707106781 * (T19 + T1a);
                T1c = T18 - T1b;
                T1g = T18 + T1b;
            }
            {
                E Tv, TZ, T1d, T1f;
                Tv = W[18];
                TZ = W[19];
                Rp[(rs[5])] = ((Tv * TY) - ((TZ) * (T1c)));
                Rm[(rs[5])] = (((TZ) * (TY)) + (Tv * T1c));
                T1d = W[2];
                T1f = W[3];
                Rp[(rs[1])] = ((T1d * T1e) - ((T1f) * (T1g)));
                Rm[(rs[1])] = (((T1f) * (T1e)) + (T1d * T1g));
            }
        }
        {
            E T1k, T1q, T1o, T1s;
            {
                E T1i, T1j, T1m, T1n;
                T1i = Tw - TD;
                T1j = KP707106781 * (T1a - T19);
                T1k = T1i - T1j;
                T1q = T1i + T1j;
                T1m = T17 - T10;
                T1n = KP707106781 * (TN - TW);
                T1o = T1m - T1n;
                T1s = T1m + T1n;
            }
            {
                E T1h, T1l, T1p, T1r;
                T1h = W[26];
                T1l = W[27];
                Rp[(rs[7])] = ((T1h * T1k) - ((T1l) * (T1o)));
                Rm[(rs[7])] = (((T1h) * (T1o)) + (T1l * T1k));
                T1p = W[10];
                T1r = W[11];
                Rp[(rs[3])] = ((T1p * T1q) - ((T1r) * (T1s)));
                Rm[(rs[3])] = (((T1p) * (T1s)) + (T1r * T1q));
            }
        }
        {
            E T2g, T2u, T2s, T2w;
            {
                E T20, T2f, T2o, T2r;
                T20 = T1S - T1Z;
                T2f = T27 - T2e;
                T2g = T20 - T2f;
                T2u = T20 + T2f;
                T2o = T2k - T2n;
                T2r = T2p - T2q;
                T2s = T2o - T2r;
                T2w = T2o + T2r;
            }
            {
                E T1P, T2h, T2t, T2v;
                T1P = W[24];
                T2h = W[25];
                Ip[(rs[6])] = ((T1P * T2g) - ((T2h) * (T2s)));
                Im[(rs[6])] = (((T2h) * (T2g)) + (T1P * T2s));
                T2t = W[8];
                T2v = W[9];
                Ip[(rs[2])] = ((T2t * T2u) - ((T2v) * (T2w)));
                Im[(rs[2])] = (((T2v) * (T2u)) + (T2t * T2w));
            }
        }
        {
            E T2A, T2G, T2E, T2I;
            {
                E T2y, T2z, T2C, T2D;
                T2y = T1S + T1Z;
                T2z = T2p + T2q;
                T2A = T2y - T2z;
                T2G = T2y + T2z;
                T2C = T2k + T2n;
                T2D = T2e + T27;
                T2E = T2C - T2D;
                T2I = T2C + T2D;
            }
            {
                E T2x, T2B, T2F, T2H;
                T2x = W[16];
                T2B = W[17];
                Ip[(rs[4])] = ((T2x * T2A) - ((T2B) * (T2E)));
                Im[(rs[4])] = (((T2x) * (T2E)) + (T2B * T2A));
                T2F = W[0];
                T2H = W[1];
                Ip[0] = ((T2F * T2G) - ((T2H) * (T2I)));
                Im[0] = (((T2F) * (T2I)) + (T2H * T2G));
            }
        }
        {
            E T1G, T1M, T1K, T1O;
            {
                E T1E, T1F, T1I, T1J;
                T1E = T7 - Te;
                T1F = T1A - T1z;
                T1G = T1E - T1F;
                T1M = T1E + T1F;
                T1I = T1w - T1x;
                T1J = Tm - Tt;
                T1K = T1I - T1J;
                T1O = T1J + T1I;
            }
            {
                E T1D, T1H, T1L, T1N;
                T1D = W[22];
                T1H = W[23];
                Rp[(rs[6])] = ((T1D * T1G) - ((T1H) * (T1K)));
                Rm[(rs[6])] = (((T1D) * (T1K)) + (T1H * T1G));
                T1L = W[6];
                T1N = W[7];
                Rp[(rs[2])] = ((T1L * T1M) - ((T1N) * (T1O)));
                Rm[(rs[2])] = (((T1L) * (T1O)) + (T1N * T1M));
            }
        }
        Rp = Rp + ms;
        Ip = Ip + ms;
        Rm = Rm - ms;
        Im = Im - ms;
        rs = (stride)((char*)rs + fftw_an_INT_guaranteed_to_be_zero);
    }
}
}
