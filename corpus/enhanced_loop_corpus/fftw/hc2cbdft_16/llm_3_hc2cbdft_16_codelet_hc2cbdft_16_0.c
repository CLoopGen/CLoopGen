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
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 30); m < me; m = m + 1 , Rp += ms , Ip += ms , Rm -= ms , Im -= ms , W += 30) {
    E TB, T2L, T30, T1n, Tf, T1U, T2H, T3p, T1E, T1Z, TM, T31, T2s, T3k, T1i;
    E T2M, Tu, T1Y, T2Q, T2X, T2T, T2Y, TY, T1d, T19, T1e, T2v, T2C, T2y, T2D;
    E T1x, T1V;
    const INT * restrict rrs = rs; // Cache stride array for locality
    const R * restrict pRp = Rp, * restrict pIp = Ip;
    R * restrict pRm = Rm, * restrict pIm = Im;
    const R * restrict pW = W;

    {
        E T3, T1j, TA, T1B, T6, Tx, T1m, T1C, Ta, TC, TF, T1y, Td, TH, TK;
        E T1z;
        {
            E T1, T2, Ty, Tz;
            T1 = pRp[0];
            T2 = pRm[rrs[7]];
            T3 = T1 + T2;
            T1j = T1 - T2;
            Ty = pIp[0];
            Tz = pIm[rrs[7]];
            TA = Ty + Tz;
            T1B = Ty - Tz;
        }
        {
            E T4, T5, T1k, T1l;
            T4 = pRp[rrs[4]];
            T5 = pRm[rrs[3]];
            T6 = T4 + T5;
            Tx = T4 - T5;
            T1k = pIp[rrs[4]];
            T1l = pIm[rrs[3]];
            T1m = T1k + T1l;
            T1C = T1k - T1l;
        }
        {
            E T8, T9, TD, TE;
            T8 = pRp[rrs[2]];
            T9 = pRm[rrs[5]];
            Ta = T8 + T9;
            TC = T8 - T9;
            TD = pIp[rrs[2]];
            TE = pIm[rrs[5]];
            TF = TD + TE;
            T1y = TD - TE;
        }
        {
            E Tb, Tc, TI, TJ;
            Tb = pRm[rrs[1]];
            Tc = pRp[rrs[6]];
            Td = Tb + Tc;
            TH = Tb - Tc;
            TI = pIm[rrs[1]];
            TJ = pIp[rrs[6]];
            TK = TI + TJ;
            T1z = TJ - TI;
        }
        {
            E T7, Te, TG, TL;
            TB = Tx + TA;
            T2L = TA - Tx;
            T30 = T1j + T1m;
            T1n = T1j - T1m;
            T7 = T3 + T6;
            Te = Ta + Td;
            Tf = T7 + Te;
            T1U = T7 - Te;
            {
                E T2F, T2G, T1A, T1D;
                T2F = Ta - Td;
                T2G = T1B - T1C;
                T2H = T2F + T2G;
                T3p = T2G - T2F;
                T1A = T1y + T1z;
                T1D = T1B + T1C;
                T1E = T1A + T1D;
                T1Z = T1D - T1A;
            }
            TG = TC + TF;
            TL = TH + TK;
            TM = KP707106781 * (TG - TL);
            T31 = KP707106781 * (TG + TL);
            {
                E T2q, T2r, T1g, T1h;
                T2q = T3 - T6;
                T2r = T1z - T1y;
                T2s = T2q + T2r;
                T3k = T2q - T2r;
                T1g = TC - TF;
                T1h = TH - TK;
                T1i = KP707106781 * (T1g + T1h);
                T2M = KP707106781 * (T1g - T1h);
            }
        }
    }
    {
        E Ti, TT, TR, T1r, Tl, TO, TW, T1s, Tp, T14, T12, T1u, Ts, TZ, T17;
        E T1v;
        {
            E Tg, Th, TP, TQ;
            Tg = pRp[rrs[1]];
            Th = pRm[rrs[6]];
            Ti = Tg + Th;
            TT = Tg - Th;
            TP = pIp[rrs[1]];
            TQ = pIm[rrs[6]];
            TR = TP + TQ;
            T1r = TP - TQ;
        }
        {
            E Tj, Tk, TU, TV;
            Tj = pRp[rrs[5]];
            Tk = pRm[rrs[2]];
            Tl = Tj + Tk;
            TO = Tj - Tk;
            TU = pIp[rrs[5]];
            TV = pIm[rrs[2]];
            TW = TU + TV;
            T1s = TU - TV;
        }
        {
            E Tn, To, T10, T11;
            Tn = pRm[0];
            To = pRp[rrs[7]];
            Tp = Tn + To;
            T14 = Tn - To;
            T10 = pIm[0];
            T11 = pIp[rrs[7]];
            T12 = T10 + T11;
            T1u = T11 - T10;
        }
        {
            E Tq, Tr, T15, T16;
            Tq = pRp[rrs[3]];
            Tr = pRm[rrs[4]];
            Ts = Tq + Tr;
            TZ = Tq - Tr;
            T15 = pIp[rrs[3]];
            T16 = pIm[rrs[4]];
            T17 = T15 + T16;
            T1v = T15 - T16;
        }
        {
            E Tm, Tt, T2O, T2P;
            Tm = Ti + Tl;
            Tt = Tp + Ts;
            Tu = Tm + Tt;
            T1Y = Tm - Tt;
            T2O = TR - TO;
            T2P = TT + TW;
            T2Q = (((KP382683432) * (T2O)) + (KP923879532 * T2P));
            T2X = ((KP382683432 * T2P) - ((KP923879532) * (T2O)));
        }
        {
            E T2R, T2S, TS, TX;
            T2R = TZ + T12;
            T2S = T14 + T17;
            T2T = (((KP382683432) * (T2R)) + (KP923879532 * T2S));
            T2Y = ((KP382683432 * T2S) - ((KP923879532) * (T2R)));
            TS = TO + TR;
            TX = TT - TW;
            TY = (((KP923879532) * (TS)) + (KP382683432 * TX));
            T1d = ((KP923879532 * TX) - ((KP382683432) * (TS)));
        }
        {
            E T13, T18, T2t, T2u;
            T13 = TZ - T12;
            T18 = T14 - T17;
            T19 = ((KP923879532 * T13) - ((KP382683432) * (T18)));
            T1e = (((KP382683432) * (T13)) + (KP923879532 * T18));
            T2t = Ti - Tl;
            T2u = T1r - T1s;
            T2v = T2t - T2u;
            T2C = T2t + T2u;
        }
        {
            E T2w, T2x, T1t, T1w;
            T2w = Tp - Ts;
            T2x = T1u - T1v;
            T2y = T2w + T2x;
            T2D = T2x - T2w;
            T1t = T1r + T1s;
            T1w = T1u + T1v;
            T1x = T1t + T1w;
            T1V = T1w - T1t;
        }
    }
    {
        E Tv, T1F, T1b, T1N, T1p, T1P, T1L, T1R;
        Tv = Tf + Tu;
        T1F = T1x + T1E;
        {
            E TN, T1a, T1f, T1o;
            TN = TB + TM;
            T1a = TY + T19;
            T1b = TN + T1a;
            T1N = TN - T1a;
            T1f = T1d + T1e;
            T1o = T1i + T1n;
            T1p = T1f + T1o;
            T1P = T1o - T1f;
            {
                E T1I, T1K, T1H, T1J;
                T1I = Tf - Tu;
                T1K = T1E - T1x;
                T1H = pW[14];
                T1J = pW[15];
                T1L = ((T1H * T1I) - ((T1J) * (T1K)));
                T1R = (((T1J) * (T1I)) + (T1H * T1K));
            }
        }
        {
            E T1q, T1G, Tw, T1c;
            Tw = pW[0];
            T1c = pW[1];
            T1q = (((Tw) * (T1b)) + (T1c * T1p));
            T1G = ((Tw * T1p) - ((T1c) * (T1b)));
            ((R*)Rp)[0] = Tv - T1q;
            ((R*)Ip)[0] = T1F + T1G;
            ((R*)Rm)[0] = Tv + T1q;
            ((R*)Im)[0] = T1G - T1F;
        }
        {
            E T1Q, T1S, T1M, T1O;
            T1M = pW[16];
            T1O = pW[17];
            T1Q = (((T1M) * (T1N)) + (T1O * T1P));
            T1S = ((T1M * T1P) - ((T1O) * (T1N)));
            ((R*)Rp)[rrs[4]] = T1L - T1Q;
            ((R*)Ip)[rrs[4]] = T1R + T1S;
            ((R*)Rm)[rrs[4]] = T1L + T1Q;
            ((R*)Im)[rrs[4]] = T1S - T1R;
        }
    }
    {
        E T25, T2j, T29, T2l, T21, T2b, T2h, T2n;
        {
            E T23, T24, T27, T28;
            T23 = TB - TM;
            T24 = T1d - T1e;
            T25 = T23 + T24;
            T2j = T23 - T24;
            T27 = T19 - TY;
            T28 = T1n - T1i;
            T29 = T27 + T28;
            T2l = T28 - T27;
        }
        {
            E T1W, T20, T1T, T1X;
            T1W = T1U + T1V;
            T20 = T1Y + T1Z;
            T1T = pW[6];
            T1X = pW[7];
            T21 = ((T1T * T1W) - ((T1X) * (T20)));
            T2b = (((T1X) * (T1W)) + (T1T * T20));
        }
        {
            E T2e, T2g, T2d, T2f;
            T2e = T1U - T1V;
            T2g = T1Z - T1Y;
            T2d = pW[22];
            T2f = pW[23];
            T2h = ((T2d * T2e) - ((T2f) * (T2g)));
            T2n = (((T2f) * (T2e)) + (T2d * T2g));
        }
        {
            E T2a, T2c, T22, T26;
            T22 = pW[8];
            T26 = pW[9];
            T2a = (((T22) * (T25)) + (T26 * T29));
            T2c = ((T22 * T29) - ((T26) * (T25)));
            ((R*)Rp)[rrs[2]] = T21 - T2a;
            ((R*)Ip)[rrs[2]] = T2b + T2c;
            ((R*)Rm)[rrs[2]] = T21 + T2a;
            ((R*)Im)[rrs[2]] = T2c - T2b;
        }
        {
            E T2m, T2o, T2i, T2k;
            T2i = pW[24];
            T2k = pW[25];
            T2m = (((T2i) * (T2j)) + (T2k * T2l));
            T2o = ((T2i * T2l) - ((T2k) * (T2j)));
            ((R*)Rp)[rrs[6]] = T2h - T2m;
            ((R*)Ip)[rrs[6]] = T2n + T2o;
            ((R*)Rm)[rrs[6]] = T2h + T2m;
            ((R*)Im)[rrs[6]] = T2o - T2n;
        }
    }
    {
        E T2A, T38, T2I, T3a, T2V, T3d, T33, T3f, T2z, T2E;
        T2z = KP707106781 * (T2v + T2y);
        T2A = T2s + T2z;
        T38 = T2s - T2z;
        T2E = KP707106781 * (T2C + T2D);
        T2I = T2E + T2H;
        T3a = T2H - T2E;
        {
            E T2N, T2U, T2Z, T32;
            T2N = T2L + T2M;
            T2U = T2Q - T2T;
            T2V = T2N + T2U;
            T3d = T2N - T2U;
            T2Z = T2X + T2Y;
            T32 = T30 - T31;
            T33 = T2Z + T32;
            T3f = T32 - T2Z;
        }
        {
            E T2J, T35, T34, T36;
            {
                E T2p, T2B, T2K, T2W;
                T2p = pW[2];
                T2B = pW[3];
                T2J = ((T2p * T2A) - ((T2B) * (T2I)));
                T35 = (((T2B) * (T2A)) + (T2p * T2I));
                T2K = pW[4];
                T2W = pW[5];
                T34 = (((T2K) * (T2V)) + (T2W * T33));
                T36 = ((T2K * T33) - ((T2W) * (T2V)));
            }
            ((R*)Rp)[rrs[1]] = T2J - T34;
            ((R*)Ip)[rrs[1]] = T35 + T36;
            ((R*)Rm)[rrs[1]] = T2J + T34;
            ((R*)Im)[rrs[1]] = T36 - T35;
        }
        {
            E T3b, T3h, T3g, T3i;
            {
                E T37, T39, T3c, T3e;
                T37 = pW[18];
                T39 = pW[19];
                T3b = ((T37 * T38) - ((T39) * (T3a)));
                T3h = (((T39) * (T38)) + (T37 * T3a));
                T3c = pW[20];
                T3e = pW[21];
                T3g = (((T3c) * (T3d)) + (T3e * T3f));
                T3i = ((T3c * T3f) - ((T3e) * (T3d)));
            }
            ((R*)Rp)[rrs[5]] = T3b - T3g;
            ((R*)Ip)[rrs[5]] = T3h + T3i;
            ((R*)Rm)[rrs[5]] = T3b + T3g;
            ((R*)Im)[rrs[5]] = T3i - T3h;
        }
    }
    {
        E T3m, T3E, T3q, T3G, T3v, T3J, T3z, T3L, T3l, T3o;
        T3l = KP707106781 * (T2D - T2C);
        T3m = T3k + T3l;
        T3E = T3k - T3l;
        T3o = KP707106781 * (T2v - T2y);
        T3q = T3o + T3p;
        T3G = T3p - T3o;
        {
            E T3t, T3u, T3x, T3y;
            T3t = T2L - T2M;
            T3u = T2X - T2Y;
            T3v = T3t + T3u;
            T3J = T3t - T3u;
            T3x = T31 + T30;
            T3y = T2Q + T2T;
            T3z = T3x - T3y;
            T3L = T3y + T3x;
        }
        {
            E T3r, T3B, T3A, T3C;
            {
                E T3j, T3n, T3s, T3w;
                T3j = pW[10];
                T3n = pW[11];
                T3r = ((T3j * T3m) - ((T3n) * (T3q)));
                T3B = (((T3n) * (T3m)) + (T3j * T3q));
                T3s = pW[12];
                T3w = pW[13];
                T3A = (((T3s) * (T3v)) + (T3w * T3z));
                T3C = ((T3s * T3z) - ((T3w) * (T3v)));
            }
            ((R*)Rp)[rrs[3]] = T3r - T3A;
            ((R*)Ip)[rrs[3]] = T3B + T3C;
            ((R*)Rm)[rrs[3]] = T3r + T3A;
            ((R*)Im)[rrs[3]] = T3C - T3B;
        }
        {
            E T3H, T3N, T3M, T3O;
            {
                E T3D, T3F, T3I, T3K;
                T3D = pW[26];
                T3F = pW[27];
                T3H = ((T3D * T3E) - ((T3F) * (T3G)));
                T3N = (((T3F) * (T3E)) + (T3D * T3G));
                T3I = pW[28];
                T3K = pW[29];
                T3M = (((T3I) * (T3J)) + (T3K * T3L));
                T3O = ((T3I * T3L) - ((T3K) * (T3J)));
            }
            ((R*)Rp)[rrs[7]] = T3H - T3M;
            ((R*)Ip)[rrs[7]] = T3N + T3O;
            ((R*)Rm)[rrs[7]] = T3H + T3M;
            ((R*)Im)[rrs[7]] = T3O - T3N;
        }
    }
}
}
