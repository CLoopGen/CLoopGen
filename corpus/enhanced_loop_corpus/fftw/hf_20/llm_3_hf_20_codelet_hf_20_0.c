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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 38); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 38 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tj, T1R, T4j, T4s, T2q, T37, T3Q, T42, T1r, T1O, T1P, T3i, T3l, T3J, T3D;
    E T3E, T44, T1V, T1W, T1X, T2e, T2j, T2k, T2W, T2X, T4f, T33, T34, T35, T2J;
    E T2O, T4q, TG, T13, T14, T3p, T3s, T3K, T3A, T3B, T43, T1S, T1T, T1U, T23;
    E T28, T29, T2T, T2U, T4e, T30, T31, T32, T2y, T2D, T4p;

    // Indirect access via pointer arithmetic using precomputed offsets
    const E* restrict cr_base = cr;
    const E* restrict ci_base = ci;
    const E* restrict W_base = W;
    const INT* restrict rs_ptr = rs;

    #define CR(i) (*(cr_base + (*(rs_ptr + (i)))))
    #define CI(i) (*(ci_base + (*(rs_ptr + (i)))))
    #define WW(i) (*(W_base + (i)))

    // Handle index 0 separately since it's direct access
    E T1 = cr[0];
    E T3N = ci[0];

    E T6, T3M, Tc, T2n, Th, T2o;
    {
        E T3 = CR(10), T5 = CI(10), T2 = WW(18), T4 = WW(19);
        T6 = T2*T3 + T4*T5;
        T3M = T2*T5 - T4*T3;
    }
    {
        E T9 = CR(5), Tb = CI(5), T8 = WW(8), Ta = WW(9);
        Tc = T8*T9 + Ta*Tb;
        T2n = T8*Tb - Ta*T9;
    }
    {
        E Te = CR(15), Tg = CI(15), Td = WW(28), Tf = WW(29);
        Th = Td*Te + Tf*Tg;
        T2o = Td*Tg - Tf*Te;
    }

    E T7 = T1 + T6, Ti = Tc + Th;
    Tj = T7 - Ti;
    T1R = T7 + Ti;
    E T4h = T3N - T3M, T4i = Tc - Th;
    T4j = T4h - T4i;
    T4s = T4i + T4h;

    E T2m = T1 - T6, T2p = T2n - T2o;
    T2q = T2m - T2p;
    T37 = T2m + T2p;
    E T3O = T3M + T3N, T3P = T2n + T2o;
    T3Q = T3O - T3P;
    T42 = T3P + T3O;

    // Continue with indirect accesses...
    E T1f, T3g, T2a, T2H, T1N, T3j, T2i, T2N, T1q, T3h, T2d, T2I, T1C, T3k, T2f, T2M;
    {
        E T19, T2F, T1e, T2G;
        {
            E T16 = CR(8), T18 = CI(8), T15 = WW(14), T17 = WW(15);
            T19 = T15*T16 + T17*T18;
            T2F = T15*T18 - T17*T16;
        }
        {
            E T1b = CR(18), T1d = CI(18), T1a = WW(34), T1c = WW(35);
            T1e = T1a*T1b + T1c*T1d;
            T2G = T1a*T1d - T1c*T1b;
        }
        T1f = T19 + T1e;
        T3g = T2F + T2G;
        T2a = T19 - T1e;
        T2H = T2F - T2G;
    }
    {
        E T1H, T2g, T1M, T2h;
        {
            E T1E = CR(17), T1G = CI(17), T1D = WW(32), T1F = WW(33);
            T1H = T1D*T1E + T1F*T1G;
            T2g = T1D*T1G - T1F*T1E;
        }
        {
            E T1J = CR(7), T1L = CI(7), T1I = WW(12), T1K = WW(13);
            T1M = T1I*T1J + T1K*T1L;
            T2h = T1I*T1L - T1K*T1J;
        }
        T1N = T1H + T1M;
        T3j = T2g + T2h;
        T2i = T2g - T2h;
        T2N = T1H - T1M;
    }
    {
        E T1k, T2b, T1p, T2c;
        {
            E T1h = CR(13), T1j = CI(13), T1g = WW(24), T1i = WW(25);
            T1k = T1g*T1h + T1i*T1j;
            T2b = T1g*T1j - T1i*T1h;
        }
        {
            E T1m = CR(3), T1o = CI(3), T1l = WW(4), T1n = WW(5);
            T1p = T1l*T1m + T1n*T1o;
            T2c = T1l*T1o - T1n*T1m;
        }
        T1q = T1k + T1p;
        T3h = T2b + T2c;
        T2d = T2b - T2c;
        T2I = T1k - T1p;
    }
    {
        E T1w, T2K, T1B, T2L;
        {
            E T1t = CR(12), T1v = CI(12), T1s = WW(22), T1u = WW(23);
            T1w = T1s*T1t + T1u*T1v;
            T2K = T1s*T1v - T1u*T1t;
        }
        {
            E T1y = CR(2), T1A = CI(2), T1x = WW(2), T1z = WW(3);
            T1B = T1x*T1y + T1z*T1A;
            T2L = T1x*T1A - T1z*T1y;
        }
        T1C = T1w + T1B;
        T3k = T2K + T2L;
        T2f = T1w - T1B;
        T2M = T2K - T2L;
    }

    T1r = T1f - T1q;
    T1O = T1C - T1N;
    T1P = T1r + T1O;
    T3i = T3g - T3h;
    T3l = T3j - T3k;
    T3J = T3l - T3i;
    T3D = T3g + T3h;
    T3E = T3k + T3j;
    T44 = T3D + T3E;
    T1V = T1f + T1q;
    T1W = T1C + T1N;
    T1X = T1V + T1W;
    T2e = T2a - T2d;
    T2j = T2f - T2i;
    T2k = T2e + T2j;
    T2W = T2H - T2I;
    T2X = T2M - T2N;
    T4f = T2W + T2X;
    T33 = T2a + T2d;
    T34 = T2f + T2i;
    T35 = T33 + T34;
    T2J = T2H + T2I;
    T2O = T2M + T2N;
    T4q = T2J + T2O;

    E Tu, T3n, T1Z, T2w, T12, T3r, T27, T2z, TF, T3o, T22, T2x, TR, T3q, T24, T2C;
    {
        E To, T2u, Tt, T2v;
        {
            E Tl = CR(4), Tn = CI(4), Tk = WW(6), Tm = WW(7);
            To = Tk*Tl + Tm*Tn;
            T2u = Tk*Tn - Tm*Tl;
        }
        {
            E Tq = CR(14), Ts = CI(14), Tp = WW(26), Tr = WW(27);
            Tt = Tp*Tq + Tr*Ts;
            T2v = Tp*Ts - Tr*Tq;
        }
        Tu = To + Tt;
        T3n = T2u + T2v;
        T1Z = To - Tt;
        T2w = T2u - T2v;
    }
    {
        E TW, T25, T11, T26;
        {
            E TT = CR(1), TV = CI(1), TS = WW(0), TU = WW(1);
            TW = TS*TT + TU*TV;
            T25 = TS*TV - TU*TT;
        }
        {
            E TY = CR(11), T10 = CI(11), TX = WW(20), TZ = WW(21);
            T11 = TX*TY + TZ*T10;
            T26 = TX*T10 - TZ*TY;
        }
        T12 = TW + T11;
        T3r = T25 + T26;
        T27 = T25 - T26;
        T2z = T11 - TW;
    }
    {
        E Tz, T20, TE, T21;
        {
            E Tw = CR(9), Ty = CI(9), Tv = WW(16), Tx = WW(17);
            Tz = Tv*Tw + Tx*Ty;
            T20 = Tv*Ty - Tx*Tw;
        }
        {
            E TB = CR(19), TD = CI(19), TA = WW(36), TC = WW(37);
            TE = TA*TB + TC*TD;
            T21 = TA*TD - TC*TB;
        }
        TF = Tz + TE;
        T3o = T20 + T21;
        T22 = T20 - T21;
        T2x = Tz - TE;
    }
    {
        E TL, T2A, TQ, T2B;
        {
            E TI = CR(16), TK = CI(16), TH = WW(30), TJ = WW(31);
            TL = TH*TI + TJ*TK;
            T2A = TH*TK - TJ*TI;
        }
        {
            E TN = CR(6), TP = CI(6), TM = WW(10), TO = WW(11);
            TQ = TM*TN + TO*TP;
            T2B = TM*TP - TO*TN;
        }
        TR = TL + TQ;
        T3q = T2A + T2B;
        T24 = TL - TQ;
        T2C = T2A - T2B;
    }

    TG = Tu - TF;
    T13 = TR - T12;
    T14 = TG + T13;
    T3p = T3n - T3o;
    T3s = T3q - T3r;
    T3K = T3p + T3s;
    T3A = T3n + T3o;
    T3B = T3q + T3r;
    T43 = T3A + T3B;
    T1S = Tu + TF;
    T1T = TR + T12;
    T1U = T1S + T1T;
    T23 = T1Z - T22;
    T28 = T24 - T27;
    T29 = T23 + T28;
    T2T = T2w - T2x;
    T2U = T2C + T2z;
    T4e = T2T + T2U;
    T30 = T1Z + T22;
    T31 = T24 + T27;
    T32 = T30 + T31;
    T2y = T2w + T2x;
    T2D = T2z - T2C;
    T4p = T2D - T2y;

    #undef CR
    #undef CI
    #undef WW

    {
        E T3e = KP559016994 * (T14 - T1P);
        E T1Q = T14 + T1P;
        E T3d = Tj - KP250000000 * T1Q;
        E T3m = T3i + T3l;
        E T3t = T3p - T3s;
        E T3u = KP951056516 * T3m - KP587785252 * T3t;
        E T3w = KP951056516 * T3t + KP587785252 * T3m;
        ci[(rs[9])] = Tj + T1Q;
        E T3v = T3e + T3d;
        ci[(rs[5])] = T3v - T3w;
        cr[(rs[6])] = T3v + T3w;
        E T3f = T3d - T3e;
        cr[(rs[2])] = T3f - T3u;
        ci[(rs[1])] = T3f + T3u;
    }
    {
        E T36 = KP559016994 * (T32 - T35);
        E T38 = T32 + T35;
        E T39 = T37 - KP250000000 * T38;
        E T2V = T2T - T2U;
        E T2Y = T2W - T2X;
        E T2Z = KP951056516 * T2V + KP587785252 * T2Y;
        E T3c = KP951056516 * T2Y - KP587785252 * T2V;
        cr[(rs[5])] = T37 + T38;
        E T3b = T39 - T36;
        ci[(rs[2])] = T3b - T3c;
        ci[(rs[6])] = T3c + T3b;
        E T3a = T36 + T39;
        cr[(rs[1])] = T2Z + T3a;
        cr[(rs[9])] = T3a - T2Z;
    }
    {
        E T3x = KP559016994 * (T1U - T1X);
        E T1Y = T1U + T1X;
        E T3y = T1R - KP250000000 * T1Y;
        E T3C = T3A - T3B;
        E T3F = T3D - T3E;
        E T3G = KP951056516 * T3C + KP587785252 * T3F;
        E T3I = KP951056516 * T3F - KP587785252 * T3C;
        cr[0] = T1R + T1Y;
        E T3H = T3y - T3x;
        ci[(rs[7])] = T3H - T3I;
        cr[(rs[8])] = T3H + T3I;
        E T3z = T3x + T3y;
        cr[(rs[4])] = T3z - T3G;
        ci[(rs[3])] = T3z + T3G;
    }
    {
        E T2l = KP559016994 * (T29 - T2k);
        E T2r = T29 + T2k;
        E T2s = T2q - KP250000000 * T2r;
        E T2E = T2y + T2D;
        E T2P = T2J - T2O;
        E T2Q = KP951056516 * T2E + KP587785252 * T2P;
        E T2R = KP951056516 * T2P - KP587785252 * T2E;
        ci[(rs[4])] = T2q + T2r;
        E T2S = T2s - T2l;
        cr[(rs[3])] = T2R + T2S;
        cr[(rs[7])] = T2S - T2R;
        E T2t = T2l + T2s;
        ci[0] = T2t - T2Q;
        ci[(rs[8])] = T2Q + T2t;
    }
    {
        E T3U = KP559016994 * (T3K + T3J);
        E T3L = T3J - T3K;
        E T3V = KP250000000 * T3L + T3Q;
        E T3R = T13 - TG;
        E T3S = T1r - T1O;
        E T3T = KP951056516 * T3R - KP587785252 * T3S;
        E T3X = KP587785252 * T3R + KP951056516 * T3S;
        cr[(rs[10])] = T3L - T3Q;
        E T3Y = T3V - T3U;
        cr[(rs[18])] = T3X - T3Y;
        ci[(rs[17])] = T3X + T3Y;
        E T3W = T3U + T3V;
        cr[(rs[14])] = T3T - T3W;
        ci[(rs[13])] = T3T + T3W;
    }
    {
        E T4g = KP559016994 * (T4e - T4f);
        E T4k = T4e + T4f;
        E T4l = T4j - KP250000000 * T4k;
        E T4b = T33 - T34;
        E T4c = T30 - T31;
        E T4d = KP951056516 * T4b - KP587785252 * T4c;
        E T4n = KP951056516 * T4c + KP587785252 * T4b;
        ci[(rs[14])] = T4k + T4j;
        E T4o = T4g + T4l;
        ci[(rs[10])] = T4n + T4o;
        ci[(rs[18])] = T4o - T4n;
        E T4m = T4g - T4l;
        cr[(rs[13])] = T4d + T4m;
        cr[(rs[17])] = T4m - T4d;
    }
    {
        E T47 = KP559016994 * (T43 - T44);
        E T45 = T43 + T44;
        E T46 = T42 - KP250000000 * T45;
        E T3Z = T1S - T1T;
        E T40 = T1V - T1W;
        E T41 = KP587785252 * T3Z - KP951056516 * T40;
        E T49 = KP951056516 * T3Z + KP587785252 * T40;
        ci[(rs[19])] = T45 + T42;
        E T4a = T47 + T46;
        cr[(rs[16])] = T49 - T4a;
        ci[(rs[15])] = T49 + T4a;
        E T48 = T46 - T47;
        cr[(rs[12])] = T41 - T48;
        ci[(rs[11])] = T41 + T48;
    }
    {
        E T4w = KP559016994 * (T4p + T4q);
        E T4r = T4p - T4q;
        E T4x = KP250000000 * T4r + T4s;
        E T4t = T23 - T28;
        E T4u = T2e - T2j;
        E T4v = KP951056516 * T4t + KP587785252 * T4u;
        E T4z = KP951056516 * T4u - KP587785252 * T4t;
        cr[(rs[15])] = T4r - T4s;
        E T4A = T4w + T4x;
        ci[(rs[12])] = T4z + T4A;
        ci[(rs[16])] = T4A - T4z;
        E T4y = T4w - T4x;
        cr[(rs[11])] = T4v + T4y;
        cr[(rs[19])] = T4y - T4v;
    }
}
}
