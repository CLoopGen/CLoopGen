#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP637423989;
extern  E KP770513242;
extern  E KP998026728;
extern  E KP062790519;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T9, T4u, T2T, TP, T3H, TW, T5y, T3I, T2Q, T4v, Ti, Tr, Ts, T5m, T5n;
    E T5v, T18, T4G, T34, T3M, T1G, T4J, T38, T3T, T1v, T4K, T37, T3W, T1j, T4H;
    E T35, T3P, TB, TK, TL, T5p, T5q, T5w, T1T, T4N, T3c, T41, T2r, T4Q, T3e;
    E T4b, T2g, T4R, T3f, T48, T24, T4O, T3b, T44;
    const INT * restrict isp = is; // Cache is stride pointer for indirect access
    const INT s0 = isp[0], s1 = isp[1], s2 = isp[2], s3 = isp[3], s4 = isp[4];
    const INT s5 = isp[5], s6 = isp[6], s7 = isp[7], s8 = isp[8], s9 = isp[9];
    const INT s10 = isp[10], s11 = isp[11], s12 = isp[12], s13 = isp[13], s14 = isp[14];
    const INT s15 = isp[15], s16 = isp[16], s17 = isp[17], s18 = isp[18], s19 = isp[19];
    const INT s20 = isp[20], s21 = isp[21], s22 = isp[22], s23 = isp[23], s24 = isp[24];
    {
        E T1, T4, T7, T8, T2S, T2R, TN, TO;
        T1 = ri[0];
        {
            E T2, T3, T5, T6;
            T2 = ri[s5];
            T3 = ri[s20];
            T4 = T2 + T3;
            T5 = ri[s10];
            T6 = ri[s15];
            T7 = T5 + T6;
            T8 = T4 + T7;
            T2S = T5 - T6;
            T2R = T2 - T3;
        }
        T9 = T1 + T8;
        T4u = ((KP951056516 * T2S) - ((KP587785252) * (T2R)));
        T2T = (((KP951056516) * (T2R)) + (KP587785252 * T2S));
        TN = KP559016994 * (T4 - T7);
        TO = ((T1) - ((KP250000000) * (T8)));
        TP = TN + TO;
        T3H = TO - TN;
    }
    {
        E T2N, T2K, T2L, TS, T2O, TV, T2M, T2P;
        T2N = ii[0];
        {
            E TQ, TR, TT, TU;
            TQ = ii[s5];
            TR = ii[s20];
            T2K = TQ + TR;
            TT = ii[s10];
            TU = ii[s15];
            T2L = TT + TU;
            TS = TQ - TR;
            T2O = T2K + T2L;
            TV = TT - TU;
        }
        TW = (((KP951056516) * (TS)) + (KP587785252 * TV));
        T5y = T2N + T2O;
        T3I = ((KP951056516 * TV) - ((KP587785252) * (TS)));
        T2M = KP559016994 * (T2K - T2L);
        T2P = ((T2N) - ((KP250000000) * (T2O)));
        T2Q = T2M + T2P;
        T4v = T2P - T2M;
    }
    {
        E Ta, T1c, Tj, T1z, Th, T1h, TY, T1g, T13, T1d, T16, T1b, Tq, T1E, T1l;
        E T1D, T1q, T1A, T1t, T1y;
        Ta = ri[s1];
        T1c = ii[s1];
        Tj = ri[s4];
        T1z = ii[s4];
        {
            E Tb, Tc, Td, Te, Tf, Tg;
            Tb = ri[s6];
            Tc = ri[s21];
            Td = Tb + Tc;
            Te = ri[s11];
            Tf = ri[s16];
            Tg = Te + Tf;
            Th = Td + Tg;
            T1h = Te - Tf;
            TY = KP559016994 * (Td - Tg);
            T1g = Tb - Tc;
        }
        {
            E T11, T12, T19, T14, T15, T1a;
            T11 = ii[s6];
            T12 = ii[s21];
            T19 = T11 + T12;
            T14 = ii[s11];
            T15 = ii[s16];
            T1a = T14 + T15;
            T13 = T11 - T12;
            T1d = T19 + T1a;
            T16 = T14 - T15;
            T1b = KP559016994 * (T19 - T1a);
        }
        {
            E Tk, Tl, Tm, Tn, To, Tp;
            Tk = ri[s9];
            Tl = ri[s24];
            Tm = Tk + Tl;
            Tn = ri[s14];
            To = ri[s19];
            Tp = Tn + To;
            Tq = Tm + Tp;
            T1E = Tn - To;
            T1l = KP559016994 * (Tm - Tp);
            T1D = Tk - Tl;
        }
        {
            E T1o, T1p, T1w, T1r, T1s, T1x;
            T1o = ii[s9];
            T1p = ii[s24];
            T1w = T1o + T1p;
            T1r = ii[s14];
            T1s = ii[s19];
            T1x = T1r + T1s;
            T1q = T1o - T1p;
            T1A = T1w + T1x;
            T1t = T1r - T1s;
            T1y = KP559016994 * (T1w - T1x);
        }
        Ti = Ta + Th;
        Tr = Tj + Tq;
        Ts = Ti + Tr;
        T5m = T1c + T1d;
        T5n = T1z + T1A;
        T5v = T5m + T5n;
        {
            E T17, T3L, T10, T3K, TZ;
            T17 = (((KP951056516) * (T13)) + (KP587785252 * T16));
            T3L = ((KP951056516 * T16) - ((KP587785252) * (T13)));
            TZ = ((Ta) - ((KP250000000) * (Th)));
            T10 = TY + TZ;
            T3K = TZ - TY;
            T18 = T10 + T17;
            T4G = T3K + T3L;
            T34 = T10 - T17;
            T3M = T3K - T3L;
        }
        {
            E T1F, T3R, T1C, T3S, T1B;
            T1F = (((KP951056516) * (T1D)) + (KP587785252 * T1E));
            T3R = ((KP951056516 * T1E) - ((KP587785252) * (T1D)));
            T1B = ((T1z) - ((KP250000000) * (T1A)));
            T1C = T1y + T1B;
            T3S = T1B - T1y;
            T1G = T1C - T1F;
            T4J = T3S - T3R;
            T38 = T1F + T1C;
            T3T = T3R + T3S;
        }
        {
            E T1u, T3V, T1n, T3U, T1m;
            T1u = (((KP951056516) * (T1q)) + (KP587785252 * T1t));
            T3V = ((KP951056516 * T1t) - ((KP587785252) * (T1q)));
            T1m = ((Tj) - ((KP250000000) * (Tq)));
            T1n = T1l + T1m;
            T3U = T1m - T1l;
            T1v = T1n + T1u;
            T4K = T3U + T3V;
            T37 = T1n - T1u;
            T3W = T3U - T3V;
        }
        {
            E T1i, T3N, T1f, T3O, T1e;
            T1i = (((KP951056516) * (T1g)) + (KP587785252 * T1h));
            T3N = ((KP951056516 * T1h) - ((KP587785252) * (T1g)));
            T1e = ((T1c) - ((KP250000000) * (T1d)));
            T1f = T1b + T1e;
            T3O = T1e - T1b;
            T1j = T1f - T1i;
            T4H = T3O - T3N;
            T35 = T1i + T1f;
            T3P = T3N + T3O;
        }
    }
    {
        E Tt, T1X, TC, T2k, TA, T22, T1J, T21, T1O, T1Y, T1R, T1W, TJ, T2p, T26;
        E T2o, T2b, T2l, T2e, T2j;
        Tt = ri[s2];
        T1X = ii[s2];
        TC = ri[s3];
        T2k = ii[s3];
        {
            E Tu, Tv, Tw, Tx, Ty, Tz;
            Tu = ri[s7];
            Tv = ri[s22];
            Tw = Tu + Tv;
            Tx = ri[s12];
            Ty = ri[s17];
            Tz = Tx + Ty;
            TA = Tw + Tz;
            T22 = Tx - Ty;
            T1J = KP559016994 * (Tw - Tz);
            T21 = Tu - Tv;
        }
        {
            E T1M, T1N, T1U, T1P, T1Q, T1V;
            T1M = ii[s7];
            T1N = ii[s22];
            T1U = T1M + T1N;
            T1P = ii[s12];
            T1Q = ii[s17];
            T1V = T1P + T1Q;
            T1O = T1M - T1N;
            T1Y = T1U + T1V;
            T1R = T1P - T1Q;
            T1W = KP559016994 * (T1U - T1V);
        }
        {
            E TD, TE, TF, TG, TH, TI;
            TD = ri[s8];
            TE = ri[s23];
            TF = TD + TE;
            TG = ri[s13];
            TH = ri[s18];
            TI = TG + TH;
            TJ = TF + TI;
            T2p = TG - TH;
            T26 = KP559016994 * (TF - TI);
            T2o = TD - TE;
        }
        {
            E T29, T2a, T2h, T2c, T2d, T2i;
            T29 = ii[s8];
            T2a = ii[s23];
            T2h = T29 + T2a;
            T2c = ii[s13];
            T2d = ii[s18];
            T2i = T2c + T2d;
            T2b = T29 - T2a;
            T2l = T2h + T2i;
            T2e = T2c - T2d;
            T2j = KP559016994 * (T2h - T2i);
        }
        TB = Tt + TA;
        TK = TC + TJ;
        TL = TB + TK;
        T5p = T1X + T1Y;
        T5q = T2k + T2l;
        T5w = T5p + T5q;
        {
            E T1S, T40, T1L, T3Z, T1K;
            T1S = (((KP951056516) * (T1O)) + (KP587785252 * T1R));
            T40 = ((KP951056516 * T1R) - ((KP587785252) * (T1O)));
            T1K = ((Tt) - ((KP250000000) * (TA)));
            T1L = T1J + T1K;
            T3Z = T1K - T1J;
            T1T = T1L + T1S;
            T4N = T3Z + T40;
            T3c = T1L - T1S;
            T41 = T3Z - T40;
        }
        {
            E T2q, T49, T2n, T4a, T2m;
            T2q = (((KP951056516) * (T2o)) + (KP587785252 * T2p));
            T49 = ((KP951056516 * T2p) - ((KP587785252) * (T2o)));
            T2m = ((T2k) - ((KP250000000) * (T2l)));
            T2n = T2j + T2m;
            T4a = T2m - T2j;
            T2r = T2n - T2q;
            T4Q = T4a - T49;
            T3e = T2q + T2n;
            T4b = T49 + T4a;
        }
        {
            E T2f, T47, T28, T46, T27;
            T2f = (((KP951056516) * (T2b)) + (KP587785252 * T2e));
            T47 = ((KP951056516 * T2e) - ((KP587785252) * (T2b)));
            T27 = ((TC) - ((KP250000000) * (TJ)));
            T28 = T26 + T27;
            T46 = T27 - T26;
            T2g = T28 + T2f;
            T4R = T46 + T47;
            T3f = T28 - T2f;
            T48 = T46 - T47;
        }
        {
            E T23, T42, T20, T43, T1Z;
            T23 = (((KP951056516) * (T21)) + (KP587785252 * T22));
            T42 = ((KP951056516 * T22) - ((KP587785252) * (T21)));
            T1Z = ((T1X) - ((KP250000000) * (T1Y)));
            T20 = T1W + T1Z;
            T43 = T1Z - T1W;
            T24 = T20 - T23;
            T4O = T43 - T42;
            T3b = T23 + T20;
            T44 = T42 + T43;
        }
    }
    {
        E T5j, TM, T5k, T5s, T5u, T5o, T5r, T5t, T5l;
        T5j = KP559016994 * (Ts - TL);
        TM = Ts + TL;
        T5k = ((T9) - ((KP250000000) * (TM)));
        T5o = T5m - T5n;
        T5r = T5p - T5q;
        T5s = (((KP951056516) * (T5o)) + (KP587785252 * T5r));
        T5u = ((KP951056516 * T5r) - ((KP587785252) * (T5o)));
        ro[0] = T9 + TM;
        T5t = T5k - T5j;
        ro[s10] = T5t - T5u;
        ro[s15] = T5t + T5u;
        T5l = T5j + T5k;
        ro[s20] = T5l - T5s;
        ro[s5] = T5l + T5s;
    }
    {
        E T5x, T5z, T5A, T5E, T5F, T5C, T5D, T5G, T5B;
        T5x = KP559016994 * (T5v - T5w);
        T5z = T5v + T5w;
        T5A = ((T5y) - ((KP250000000) * (T5z)));
        T5C = Ti - Tr;
        T5D = TB - TK;
        T5E = (((KP951056516) * (T5C)) + (KP587785252 * T5D));
        T5F = ((KP951056516 * T5D) - ((KP587785252) * (T5C)));
        io[0] = T5y + T5z;
        T5G = T5A - T5x;
        io[s10] = T5F + T5G;
        io[s15] = T5G - T5F;
        T5B = T5x + T5A;
        io[s5] = T5B - T5E;
        io[s20] = T5E + T5B;
    }
    {
        E TX, T2U, T2u, T2Z, T2v, T2Y, T2A, T2V, T2D, T2J;
        TX = TP + TW;
        T2U = T2Q - T2T;
        {
            E T1k, T1H, T1I, T25, T2s, T2t;
            T1k = (((KP968583161) * (T18)) + (KP248689887 * T1j));
            T1H = (((KP535826794) * (T1v)) + (KP844327925 * T1G));
            T1I = T1k + T1H;
            T25 = (((KP876306680) * (T1T)) + (KP481753674 * T24));
            T2s = (((KP728968627) * (T2g)) + (KP684547105 * T2r));
            T2t = T25 + T2s;
            T2u = T1I + T2t;
            T2Z = T25 - T2s;
            T2v = KP559016994 * (T1I - T2t);
            T2Y = T1k - T1H;
        }
        {
            E T2y, T2z, T2H, T2B, T2C, T2I;
            T2y = ((KP968583161 * T1j) - ((KP248689887) * (T18)));
            T2z = ((KP535826794 * T1G) - ((KP844327925) * (T1v)));
            T2H = T2y + T2z;
            T2B = ((KP876306680 * T24) - ((KP481753674) * (T1T)));
            T2C = ((KP728968627 * T2r) - ((KP684547105) * (T2g)));
            T2I = T2B + T2C;
            T2A = T2y - T2z;
            T2V = T2H + T2I;
            T2D = T2B - T2C;
            T2J = KP559016994 * (T2H - T2I);
        }
        ro[s1] = TX + T2u;
        io[s1] = T2U + T2V;
        {
            E T2E, T2G, T2x, T2F, T2w;
            T2E = (((KP951056516) * (T2A)) + (KP587785252 * T2D));
            T2G = ((KP951056516 * T2D) - ((KP587785252) * (T2A)));
            T2w = ((TX) - ((KP250000000) * (T2u)));
            T2x = T2v + T2w;
            T2F = T2w - T2v;
            ro[s21] = T2x - T2E;
            ro[s16] = T2F + T2G;
            ro[s6] = T2x + T2E;
            ro[s11] = T2F - T2G;
        }
        {
            E T30, T31, T2X, T32, T2W;
            T30 = (((KP951056516) * (T2Y)) + (KP587785252 * T2Z));
            T31 = ((KP951056516 * T2Z) - ((KP587785252) * (T2Y)));
            T2W = ((T2U) - ((KP250000000) * (T2V)));
            T2X = T2J + T2W;
            T32 = T2W - T2J;
            io[s6] = T2X - T30;
            io[s16] = T32 - T31;
            io[s21] = T30 + T2X;
            io[s11] = T31 + T32;
        }
    }
    {
        E T4F, T52, T4U, T5b, T56, T57, T51, T5f, T53, T5e;
        T4F = T3H + T3I;
        T52 = T4v - T4u;
        {
            E T4I, T4L, T4M, T4P, T4S, T4T;
            T4I = (((KP728968627) * (T4G)) + (KP684547105 * T4H));
            T4L = ((KP125333233 * T4J) - ((KP992114701) * (T4K)));
            T4M = T4I + T4L;
            T4P = (((KP062790519) * (T4N)) + (KP998026728 * T4O));
            T4S = ((KP770513242 * T4Q) - ((KP637423989) * (T4R)));
            T4T = T4P + T4S;
            T4U = T4M + T4T;
            T5b = KP559016994 * (T4M - T4T);
            T56 = T4I - T4L;
            T57 = T4P - T4S;
        }
        {
            E T4V, T4W, T4X, T4Y, T4Z, T50;
            T4V = ((KP728968627 * T4H) - ((KP684547105) * (T4G)));
            T4W = (((KP125333233) * (T4K)) + (KP992114701 * T4J));
            T4X = T4V - T4W;
            T4Y = ((KP062790519 * T4O) - ((KP998026728) * (T4N)));
            T4Z = (((KP770513242) * (T4R)) + (KP637423989 * T4Q));
            T50 = T4Y - T4Z;
            T51 = KP559016994 * (T4X - T50);
            T5f = T4Y + T4Z;
            T53 = T4X + T50;
            T5e = T4V + T4W;
        }
        ro[s3] = T4F + T4U;
        io[s3] = T52 + T53;
        {
            E T58, T59, T55, T5a, T54;
            T58 = (((KP951056516) * (T56)) + (KP587785252 * T57));
            T59 = ((KP951056516 * T57) - ((KP587785252) * (T56)));
            T54 = ((T52) - ((KP250000000) * (T53)));
            T55 = T51 + T54;
            T5a = T54 - T51;
            io[s8] = T55 - T58;
            io[s18] = T5a - T59;
            io[s23] = T58 + T55;
            io[s13] = T59 + T5a;
        }
        {
            E T5g, T5i, T5d, T5h, T5c;
            T5g = (((KP951056516) * (T5e)) + (KP587785252 * T5f));
            T5i = ((KP951056516 * T5f) - ((KP587785252) * (T5e)));
            T5c = ((T4F) - ((KP250000000) * (T4U)));
            T5d = T5b + T5c;
            T5h = T5c - T5b;
            ro[s23] = T5d - T5g;
            ro[s18] = T5h + T5i;
            ro[s8] = T5d + T5g;
            ro[s13] = T5h - T5i;
        }
    }
    {
        E T3J, T4w, T4e, T4B, T4f, T4A, T4k, T4x, T4n, T4t;
        T3J = T3H - T3I;
        T4w = T4u + T4v;
        {
            E T3Q, T3X, T3Y, T45, T4c, T4d;
            T3Q = (((KP876306680) * (T3M)) + (KP481753674 * T3P));
            T3X = ((KP904827052 * T3T) - ((KP425779291) * (T3W)));
            T3Y = T3Q + T3X;
            T45 = (((KP535826794) * (T41)) + (KP844327925 * T44));
            T4c = (((KP062790519) * (T48)) + (KP998026728 * T4b));
            T4d = T45 + T4c;
            T4e = T3Y + T4d;
            T4B = T45 - T4c;
            T4f = KP559016994 * (T3Y - T4d);
            T4A = T3Q - T3X;
        }
        {
            E T4i, T4j, T4r, T4l, T4m, T4s;
            T4i = ((KP876306680 * T3P) - ((KP481753674) * (T3M)));
            T4j = (((KP904827052) * (T3W)) + (KP425779291 * T3T));
            T4r = T4i - T4j;
            T4l = ((KP535826794 * T44) - ((KP844327925) * (T41)));
            T4m = ((KP062790519 * T4b) - ((KP998026728) * (T48)));
            T4s = T4l + T4m;
            T4k = T4i + T4j;
            T4x = T4r + T4s;
            T4n = T4l - T4m;
            T4t = KP559016994 * (T4r - T4s);
        }
        ro[s2] = T3J + T4e;
        io[s2] = T4w + T4x;
        {
            E T4o, T4q, T4h, T4p, T4g;
            T4o = (((KP951056516) * (T4k)) + (KP587785252 * T4n));
            T4q = ((KP951056516 * T4n) - ((KP587785252) * (T4k)));
            T4g = ((T3J) - ((KP250000000) * (T4e)));
            T4h = T4f + T4g;
            T4p = T4g - T4f;
            ro[s22] = T4h - T4o;
            ro[s17] = T4p + T4q;
            ro[s7] = T4h + T4o;
            ro[s12] = T4p - T4q;
        }
        {
            E T4C, T4D, T4z, T4E, T4y;
            T4C = (((KP951056516) * (T4A)) + (KP587785252 * T4B));
            T4D = ((KP951056516 * T4B) - ((KP587785252) * (T4A)));
            T4y = ((T4w) - ((KP250000000) * (T4x)));
            T4z = T4t + T4y;
            T4E = T4y - T4t;
            io[s7] = T4z - T4C;
            io[s17] = T4E - T4D;
            io[s22] = T4C + T4z;
            io[s12] = T4D + T4E;
        }
    }
    {
        E T33, T3j, T3i, T3z, T3r, T3s, T3q, T3D, T3v, T3C;
        T33 = TP - TW;
        T3j = T2T + T2Q;
        {
            E T36, T39, T3a, T3d, T3g, T3h;
            T36 = (((KP535826794) * (T34)) + (KP844327925 * T35));
            T39 = (((KP637423989) * (T37)) + (KP770513242 * T38));
            T3a = T36 - T39;
            T3d = ((KP904827052 * T3b) - ((KP425779291) * (T3c)));
            T3g = ((KP125333233 * T3e) - ((KP992114701) * (T3f)));
            T3h = T3d + T3g;
            T3i = T3a + T3h;
            T3z = KP559016994 * (T3a - T3h);
            T3r = T3d - T3g;
            T3s = T36 + T39;
        }
        {
            E T3k, T3l, T3m, T3n, T3o, T3p;
            T3k = ((KP535826794 * T35) - ((KP844327925) * (T34)));
            T3l = ((KP770513242 * T37) - ((KP637423989) * (T38)));
            T3m = T3k + T3l;
            T3n = (((KP904827052) * (T3c)) + (KP425779291 * T3b));
            T3o = (((KP125333233) * (T3f)) + (KP992114701 * T3e));
            T3p = T3n + T3o;
            T3q = T3m - T3p;
            T3D = T3o - T3n;
            T3v = KP559016994 * (T3m + T3p);
            T3C = T3k - T3l;
        }
        ro[s4] = T33 + T3i;
        io[s4] = T3j + T3q;
        {
            E T3t, T3y, T3w, T3x, T3u;
            T3t = ((KP951056516 * T3r) - ((KP587785252) * (T3s)));
            T3y = (((KP951056516) * (T3s)) + (KP587785252 * T3r));
            T3u = ((T3j) - ((KP250000000) * (T3q)));
            T3w = T3u - T3v;
            T3x = T3u + T3v;
            io[s14] = T3t + T3w;
            io[s24] = T3y + T3x;
            io[s19] = T3w - T3t;
            io[s9] = T3x - T3y;
        }
        {
            E T3E, T3G, T3B, T3F, T3A;
            T3E = (((KP951056516) * (T3C)) + (KP587785252 * T3D));
            T3G = ((KP951056516 * T3D) - ((KP587785252) * (T3C)));
            T3A = ((T33) - ((KP250000000) * (T3i)));
            T3B = T3z + T3A;
            T3F = T3A - T3z;
            ro[s24] = T3B - T3E;
            ro[s19] = T3F + T3G;
            ro[s9] = T3B + T3E;
            ro[s14] = T3F - T3G;
        }
    }
}
}
