#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
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
INT i;
for (m = mb , W = W + (mb * 8), i = 0; m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero, i++) {
    E T2, T5, Tg, Ti, Tk, To, T1h, T1f, T6, T3, T8, T14, T1Q, Tc, T1O;
    E T1v, T18, T1t, T1n, T24, T1j, T22, Tq, Tu, T1E, T1G, Tx, Ty, Tz, TJ;
    E T1Z, TB, T1X, T1A, TZ, TL, T1y, TX;
    E * restrict rptr = &ri[i * ms];
    E * restrict iptr = &ii[i * ms];
    E * restrict wptr = &W[0];
    {
        E T7, T16, Ta, T13, T4, T17, Tb, T12;
        {
            E Th, Tn, Tj, Tm;
            T2 = wptr[0];
            T5 = wptr[1];
            Tg = wptr[2];
            Ti = wptr[3];
            Th = T2 * Tg;
            Tn = T5 * Tg;
            Tj = T5 * Ti;
            Tm = T2 * Ti;
            Tk = Th - Tj;
            To = Tm + Tn;
            T1h = Tm - Tn;
            T1f = Th + Tj;
            T6 = wptr[5];
            T7 = T5 * T6;
            T16 = Tg * T6;
            Ta = T2 * T6;
            T13 = Ti * T6;
            T3 = wptr[4];
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
                Tx = wptr[6];
                Ty = wptr[7];
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
        E TF, T2b, T4A, T4J, T2K, T3r, T4a, T4m, T1N, T28, T29, T3C, T3F, T4o, T3X;
        E T3Y, T44, T2f, T2g, T2h, T2n, T2s, T4L, T3g, T3h, T4w, T3n, T3o, T3p, T30;
        E T35, T36, TW, T1r, T1s, T3J, T3M, T4n, T3U, T3V, T43, T2c, T2d, T2e, T2y;
        E T2D, T4K, T3d, T3e, T4v, T3k, T3l, T3m, T2P, T2U, T2V;
        const stride s = rs;
        {
            E T1, T48, Te, T47, Tw, T2H, TD, T2I, T9, Td;
            T1 = rptr[0];
            T48 = iptr[0];
            T9 = rptr[s[10]];
            Td = iptr[s[10]];
            Te = (((T8) * (T9)) + (Tc * Td));
            T47 = ((T8 * Td) - ((Tc) * (T9)));
            Tw = (((Tq) * (rptr[s[5]])) + (Tu * iptr[s[5]]));
            T2H = ((Tq * iptr[s[5]]) - ((Tu) * (rptr[s[5]])));
            TD = (((Tz) * (rptr[s[15]])) + (TB * iptr[s[15]]));
            T2I = ((Tz * iptr[s[15]]) - ((TB) * (rptr[s[15]])));
            {
                E Tf, TE, T4y, T4z;
                Tf = T1 + Te;
                TE = Tw + TD;
                TF = Tf - TE;
                T2b = Tf + TE;
                T4y = T48 - T47;
                T4z = Tw - TD;
                T4A = T4y - T4z;
                T4J = T4z + T4y;
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
            E T1D, T3A, T2l, T2W, T27, T3E, T2r, T34, T1M, T3B, T2m, T2Z, T1W, T3D, T2q;
            E T31;
            {
                E T1x, T2j, T1C, T2k;
                T1x = (((T1t) * (rptr[s[8]])) + (T1v * iptr[s[8]]));
                T2j = ((T1t * iptr[s[8]]) - ((T1v) * (rptr[s[8]])));
                T1C = (((T1y) * (rptr[s[18]])) + (T1A * iptr[s[18]]));
                T2k = ((T1y * iptr[s[18]]) - ((T1A) * (rptr[s[18]])));
                T1D = T1x + T1C;
                T3A = T2j + T2k;
                T2l = T2j - T2k;
                T2W = T1x - T1C;
            }
            {
                E T21, T32, T26, T33;
                T21 = (((T1X) * (rptr[s[17]])) + (T1Z * iptr[s[17]]));
                T32 = ((T1X * iptr[s[17]]) - ((T1Z) * (rptr[s[17]])));
                T26 = (((T22) * (rptr[s[7]])) + (T24 * iptr[s[7]]));
                T33 = ((T22 * iptr[s[7]]) - ((T24) * (rptr[s[7]])));
                T27 = T21 + T26;
                T3E = T32 + T33;
                T2r = T21 - T26;
                T34 = T32 - T33;
            }
            {
                E T1I, T2X, T1L, T2Y;
                T1I = (((T1E) * (rptr[s[13]])) + (T1G * iptr[s[13]]));
                T2X = ((T1E * iptr[s[13]]) - ((T1G) * (rptr[s[13]])));
                T1L = (((Tg) * (rptr[s[3]])) + (Ti * iptr[s[3]]));
                T2Y = ((Tg * iptr[s[3]]) - ((Ti) * (rptr[s[3]])));
                T1M = T1I + T1L;
                T3B = T2X + T2Y;
                T2m = T1I - T1L;
                T2Z = T2X - T2Y;
            }
            {
                E T1S, T2o, T1V, T2p;
                T1S = (((T1O) * (rptr[s[12]])) + (T1Q * iptr[s[12]]));
                T2o = ((T1O * iptr[s[12]]) - ((T1Q) * (rptr[s[12]])));
                T1V = (((T1f) * (rptr[s[2]])) + (T1h * iptr[s[2]]));
                T2p = ((T1f * iptr[s[2]]) - ((T1h) * (rptr[s[2]])));
                T1W = T1S + T1V;
                T3D = T2o + T2p;
                T2q = T2o - T2p;
                T31 = T1S - T1V;
            }
            T1N = T1D - T1M;
            T28 = T1W - T27;
            T29 = T1N + T28;
            T3C = T3A - T3B;
            T3F = T3D - T3E;
            T4o = T3C + T3F;
            T3X = T3A + T3B;
            T3Y = T3D + T3E;
            T44 = T3X + T3Y;
            T2f = T1D + T1M;
            T2g = T1W + T27;
            T2h = T2f + T2g;
            T2n = T2l + T2m;
            T2s = T2q + T2r;
            T4L = T2n + T2s;
            T3g = T2l - T2m;
            T3h = T2q - T2r;
            T4w = T3g + T3h;
            T3n = T2W + T2Z;
            T3o = T31 + T34;
            T3p = T3n + T3o;
            T30 = T2W - T2Z;
            T35 = T31 - T34;
            T36 = T30 + T35;
        }
        {
            E TO, T3H, T2w, T2L, T1q, T3L, T2C, T2T, TV, T3I, T2x, T2O, T1b, T3K, T2B;
            E T2Q;
            {
                E TI, T2u, TN, T2v;
                TI = (((Tk) * (rptr[s[4]])) + (To * iptr[s[4]]));
                T2u = ((Tk * iptr[s[4]]) - ((To) * (rptr[s[4]])));
                TN = (((TJ) * (rptr[s[14]])) + (TL * iptr[s[14]]));
                T2v = ((TJ * iptr[s[14]]) - ((TL) * (rptr[s[14]])));
                TO = TI + TN;
                T3H = T2u + T2v;
                T2w = T2u - T2v;
                T2L = TI - TN;
            }
            {
                E T1e, T2R, T1p, T2S;
                T1e = (((T2) * (rptr[s[1]])) + (T5 * iptr[s[1]]));
                T2R = ((T2 * iptr[s[1]]) - ((T5) * (rptr[s[1]])));
                T1p = (((T1j) * (rptr[s[11]])) + (T1n * iptr[s[11]]));
                T2S = ((T1j * iptr[s[11]]) - ((T1n) * (rptr[s[11]])));
                T1q = T1e + T1p;
                T3L = T2R + T2S;
                T2C = T1e - T1p;
                T2T = T2R - T2S;
            }
            {
                E TR, T2M, TU, T2N;
                TR = (((T3) * (rptr[s[9]])) + (T6 * iptr[s[9]]));
                T2M = ((T3 * iptr[s[9]]) - ((T6) * (rptr[s[9]])));
                TU = (((Tx) * (rptr[s[19]])) + (Ty * iptr[s[19]]));
                T2N = ((Tx * iptr[s[19]]) - ((Ty) * (rptr[s[19]])));
                TV = TR + TU;
                T3I = T2M + T2N;
                T2x = TR - TU;
                T2O = T2M - T2N;
            }
            {
                E T11, T2z, T1a, T2A;
                T11 = (((TX) * (rptr[s[16]])) + (TZ * iptr[s[16]]));
                T2z = ((TX * iptr[s[16]]) - ((TZ) * (rptr[s[16]])));
                T1a = (((T14) * (rptr[s[6]])) + (T18 * iptr[s[6]]));
                T2A = ((T14 * iptr[s[6]]) - ((T18) * (rptr[s[6]])));
                T1b = T11 + T1a;
                T3K = T2z + T2A;
                T2B = T2z - T2A;
                T2Q = T11 - T1a;
            }
            TW = TO - TV;
            T1r = T1b - T1q;
            T1s = TW + T1r;
            T3J = T3H - T3I;
            T3M = T3K - T3L;
            T4n = T3J + T3M;
            T3U = T3H + T3I;
            T3V = T3K + T3L;
            T43 = T3U + T3V;
            T2c = TO + TV;
            T2d = T1b + T1q;
            T2e = T2c + T2d;
            T2y = T2w + T2x;
            T2D = T2B + T2C;
            T4K = T2y + T2D;
            T3d = T2w - T2x;
            T3e = T2B - T2C;
            T4v = T3d + T3e;
            T3k = T2L + T2O;
            T3l = T2Q + T2T;
            T3m = T3k + T3l;
            T2P = T2L - T2O;
            T2U = T2Q - T2T;
            T2V = T2P + T2U;
        }
        {
            E T3y, T2a, T3x, T3O, T3Q, T3G, T3N, T3P, T3z;
            T3y = KP559016994 * (T1s - T29);
            T2a = T1s + T29;
            T3x = ((TF) - ((KP250000000) * (T2a)));
            T3G = T3C - T3F;
            T3N = T3J - T3M;
            T3O = ((KP951056516 * T3G) - ((KP587785252) * (T3N)));
            T3Q = (((KP951056516) * (T3N)) + (KP587785252 * T3G));
            rptr[s[10]] = TF + T2a;
            T3P = T3y + T3x;
            rptr[s[14]] = T3P - T3Q;
            rptr[s[6]] = T3P + T3Q;
            T3z = T3x - T3y;
            rptr[s[2]] = T3z - T3O;
            rptr[s[18]] = T3z + T3O;
        }
        {
            E T4r, T4p, T4q, T4l, T4u, T4j, T4k, T4t, T4s;
            T4r = KP559016994 * (T4n - T4o);
            T4p = T4n + T4o;
            T4q = ((T4m) - ((KP250000000) * (T4p)));
            T4j = T1N - T28;
            T4k = TW - T1r;
            T4l = ((KP951056516 * T4j) - ((KP587785252) * (T4k)));
            T4u = (((KP951056516) * (T4k)) + (KP587785252 * T4j));
            iptr[s[10]] = T4p + T4m;
            T4t = T4r + T4q;
            iptr[s[6]] = T4t - T4u;
            iptr[s[14]] = T4u + T4t;
            T4s = T4q - T4r;
            iptr[s[2]] = T4l + T4s;
            iptr[s[18]] = T4s - T4l;
        }
        {
            E T3R, T2i, T3S, T40, T42, T3W, T3Z, T41, T3T;
            T3R = KP559016994 * (T2e - T2h);
            T2i = T2e + T2h;
            T3S = ((T2b) - ((KP250000000) * (T2i)));
            T3W = T3U - T3V;
            T3Z = T3X - T3Y;
            T40 = (((KP951056516) * (T3W)) + (KP587785252 * T3Z));
            T42 = ((KP951056516 * T3Z) - ((KP587785252) * (T3W)));
            rptr[0] = T2b + T2i;
            T41 = T3S - T3R;
            rptr[s[12]] = T41 - T42;
            rptr[s[8]] = T41 + T42;
            T3T = T3R + T3S;
            rptr[s[4]] = T3T - T40;
            rptr[s[16]] = T3T + T40;
        }
        {
            E T4e, T45, T4f, T4d, T4i, T4b, T4c, T4h, T4g;
            T4e = KP559016994 * (T43 - T44);
            T45 = T43 + T44;
            T4f = ((T4a) - ((KP250000000) * (T45)));
            T4b = T2c - T2d;
            T4c = T2f - T2g;
            T4d = (((KP951056516) * (T4b)) + (KP587785252 * T4c));
            T4i = ((KP951056516 * T4c) - ((KP587785252) * (T4b)));
            iptr[0] = T45 + T4a;
            T4h = T4f - T4e;
            iptr[s[8]] = T4h - T4i;
            iptr[s[12]] = T4i + T4h;
            T4g = T4e + T4f;
            iptr[s[4]] = T4d + T4g;
            iptr[s[16]] = T4g - T4d;
        }
        {
            E T39, T37, T38, T2F, T3b, T2t, T2E, T3c, T3a;
            T39 = KP559016994 * (T2V - T36);
            T37 = T2V + T36;
            T38 = ((T2K) - ((KP250000000) * (T37)));
            T2t = T2n - T2s;
            T2E = T2y - T2D;
            T2F = ((KP951056516 * T2t) - ((KP587785252) * (T2E)));
            T3b = (((KP951056516) * (T2E)) + (KP587785252 * T2t));
            rptr[s[15]] = T2K + T37;
            T3c = T39 + T38;
            rptr[s[11]] = T3b + T3c;
            rptr[s[19]] = T3c - T3b;
            T3a = T38 - T39;
            rptr[s[3]] = T2F + T3a;
            rptr[s[7]] = T3a - T2F;
        }
        {
            E T4O, T4M, T4N, T4S, T4U, T4Q, T4R, T4T, T4P;
            T4O = KP559016994 * (T4K - T4L);
            T4M = T4K + T4L;
            T4N = ((T4J) - ((KP250000000) * (T4M)));
            T4Q = T30 - T35;
            T4R = T2P - T2U;
            T4S = ((KP951056516 * T4Q) - ((KP587785252) * (T4R)));
            T4U = (((KP951056516) * (T4R)) + (KP587785252 * T4Q));
            iptr[s[15]] = T4M + T4J;
            T4T = T4O + T4N;
            iptr[s[11]] = T4T - T4U;
            iptr[s[19]] = T4U + T4T;
            T4P = T4N - T4O;
            iptr[s[3]] = T4P - T4S;
            iptr[s[7]] = T4S + T4P;
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
            rptr[s[5]] = T3r + T3s;
            T3w = T3t - T3q;
            rptr[s[13]] = T3v + T3w;
            rptr[s[17]] = T3w - T3v;
            T3u = T3q + T3t;
            rptr[s[1]] = T3j + T3u;
            rptr[s[9]] = T3u - T3j;
        }
        {
            E T4x, T4B, T4C, T4G, T4I, T4E, T4F, T4H, T4D;
            T4x = KP559016994 * (T4v - T4w);
            T4B = T4v + T4w;
            T4C = ((T4A) - ((KP250000000) * (T4B)));
            T4E = T3k - T3l;
            T4F = T3n - T3o;
            T4G = (((KP951056516) * (T4E)) + (KP587785252 * T4F));
            T4I = ((KP951056516 * T4F) - ((KP587785252) * (T4E)));
            iptr[s[5]] = T4B + T4A;
            T4H = T4C - T4x;
            iptr[s[13]] = T4H - T4I;
            iptr[s[17]] = T4I + T4H;
            T4D = T4x + T4C;
            iptr[s[1]] = T4D - T4G;
            iptr[s[9]] = T4G + T4D;
        }
    }
}
}
