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
for (m = mb , W = W + ((mb - 1) * 30); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 60 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T7, T2K, T2W, Tw, T17, T1S, T2k, T1w, Te, TD, T1x, T10, T2n, T2L, T1Z;
    E T2X, Tm, T1z, TN, T19, T2e, T2p, T2P, T2Z, Tt, T1A, TW, T1a, T27, T2q;
    E T2S, T30;
    E T7b, T2Kb, T2Wb, Twb, T17b, T1Sb, T2kb, T1wb, Teb, TDb, T1xb, T10b, T2nb, T2Lb, T1Zb;
    E T2Xb, Tmb, T1zb, TNb, T19b, T2eb, T2pb, T2Pb, T2Zb, Ttb, T1Ab, TWb, T1ab, T27b, T2qb;
    E T2Sb, T30b;
    {
        E T3, T1Q, T13, T2j, T6, T2i, T16, T1R;
        E T3b, T1Qb, T13b, T2jb, T6b, T2ib, T16b, T1Rb;
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
        {
            E T1b, T2b, T11b, T12b;
            T1b = Rp[ms];
            T2b = Rm[(rs[7]) - ms];
            T3b = T1b + T2b;
            T1Qb = T1b - T2b;
            T11b = Ip[ms];
            T12b = Im[(rs[7]) - ms];
            T13b = T11b - T12b;
            T2jb = T11b + T12b;
        }
        {
            E T4b, T5b, T14b, T15b;
            T4b = Rp[(rs[4]) + ms];
            T5b = Rm[(rs[3]) - ms];
            T6b = T4b + T5b;
            T2ib = T4b - T5b;
            T14b = Ip[(rs[4]) + ms];
            T15b = Im[(rs[3]) - ms];
            T16b = T14b - T15b;
            T1Rb = T14b + T15b;
        }
        T7b = T3b + T6b;
        T2Kb = T1Qb + T1Rb;
        T2Wb = T2jb - T2ib;
        Twb = T3b - T6b;
        T17b = T13b - T16b;
        T1Sb = T1Qb - T1Rb;
        T2kb = T2ib + T2jb;
        T1wb = T13b + T16b;
    }
    {
        E Ta, T1T, TC, T1U, Td, T1W, Tz, T1X;
        E Tab, T1Tb, TCb, T1Ub, Tdb, T1Wb, Tzb, T1Xb;
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
        {
            E T8b, T9b, TAb, TBb;
            T8b = Rp[(rs[2]) + ms];
            T9b = Rm[(rs[5]) - ms];
            Tab = T8b + T9b;
            T1Tb = T8b - T9b;
            TAb = Ip[(rs[2]) + ms];
            TBb = Im[(rs[5]) - ms];
            TCb = TAb - TBb;
            T1Ub = TAb + TBb;
        }
        {
            E Tbb, Tcb, Txb, Tyb;
            Tbb = Rm[(rs[1]) - ms];
            Tcb = Rp[(rs[6]) + ms];
            Tdb = Tbb + Tcb;
            T1Wb = Tbb - Tcb;
            Txb = Ip[(rs[6]) + ms];
            Tyb = Im[(rs[1]) - ms];
            Tzb = Txb - Tyb;
            T1Xb = Txb + Tyb;
        }
        Teb = Tab + Tdb;
        TDb = Tzb - TCb;
        T1xb = TCb + Tzb;
        T10b = Tab - Tdb;
        {
            E T2lb, T2mb, T1Vb, T1Yb;
            T2lb = T1Tb + T1Ub;
            T2mb = T1Wb + T1Xb;
            T2nb = KP707106781 * (T2lb - T2mb);
            T2Lb = KP707106781 * (T2lb + T2mb);
            T1Vb = T1Tb - T1Ub;
            T1Yb = T1Wb - T1Xb;
            T1Zb = KP707106781 * (T1Vb + T1Yb);
            T2Xb = KP707106781 * (T1Vb - T1Yb);
        }
    }
    {
        E Ti, T2b, TI, T29, Tl, T28, TL, T2c, TF, TM;
        E Tib, T2bb, TIb, T29b, Tlb, T28b, TLb, T2cb, TFb, TMb;
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
        {
            E Tgb, Thb, TGb, THb;
            Tgb = Rp[(rs[1]) + ms];
            Thb = Rm[(rs[6]) - ms];
            Tib = Tgb + Thb;
            T2bb = Tgb - Thb;
            TGb = Ip[(rs[1]) + ms];
            THb = Im[(rs[6]) - ms];
            TIb = TGb - THb;
            T29b = TGb + THb;
        }
        {
            E Tjb, Tkb, TJb, TKb;
            Tjb = Rp[(rs[5]) + ms];
            Tkb = Rm[(rs[2]) - ms];
            Tlb = Tjb + Tkb;
            T28b = Tjb - Tkb;
            TJb = Ip[(rs[5]) + ms];
            TKb = Im[(rs[2]) - ms];
            TLb = TJb - TKb;
            T2cb = TJb + TKb;
        }
        Tmb = Tib + Tlb;
        T1zb = TIb + TLb;
        TFb = Tib - Tlb;
        TMb = TIb - TLb;
        TNb = TFb - TMb;
        T19b = TFb + TMb;
        {
            E T2ab, T2db, T2Nb, T2Ob;
            T2ab = T28b + T29b;
            T2db = T2bb - T2cb;
            T2eb = (((KP923879532) * (T2ab)) + (KP382683432 * T2db));
            T2pb = ((KP923879532 * T2db) - ((KP382683432) * (T2ab)));
            T2Nb = T2bb + T2cb;
            T2Ob = T29b - T28b;
            T2Pb = ((KP382683432 * T2Nb) - ((KP923879532) * (T2Ob)));
            T2Zb = (((KP382683432) * (T2Ob)) + (KP923879532 * T2Nb));
        }
    }
    {
        E Tp, T24, TR, T22, Ts, T21, TU, T25, TO, TV;
        E Tpb, T24b, TRb, T22b, Tsb, T21b, TUb, T25b, TOb, TVb;
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
        {
            E Tnb, Tob, TPb, TQb;
            Tnb = Rm[-ms];
            Tob = Rp[(rs[7]) + ms];
            Tpb = Tnb + Tob;
            T24b = Tnb - Tob;
            TPb = Ip[(rs[7]) + ms];
            TQb = Im[-ms];
            TRb = TPb - TQb;
            T22b = TPb + TQb;
        }
        {
            E Tqb, Trb, TSb, TTb;
            Tqb = Rp[(rs[3]) + ms];
            Trb = Rm[(rs[4]) - ms];
            Tsb = Tqb + Trb;
            T21b = Tqb - Trb;
            TSb = Ip[(rs[3]) + ms];
            TTb = Im[(rs[4]) - ms];
            TUb = TSb - TTb;
            T25b = TSb + TTb;
        }
        Ttb = Tpb + Tsb;
        T1Ab = TRb + TUb;
        TOb = Tpb - Tsb;
        TVb = TRb - TUb;
        TWb = TOb + TVb;
        T1ab = TVb - TOb;
        {
            E T23b, T26b, T2Qb, T2Rb;
            T23b = T21b - T22b;
            T26b = T24b - T25b;
            T27b = ((KP923879532 * T23b) - ((KP382683432) * (T26b)));
            T2qb = (((KP382683432) * (T23b)) + (KP923879532 * T26b));
            T2Qb = T24b + T25b;
            T2Rb = T21b + T22b;
            T2Sb = ((KP382683432 * T2Qb) - ((KP923879532) * (T2Rb)));
            T30b = (((KP382683432) * (T2Rb)) + (KP923879532 * T2Qb));
        }
    }
    {
        E Tf, Tu, T1u, T1y, T1B, T1C, T1t, T1v;
        E Tfb, Tub, T1ub, T1yb, T1Bb, T1Cb, T1tb, T1vb;
        Tf = T7 + Te;
        Tu = Tm + Tt;
        T1u = Tf - Tu;
        T1y = T1w + T1x;
        T1B = T1y - T1B;
        Rp[0] = Tf + Tu;
        Rm[0] = T1y + T1B;
        T1t = W[14];
        T1v = W[15];
        Rp[(rs[4])] = ((T1t * T1u) - ((T1v) * (T1C)));
        Rm[(rs[4])] = (((T1v) * (T1u)) + (T1t * T1C));
        Tfb = T7b + Teb;
        Tub = Tmb + Ttb;
        T1ub = Tfb - Tub;
        T1yb = T1wb + T1xb;
        T1Bb = T1yb - T1Ab;
        Rp[ms] = Tfb + Tub;
        Rm[-ms] = T1yb + T1Ab;
        T1tb = W[44];
        T1vb = W[45];
        Rp[(rs[4]) + ms] = ((T1tb * T1ub) - ((T1vb) * (T1Cb)));
        Rm[(rs[4]) - ms] = (((T1vb) * (T1ub)) + (T1tb * T1Cb));
    }
    {
        E T2U, T34, T32, T36;
        E T2Ub, T34b, T32b, T36b;
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
        {
            E T2Mb, T2Tb, T2Yb, T31b;
            T2Mb = T2Kb - T2Lb;
            T2Tb = T2Pb + T2Sb;
            T2Ub = T2Mb - T2Tb;
            T34b = T2Mb + T2Tb;
            T2Yb = T2Wb + T2Xb;
            T31b = T2Zb - T30b;
            T32b = T2Yb - T31b;
            T36b = T2Yb + T31b;
        }
        {
            E T2Jb, T2Vb, T33b, T35b;
            T2Jb = W[50];
            T2Vb = W[51];
            Ip[(rs[5]) + ms] = ((T2Jb * T2Ub) - ((T2Vb) * (T32b)));
            Im[(rs[5]) + ms] = (((T2Vb) * (T2Ub)) + (T2Jb * T32b));
            T33b = W[34];
            T35b = W[35];
            Ip[(rs[1]) + ms] = ((T33b * T34b) - ((T35b) * (T36b)));
            Im[(rs[1]) + ms] = (((T35b) * (T34b)) + (T33b * T36b));
        }
    }
    {
        E T3a, T3g, T3e, T3i;
        E T3ab, T3gb, T3eb, T3ib;
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
        {
            E T38b, T39b, T3cb, T3db;
            T38b = T2Kb + T2Lb;
            T39b = T2Zb + T30b;
            T3ab = T38b - T39b;
            T3gb = T38b + T39b;
            T3cb = T2Wb - T2Xb;
            T3db = T2Pb - T2Sb;
            T3eb = T3cb + T3db;
            T3ib = T3cb - T3db;
        }
        {
            E T37b, T3bb, T3fb, T3hb;
            T37b = W[42];
            T3bb = W[43];
            Ip[(rs[3]) + ms] = ((T37b * T3ab) - ((T3bb) * (T3eb)));
            Im[(rs[3]) + ms] = (((T37b) * (T3eb)) + (T3bb * T3ab));
            T3fb = W[58];
            T3hb = W[59];
            Ip[(rs[7]) + ms] = ((T3fb * T3gb) - ((T3hb) * (T3ib)));
            Im[(rs[7]) + ms] = (((T3fb) * (T3ib)) + (T3hb * T3gb));
        }
    }
    {
        E TY, T1e, T1c, T1g;
        E TYb, T1eb, T1cb, T1gb;
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
        {
            E TEb, TXb, T18b, T1bb;
            TEb = Twb + TDb;
            TXb = KP707106781 * (TNb + TWb);
            TYb = TEb - TXb;
            T1eb = TEb + TXb;
            T18b = T10b + T17b;
            T1bb = KP707106781 * (T19b + T1ab);
            T1cb = T18b - T1bb;
            T1gb = T18b + T1bb;
        }
        {
            E Tvb, TZb, T1db, T1fb;
            Tvb = W[48];
            TZb = W[49];
            Rp[(rs[5]) + ms] = ((Tvb * TYb) - ((TZb) * (T1cb)));
            Rm[(rs[5]) + ms] = (((TZb) * (TYb)) + (Tvb * T1cb));
            T1db = W[32];
            T1fb = W[33];
            Rp[(rs[1]) + ms] = ((T1db * T1eb) - ((T1fb) * (T1gb)));
            Rm[(rs[1]) + ms] = (((T1fb) * (T1eb)) + (T1db * T1gb));
        }
    }
    {
        E T1k, T1q, T1o, T1s;
        E T1kb, T1qb, T1ob, T1sb;
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
        {
            E T1ib, T1jb, T1mb, T1nb;
            T1ib = Twb - TDb;
            T1jb = KP707106781 * (T1ab - T19b);
            T1kb = T1ib - T1jb;
            T1qb = T1ib + T1jb;
            T1mb = T17b - T10b;
            T1nb = KP707106781 * (TNb - TWb);
            T1ob = T1mb - T1nb;
            T1sb = T1mb + T1nb;
        }
        {
            E T1hb, T1lb, T1pb, T1rb;
            T1hb = W[56];
            T1lb = W[57];
            Rp[(rs[7]) + ms] = ((T1hb * T1kb) - ((T1lb) * (T1ob)));
            Rm[(rs[7]) + ms] = (((T1hb) * (T1ob)) + (T1lb * T1kb));
            T1pb = W[40];
            T1rb = W[41];
            Rp[(rs[3]) + ms] = ((T1pb * T1qb) - ((T1rb) * (T1sb)));
            Rm[(rs[3]) + ms] = (((T1pb) * (T1sb)) + (T1rb * T1qb));
        }
    }
    {
        E T2g, T2u, T2s, T2w;
        E T2gb, T2ub, T2sb, T2wb;
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
        {
            E T20b, T2fb, T2ob, T2rb;
            T20b = T1Sb - T1Zb;
            T2fb = T27b - T2eb;
            T2gb = T20b - T2fb;
            T2ub = T20b + T2fb;
            T2ob = T2kb - T2nb;
            T2rb = T2pb - T2qb;
            T2sb = T2ob - T2rb;
            T2wb = T2ob + T2rb;
        }
        {
            E T1Pb, T2hb, T2tb, T2vb;
            T1Pb = W[54];
            T2hb = W[55];
            Ip[(rs[6]) + ms] = ((T1Pb * T2gb) - ((T2hb) * (T2sb)));
            Im[(rs[6]) + ms] = (((T2hb) * (T2gb)) + (T1Pb * T2sb));
            T2tb = W[38];
            T2vb = W[39];
            Ip[(rs[2]) + ms] = ((T2tb * T2ub) - ((T2vb) * (T2wb)));
            Im[(rs[2]) + ms] = (((T2vb) * (T2ub)) + (T2tb * T2wb));
        }
    }
    {
        E T2A, T2G, T2E, T2I;
        E T2Ab, T2Gb, T2Eb, T2Ib;
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
        {
            E T2yb, T2zb, T2Cb, T2Db;
            T2yb = T1Sb + T1Zb;
            T2zb = T2pb + T2qb;
            T2Ab = T2yb - T2zb;
            T2Gb = T2yb + T2zb;
            T2Cb = T2kb + T2nb;
            T2Db = T2eb + T27b;
            T2Eb = T2Cb - T2Db;
            T2Ib = T2Cb + T2Db;
        }
        {
            E T2xb, T2Bb, T2Fb, T2Hb;
            T2xb = W[46];
            T2Bb = W[47];
            Ip[(rs[4]) + ms] = ((T2xb * T2Ab) - ((T2Bb) * (T2Eb)));
            Im[(rs[4]) + ms] = (((T2xb) * (T2Eb)) + (T2Bb * T2Ab));
            T2Fb = W[30];
            T2Hb = W[31];
            Ip[ms] = ((T2Fb * T2Gb) - ((T2Hb) * (T2Ib)));
            Im[ms] = (((T2Fb) * (T2Ib)) + (T2Hb * T2Gb));
        }
    }
    {
        E T1G, T1M, T1K, T1O;
        E T1Gb, T1Mb, T1Kb, T1Ob;
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
        {
            E T1Eb, T1Fb, T1Ib, T1Jb;
            T1Eb = T7b - Teb;
            T1Fb = T1Ab - T1zb;
            T1Gb = T1Eb - T1Fb;
            T1Mb = T1Eb + T1Fb;
            T1Ib = T1wb - T1xb;
            T1Jb = Tmb - Ttb;
            T1Kb = T1Ib - T1Jb;
            T1Ob = T1Jb + T1Ib;
        }
        {
            E T1Db, T1Hb, T1Lb, T1Nb;
            T1Db = W[52];
            T1Hb = W[53];
            Rp[(rs[6]) + ms] = ((T1Db * T1Gb) - ((T1Hb) * (T1Kb)));
            Rm[(rs[6]) + ms] = (((T1Db) * (T1Kb)) + (T1Hb * T1Gb));
            T1Lb = W[36];
            T1Nb = W[37];
            Rp[(rs[2]) + ms] = ((T1Lb * T1Mb) - ((T1Nb) * (T1Ob)));
            Rm[(rs[2]) + ms] = (((T1Lb) * (T1Ob)) + (T1Nb * T1Mb));
        }
    }
}
}
