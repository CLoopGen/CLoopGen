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
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
    E TG;
    E accum_real[8] = {0}, accum_imag[8] = {0};

    {
        E T1, T2, Tj, Tk;
        T1 = ri[0];
        T2 = ri[(is[4])];
        T3 = T1 + T2;
        Tn = T1 - T2;
        {
            E Tg, Th, T4, T5;
            Tg = ii[0];
            Th = ii[(is[4])];
            Ti = Tg + Th;
            TC = Tg - Th;
            T4 = ri[(is[2])];
            T5 = ri[(is[6])];
            T6 = T4 + T5;
            TB = T4 - T5;
        }
        Tj = ii[(is[2])];
        Tk = ii[(is[6])];
        Tl = Tj + Tk;
        To = Tj - Tk;
        {
            E Tb, Tc, Tv, Tw, Tx, Ty;
            Tb = ri[(is[7])];
            Tc = ri[(is[3])];
            Tv = Tb - Tc;
            Tw = ii[(is[7])];
            Tx = ii[(is[3])];
            Ty = Tw - Tx;
            Td = Tb + Tc;
            TN = Tw + Tx;
            Tz = Tv - Ty;
            TH = Tv + Ty;
        }
        {
            E T8, T9, Tq, Tr, Ts, Tt;
            T8 = ri[(is[1])];
            T9 = ri[(is[5])];
            Tq = T8 - T9;
            Tr = ii[(is[1])];
            Ts = ii[(is[5])];
            Tt = Tr - Ts;
            Ta = T8 + T9;
            TM = Tr + Ts;
            Tu = Tq + Tt;
            TG = Tt - Tq;
        }
    }

    accum_real[0] = T3 + T6 + Ta + Td;
    accum_real[4] = T3 + T6 - Ta - Td;
    accum_imag[0] = Ti + Tl + TM + TN;
    accum_imag[4] = Ti + Tl - TM - TN;

    accum_real[2] = T3 - T6 + TM - TN;
    accum_real[6] = T3 - T6 - (TM - TN);
    accum_imag[2] = Td - Ta + Ti - Tl;
    accum_imag[6] = Ti - Tl - (Td - Ta);

    accum_real[1] = Tn + To + KP707106781 * (Tu + Tz);
    accum_real[5] = Tn + To - KP707106781 * (Tu + Tz);
    accum_imag[1] = TC - TB + KP707106781 * (TG + TH);
    accum_imag[5] = TC - TB - KP707106781 * (TG + TH);

    accum_real[3] = Tn - To + KP707106781 * (TH - TG);
    accum_real[7] = Tn - To - KP707106781 * (TH - TG);
    accum_imag[3] = TB + TC + KP707106781 * (Tu - Tz);
    accum_imag[7] = TB + TC - KP707106781 * (Tu - Tz);

    ro[0] = accum_real[0];
    ro[(os[4])] = accum_real[4];
    ro[(os[2])] = accum_real[2];
    ro[(os[6])] = accum_real[6];
    ro[(os[1])] = accum_real[1];
    ro[(os[5])] = accum_real[5];
    ro[(os[3])] = accum_real[3];
    ro[(os[7])] = accum_real[7];

    io[0] = accum_imag[0];
    io[(os[4])] = accum_imag[4];
    io[(os[2])] = accum_imag[2];
    io[(os[6])] = accum_imag[6];
    io[(os[1])] = accum_imag[1];
    io[(os[5])] = accum_imag[5];
    io[(os[3])] = accum_imag[3];
    io[(os[7])] = accum_imag[7];
}
}
