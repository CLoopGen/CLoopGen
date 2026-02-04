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
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1R, T25, TC, TN, T1x, T1H, T1l, Tt, T22, T2h, T1b, T1g, T1E, T1Z;
    E T1D, Te, T1S, T26, TJ, TQ, T1m, T1n, TT, Tm, T1X, T2g, T10, T15, T1B;
    E T1U, T1A;
    E temp_storage[32]; // Introduce local storage to modify data flow
    INT idx = 0;

    {
        E T3, TL, Ty, T1k, T6, T1j, TB, TM;
        {
            E T1 = ri[0];
            E T2 = ri[(is[8])];
            T3 = T1 + T2;
            TL = T1 - T2;
            E Tw = ii[0];
            E Tx = ii[(is[8])];
            Ty = Tw + Tx;
            T1k = Tw - Tx;
        }
        {
            E T4 = ri[(is[4])];
            E T5 = ri[(is[12])];
            T6 = T4 + T5;
            T1j = T4 - T5;
            E Tz = ii[(is[4])];
            E TA = ii[(is[12])];
            TB = Tz + TA;
            TM = Tz - TA;
        }
        temp_storage[idx++] = T3; temp_storage[idx++] = T6;
        temp_storage[idx++] = Ty; temp_storage[idx++] = TB;
        temp_storage[idx++] = TL; temp_storage[idx++] = TM;
        temp_storage[idx++] = T1k; temp_storage[idx++] = T1j;
    }

    {
        E Tp, T17, T1f, T20, Ts, T1c, T1a, T21;
        {
            E Tn = ri[(is[15])];
            E To = ri[(is[7])];
            Tp = Tn + To;
            T17 = Tn - To;
            E T1d = ii[(is[15])];
            E T1e = ii[(is[7])];
            T1f = T1d - T1e;
            T20 = T1d + T1e;
        }
        {
            E Tq = ri[(is[3])];
            E Tr = ri[(is[11])];
            Ts = Tq + Tr;
            T1c = Tq - Tr;
            E T18 = ii[(is[3])];
            E T19 = ii[(is[11])];
            T1a = T18 - T19;
            T21 = T18 + T19;
        }
        temp_storage[idx++] = Tp; temp_storage[idx++] = Ts;
        temp_storage[idx++] = T20; temp_storage[idx++] = T21;
        temp_storage[idx++] = T17; temp_storage[idx++] = T1a;
        temp_storage[idx++] = T1c; temp_storage[idx++] = T1f;
    }

    {
        E Ta, TP, TF, TO, Td, TR, TI, TS;
        {
            E T8 = ri[(is[2])];
            E T9 = ri[(is[10])];
            Ta = T8 + T9;
            TP = T8 - T9;
            E TD = ii[(is[2])];
            E TE = ii[(is[10])];
            TF = TD + TE;
            TO = TD - TE;
        }
        {
            E Tb = ri[(is[14])];
            E Tc = ri[(is[6])];
            Td = Tb + Tc;
            TR = Tb - Tc;
            E TG = ii[(is[14])];
            E TH = ii[(is[6])];
            TI = TG + TH;
            TS = TG - TH;
        }
        temp_storage[idx++] = Ta; temp_storage[idx++] = Td;
        temp_storage[idx++] = TF; temp_storage[idx++] = TI;
        temp_storage[idx++] = TP; temp_storage[idx++] = TO;
        temp_storage[idx++] = TR; temp_storage[idx++] = TS;
    }

    {
        E Ti, T11, TZ, T1V, Tl, TW, T14, T1W;
        {
            E Tg = ri[(is[1])];
            E Th = ri[(is[9])];
            Ti = Tg + Th;
            T11 = Tg - Th;
            E TX = ii[(is[1])];
            E TY = ii[(is[9])];
            TZ = TX - TY;
            T1V = TX + TY;
        }
        {
            E Tj = ri[(is[5])];
            E Tk = ri[(is[13])];
            Tl = Tj + Tk;
            TW = Tj - Tk;
            E T12 = ii[(is[5])];
            E T13 = ii[(is[13])];
            T14 = T12 - T13;
            T1W = T12 + T13;
        }
        temp_storage[idx++] = Ti; temp_storage[idx++] = Tl;
        temp_storage[idx++] = T1V; temp_storage[idx++] = T1W;
        temp_storage[idx++] = T11; temp_storage[idx++] = TZ;
        temp_storage[idx++] = TW; temp_storage[idx++] = T14;
    }

    // Reconstruct values from temp_storage to break direct RAW/WAR dependencies
    INT j = 0;
    E T3 = temp_storage[j++], T6 = temp_storage[j++];
    E Ty = temp_storage[j++], TB = temp_storage[j++];
    E TL = temp_storage[j++], TM = temp_storage[j++];
    E T1k = temp_storage[j++], T1j = temp_storage[j++];
    E Tp = temp_storage[j++], Ts = temp_storage[j++];
    E T20 = temp_storage[j++], T21 = temp_storage[j++];
    E T17 = temp_storage[j++], T1a = temp_storage[j++];
    E T1c = temp_storage[j++], T1f = temp_storage[j++];
    E Ta = temp_storage[j++], Td = temp_storage[j++];
    E TF = temp_storage[j++], TI = temp_storage[j++];
    E TP = temp_storage[j++], TO = temp_storage[j++];
    E TR = temp_storage[j++], TS = temp_storage[j++];
    E Ti = temp_storage[j++], Tl = temp_storage[j++];
    E T1V = temp_storage[j++], T1W = temp_storage[j++];
    E T11 = temp_storage[j++], TZ = temp_storage[j++];
    E TW = temp_storage[j++], T14 = temp_storage[j++];

    T7 = T3 + T6;
    T1R = T3 - T6;
    T25 = Ty - TB;
    TC = Ty + TB;
    TN = TL - TM;
    T1x = TL + TM;
    T1H = T1k - T1j;
    T1l = T1j + T1k;
    Tt = Tp + Ts;
    T22 = T20 - T21;
    T2h = T20 + T21;
    T1b = T17 - T1a;
    T1g = T1c + T1f;
    T1E = T1f - T1c;
    T1Z = Tp - Ts;
    T1D = T17 + T1a;
    Te = Ta + Td;
    T1S = TF - TI;
    T26 = Td - Ta;
    TJ = TF + TI;
    TQ = TO - TP;
    T1m = TR - TS;
    T1n = TP + TO;
    TT = TR + TS;
    Tm = Ti + Tl;
    T1X = T1V - T1W;
    T2g = T1V + T1W;
    T10 = TW + TZ;
    T15 = T11 - T14;
    T1B = T11 + T14;
    T1U = Ti - Tl;
    T1A = TZ - TW;

    {
        E Tf, Tu, T2j, T2k;
        Tf = T7 + Te;
        Tu = Tm + Tt;
        ro[(os[8])] = Tf - Tu;
        ro[0] = Tf + Tu;
        T2j = TC + TJ;
        T2k = T2g + T2h;
        io[(os[8])] = T2j - T2k;
        io[0] = T2j + T2k;
    }
    {
        E Tv, TK, T2f, T2i;
        Tv = Tt - Tm;
        TK = TC - TJ;
        io[(os[4])] = Tv + TK;
        io[(os[12])] = TK - Tv;
        T2f = T7 - Te;
        T2i = T2g - T2h;
        ro[(os[12])] = T2f - T2i;
        ro[(os[4])] = T2f + T2i;
    }
    {
        E T1T, T27, T24, T28, T1Y, T23;
        T1T = T1R + T1S;
        T27 = T25 - T26;
        T1Y = T1U + T1X;
        T23 = T1Z - T22;
        T24 = KP707106781 * (T1Y + T23);
        T28 = KP707106781 * (T23 - T1Y);
        ro[(os[10])] = T1T - T24;
        io[(os[6])] = T27 + T28;
        ro[(os[2])] = T1T + T24;
        io[(os[14])] = T27 - T28;
    }
    {
        E T29, T2d, T2c, T2e, T2a, T2b;
        T29 = T1R - T1S;
        T2d = T26 + T25;
        T2a = T1X - T1U;
        T2b = T1Z + T22;
        T2c = KP707106781 * (T2a - T2b);
        T2e = KP707106781 * (T2a + T2b);
        ro[(os[14])] = T29 - T2c;
        io[(os[2])] = T2d + T2e;
        ro[(os[6])] = T29 + T2c;
        io[(os[10])] = T2d - T2e;
    }
    {
        E TV, T1r, T1p, T1v, T1i, T1q, T1u, T1w, TU, T1o;
        TU = KP707106781 * (TQ - TT);
        TV = TN + TU;
        T1r = TN - TU;
        T1o = KP707106781 * (T1m - T1n);
        T1p = T1l - T1o;
        T1v = T1l + T1o;
        {
            E T16 = (((KP923879532) * (T10)) + (KP382683432 * T15));
            E T1h = ((KP382683432 * T1b) - ((KP923879532) * (T1g)));
            T1i = T16 + T1h;
            T1q = T1h - T16;
            E T1s = ((KP382683432 * T10) - ((KP923879532) * (T15)));
            E T1t = (((KP382683432) * (T1g)) + (KP923879532 * T1b));
            T1u = T1s - T1t;
            T1w = T1s + T1t;
        }
        ro[(os[11])] = TV - T1i;
        io[(os[11])] = T1v - T1w;
        ro[(os[3])] = TV + T1i;
        io[(os[3])] = T1v + T1w;
        io[(os[15])] = T1p - T1q;
        ro[(os[15])] = T1r - T1u;
        io[(os[7])] = T1p + T1q;
        ro[(os[7])] = T1r + T1u;
    }
    {
        E T1z, T1L, T1J, T1P, T1G, T1K, T1O, T1Q, T1y, T1I;
        T1y = KP707106781 * (T1n + T1m);
        T1z = T1x + T1y;
        T1L = T1x - T1y;
        T1I = KP707106781 * (TQ + TT);
        T1J = T1H - T1I;
        T1P = T1H + T1I;
        {
            E T1C = (((KP382683432) * (T1A)) + (KP923879532 * T1B));
            E T1F = ((KP923879532 * T1D) - ((KP382683432) * (T1E)));
            T1G = T1C + T1F;
            T1K = T1F - T1C;
            E T1M = ((KP923879532 * T1A) - ((KP382683432) * (T1B)));
            E T1N = (((KP923879532) * (T1E)) + (KP382683432 * T1D));
            T1O = T1M - T1N;
            T1Q = T1M + T1N;
        }
        ro[(os[9])] = T1z - T1G;
        io[(os[9])] = T1P - T1Q;
        ro[(os[1])] = T1z + T1G;
        io[(os[1])] = T1P + T1Q;
        io[(os[13])] = T1J - T1K;
        ro[(os[13])] = T1L - T1O;
        io[(os[5])] = T1J + T1K;
        ro[(os[5])] = T1L + T1O;
    }
}
}
