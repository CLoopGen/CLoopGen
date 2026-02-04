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
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, Tg, Ti, Tk, To, T1h, T1f, T6, T3, T8, T14, T1Q, Tc, T1O;
    E T1v, T18, T1t, T1n, T24, T1j, T22, Tq, Tu, T1E, T1G, Tx, Ty, Tz, TJ;
    E T1Z, TB, T1X, T1A, TZ, TL, T1y, TX;
    for (INT inner = 0; inner < 1; inner++) {
        {
            E T7, T16, Ta, T13, T4, T17, Tb, T12;
            {
                E Th, Tn, Tj, Tm;
                T2 = W[0];
                T5 = W[1];
                Tg = W[2];
                Ti = W[3];
                Th = T2 * Tg;
                Tn = T5 * Tg;
                Tj = T5 * Ti;
                Tm = T2 * Ti;
                Tk = Th - Tj;
                To = Tm + Tn;
                T1h = Tm - Tn;
                T1f = Th + Tj;
                T6 = W[5];
                T7 = T5 * T6;
                T16 = Tg * T6;
                Ta = T2 * T6;
                T13 = Ti * T6;
                T3 = W[4];
                T4 = T2 * T3;
                T17 = Ti * T3;
                Tb = T5 * T3;
                T12 = Tg * T3;
            }
            T8 = T4 - T7;
            T14 = T12 + T13;
            T1Q = T16 + T17;
            Tc = Ta + Tb;
            T1O = T12 - T13;
            T1v = Ta - Tb;
            T18 = T16 - T17;
            T1t = T4 + T7;
            {
                E T1l, T1m, T1g, T1i;
                T1l = T1f * T6;
                T1m = T1h * T3;
                T1n = T1l + T1m;
                T24 = T1l - T1m;
                T1g = T1f * T3;
                T1i = T1h * T6;
                T1j = T1g - T1i;
                T22 = T1g + T1i;
                {
                    E Tl, Tp, Ts, Tt;
                    Tl = Tk * T3;
                    Tp = To * T6;
                    Tq = Tl + Tp;
                    Ts = Tk * T6;
                    Tt = To * T3;
                    Tu = Ts - Tt;
                    T1E = Tl - Tp;
                    T1G = Ts + Tt;
                    Tx = W[6];
                    Ty = W[7];
                    Tz = (((Tk) * (Tx)) + (To * Ty));
                    TJ = (((Tq) * (Tx)) + (Tu * Ty));
                    T1Z = ((T1f * Ty) - ((T1h) * (Tx)));
                    TB = ((Tk * Ty) - ((To) * (Tx)));
                    T1X = (((T1f) * (Tx)) + (T1h * Ty));
                    T1A = ((T2 * Ty) - ((T5) * (Tx)));
                    TZ = ((Tg * Ty) - ((Ti) * (Tx)));
                    TL = ((Tq * Ty) - ((Tu) * (Tx)));
                    T1y = (((T2) * (Tx)) + (T5 * Ty));
                    TX = (((Tg) * (Tx)) + (Ti * Ty));
                }
            }
        }
        {
            E TF, T2b, T4D, T4M, T2K, T3r, T4a, T4m, T1N, T28, T29, T3J, T3M, T44, T3U;
            E T3V, T4j, T2f, T2g, T2h, T2n, T2s, T4K, T3g, T3h, T4z, T3n, T3o, T3p, T30;
            E T35, T36, TW, T1r, T1s, T3C, T3F, T43, T3X, T3Y, T4k, T2c, T2d, T2e, T2y;
            E T2D, T4J, T3d, T3e, T4y, T3k, T3l, T3m, T2P, T2U, T2V;
            {
                E T1, T48, Te, T47, Tw, T2H, TD, T2I, T9, Td;
                T1 = Rp[0];
                T48 = Rm[0];
                T9 = Rp[(rs[5])];
                Td = Rm[(rs[5])];
                Te = (((T8) * (T9)) + (Tc * Td));
                T47 = ((T8 * Td) - ((Tc) * (T9)));
                {
                    E Tr, Tv, TA, TC;
                    Tr = Ip[(rs[2])];
                    Tv = Im[(rs[2])];
                    Tw = (((Tq) * (Tr)) + (Tu * Tv));
                    T2H = ((Tq * Tv) - ((Tu) * (Tr)));
                    TA = Ip[(rs[7])];
                    TC = Im[(rs[7])];
                    TD = (((Tz) * (TA)) + (TB * TC));
                    T2I = ((Tz * TC) - ((TB) * (TA)));
                }
                {
                    E Tf, TE, T4B, T4C;
                    Tf = T1 + Te;
                    TE = Tw + TD;
                    TF = Tf - TE;
                    T2b = Tf + TE;
                    T4B = T48 - T47;
                    T4C = Tw - TD;
                    T4D = T4B - T4C;
                    T4M = T4C + T4B;
                }
                {
                    E T2G, T2J, T46, T49;
                    T2G = T1 - Te;
                    T2J = T2H - T2I;
                    T2K = T2G - T2J;
                    T3r = T2G + T2J;
                    T46 = T2H + T2I;
                    T49 = T47 + T48;
                    T4a = T46 + T49;
                    T4m = T49 - T46;
                }
            }
            {
                E T1D, T3H, T2l, T2W, T27, T3L, T2r, T34, T1M, T3I, T2m, T2Z, T1W, T3K, T2q;
                E T31;
                {
                    E T1x, T2j, T1C, T2k;
                    {
                        E T1u, T1w, T1z, T1B;
                        T1u = Rp[(rs[4])];
                        T1w = Rm[(rs[4])];
                        T1x = (((T1t) * (T1u)) + (T1v * T1w));
                        T2j = ((T1t * T1w) - ((T1v) * (T1u)));
                        T1z = Rp[(rs[9])];
                        T1B = Rm[(rs[9])];
                        T1C = (((T1y) * (T1z)) + (T1A * T1B));
                        T2k = ((T1y * T1B) - ((T1A) * (T1z)));
                    }
                    T1D = T1x + T1C;
                    T3H = T2j + T2k;
                    T2l = T2j - T2k;
                    T2W = T1x - T1C;
                }
                {
                    E T21, T32, T26, T33;
                    {
                        E T1Y, T20, T23, T25;
                        T1Y = Ip[(rs[8])];
                        T20 = Im[(rs[8])];
                        T21 = (((T1X) * (T1Y)) + (T1Z * T20));
                        T32 = ((T1X * T20) - ((T1Z) * (T1Y)));
                        T23 = Ip[(rs[3])];
                        T25 = Im[(rs[3])];
                        T26 = (((T22) * (T23)) + (T24 * T25));
                        T33 = ((T22 * T25) - ((T24) * (T23)));
                    }
                    T27 = T21 + T26;
                    T3L = T32 + T33;
                    T2r = T21 - T26;
                    T34 = T32 - T33;
                }
                {
                    E T1I, T2X, T1L, T2Y;
                    {
                        E T1F, T1H, T1J, T1K;
                        T1F = Ip[(rs[6])];
                        T1H = Im[(rs[6])];
                        T1I = (((T1E) * (T1F)) + (T1G * T1H));
                        T2X = ((T1E * T1H) - ((T1G) * (T1F)));
                        T1J = Ip[(rs[1])];
                        T1K = Im[(rs[1])];
                        T1L = (((Tg) * (T1J)) + (Ti * T1K));
                        T2Y = ((Tg * T1K) - ((Ti) * (T1J)));
                    }
                    T1M = T1I + T1L;
                    T3I = T2X + T2Y;
                    T2m = T1I - T1L;
                    T2Z = T2X - T2Y;
                }
                {
                    E T1S, T2o, T1V, T2p;
                    {
                        E T1P, T1R, T1T, T1U;
                        T1P = Rp[(rs[6])];
                        T1R = Rm[(rs[6])];
                        T1S = (((T1O) * (T1P)) + (T1Q * T1R));
                        T2o = ((T1O * T1R) - ((T1Q) * (T1P)));
                        T1T = Rp[(rs[1])];
                        T1U = Rm[(rs[1])];
                        T1V = (((T1f) * (T1T)) + (T1h * T1U));
                        T2p = ((T1f * T1U) - ((T1h) * (T1T)));
                    }
                    T1W = T1S + T1V;
                    T3K = T2o + T2p;
                    T2q = T2o - T2p;
                    T31 = T1S - T1V;
                }
                T1N = T1D - T1M;
                T28 = T1W - T27;
                T29 = T1N + T28;
                T3J = T3H + T3I;
                T3M = T3K + T3L;
                T44 = T3J + T3M;
                T3U = T3H - T3I;
                T3V = T3L - T3K;
                T4j = T3V - T3U;
                T2f = T1D + T1M;
                T2g = T1W + T27;
                T2h = T2f + T2g;
                T2n = T2l + T2m;
                T2s = T2q + T2r;
                T4K = T2n + T2s;
                T3g = T2l - T2m;
                T3h = T2q - T2r;
                T4z = T3g + T3h;
                T3n = T2W + T2Z;
                T3o = T31 + T34;
                T3p = T3n + T3o;
                T30 = T2W - T2Z;
                T35 = T31 - T34;
                T36 = T30 + T35;
            }
            {
                E TO, T3A, T2w, T2L, T1q, T3E, T2z, T2T, TV, T3B, T2x, T2O, T1b, T3D, T2C;
                E T2Q;
                {
                    E TI, T2u, TN, T2v;
                    {
                        E TG, TH, TK, TM;
                        TG = Rp[(rs[2])];
                        TH = Rm[(rs[2])];
                        TI = (((Tk) * (TG)) + (To * TH));
                        T2u = ((Tk * TH) - ((To) * (TG)));
                        TK = Rp[(rs[7])];
                        TM = Rm[(rs[7])];
                        TN = (((TJ) * (TK)) + (TL * TM));
                        T2v = ((TJ * TM) - ((TL) * (TK)));
                    }
                    TO = TI + TN;
                    T3A = T2u + T2v;
                    T2w = T2u - T2v;
                    T2L = TI - TN;
                }
                {
                    E T1e, T2R, T1p, T2S;
                    {
                        E T1c, T1d, T1k, T1o;
                        T1c = Ip[0];
                        T1d = Im[0];
                        T1e = (((T2) * (T1c)) + (T5 * T1d));
                        T2R = ((T2 * T1d) - ((T5) * (T1c)));
                        T1k = Ip[(rs[5])];
                        T1o = Im[(rs[5])];
                        T1p = (((T1j) * (T1k)) + (T1n * T1o));
                        T2S = ((T1j * T1o) - ((T1n) * (T1k)));
                    }
                    T1q = T1e + T1p;
                    T3E = T2R + T2S;
                    T2z = T1p - T1e;
                    T2T = T2R - T2S;
                }
                {
                    E TR, T2M, TU, T2N;
                    {
                        E TP, TQ, TS, TT;
                        TP = Ip[(rs[4])];
                        TQ = Im[(rs[4])];
                        TR = (((T3) * (TP)) + (T6 * TQ));
                        T2M = ((T3 * TQ) - ((T6) * (TP)));
                        TS = Ip[(rs[9])];
                        TT = Im[(rs[9])];
                        TU = (((Tx) * (TS)) + (Ty * TT));
                        T2N = ((Tx * TT) - ((Ty) * (TS)));
                    }
                    TV = TR + TU;
                    T3B = T2M + T2N;
                    T2x = TR - TU;
                    T2O = T2M - T2N;
                }
                {
                    E T11, T2A, T1a, T2B;
                    {
                        E TY, T10, T15, T19;
                        TY = Rp[(rs[8])];
                        T10 = Rm[(rs[8])];
                        T11 = (((TX) * (TY)) + (TZ * T10));
                        T2A = ((TX * T10) - ((TZ) * (TY)));
                        T15 = Rp[(rs[3])];
                        T19 = Rm[(rs[3])];
                        T1a = (((T14) * (T15)) + (T18 * T19));
                        T2B = ((T14 * T19) - ((T18) * (T15)));
                    }
                    T1b = T11 + T1a;
                    T3D = T2A + T2B;
                    T2C = T2A - T2B;
                    T2Q = T11 - T1a;
                }
                TW = TO - TV;
                T1r = T1b - T1q;
                T1s = TW + T1r;
                T3C = T3A + T3B;
                T3F = T3D + T3E;
                T43 = T3C + T3F;
                T3X = T3A - T3B;
                T3Y = T3D - T3E;
                T4k = T3X + T3Y;
                T2c = TO + TV;
                T2d = T1b + T1q;
                T2e = T2c + T2d;
                T2y = T2w + T2x;
                T2D = T2z - T2C;
                T4J = T2D - T2y;
                T3d = T2w - T2x;
                T3e = T2C + T2z;
                T4y = T3d + T3e;
                T3k = T2L + T2O;
                T3l = T2Q + T2T;
                T3m = T3k + T3l;
                T2P = T2L - T2O;
                T2U = T2Q - T2T;
                T2V = T2P + T2U;
            }
            {
                E T3S, T2a, T3R, T40, T42, T3W, T3Z, T41, T3T;
                T3S = KP559016994 * (T1s - T29);
                T2a = T1s + T29;
                T3R = ((TF) - ((KP250000000) * (T2a)));
                T3W = T3U + T3V;
                T3Z = T3X - T3Y;
                T40 = ((KP951056516 * T3W) - ((KP587785252) * (T3Z)));
                T42 = (((KP951056516) * (T3Z)) + (KP587785252 * T3W));
                Rm[(rs[9])] = TF + T2a;
                T41 = T3S + T3R;
                Rm[(rs[5])] = T41 - T42;
                Rp[(rs[6])] = T41 + T42;
                T3T = T3R - T3S;
                Rp[(rs[2])] = T3T - T40;
                Rm[(rs[1])] = T3T + T40;
            }
            {
                E T4r, T4l, T4q, T4p, T4t, T4n, T4o, T4u, T4s;
                T4r = KP559016994 * (T4k + T4j);
                T4l = T4j - T4k;
                T4q = (((KP250000000) * (T4l)) + (T4m));
                T4n = T1r - TW;
                T4o = T1N - T28;
                T4p = (((KP587785252) * (T4n)) + (KP951056516 * T4o));
                T4t = ((KP951056516 * T4n) - ((KP587785252) * (T4o)));
                Im[(rs[9])] = T4l - T4m;
                T4u = T4r + T4q;
                Im[(rs[5])] = T4t - T4u;
                Ip[(rs[6])] = T4t + T4u;
                T4s = T4q - T4r;
                Im[(rs[1])] = T4p - T4s;
                Ip[(rs[2])] = T4p + T4s;
            }
            {
                E T3x, T2i, T3y, T3O, T3Q, T3G, T3N, T3P, T3z;
                T3x = KP559016994 * (T2e - T2h);
                T2i = T2e + T2h;
                T3y = ((T2b) - ((KP250000000) * (T2i)));
                T3G = T3C - T3F;
                T3N = T3J - T3M;
                T3O = (((KP951056516) * (T3G)) + (KP587785252 * T3N));
                T3Q = ((KP951056516 * T3N) - ((KP587785252) * (T3G)));
                Rp[0] = T2b + T2i;
                T3P = T3y - T3x;
                Rm[(rs[7])] = T3P - T3Q;
                Rp[(rs[8])] = T3P + T3Q;
                T3z = T3x + T3y;
                Rp[(rs[4])] = T3z - T3O;
                Rm[(rs[3])] = T3z + T3O;
            }
            {
                E T4e, T45, T4f, T4d, T4h, T4b, T4c, T4i, T4g;
                T4e = KP559016994 * (T43 - T44);
                T45 = T43 + T44;
                T4f = ((T4a) - ((KP250000000) * (T45)));
                T4b = T2c - T2d;
                T4c = T2f - T2g;
                T4d = (((KP951056516) * (T4b)) + (KP587785252 * T4c));
                T4h = ((KP587785252 * T4b) - ((KP951056516) * (T4c)));
                Ip[0] = T45 + T4a;
                T4i = T4f - T4e;
                Im[(rs[7])] = T4h - T4i;
                Ip[(rs[8])] = T4h + T4i;
                T4g = T4e + T4f;
                Im[(rs[3])] = T4d - T4g;
                Ip[(rs[4])] = T4d + T4g;
            }
            {
                E T39, T37, T38, T2F, T3b, T2t, T2E, T3c, T3a;
                T39 = KP559016994 * (T2V - T36);
                T37 = T2V + T36;
                T38 = ((T2K) - ((KP250000000) * (T37)));
                T2t = T2n - T2s;
                T2E = T2y + T2D;
                T2F = ((KP951056516 * T2t) - ((KP587785252) * (T2E)));
                T3b = (((KP951056516) * (T2E)) + (KP587785252 * T2t));
                Rm[(rs[4])] = T2K + T37;
                T3c = T39 + T38;
                Rm[(rs[8])] = T3b + T3c;
                Rm[0] = T3c - T3b;
                T3a = T38 - T39;
                Rp[(rs[3])] = T2F + T3a;
                Rp[(rs[7])] = T3a - T2F;
            }
            {
                E T4Q, T4L, T4R, T4P, T4U, T4N, T4O, T4T, T4S;
                T4Q = KP559016994 * (T4J + T4K);
                T4L = T4J - T4K;
                T4R = (((KP250000000) * (T4L)) + (T4M));
                T4N = T2P - T2U;
                T4O = T30 - T35;
                T4P = (((KP951056516) * (T4N)) + (KP587785252 * T4O));
                T4U = ((KP951056516 * T4O) - ((KP587785252) * (T4N)));
                Im[(rs[4])] = T4L - T4M;
                T4T = T4Q + T4R;
                Ip[(rs[3])] = T4T - T4U;
                Ip[(rs[7])] = T4U + T4T;
                T4S = T4Q - T4R;
                Im[(rs[8])] = T4P + T4S;
                Im[0] = T4S - T4P;
            }
            {
                E T3q, T3s, T3t, T3j, T3v, T3f, T3i, T3w, T3u;
                T3q = KP559016994 * (T3m - T3p);
                T3s = T3m + T3p;
                T3t = ((T3r) - ((KP250000000) * (T3s)));
                T3f = T3d - T3e;
                T3i = T3g - T3h;
                T3j = (((KP951056516) * (T3f)) + (KP587785252 * T3i));
                T3v = ((KP951056516 * T3i) - ((KP587785252) * (T3f)));
                Rp[(rs[5])] = T3r + T3s;
                T3w = T3t - T3q;
                Rm[(rs[6])] = T3v + T3w;
                Rm[(rs[2])] = T3w - T3v;
                T3u = T3q + T3t;
                Rp[(rs[1])] = T3j + T3u;
                Rp[(rs[9])] = T3u - T3j;
            }
            {
                E T4A, T4E, T4F, T4x, T4I, T4v, T4w, T4H, T4G;
                T4A = KP559016994 * (T4y - T4z);
                T4E = T4y + T4z;
                T4F = ((T4D) - ((KP250000000) * (T4E)));
                T4v = T3n - T3o;
                T4w = T3k - T3l;
                T4x = ((KP951056516 * T4v) - ((KP587785252) * (T4w)));
                T4I = (((KP951056516) * (T4w)) + (KP587785252 * T4v));
                Ip[(rs[5])] = T4E + T4D;
                T4H = T4A + T4F;
                Ip[(rs[1])] = T4H - T4I;
                Ip[(rs[9])] = T4I + T4H;
                T4G = T4A - T4F;
                Im[(rs[6])] = T4x + T4G;
                Im[(rs[2])] = T4G - T4x;
            }
        }
    }
}
}
