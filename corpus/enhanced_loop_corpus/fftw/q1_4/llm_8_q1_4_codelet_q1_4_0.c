#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 2 , rio = rio + (2 * ms) , iio = iio + (2 * ms) , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T3, Te, Tb, Tq, T6, T8, Th, Tr, Tv, TG, TD, TS, Ty, TA, TJ;
    E TT, TX, T18, T15, T1k, T10, T12, T1b, T1l, T1p, T1A, T1x, T1M, T1s, T1u;
    E T1D, T1N;
    E U3, Ue, Ub, Uq, U6, U8, Uh, Ur, Uv, UG, UD, US, Uy, UA, UJ;
    E UT, UX, U18, U15, U1k, U10, U12, U1b, U1l, U1p, U1A, U1x, U1M, U1s, U1u;
    E U1D, U1N;

    // First iteration (m)
    {
        E T1, T2, T9, Ta;
        T1 = rio[0];
        T2 = rio[(rs[2])];
        T3 = T1 + T2;
        Te = T1 - T2;
        T9 = iio[0];
        Ta = iio[(rs[2])];
        Tb = T9 - Ta;
        Tq = T9 + Ta;
    }
    {
        E T4, T5, Tf, Tg;
        T4 = rio[(rs[1])];
        T5 = rio[(rs[3])];
        T6 = T4 + T5;
        T8 = T4 - T5;
        Tf = iio[(rs[1])];
        Tg = iio[(rs[3])];
        Th = Tf - Tg;
        Tr = Tf + Tg;
    }
    {
        E Tt, Tu, TB, TC;
        Tt = rio[(vs[1])];
        Tu = rio[(vs[1]) + (rs[2])];
        Tv = Tt + Tu;
        TG = Tt - Tu;
        TB = iio[(vs[1])];
        TC = iio[(vs[1]) + (rs[2])];
        TD = TB - TC;
        TS = TB + TC;
    }
    {
        E Tw, Tx, TH, TI;
        Tw = rio[(vs[1]) + (rs[1])];
        Tx = rio[(vs[1]) + (rs[3])];
        Ty = Tw + Tx;
        TA = Tw - Tx;
        TH = iio[(vs[1]) + (rs[1])];
        TI = iio[(vs[1]) + (rs[3])];
        TJ = TH - TI;
        TT = TH + TI;
    }
    {
        E TV, TW, T13, T14;
        TV = rio[(vs[2])];
        TW = rio[(vs[2]) + (rs[2])];
        TX = TV + TW;
        T18 = TV - TW;
        T13 = iio[(vs[2])];
        T14 = iio[(vs[2]) + (rs[2])];
        T15 = T13 - T14;
        T1k = T13 + T14;
    }
    {
        E TY, TZ, T19, T1a;
        TY = rio[(vs[2]) + (rs[1])];
        TZ = rio[(vs[2]) + (rs[3])];
        T10 = TY + TZ;
        T12 = TY - TZ;
        T19 = iio[(vs[2]) + (rs[1])];
        T1a = iio[(vs[2]) + (rs[3])];
        T1b = T19 - T1a;
        T1l = T19 + T1a;
    }
    {
        E T1n, T1o, T1v, T1w;
        T1n = rio[(vs[3])];
        T1o = rio[(vs[3]) + (rs[2])];
        T1p = T1n + T1o;
        T1A = T1n - T1o;
        T1v = iio[(vs[3])];
        T1w = iio[(vs[3]) + (rs[2])];
        T1x = T1v - T1w;
        T1M = T1v + T1w;
    }
    {
        E T1q, T1r, T1B, T1C;
        T1q = rio[(vs[3]) + (rs[1])];
        T1r = rio[(vs[3]) + (rs[3])];
        T1s = T1q + T1r;
        T1u = T1q - T1r;
        T1B = iio[(vs[3]) + (rs[1])];
        T1C = iio[(vs[3]) + (rs[3])];
        T1D = T1B - T1C;
        T1N = T1B + T1C;
    }

    rio[0] = T3 + T6;
    iio[0] = Tq + Tr;
    rio[(rs[1])] = Tv + Ty;
    iio[(rs[1])] = TS + TT;
    rio[(rs[2])] = TX + T10;
    iio[(rs[2])] = T1k + T1l;
    iio[(rs[3])] = T1M + T1N;
    rio[(rs[3])] = T1p + T1s;

    {
        E Tc, Ti, T7, Td;
        Tc = T8 + Tb;
        Ti = Te - Th;
        T7 = W[4];
        Td = W[5];
        iio[(vs[3])] = ((T7 * Tc) - ((Td) * (Ti)));
        rio[(vs[3])] = (((Td) * (Tc)) + (T7 * Ti));
    }
    {
        E T1K, T1O, T1J, T1L;
        T1K = T1p - T1s;
        T1O = T1M - T1N;
        T1J = W[2];
        T1L = W[3];
        rio[(vs[2]) + (rs[3])] = (((T1J) * (T1K)) + (T1L * T1O));
        iio[(vs[2]) + (rs[3])] = ((T1J * T1O) - ((T1L) * (T1K)));
    }
    {
        E Tk, Tm, Tj, Tl;
        Tk = Tb - T8;
        Tm = Te + Th;
        Tj = W[0];
        Tl = W[1];
        iio[(vs[1])] = ((Tj * Tk) - ((Tl) * (Tm)));
        rio[(vs[1])] = (((Tl) * (Tk)) + (Tj * Tm));
    }
    {
        E To, Ts, Tn, Tp;
        To = T3 - T6;
        Ts = Tq - Tr;
        Tn = W[2];
        Tp = W[3];
        rio[(vs[2])] = (((Tn) * (To)) + (Tp * Ts));
        iio[(vs[2])] = ((Tn * Ts) - ((Tp) * (To)));
    }
    {
        E T16, T1c, T11, T17;
        T16 = T12 + T15;
        T1c = T18 - T1b;
        T11 = W[4];
        T17 = W[5];
        iio[(vs[3]) + (rs[2])] = ((T11 * T16) - ((T17) * (T1c)));
        rio[(vs[3]) + (rs[2])] = (((T17) * (T16)) + (T11 * T1c));
    }
    {
        E T1G, T1I, T1F, T1H;
        T1G = T1x - T1u;
        T1I = T1A + T1D;
        T1F = W[0];
        T1H = W[1];
        iio[(vs[1]) + (rs[3])] = ((T1F * T1G) - ((T1H) * (T1I)));
        rio[(vs[1]) + (rs[3])] = (((T1H) * (T1G)) + (T1F * T1I));
    }
    {
        E TQ, TU, TP, TR;
        TQ = Tv - Ty;
        TU = TS - TT;
        TP = W[2];
        TR = W[3];
        rio[(vs[2]) + (rs[1])] = (((TP) * (TQ)) + (TR * TU));
        iio[(vs[2]) + (rs[1])] = ((TP * TU) - ((TR) * (TQ)));
    }
    {
        E T1e, T1g, T1d, T1f;
        T1e = T15 - T12;
        T1g = T18 + T1b;
        T1d = W[0];
        T1f = W[1];
        iio[(vs[1]) + (rs[2])] = ((T1d * T1e) - ((T1f) * (T1g)));
        rio[(vs[1]) + (rs[2])] = (((T1f) * (T1e)) + (T1d * T1g));
    }
    {
        E T1i, T1m, T1h, T1j;
        T1i = TX - T10;
        T1m = T1k - T1l;
        T1h = W[2];
        T1j = W[3];
        rio[(vs[2]) + (rs[2])] = (((T1h) * (T1i)) + (T1j * T1m));
        iio[(vs[2]) + (rs[2])] = ((T1h * T1m) - ((T1j) * (T1i)));
    }
    {
        E T1y, T1E, T1t, T1z;
        T1y = T1u + T1x;
        T1E = T1A - T1D;
        T1t = W[4];
        T1z = W[5];
        iio[(vs[3]) + (rs[3])] = ((T1t * T1y) - ((T1z) * (T1E)));
        rio[(vs[3]) + (rs[3])] = (((T1z) * (T1y)) + (T1t * T1E));
    }
    {
        E TM, TO, TL, TN;
        TM = TD - TA;
        TO = TG + TJ;
        TL = W[0];
        TN = W[1];
        iio[(vs[1]) + (rs[1])] = ((TL * TM) - ((TN) * (TO)));
        rio[(vs[1]) + (rs[1])] = (((TN) * (TM)) + (TL * TO));
    }
    {
        E TE, TK, Tz, TF;
        TE = TA + TD;
        TK = TG - TJ;
        Tz = W[4];
        TF = W[5];
        iio[(vs[3]) + (rs[1])] = ((Tz * TE) - ((TF) * (TK)));
        rio[(vs[3]) + (rs[1])] = (((TF) * (TE)) + (Tz * TK));
    }

    // Second iteration (m+1), offset by ms in rio/iio and 6 in W
    R *rio_next = rio + ms;
    R *iio_next = iio + ms;
    R *W_next = W + 6;

    {
        E U1, U2, U9, Ua;
        U1 = rio_next[0];
        U2 = rio_next[(rs[2])];
        U3 = U1 + U2;
        Ue = U1 - U2;
        U9 = iio_next[0];
        Ua = iio_next[(rs[2])];
        Ub = U9 - Ua;
        Uq = U9 + Ua;
    }
    {
        E U4, U5, Uf, Ug;
        U4 = rio_next[(rs[1])];
        U5 = rio_next[(rs[3])];
        U6 = U4 + U5;
        U8 = U4 - U5;
        Uf = iio_next[(rs[1])];
        Ug = iio_next[(rs[3])];
        Uh = Uf - Ug;
        Ur = Uf + Ug;
    }
    {
        E Ut, Uu, UB, UC;
        Ut = rio_next[(vs[1])];
        Uu = rio_next[(vs[1]) + (rs[2])];
        Uv = Ut + Uu;
        UG = Ut - Uu;
        UB = iio_next[(vs[1])];
        UC = iio_next[(vs[1]) + (rs[2])];
        UD = UB - UC;
        US = UB + UC;
    }
    {
        E Uw, Ux, UH, UI;
        Uw = rio_next[(vs[1]) + (rs[1])];
        Ux = rio_next[(vs[1]) + (rs[3])];
        Uy = Uw + Ux;
        UA = Uw - Ux;
        UH = iio_next[(vs[1]) + (rs[1])];
        UI = iio_next[(vs[1]) + (rs[3])];
        UJ = UH - UI;
        UT = UH + UI;
    }
    {
        E UV, UW, U13, U14;
        UV = rio_next[(vs[2])];
        UW = rio_next[(vs[2]) + (rs[2])];
        UX = UV + UW;
        U18 = UV - UW;
        U13 = iio_next[(vs[2])];
        U14 = iio_next[(vs[2]) + (rs[2])];
        U15 = U13 - U14;
        U1k = U13 + U14;
    }
    {
        E UY, UZ, U19, U1a;
        UY = rio_next[(vs[2]) + (rs[1])];
        UZ = rio_next[(vs[2]) + (rs[3])];
        U10 = UY + UZ;
        U12 = UY - UZ;
        U19 = iio_next[(vs[2]) + (rs[1])];
        U1a = iio_next[(vs[2]) + (rs[3])];
        U1b = U19 - U1a;
        U1l = U19 + U1a;
    }
    {
        E U1n, U1o, U1v, U1w;
        U1n = rio_next[(vs[3])];
        U1o = rio_next[(vs[3]) + (rs[2])];
        U1p = U1n + U1o;
        U1A = U1n - U1o;
        U1v = iio_next[(vs[3])];
        U1w = iio_next[(vs[3]) + (rs[2])];
        U1x = U1v - U1w;
        U1M = U1v + U1w;
    }
    {
        E U1q, U1r, U1B, U1C;
        U1q = rio_next[(vs[3]) + (rs[1])];
        U1r = rio_next[(vs[3]) + (rs[3])];
        U1s = U1q + U1r;
        U1u = U1q - U1r;
        U1B = iio_next[(vs[3]) + (rs[1])];
        U1C = iio_next[(vs[3]) + (rs[3])];
        U1D = U1B - U1C;
        U1N = U1B + U1C;
    }

    rio_next[0] = U3 + U6;
    iio_next[0] = Uq + Ur;
    rio_next[(rs[1])] = Uv + Uy;
    iio_next[(rs[1])] = US + UT;
    rio_next[(rs[2])] = UX + U10;
    iio_next[(rs[2])] = U1k + U1l;
    iio_next[(rs[3])] = U1M + U1N;
    rio_next[(rs[3])] = U1p + U1s;

    {
        E Uc, Ui, U7, Ud;
        Uc = U8 + Ub;
        Ui = Ue - Uh;
        U7 = W_next[4];
        Ud = W_next[5];
        iio_next[(vs[3])] = ((U7 * Uc) - ((Ud) * (Ui)));
        rio_next[(vs[3])] = (((Ud) * (Uc)) + (U7 * Ui));
    }
    {
        E U1K, U1O, U1J, U1L;
        U1K = U1p - U1s;
        U1O = U1M - U1N;
        U1J = W_next[2];
        U1L = W_next[3];
        rio_next[(vs[2]) + (rs[3])] = (((U1J) * (U1K)) + (U1L * U1O));
        iio_next[(vs[2]) + (rs[3])] = ((U1J * U1O) - ((U1L) * (U1K)));
    }
    {
        E Uk, Um, Uj, Ul;
        Uk = Ub - U8;
        Um = Ue + Uh;
        Uj = W_next[0];
        Ul = W_next[1];
        iio_next[(vs[1])] = ((Uj * Uk) - ((Ul) * (Um)));
        rio_next[(vs[1])] = (((Ul) * (Uk)) + (Uj * Um));
    }
    {
        E Uo, Us, Un, Up;
        Uo = U3 - U6;
        Us = Uq - Ur;
        Un = W_next[2];
        Up = W_next[3];
        rio_next[(vs[2])] = (((Un) * (Uo)) + (Up * Us));
        iio_next[(vs[2])] = ((Un * Us) - ((Up) * (Uo)));
    }
    {
        E U16, U1c, U11, U17;
        U16 = U12 + U15;
        U1c = U18 - U1b;
        U11 = W_next[4];
        U17 = W_next[5];
        iio_next[(vs[3]) + (rs[2])] = ((U11 * U16) - ((U17) * (U1c)));
        rio_next[(vs[3]) + (rs[2])] = (((U17) * (U16)) + (U11 * U1c));
    }
    {
        E U1G, U1I, U1F, U1H;
        U1G = U1x - U1u;
        U1I = U1A + U1D;
        U1F = W_next[0];
        U1H = W_next[1];
        iio_next[(vs[1]) + (rs[3])] = ((U1F * U1G) - ((U1H) * (U1I)));
        rio_next[(vs[1]) + (rs[3])] = (((U1H) * (U1G)) + (U1F * U1I));
    }
    {
        E UQ, UU, UP, UR;
        UQ = Uv - Uy;
        UU = US - UT;
        UP = W_next[2];
        UR = W_next[3];
        rio_next[(vs[2]) + (rs[1])] = (((UP) * (UQ)) + (UR * UU));
        iio_next[(vs[2]) + (rs[1])] = ((UP * UU) - ((UR) * (UQ)));
    }
    {
        E U1e, U1g, U1d, U1f;
        U1e = U15 - U12;
        U1g = U18 + U1b;
        U1d = W_next[0];
        U1f = W_next[1];
        iio_next[(vs[1]) + (rs[2])] = ((U1d * U1e) - ((U1f) * (U1g)));
        rio_next[(vs[1]) + (rs[2])] = (((U1f) * (U1e)) + (U1d * U1g));
    }
    {
        E U1i, U1m, U1h, U1j;
        U1i = UX - U10;
        U1m = U1k - U1l;
        U1h = W_next[2];
        U1j = W_next[3];
        rio_next[(vs[2]) + (rs[2])] = (((U1h) * (U1i)) + (U1j * U1m));
        iio_next[(vs[2]) + (rs[2])] = ((U1h * U1m) - ((U1j) * (U1i)));
    }
    {
        E U1y, U1E, U1t, U1z;
        U1y = U1u + U1x;
        U1E = U1A - U1D;
        U1t = W_next[4];
        U1z = W_next[5];
        iio_next[(vs[3]) + (rs[3])] = ((U1t * U1y) - ((U1z) * (U1E)));
        rio_next[(vs[3]) + (rs[3])] = (((U1z) * (U1y)) + (U1t * U1E));
    }
    {
        E UM, UO, UL, UN;
        UM = UD - UA;
        UO = UG + UJ;
        UL = W_next[0];
        UN = W_next[1];
        iio_next[(vs[1]) + (rs[1])] = ((UL * UM) - ((UN) * (UO)));
        rio_next[(vs[1]) + (rs[1])] = (((UN) * (UM)) + (UL * UO));
    }
    {
        E UE, UK, Uz, UF;
        UE = UA + UD;
        UK = UG - UJ;
        Uz = W_next[4];
        UF = W_next[5];
        iio_next[(vs[3]) + (rs[1])] = ((Uz * UE) - ((UF) * (UK)));
        rio_next[(vs[3]) + (rs[1])] = (((UF) * (UE)) + (Uz * UK));
    }
}
}
