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
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , Rp += ms , Ip += ms , Rm -= ms , Im -= ms , W += 8) {
    E TD, TG, TE, TH, TJ, T1t, T27, T25, T1T, T1R, T1V, T2j, T2Z, T21, T2X;
    E T2T, T2n, T2P, T3V, T41, T3R, T3X, T29, T2c, T4H, T4L, T1L, T1M, T1N, T2d;
    E T4R, T1P, T4P, T49, T2N, T2f, T47, T2L;
    const INT * restrict rs_ptr = (const INT *)rs;
    E * restrict rp_ptr = &Rp[0];
    E * restrict ip_ptr = &Ip[0];
    E * restrict rm_ptr = &Rm[0];
    E * restrict im_ptr = &Im[0];
    const E * restrict w_ptr = &W[0];

    {
        E T1U, T2l, T1Z, T2i, T1S, T2m, T20, T2h;
        {
            E TF, T1s, TI, T1r;
            TD = w_ptr[0];
            TG = w_ptr[1];
            TE = w_ptr[2];
            TH = w_ptr[3];
            TF = TD * TE;
            T1s = TG * TE;
            TI = TG * TH;
            T1r = TD * TH;
            TJ = TF + TI;
            T1t = T1r - T1s;
            T27 = T1r + T1s;
            T25 = TF - TI;
            T1T = w_ptr[5];
            T1U = TH * T1T;
            T2l = TD * T1T;
            T1Z = TE * T1T;
            T2i = TG * T1T;
            T1R = w_ptr[4];
            T1S = TE * T1R;
            T2m = TG * T1R;
            T20 = TH * T1R;
            T2h = TD * T1R;
        }
        T1V = T1S + T1U;
        T2j = T2h - T2i;
        T2Z = T1Z + T20;
        T21 = T1Z - T20;
        T2X = T1S - T1U;
        T2T = T2l - T2m;
        T2n = T2l + T2m;
        T2P = T2h + T2i;
        {
            E T3T, T3U, T3P, T3Q;
            T3T = TJ * T1T;
            T3U = T1t * T1R;
            T3V = T3T - T3U;
            T41 = T3T + T3U;
            T3P = TJ * T1R;
            T3Q = T1t * T1T;
            T3R = T3P + T3Q;
            T3X = T3P - T3Q;
            {
                E T26, T28, T2a, T2b;
                T26 = T25 * T1R;
                T28 = T27 * T1T;
                T29 = T26 + T28;
                T2a = T25 * T1T;
                T2b = T27 * T1R;
                T2c = T2a - T2b;
                T4H = T26 - T28;
                T4L = T2a + T2b;
                T1L = w_ptr[6];
                T1M = w_ptr[7];
                T1N = TD * T1L + TG * T1M;
                T2d = T29 * T1L + T2c * T1M;
                T4R = TJ * T1M - T1t * T1L;
                T1P = TD * T1M - TG * T1L;
                T4P = TJ * T1L + T1t * T1M;
                T49 = T25 * T1M - T27 * T1L;
                T2N = TE * T1M - TH * T1L;
                T2f = T29 * T1M - T2c * T1L;
                T47 = T25 * T1L + T27 * T1M;
                T2L = TE * T1L + TH * T1M;
            }
        }
    }

    {
        E T7, T4i, T4x, TK, T1D, T3i, T3E, T2D, T19, T3L, T3M, T1o, T2x, T4C, T4B;
        E T2u, T1v, T4r, T4o, T1u, T2H, T37, T2I, T3e, T3p, T3w, T3x, Tm, TB, TC;
        E T4u, T4v, T4y, T2A, T2B, T2E, T1E, T1F, T1G, T4d, T4g, T4j, T3F, T3G, T3H;
        E TN, TQ, TR, T48, T4a;

        {
            E T3, T3g, T1z, T3C, T6, T3D, T1C, T3h;
            {
                E T1, T2, T1x, T1y;
                T1 = rp_ptr[0];
                T2 = rm_ptr[rs_ptr[9]];
                T3 = T1 + T2;
                T3g = T1 - T2;
                T1x = ip_ptr[0];
                T1y = im_ptr[rs_ptr[9]];
                T1z = T1x - T1y;
                T3C = T1x + T1y;
            }
            {
                E T4, T5, T1A, T1B;
                T4 = rp_ptr[rs_ptr[5]];
                T5 = rm_ptr[rs_ptr[4]];
                T6 = T4 + T5;
                T3D = T4 - T5;
                T1A = ip_ptr[rs_ptr[5]];
                T1B = im_ptr[rs_ptr[4]];
                T1C = T1A - T1B;
                T3h = T1A + T1B;
            }
            T7 = T3 + T6;
            T4i = T3g - T3h;
            T4x = T3D + T3C;
            TK = T3 - T6;
            T1D = T1z - T1C;
            T3i = T3g + T3h;
            T3E = T3C - T3D;
            T2D = T1z + T1C;
        }

        {
            E Te, T4b, T4m, TL, T11, T33, T3l, T2s, TA, T4f, T4q, TP, T1n, T3d, T3v;
            E T2w, Tl, T4c, T4n, TM, T18, T36, T3o, T2t, Tt, T4e, T4p, TO, T1g, T3a;
            E T3s, T2v;

            {
                E Ta, T3j, TX, T31, Td, T32, T10, T3k;
                {
                    E T8, T9, TV, TW;
                    T8 = rp_ptr[rs_ptr[4]];
                    T9 = rm_ptr[rs_ptr[5]];
                    Ta = T8 + T9;
                    T3j = T8 - T9;
                    TV = ip_ptr[rs_ptr[4]];
                    TW = im_ptr[rs_ptr[5]];
                    TX = TV - TW;
                    T31 = TV + TW;
                }
                {
                    E Tb, Tc, TY, TZ;
                    Tb = rp_ptr[rs_ptr[9]];
                    Tc = rm_ptr[0];
                    Td = Tb + Tc;
                    T32 = Tb - Tc;
                    TY = ip_ptr[rs_ptr[9]];
                    TZ = im_ptr[0];
                    T10 = TY - TZ;
                    T3k = TY + TZ;
                }
                Te = Ta + Td;
                T4b = T3j - T3k;
                T4m = T32 + T31;
                TL = Ta - Td;
                T11 = TX - T10;
                T33 = T31 - T32;
                T3l = T3j + T3k;
                T2s = TX + T10;
            }

            {
                E Tw, T3t, T1j, T3c, Tz, T3b, T1m, T3u;
                {
                    E Tu, Tv, T1h, T1i;
                    Tu = rm_ptr[rs_ptr[7]];
                    Tv = rp_ptr[rs_ptr[2]];
                    Tw = Tu + Tv;
                    T3t = Tu - Tv;
                    T1h = ip_ptr[rs_ptr[2]];
                    T1i = im_ptr[rs_ptr[7]];
                    T1j = T1h - T1i;
                    T3c = T1h + T1i;
                }
                {
                    E Tx, Ty, T1k, T1l;
                    Tx = rm_ptr[rs_ptr[2]];
                    Ty = rp_ptr[rs_ptr[7]];
                    Tz = Tx + Ty;
                    T3b = Tx - Ty;
                    T1k = ip_ptr[rs_ptr[7]];
                    T1l = im_ptr[rs_ptr[2]];
                    T1m = T1k - T1l;
                    T3u = T1k + T1l;
                }
                TA = Tw + Tz;
                T4f = T3t + T3u;
                T4q = T3b - T3c;
                TP = Tw - Tz;
                T1n = T1j - T1m;
                T3d = T3b + T3c;
                T3v = T3t - T3u;
                T2w = T1j + T1m;
            }

            {
                E Th, T3m, T14, T35, Tk, T34, T17, T3n;
                {
                    E Tf, Tg, T12, T13;
                    Tf = rm_ptr[rs_ptr[3]];
                    Tg = rp_ptr[rs_ptr[6]];
                    Th = Tf + Tg;
                    T3m = Tf - Tg;
                    T12 = ip_ptr[rs_ptr[6]];
                    T13 = im_ptr[rs_ptr[3]];
                    T14 = T12 - T13;
                    T35 = T12 + T13;
                }
                {
                    E Ti, Tj, T15, T16;
                    Ti = rp_ptr[rs_ptr[1]];
                    Tj = rm_ptr[rs_ptr[8]];
                    Tk = Ti + Tj;
                    T34 = Ti - Tj;
                    T15 = ip_ptr[rs_ptr[1]];
                    T16 = im_ptr[rs_ptr[8]];
                    T17 = T15 - T16;
                    T3n = T15 + T16;
                }
                Tl = Th + Tk;
                T4c = T3m - T3n;
                T4n = T34 - T35;
                TM = Th - Tk;
                T18 = T14 - T17;
                T36 = T34 + T35;
                T3o = T3m + T3n;
                T2t = T14 + T17;
            }

            {
                E Tp, T3q, T1c, T38, Ts, T39, T1f, T3r;
                {
                    E Tn, To, T1a, T1b;
                    Tn = rp_ptr[rs_ptr[8]];
                    To = rm_ptr[rs_ptr[1]];
                    Tp = Tn + To;
                    T3q = Tn - To;
                    T1a = ip_ptr[rs_ptr[8]];
                    T1b = im_ptr[rs_ptr[1]];
                    T1c = T1a - T1b;
                    T38 = T1a + T1b;
                }
                {
                    E Tq, Tr, T1d, T1e;
                    Tq = rm_ptr[rs_ptr[6]];
                    Tr = rp_ptr[rs_ptr[3]];
                    Ts = Tq + Tr;
                    T39 = Tq - Tr;
                    T1d = ip_ptr[rs_ptr[3]];
                    T1e = im_ptr[rs_ptr[6]];
                    T1f = T1d - T1e;
                    T3r = T1d + T1e;
                }
                Tt = Tp + Ts;
                T4e = T3q + T3r;
                T4p = T39 + T38;
                TO = Tp - Ts;
                T1g = T1c - T1f;
                T3a = T38 - T39;
                T3s = T3q - T3r;
                T2v = T1c + T1f;
            }

            T19 = T11 - T18;
            T3L = T3l - T3o;
            T3M = T3s - T3v;
            T1o = T1g - T1n;
            T2x = T2v - T2w;
            T4C = T4e - T4f;
            T4B = T4b - T4c;
            T2u = T2s - T2t;
            T1v = TO - TP;
            T4r = T4p - T4q;
            T4o = T4m - T4n;
            T1u = TL - TM;
            T2H = Te - Tl;
            T37 = T33 + T36;
            T2I = Tt - TA;
            T3e = T3a + T3d;
            T3p = T3l + T3o;
            T3w = T3s + T3v;
            T3x = T3p + T3w;
            Tm = Te + Tl;
            TB = Tt + TA;
            TC = Tm + TB;
            T4u = T4m + T4n;
            T4v = T4p + T4q;
            T4y = T4u + T4v;
            T2A = T2s + T2t;
            T2B = T2v + T2w;
            T2E = T2A + T2B;
            T1E = T11 + T18;
            T1F = T1g + T1n;
            T1G = T1E + T1F;
            T4d = T4b + T4c;
            T4g = T4e + T4f;
            T4j = T4d + T4g;
            T3F = T33 - T36;
            T3G = T3a - T3d;
            T3H = T3F + T3G;
            TN = TL + TM;
            TQ = TO + TP;
            TR = TN + TQ;
        }

        rp_ptr[0] = T7 + TC;
        rm_ptr[0] = T2D + T2E;

        {
            E T2k, T2o, T4T, T4U;
            T2k = TK + TR;
            T2o = T1D + T1G;
            rp_ptr[rs_ptr[5]] = T2j * T2k - T2n * T2o;
            rm_ptr[rs_ptr[5]] = T2n * T2k + T2j * T2o;
            T4T = T4i + T4j;
            T4U = T4x + T4y;
            ip_ptr[rs_ptr[2]] = T29 * T4T - T2c * T4U;
            im_ptr[rs_ptr[2]] = T29 * T4U + T2c * T4T;
        }

        T48 = T3i + T3x;
        T4a = T3E + T3H;
        ip_ptr[rs_ptr[7]] = T47 * T48 - T49 * T4a;
        im_ptr[rs_ptr[7]] = T47 * T4a + T49 * T48;

        {
            E T2y, T2J, T2V, T2R, T2G, T2U, T2r, T2Q;
            T2y = KP951056516 * T2u + KP587785252 * T2x;
            T2J = KP951056516 * T2H + KP587785252 * T2I;
            T2V = KP587785252 * T2H - KP951056516 * T2I;
            T2R = KP587785252 * T2u - KP951056516 * T2x;
            {
                E T2C, T2F, T2p, T2q;
                T2C = KP559016994 * (T2A - T2B);
                T2F = T7 - KP250000000 * TC;
                T2G = T2C + T2F;
                T2U = T2F - T2C;
                T2p = KP559016994 * (Tm - TB);
                T2q = T2D - KP250000000 * T2E;
                T2r = T2p + T2q;
                T2Q = T2q - T2p;
            }
            {
                E T2z, T2K, T2Y, T30;
                T2z = T2r + T2y;
                T2K = T2G - T2J;
                rp_ptr[rs_ptr[2]] = T25 * T2z - T27 * T2K;
                rm_ptr[rs_ptr[2]] = T27 * T2z + T25 * T2K;
                T2Y = T2Q - T2R;
                T30 = T2V + T2U;
                rp_ptr[rs_ptr[6]] = T2X * T2Y - T2Z * T30;
                rm_ptr[rs_ptr[6]] = T2Z * T2Y + T2X * T30;
            }
            {
                E T2M, T2O, T2S, T2W;
                T2M = T2r - T2y;
                T2O = T2J + T2G;
                rp_ptr[rs_ptr[8]] = T2L * T2M - T2N * T2O;
                rm_ptr[rs_ptr[8]] = T2N * T2M + T2L * T2O;
                T2S = T2Q + T2R;
                T2W = T2U - T2V;
                rp_ptr[rs_ptr[4]] = T2P * T2S - T2T * T2W;
                rm_ptr[rs_ptr[4]] = T2T * T2S + T2P * T2W;
            }
        }

        {
            E T4s, T4D, T4N, T4I, T4A, T4M, T4l, T4J;
            T4s = KP951056516 * T4o + KP587785252 * T4r;
            T4D = KP951056516 * T4B + KP587785252 * T4C;
            T4N = KP587785252 * T4B - KP951056516 * T4C;
            T4I = KP587785252 * T4o - KP951056516 * T4r;
            {
                E T4w, T4z, T4h, T4k;
                T4w = KP559016994 * (T4u - T4v);
                T4z = T4x - KP250000000 * T4y;
                T4A = T4w + T4z;
                T4M = T4z - T4w;
                T4h = KP559016994 * (T4d - T4g);
                T4k = T4i - KP250000000 * T4j;
                T4l = T4h + T4k;
                T4J = T4k - T4h;
            }
            {
                E T4t, T4E, T4Q, T4S;
                T4t = T4l - T4s;
                T4E = T4A + T4D;
                ip_ptr[0] = TD * T4t - TG * T4E;
                im_ptr[0] = TD * T4E + TG * T4t;
                T4Q = T4J - T4I;
                T4S = T4M + T4N;
                ip_ptr[rs_ptr[8]] = T4P * T4Q - T4R * T4S;
                im_ptr[rs_ptr[8]] = T4P * T4S + T4R * T4Q;
            }
            {
                E T4F, T4G, T4K, T4O;
                T4F = T4s + T4l;
                T4G = T4A - T4D;
                ip_ptr[rs_ptr[4]] = T1R * T4F - T1T * T4G;
                im_ptr[rs_ptr[4]] = T1R * T4G + T1T * T4F;
                T4K = T4I + T4J;
                T4O = T4M - T4N;
                ip_ptr[rs_ptr[6]] = T4H * T4K - T4L * T4O;
                im_ptr[rs_ptr[6]] = T4H * T4O + T4L * T4K;
            }
        }

        {
            E T1p, T1w, T22, T1X, T1J, T23, TU, T1W;
            T1p = KP587785252 * T19 - KP951056516 * T1o;
            T1w = KP587785252 * T1u - KP951056516 * T1v;
            T22 = KP951056516 * T1u + KP587785252 * T1v;
            T1X = KP951056516 * T19 + KP587785252 * T1o;
            {
                E T1H, T1I, TS, TT;
                T1H = T1D - KP250000000 * T1G;
                T1I = KP559016994 * (T1E - T1F);
                T1J = T1H - T1I;
                T23 = T1I + T1H;
                TS = TK - KP250000000 * TR;
                TT = KP559016994 * (TN - TQ);
                TU = TS - TT;
                T1W = TT + TS;
            }
            {
                E T1q, T1K, T2e, T2g;
                T1q = TU - T1p;
                T1K = T1w + T1J;
                rp_ptr[rs_ptr[1]] = TJ * T1q - T1t * T1K;
                rm_ptr[rs_ptr[1]] = T1t * T1q + TJ * T1K;
                T2e = T1W + T1X;
                T2g = T23 - T22;
                rp_ptr[rs_ptr[7]] = T2d * T2e - T2f * T2g;
                rm_ptr[rs_ptr[7]] = T2f * T2e + T2d * T2g;
            }
            {
                E T1O, T1Q, T1Y, T24;
                T1O = TU + T1p;
                T1Q = T1J - T1w;
                rp_ptr[rs_ptr[9]] = T1N * T1O - T1P * T1Q;
                rm_ptr[rs_ptr[9]] = T1P * T1O + T1N * T1Q;
                T1Y = T1W - T1X;
                T24 = T22 + T23;
                rp_ptr[rs_ptr[3]] = T1V * T1Y - T21 * T24;
                rm_ptr[rs_ptr[3]] = T21 * T1Y + T1V * T24;
            }
        }

        {
            E T3f, T3N, T43, T3Z, T3K, T42, T3A, T3Y;
            T3f = KP587785252 * T37 - KP951056516 * T3e;
            T3N = KP587785252 * T3L - KP951056516 * T3M;
            T43 = KP951056516 * T3L + KP587785252 * T3M;
            T3Z = KP951056516 * T37 + KP587785252 * T3e;
            {
                E T3I, T3J, T3y, T3z;
                T3I = T3E - KP250000000 * T3H;
                T3J = KP559016994 * (T3F - T3G);
                T3K = T3I - T3J;
                T42 = T3J + T3I;
                T3y = T3i - KP250000000 * T3x;
                T3z = KP559016994 * (T3p - T3w);
                T3A = T3y - T3z;
                T3Y = T3z + T3y;
            }
            {
                E T3B, T3O, T45, T46;
                T3B = T3f + T3A;
                T3O = T3K - T3N;
                ip_ptr[rs_ptr[1]] = TE * T3B - TH * T3O;
                im_ptr[rs_ptr[1]] = TE * T3O + TH * T3B;
                T45 = T3Z + T3Y;
                T46 = T42 - T43;
                ip_ptr[rs_ptr[9]] = T1L * T45 - T1M * T46;
                im_ptr[rs_ptr[9]] = T1L * T46 + T1M * T45;
            }
            {
                E T3S, T3W, T40, T44;
                T3S = T3A - T3f;
                T3W = T3K + T3N;
                ip_ptr[rs_ptr[3]] = T3R * T3S - T3V * T3W;
                im_ptr[rs_ptr[3]] = T3R * T3W + T3V * T3S;
                T40 = T3Y - T3Z;
                T44 = T42 + T43;
                ip_ptr[rs_ptr[5]] = T3X * T40 - T41 * T44;
                im_ptr[rs_ptr[5]] = T3X * T44 + T41 * T40;
            }
        }
    }
}
}
