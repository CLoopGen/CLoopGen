#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP1_268786568;
extern  E KP1_546020906;
extern  E KP196034280;
extern  E KP1_990369453;
extern  E KP942793473;
extern  E KP1_763842528;
extern  E KP580569354;
extern  E KP1_913880671;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP390180644;
extern  E KP1_961570560;
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
        // Unchanged body from original function
        E Ta, T2S, T18, T2u, T3F, T4V, T5l, T61, Th, T2T, T1h, T2v, T3M, T4W, T5o;
        E T62, T3Q, T5q, T5u, T44, Tp, Tw, T2V, T2W, T2X, T2Y, T3X, T5t, T1r, T2x;
        E T41, T5r, T1A, T2y, T4a, T5y, T5N, T4H, TN, T31, T4E, T5z, T39, T3q, T1L;
        E T2B, T4h, T5M, T2h, T2F, T12, T36, T5D, T5J, T5G, T5K, T1U, T26, T23, T27;
        E T4p, T4z, T4w, T4A, T34, T3r;
        {
            E T5, T3A, T3, T3y, T9, T3C, T17, T3D, T6, T14;
            {
                E T4, T3z, T1, T2;
                T4 = Cr[(csr[16])];
                T5 = KP2_000000000 * T4;
                T3z = Ci[(csi[16])];
                T3A = KP2_000000000 * T3z;
                T1 = Cr[0];
                T2 = Cr[(csr[32])];
                T3 = T1 + T2;
                T3y = T1 - T2;
                {
                    E T7, T8, T15, T16;
                    T7 = Cr[(csr[8])];
                    T8 = Cr[(csr[24])];
                    T9 = KP2_000000000 * (T7 + T8);
                    T3C = T7 - T8;
                    T15 = Ci[(csi[8])];
                    T16 = Ci[(csi[24])];
                    T17 = KP2_000000000 * (T15 - T16);
                    T3D = T15 + T16;
                }
            }
            T6 = T3 + T5;
            Ta = T6 + T9;
            T2S = T6 - T9;
            T14 = T3 - T5;
            T18 = T14 - T17;
            T2u = T14 + T17;
            {
                E T3B, T3E, T5j, T5k;
                T3B = T3y - T3A;
                T3E = KP1_414213562 * (T3C - T3D);
                T3F = T3B + T3E;
                T4V = T3B - T3E;
                T5j = T3y + T3A;
                T5k = KP1_414213562 * (T3C + T3D);
                T5l = T5j - T5k;
                T61 = T5j + T5k;
            }
        }
        {
            E Td, T3G, T1c, T3K, Tg, T3J, T1f, T3H, T19, T1g;
            {
                E Tb, Tc, T1a, T1b;
                Tb = Cr[(csr[4])];
                Tc = Cr[(csr[28])];
                Td = Tb + Tc;
                T3G = Tb - Tc;
                T1a = Ci[(csi[4])];
                T1b = Ci[(csi[28])];
                T1c = T1a - T1b;
                T3K = T1a + T1b;
            }
            {
                E Te, Tf, T1d, T1e;
                Te = Cr[(csr[20])];
                Tf = Cr[(csr[12])];
                Tg = Te + Tf;
                T3J = Te - Tf;
                T1d = Ci[(csi[20])];
                T1e = Ci[(csi[12])];
                T1f = T1d - T1e;
                T3H = T1d + T1e;
            }
            Th = KP2_000000000 * (Td + Tg);
            T2T = KP2_000000000 * (T1f + T1c);
            T19 = Td - Tg;
            T1g = T1c - T1f;
            T1h = KP1_414213562 * (T19 - T1g);
            T2v = KP1_414213562 * (T19 + T1g);
            {
                E T3I, T3L, T5m, T5n;
                T3I = T3G - T3H;
                T3L = T3J + T3K;
                T3M = ((KP1_847759065 * T3I) - ((KP765366864) * (T3L)));
                T4W = (((KP765366864) * (T3I)) + (KP1_847759065 * T3L));
                T5m = T3G + T3H;
                T5n = T3K - T3J;
                T5o = ((KP765366864 * T5m) - ((KP1_847759065) * (T5n)));
                T62 = (((KP1_847759065) * (T5m)) + (KP765366864 * T5n));
            }
        }
        {
            E Tl, T3O, T1v, T43, To, T42, T1y, T3P, Ts, T3R, T1p, T3S, Tv, T3U, T1m;
            E T3V;
            {
                E Tj, Tk, T1t, T1u;
                Tj = Cr[(csr[2])];
                Tk = Cr[(csr[30])];
                Tl = Tj + Tk;
                T3O = Tj - Tk;
                T1t = Ci[(csi[2])];
                T1u = Ci[(csi[30])];
                T1v = T1t - T1u;
                T43 = T1t + T1u;
            }
            {
                E Tm, Tn, T1w, T1x;
                Tm = Cr[(csr[18])];
                Tn = Cr[(csr[14])];
                To = Tm + Tn;
                T42 = Tm - Tn;
                T1w = Ci[(csi[18])];
                T1x = Ci[(csi[14])];
                T1y = T1w - T1x;
                T3P = T1w + T1x;
            }
            {
                E Tq, Tr, T1n, T1o;
                Tq = Cr[(csr[10])];
                Tr = Cr[(csr[22])];
                Ts = Tq + Tr;
                T3R = Tq - Tr;
                T1n = Ci[(csi[10])];
                T1o = Ci[(csi[22])];
                T1p = T1n - T1o;
                T3S = T1n + T1o;
            }
            {
                E Tt, Tu, T1k, T1l;
                Tt = Cr[(csr[6])];
                Tu = Cr[(csr[26])];
                Tv = Tt + Tu;
                T3U = Tt - Tu;
                T1k = Ci[(csi[26])];
                T1l = Ci[(csi[6])];
                T1m = T1k - T1l;
                T3V = T1l + T1k;
            }
            T3Q = T3O - T3P;
            T5q = T3O + T3P;
            T5u = T43 - T42;
            T44 = T42 + T43;
            Tp = Tl + To;
            Tw = Ts + Tv;
            T2V = Tp - Tw;
            {
                E T3T, T3W, T1j, T1q;
                T2W = T1y + T1v;
                T2X = T1p + T1m;
                T2Y = T2W - T2X;
                T3T = T3R - T3S;
                T3W = T3U - T3V;
                T3X = KP707106781 * (T3T + T3W);
                T5t = KP707106781 * (T3T - T3W);
                T1j = Tl - To;
                T1q = T1m - T1p;
                T1r = T1j + T1q;
                T2x = T1j - T1q;
                {
                    E T3Z, T40, T1s, T1z;
                    T3Z = T3R + T3S;
                    T40 = T3U + T3V;
                    T41 = KP707106781 * (T3Z - T40);
                    T5r = KP707106781 * (T3Z + T40);
                    T1s = Ts - Tv;
                    T1z = T1v - T1y;
                    T1A = T1s + T1z;
                    T2y = T1z - T1s;
                }
            }
        }
        {
            E TB, T48, T2c, T4G, TE, T4F, T2f, T49, TI, T4b, T1J, T4c, TL, T4e, T1G;
            E T4f;
            {
                E Tz, TA, T2a, T2b;
                Tz = Cr[(csr[1])];
                TA = Cr[(csr[31])];
                TB = Tz + TA;
                T48 = Tz - TA;
                T2a = Ci[(csi[1])];
                T2b = Ci[(csi[31])];
                T2c = T2a - T2b;
                T4G = T2a + T2b;
            }
            {
                E TC, TD, T2d, T2e;
                TC = Cr[(csr[17])];
                TD = Cr[(csr[15])];
                TE = TC + TD;
                T4F = TC - TD;
                T2d = Ci[(csi[17])];
                T2e = Ci[(csi[15])];
                T2f = T2d - T2e;
                T49 = T2d + T2e;
            }
            {
                E TG, TH, T1H, T1I;
                TG = Cr[(csr[9])];
                TH = Cr[(csr[23])];
                TI = TG + TH;
                T4b = TG - TH;
                T1H = Ci[(csi[9])];
                T1I = Ci[(csi[23])];
                T1J = T1H - T1I;
                T4c = T1H + T1I;
            }
            {
                E TJ, TK, T1E, T1F;
                TJ = Cr[(csr[7])];
                TK = Cr[(csr[25])];
                TL = TJ + TK;
                T4e = TJ - TK;
                T1E = Ci[(csi[25])];
                T1F = Ci[(csi[7])];
                T1G = T1E - T1F;
                T4f = T1F + T1E;
            }
            {
                E TF, TM, T1D, T1K;
                T4a = T48 - T49;
                T5y = T48 + T49;
                T5N = T4G - T4F;
                T4H = T4F + T4G;
                TF = TB + TE;
                TM = TI + TL;
                TN = TF + TM;
                T31 = TF - TM;
                {
                    E T4C, T4D, T37, T38;
                    T4C = T4b + T4c;
                    T4D = T4e + T4f;
                    T4E = KP707106781 * (T4C - T4D);
                    T5z = KP707106781 * (T4C + T4D);
                    T37 = T2f + T2c;
                    T38 = T1J + T1G;
                    T39 = T37 - T38;
                    T3q = T38 + T37;
                }
                T1D = TB - TE;
                T1K = T1G - T1J;
                T1L = T1D + T1K;
                T2B = T1D - T1K;
                {
                    E T4d, T4g, T29, T2g;
                    T4d = T4b - T4c;
                    T4g = T4e - T4f;
                    T4h = KP707106781 * (T4d + T4g);
                    T5M = KP707106781 * (T4d - T4g);
                    T29 = TI - TL;
                    T2g = T2c - T2f;
                    T2h = T29 + T2g;
                    T2F = T2g - T29;
                }
            }
        }
        {
            E TQ, T4j, T1P, T4n, TT, T4m, T1S, T4k, TX, T4q, T1Y, T4u, T10, T4t, T21;
            E T4r;
            {
                E TO, TP, T1N, T1O;
                TO = Cr[(csr[5])];
                TP = Cr[(csr[27])];
                TQ = TO + TP;
                T4j = TO - TP;
                T1N = Ci[(csi[5])];
                T1O = Ci[(csi[27])];
                T1P = T1N - T1O;
                T4n = T1N + T1O;
            }
            {
                E TR, TS, T1Q, T1R;
                TR = Cr[(csr[21])];
                TS = Cr[(csr[11])];
                TT = TR + TS;
                T4m = TR - TS;
                T1Q = Ci[(csi[21])];
                T1R = Ci[(csi[11])];
                T1S = T1Q - T1R;
                T4k = T1Q + T1R;
            }
            {
                E TV, TW, T1W, T1X;
                TV = Cr[(csr[3])];
                TW = Cr[(csr[29])];
                TX = TV + TW;
                T4q = TV - TW;
                T1W = Ci[(csi[29])];
                T1X = Ci[(csi[3])];
                T1Y = T1W - T1X;
                T4u = T1X + T1W;
            }
            {
                E TY, TZ, T1Z, T20;
                TY = Cr[(csr[13])];
                TZ = Cr[(csr[19])];
                T10 = TY + TZ;
                T4t = TY - TZ;
                T1Z = Ci[(csi[13])];
                T20 = Ci[(csi[19])];
                T21 = T1Z - T20;
                T4r = T1Z + T20;
            }
            {
                E TU, T11, T5B, T5C;
                TU = TQ + TT;
                T11 = TX + T10;
                T12 = TU + T11;
                T36 = TU - T11;
                T5B = T4j + T4k;
                T5C = T4n - T4m;
                T5D = ((KP382683432 * T5B) - ((KP923879532) * (T5C)));
                T5J = (((KP923879532) * (T5B)) + (KP382683432 * T5C));
            }
            {
                E T5E, T5F, T1M, T1T;
                T5E = T4q + T4r;
                T5F = T4t + T4u;
                T5G = ((KP382683432 * T5E) - ((KP923879532) * (T5F)));
                T5K = (((KP923879532) * (T5E)) + (KP382683432 * T5F));
                T1M = TQ - TT;
                T1T = T1P - T1S;
                T1U = T1M - T1T;
                T26 = T1M + T1T;
            }
            {
                E T1V, T22, T4l, T4o;
                T1V = TX - T10;
                T22 = T1Y - T21;
                T23 = T1V + T22;
                T27 = T22 - T1V;
                T4l = T4j - T4k;
                T4o = T4m + T4n;
                T4p = ((KP923879532 * T4l) - ((KP382683432) * (T4o)));
                T4z = (((KP382683432) * (T4l)) + (KP923879532 * T4o));
            }
            {
                E T4s, T4v, T32, T33;
                T4s = T4q - T4r;
                T4v = T4t - T4u;
                T4w = (((KP923879532) * (T4s)) + (KP382683432 * T4v));
                T4A = ((KP923879532 * T4v) - ((KP382683432) * (T4s)));
                T32 = T21 + T1Y;
                T33 = T1S + T1P;
                T34 = T32 - T33;
                T3r = T33 + T32;
            }
        }
        {
            E T13, T3x, Ty, T3w, Ti, Tx;
            T13 = KP2_000000000 * (TN + T12);
            T3x = KP2_000000000 * (T3r + T3q);
            Ti = Ta + Th;
            Tx = KP2_000000000 * (Tp + Tw);
            Ty = Ti + Tx;
            T3w = Ti - Tx;
            R0[(rs[16])] = Ty - T13;
            R0[(rs[24])] = T3w + T3x;
            R0[0] = Ty + T13;
            R0[(rs[8])] = T3w - T3x;
        }
        {
            E T3g, T3k, T3j, T3l;
            {
                E T3e, T3f, T3h, T3i;
                T3e = T2S + T2T;
                T3f = KP1_414213562 * (T2V + T2Y);
                T3g = T3e - T3f;
                T3k = T3e + T3f;
                T3h = T31 - T34;
                T3i = T39 - T36;
                T3j = ((KP765366864 * T3h) - ((KP1_847759065) * (T3i)));
                T3l = (((KP1_847759065) * (T3h)) + (KP765366864 * T3i));
            }
            R0[(rs[22])] = T3g - T3j;
            R0[(rs[30])] = T3k + T3l;
            R0[(rs[6])] = T3g + T3j;
            R0[(rs[14])] = T3k - T3l;
        }
        {
            E T3o, T3u, T3t, T3v;
            {
                E T3m, T3n, T3p, T3s;
                T3m = Ta - Th;
                T3n = KP2_000000000 * (T2X + T2W);
                T3o = T3m - T3n;
                T3u = T3m + T3n;
                T3p = TN - T12;
                T3s = T3q - T3r;
                T3t = KP1_414213562 * (T3p - T3s);
                T3v = KP1_414213562 * (T3p + T3s);
            }
            R0[(rs[20])] = T3o - T3t;
            R0[(rs[28])] = T3u + T3v;
            R0[(rs[4])] = T3o + T3t;
            R0[(rs[12])] = T3u - T3v;
        }
        {
            E T30, T3c, T3b, T3d;
            {
                E T2U, T2Z, T35, T3a;
                T2U = T2S - T2T;
                T2Z = KP1_414213562 * (T2V - T2Y);
                T30 = T2U + T2Z;
                T3c = T2U - T2Z;
                T35 = T31 + T34;
                T3a = T36 + T39;
                T3b = ((KP1_847759065 * T35) - ((KP765366864) * (T3a)));
                T3d = (((KP765366864) * (T35)) + (KP1_847759065 * T3a));
            }
            R0[(rs[18])] = T30 - T3b;
            R0[(rs[26])] = T3c + T3d;
            R0[(rs[2])] = T30 + T3b;
            R0[(rs[10])] = T3c - T3d;
        }
        {
            E T25, T2p, T2i, T2q, T1C, T2k, T2o, T2s, T24, T28;
            T24 = KP707106781 * (T1U + T23);
            T25 = T1L + T24;
            T2p = T1L - T24;
            T28 = KP707106781 * (T26 + T27);
            T2i = T28 + T2h;
            T2q = T2h - T28;
            {
                E T1i, T1B, T2m, T2n;
                T1i = T18 + T1h;
                T1B = ((KP1_847759065 * T1r) - ((KP765366864) * (T1A)));
                T1C = T1i + T1B;
                T2k = T1i - T1B;
                T2m = T18 - T1h;
                T2n = (((KP765366864) * (T1r)) + (KP1_847759065 * T1A));
                T2o = T2m - T2n;
                T2s = T2m + T2n;
            }
            {
                E T2j, T2t, T2l, T2r;
                T2j = ((KP1_961570560 * T25) - ((KP390180644) * (T2i)));
                R0[(rs[17])] = T1C - T2j;
                R0[(rs[1])] = T1C + T2j;
                T2t = (((KP1_662939224) * (T2p)) + (KP1_111140466 * T2q));
                R0[(rs[13])] = T2s - T2t;
                R0[(rs[29])] = T2s + T2t;
                T2l = (((KP390180644) * (T25)) + (KP1_961570560 * T2i));
                R0[(rs[9])] = T2k - T2l;
                R0[(rs[25])] = T2k + T2l;
                T2r = ((KP1_111140466 * T2p) - ((KP1_662939224) * (T2q)));
                R0[(rs[21])] = T2o - T2r;
                R0[(rs[5])] = T2o + T2r;
            }
        }
        {
            E T2D, T2N, T2G, T2O, T2A, T2I, T2M, T2Q, T2C, T2E;
            T2C = KP707106781 * (T27 - T26);
            T2D = T2B + T2C;
            T2N = T2B - T2C;
            T2E = KP707106781 * (T1U - T23);
            T2G = T2E + T2F;
            T2O = T2F - T2E;
            {
                E T2w, T2z, T2K, T2L;
                T2w = T2u - T2v;
                T2z = ((KP765366864 * T2x) - ((KP1_847759065) * (T2y)));
                T2A = T2w + T2z;
                T2I = T2w - T2z;
                T2K = T2u + T2v;
                T2L = (((KP1_847759065) * (T2x)) + (KP765366864 * T2y));
                T2M = T2K - T2L;
                T2Q = T2K + T2L;
            }
            {
                E T2H, T2R, T2J, T2P;
                T2H = ((KP1_662939224 * T2D) - ((KP1_111140466) * (T2G)));
                R0[(rs[19])] = T2A - T2H;
                R0[(rs[3])] = T2A + T2H;
                T2R = (((KP1_961570560) * (T2N)) + (KP390180644 * T2O));
                R0[(rs[15])] = T2Q - T2R;
                R0[(rs[31])] = T2Q + T2R;
                T2J = (((KP1_111140466) * (T2D)) + (KP1_662939224 * T2G));
                R0[(rs[11])] = T2I - T2J;
                R0[(rs[27])] = T2I + T2J;
                T2P = ((KP390180644 * T2N) - ((KP1_961570560) * (T2O)));
                R0[(rs[23])] = T2M - T2P;
                R0[(rs[7])] = T2M + T2P;
            }
        }
        {
            E T5p, T5T, T5w, T5U, T5I, T5W, T5P, T5X, T5s, T5v;
            T5p = T5l + T5o;
            T5T = T5l - T5o;
            T5s = T5q - T5r;
            T5v = T5t + T5u;
            T5w = ((KP1_662939224 * T5s) - ((KP1_111140466) * (T5v)));
            T5U = (((KP1_111140466) * (T5s)) + (KP1_662939224 * T5v));
            {
                E T5A, T5H, T5L, T5O;
                T5A = T5y - T5z;
                T5H = T5D + T5G;
                T5I = T5A + T5H;
                T5W = T5A - T5H;
                T5L = T5J - T5K;
                T5O = T5M + T5N;
                T5P = T5L + T5O;
                T5X = T5O - T5L;
            }
            {
                E T5x, T5Q, T5Z, T60;
                T5x = T5p + T5w;
                T5Q = ((KP1_913880671 * T5I) - ((KP580569354) * (T5P)));
                R1[(rs[17])] = T5x - T5Q;
                R1[(rs[1])] = T5x + T5Q;
                T5Z = T5T + T5U;
                T60 = (((KP1_763842528) * (T5W)) + (KP942793473 * T5X));
                R1[(rs[13])] = T5Z - T60;
                R1[(rs[29])] = T5Z + T60;
            }
            {
                E T5R, T5S, T5V, T5Y;
                T5R = T5p - T5w;
                T5S = (((KP580569354) * (T5I)) + (KP1_913880671 * T5P));
                R1[(rs[9])] = T5R - T5S;
                R1[(rs[25])] = T5R + T5S;
                T5V = T5T - T5U;
                T5Y = ((KP942793473 * T5W) - ((KP1_763842528) * (T5X)));
                R1[(rs[21])] = T5V - T5Y;
                R1[(rs[5])] = T5V + T5Y;
            }
        }
        {
            E T3N, T4N, T46, T4O, T4y, T4Q, T4J, T4R, T3Y, T45;
            T3N = T3F + T3M;
            T4N = T3F - T3M;
            T3Y = T3Q + T3X;
            T45 = T41 + T44;
            T46 = ((KP1_961570560 * T3Y) - ((KP390180644) * (T45)));
            T4O = (((KP390180644) * (T3Y)) + (KP1_961570560 * T45));
            {
                E T4i, T4x, T4B, T4I;
                T4i = T4a + T4h;
                T4x = T4p + T4w;
                T4y = T4i + T4x;
                T4Q = T4i - T4x;
                T4B = T4z + T4A;
                T4I = T4E + T4H;
                T4J = T4B + T4I;
                T4R = T4I - T4B;
            }
            {
                E T47, T4K, T4T, T4U;
                T47 = T3N + T46;
                T4K = ((KP1_990369453 * T4y) - ((KP196034280) * (T4J)));
                R1[(rs[16])] = T47 - T4K;
                R1[0] = T47 + T4K;
                T4T = T4N + T4O;
                T4U = (((KP1_546020906) * (T4Q)) + (KP1_268786568 * T4R));
                R1[(rs[12])] = T4T - T4U;
                R1[(rs[28])] = T4T + T4U;
            }
            {
                E T4L, T4M, T4P, T4S;
                T4L = T3N - T46;
                T4M = (((KP196034280) * (T4y)) + (KP1_990369453 * T4J));
                R1[(rs[8])] = T4L - T4M;
                R1[(rs[24])] = T4L + T4M;
                T4P = T4N - T4O;
                T4S = ((KP1_268786568 * T4Q) - ((KP1_546020906) * (T4R)));
                R1[(rs[20])] = T4P - T4S;
                R1[(rs[4])] = T4P + T4S;
            }
        }
        {
            E T63, T6h, T66, T6i, T6a, T6k, T6d, T6l, T64, T65;
            T63 = T61 - T62;
            T6h = T61 + T62;
            T64 = T5q + T5r;
            T65 = T5u - T5t;
            T66 = ((KP390180644 * T64) - ((KP1_961570560) * (T65)));
            T6i = (((KP1_961570560) * (T64)) + (KP390180644 * T65));
            {
                E T68, T69, T6b, T6c;
                T68 = T5y + T5z;
                T69 = T5J + T5K;
                T6a = T68 - T69;
                T6k = T68 + T69;
                T6b = T5D - T5G;
                T6c = T5N - T5M;
                T6d = T6b + T6c;
                T6l = T6c - T6b;
            }
            {
                E T67, T6e, T6n, T6o;
                T67 = T63 + T66;
                T6e = ((KP1_546020906 * T6a) - ((KP1_268786568) * (T6d)));
                R1[(rs[19])] = T67 - T6e;
                R1[(rs[3])] = T67 + T6e;
                T6n = T6h + T6i;
                T6o = (((KP1_990369453) * (T6k)) + (KP196034280 * T6l));
                R1[(rs[15])] = T6n - T6o;
                R1[(rs[31])] = T6n + T6o;
            }
            {
                E T6f, T6g, T6j, T6m;
                T6f = T63 - T66;
                T6g = (((KP1_268786568) * (T6a)) + (KP1_546020906 * T6d));
                R1[(rs[11])] = T6f - T6g;
                R1[(rs[27])] = T6f + T6g;
                T6j = T6h - T6i;
                T6m = ((KP196034280 * T6k) - ((KP1_990369453) * (T6l)));
                R1[(rs[23])] = T6j - T6m;
                R1[(rs[7])] = T6j + T6m;
            }
        }
        {
            E T4X, T5b, T50, T5c, T54, T5e, T57, T5f, T4Y, T4Z;
            T4X = T4V - T4W;
            T5b = T4V + T4W;
            T4Y = T3Q - T3X;
            T4Z = T44 - T41;
            T50 = ((KP1_111140466 * T4Y) - ((KP1_662939224) * (T4Z)));
            T5c = (((KP1_662939224) * (T4Y)) + (KP1_111140466 * T4Z));
            {
                E T52, T53, T55, T56;
                T52 = T4a - T4h;
                T53 = T4A - T4z;
                T54 = T52 + T53;
                T5e = T52 - T53;
                T55 = T4p - T4w;
                T56 = T4H - T4E;
                T57 = T55 + T56;
                T5f = T56 - T55;
            }
            {
                E T51, T58, T5h, T5i;
                T51 = T4X + T50;
                T58 = ((KP1_763842528 * T54) - ((KP942793473) * (T57)));
                R1[(rs[18])] = T51 - T58;
                R1[(rs[2])] = T51 + T58;
                T5h = T5b + T5c;
                T5i = (((KP1_913880671) * (T5e)) + (KP580569354 * T5f));
                R1[(rs[14])] = T5h - T5i;
                R1[(rs[30])] = T5h + T5i;
            }
            {
                E T59, T5a, T5d, T5g;
                T59 = T4X - T50;
                T5a = (((KP942793473) * (T54)) + (KP1_763842528 * T57));
                R1[(rs[10])] = T59 - T5a;
                R1[(rs[26])] = T59 + T5a;
                T5d = T5b - T5c;
                T5g = ((KP580569354 * T5e) - ((KP1_913880671) * (T5f)));
                R1[(rs[22])] = T5d - T5g;
                R1[(rs[6])] = T5d + T5g;
            }
        }
    }
}
