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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T2, T4, T3, T5, T6, T8;
    E U2, U4, U3, U5, U6, U8;

    T2 = W[0];  T4 = W[1];  T3 = W[2];  T5 = W[3];
    T6 = (((T2) * (T3)) + (T4 * T5));
    T8 = ((T2 * T5) - ((T4) * (T3)));

    U2 = W[4];  U4 = W[5];  U3 = W[6];  U5 = W[7];
    U6 = (((U2) * (U3)) + (U4 * U5));
    U8 = ((U2 * U5) - ((U4) * (U3)));

    {
        E T1, Tp, Ta, To, Te, Tk, Th, Tl, T7, T9;
        E U1, Up, Ua, Uo, Ue, Uk, Uh, Ul, U7, U9;

        T1 = Rp[0];           U1 = Rp[ms];
        Tp = Rm[0];           Up = Rm[0 - ms];
        T7 = Rp[(rs[1])];     U7 = Rp[ms + (rs[1])];
        T9 = Rm[(rs[1])];     U9 = Rm[-ms + (rs[1])];

        Ta = (((T6) * (T7)) + (T8 * T9));
        To = ((T6 * T9) - ((T8) * (T7)));
        Ua = (((U6) * (U7)) + (U8 * U9));
        Uo = ((U6 * U9) - ((U8) * (U7)));

        {
            E Tc, Td, Tf, Tg;
            E Uc, Ud, Uf, Ug;

            Tc = Ip[0];       Uc = Ip[ms];
            Td = Im[0];       Ud = Im[-ms];
            Te = (((T2) * (Tc)) + (T4 * Td));
            Tk = ((T2 * Td) - ((T4) * (Tc)));
            Ue = (((U2) * (Uc)) + (U4 * Ud));
            Uk = ((U2 * Ud) - ((U4) * (Uc)));

            Tf = Ip[(rs[1])];   Uf = Ip[ms + (rs[1])];
            Tg = Im[(rs[1])];   Ug = Im[-ms + (rs[1])];
            Th = (((T3) * (Tf)) + (T5 * Tg));
            Tl = ((T3 * Tg) - ((T5) * (Tf)));
            Uh = (((U3) * (Uf)) + (U5 * Ug));
            Ul = ((U3 * Ug) - ((U5) * (Uf)));
        }

        {
            E Tb, Ti, Tn, Tq;
            E Ub, Ui, Un, Uq;

            Tb = T1 + Ta;       Ub = U1 + Ua;
            Ti = Te + Th;       Ui = Ue + Uh;
            Rm[(rs[1])] = Tb - Ti;
            Rp[0] = Tb + Ti;
            Rm[ms + (rs[1])] = Ub - Ui;
            Rp[ms] = Ub + Ui;

            Tn = Tk + Tl;       Un = Uk + Ul;
            Tq = To + Tp;       Uq = Uo + Up;
            Im[(rs[1])] = Tn - Tq;
            Ip[0] = Tn + Tq;
            Im[ms + (rs[1])] = Un - Uq;
            Ip[ms] = Un + Uq;
        }

        {
            E Tj, Tm, Tr, Ts;
            E Uj, Um, Ur, Us;

            Tj = T1 - Ta;       Uj = U1 - Ua;
            Tm = Tk - Tl;       Um = Uk - Ul;
            Rm[0] = Tj - Tm;
            Rp[(rs[1])] = Tj + Tm;
            Rm[-ms] = Uj - Um;
            Rp[ms + (rs[1])] = Uj + Um;

            Tr = Th - Te;       Ur = Uh - Ue;
            Ts = Tp - To;       Us = Up - Uo;
            Im[0] = Tr - Ts;
            Ip[(rs[1])] = Tr + Ts;
            Im[-ms] = Ur - Us;
            Ip[ms + (rs[1])] = Ur + Us;
        }
    }
}
}
