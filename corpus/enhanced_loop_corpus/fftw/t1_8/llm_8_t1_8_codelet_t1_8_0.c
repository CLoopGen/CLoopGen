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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 14); m < me; m = m + 2 , ri = ri + (ms * 2) , ii = ii + (ms * 2) , W = W + 28 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;
    E T7a, T1ea, THa, T19a, TFa, T13a, TRa, TUa, Tia, T1fa, TKa, T16a, Tua, T12a, TMa;
    E TPa, TPb;
    E T7b, T1eb, THb, T19b, TFb, T13b, TRb, TUb, Tib, T1fb, TKb, T16b, Tub, T12b, TMb;
    E TPc, TPd;

    // First iteration (m)
    {
        E T1, T18, T6, T17;
        T1 = ri[0];
        T18 = ii[0];
        {
            E T3, T5, T2, T4;
            T3 = ri[(rs[4])];
            T5 = ii[(rs[4])];
            T2 = W[6];
            T4 = W[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T17 = ((T2 * T5) - ((T4) * (T3)));
        }
        T7a = T1 + T6;
        T1ea = T18 - T17;
        THa = T1 - T6;
        T19a = T17 + T18;
    }
    {
        E Tz, TS, TE, TT;
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri[(rs[7])];
            Ty = ii[(rs[7])];
            Tv = W[12];
            Tx = W[13];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            TS = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = ri[(rs[3])];
            TD = ii[(rs[3])];
            TA = W[4];
            TC = W[5];
            TE = (((TA) * (TB)) + (TC * TD));
            TT = ((TA * TD) - ((TC) * (TB)));
        }
        TFa = Tz + TE;
        T13a = TS + TT;
        TRa = Tz - TE;
        TUa = TS - TT;
    }
    {
        E Tc, TI, Th, TJ;
        {
            E T9, Tb, T8, Ta;
            T9 = ri[(rs[2])];
            Tb = ii[(rs[2])];
            T8 = W[2];
            Ta = W[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TI = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri[(rs[6])];
            Tg = ii[(rs[6])];
            Td = W[10];
            Tf = W[11];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TJ = ((Td * Tg) - ((Tf) * (Te)));
        }
        Tia = Tc + Th;
        T1fa = Tc - Th;
        TKa = TI - TJ;
        T16a = TI + TJ;
    }
    {
        E To, TN, Tt, TO;
        {
            E Tl, Tn, Tk, Tm;
            Tl = ri[(rs[1])];
            Tn = ii[(rs[1])];
            Tk = W[0];
            Tm = W[1];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            TN = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = ri[(rs[5])];
            Ts = ii[(rs[5])];
            Tp = W[8];
            Tr = W[9];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            TO = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        Tua = To + Tt;
        T12a = TN + TO;
        TMa = To - Tt;
        TPa = TN - TO;
    }
    {
        E Tj, TG, T1b, T1c;
        Tj = T7a + Tia;
        TG = Tua + TFa;
        ri[(rs[4])] = Tj - TG;
        ri[0] = Tj + TG;
        {
            E T15, T1a, T11, T14;
            T15 = T12a + T13a;
            T1a = T16a + T19a;
            ii[0] = T15 + T1a;
            ii[(rs[4])] = T1a - T15;
            T11 = T7a - Tia;
            T14 = T12a - T13a;
            ri[(rs[6])] = T11 - T14;
            ri[(rs[2])] = T11 + T14;
        }
        T1b = TFa - Tua;
        T1c = T19a - T16a;
        ii[(rs[2])] = T1b + T1c;
        ii[(rs[6])] = T1c - T1b;
        {
            E TX, T1g, T10, T1d, TY, TZ;
            TX = THa - TKa;
            T1g = T1ea - T1fa;
            TY = TPa - TMa;
            TZ = TRa + TUa;
            T10 = KP707106781 * (TY - TZ);
            T1d = KP707106781 * (TY + TZ);
            ri[(rs[7])] = TX - T10;
            ii[(rs[5])] = T1g - T1d;
            ri[(rs[3])] = TX + T10;
            ii[(rs[1])] = T1d + T1g;
        }
        {
            E TL, T1i, TW, T1h, TQ, TV;
            TL = THa + TKa;
            T1i = T1fa + T1ea;
            TQ = TMa + TPa;
            TV = TRa - TUa;
            TW = KP707106781 * (TQ + TV);
            T1h = KP707106781 * (TV - TQ);
            ri[(rs[5])] = TL - TW;
            ii[(rs[7])] = T1i - T1h;
            ri[(rs[1])] = TL + TW;
            ii[(rs[3])] = T1h + T1i;
        }
    }

    // Second iteration (m+1), offset by ms and W stride
    R *ri_next = ri + ms;
    R *ii_next = ii + ms;
    stride rs_next = rs;
    const R *W_next = W + 14;

    {
        E T1, T18, T6, T17;
        T1 = ri_next[0];
        T18 = ii_next[0];
        {
            E T3, T5, T2, T4;
            T3 = ri_next[(rs_next[4])];
            T5 = ii_next[(rs_next[4])];
            T2 = W_next[6];
            T4 = W_next[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T17 = ((T2 * T5) - ((T4) * (T3)));
        }
        T7b = T1 + T6;
        T1eb = T18 - T17;
        THb = T1 - T6;
        T19b = T17 + T18;
    }
    {
        E Tz, TS, TE, TT;
        {
            E Tw, Ty, Tv, Tx;
            Tw = ri_next[(rs_next[7])];
            Ty = ii_next[(rs_next[7])];
            Tv = W_next[12];
            Tx = W_next[13];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            TS = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = ri_next[(rs_next[3])];
            TD = ii_next[(rs_next[3])];
            TA = W_next[4];
            TC = W_next[5];
            TE = (((TA) * (TB)) + (TC * TD));
            TT = ((TA * TD) - ((TC) * (TB)));
        }
        TFb = Tz + TE;
        T13b = TS + TT;
        TRb = Tz - TE;
        TUb = TS - TT;
    }
    {
        E Tc, TI, Th, TJ;
        {
            E T9, Tb, T8, Ta;
            T9 = ri_next[(rs_next[2])];
            Tb = ii_next[(rs_next[2])];
            T8 = W_next[2];
            Ta = W_next[3];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            TI = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = ri_next[(rs_next[6])];
            Tg = ii_next[(rs_next[6])];
            Td = W_next[10];
            Tf = W_next[11];
            Th = (((Td) * (Te)) + (Tf * Tg));
            TJ = ((Td * Tg) - ((Tf) * (Te)));
        }
        Tib = Tc + Th;
        T1fb = Tc - Th;
        TKb = TI - TJ;
        T16b = TI + TJ;
    }
    {
        E To, TN, Tt, TO;
        {
            E Tl, Tn, Tk, Tm;
            Tl = ri_next[(rs_next[1])];
            Tn = ii_next[(rs_next[1])];
            Tk = W_next[0];
            Tm = W_next[1];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            TN = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = ri_next[(rs_next[5])];
            Ts = ii_next[(rs_next[5])];
            Tp = W_next[8];
            Tr = W_next[9];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            TO = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        Tub = To + Tt;
        T12b = TN + TO;
        TMb = To - Tt;
        TPc = TN - TO;
    }
    {
        E Tj, TG, T1b, T1c;
        Tj = T7b + Tib;
        TG = Tub + TFb;
        ri_next[(rs_next[4])] = Tj - TG;
        ri_next[0] = Tj + TG;
        {
            E T15, T1a, T11, T14;
            T15 = T12b + T13b;
            T1a = T16b + T19b;
            ii_next[0] = T15 + T1a;
            ii_next[(rs_next[4])] = T1a - T15;
            T11 = T7b - Tib;
            T14 = T12b - T13b;
            ri_next[(rs_next[6])] = T11 - T14;
            ri_next[(rs_next[2])] = T11 + T14;
        }
        T1b = TFb - Tub;
        T1c = T19b - T16b;
        ii_next[(rs_next[2])] = T1b + T1c;
        ii_next[(rs_next[6])] = T1c - T1b;
        {
            E TX, T1g, T10, T1d, TY, TZ;
            TX = THb - TKb;
            T1g = T1eb - T1fb;
            TY = TPc - TMb;
            TZ = TRb + TUb;
            T10 = KP707106781 * (TY - TZ);
            T1d = KP707106781 * (TY + TZ);
            ri_next[(rs_next[7])] = TX - T10;
            ii_next[(rs_next[5])] = T1g - T1d;
            ri_next[(rs_next[3])] = TX + T10;
            ii_next[(rs_next[1])] = T1d + T1g;
        }
        {
            E TL, T1i, TW, T1h, TQ, TV;
            TL = THb + TKb;
            T1i = T1fb + T1eb;
            TQ = TMb + TPc;
            TV = TRb - TUb;
            TW = KP707106781 * (TQ + TV);
            T1h = KP707106781 * (TV - TQ);
            ri_next[(rs_next[5])] = TL - TW;
            ii_next[(rs_next[7])] = T1i - T1h;
            ri_next[(rs_next[1])] = TL + TW;
            ii_next[(rs_next[3])] = T1h + T1i;
        }
    }
}
}
