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
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T9, T8, Ta, Tb, Td;
    T7 = W[0];
    T9 = W[1];
    T8 = W[2];
    Ta = W[3];
    Tb = (((T7) * (T8)) + (T9 * Ta));
    Td = ((T7 * Ta) - ((T9) * (T8)));
    {
        E T3, Tl, Tg, Tp, T6, To, Tj, Tm, Tc, Tk;
        {
            E T1, T2, Te, Tf;
            T1 = Rp[0];
            T2 = Rm[(rs[1])];
            T3 = T1 + T2;
            Tl = T1 - T2;
            Te = Ip[0];
            Tf = Im[(rs[1])];
            Tg = Te - Tf;
            Tp = Te + Tf;
        }
        {
            E T4, T5, Th, Ti;
            T4 = Rp[(rs[1])];
            T5 = Rm[0];
            T6 = T4 + T5;
            To = T4 - T5;
            Th = Ip[(rs[1])];
            Ti = Im[0];
            Tj = Th - Ti;
            Tm = Th + Ti;
        }
        // Introduce artificial dependence: delay write to Rp[0] until after future reads
        E temp_Rp0 = T3 + T6;
        E temp_Rm0 = Tg + Tj;
        E temp_Rpc1 = ((Tb * (T3 - T6)) - (Td * (Tg - Tj)));
        E temp_Rmc1 = ((Td * (T3 - T6)) + (Tb * (Tg - Tj)));

        // Artificially create a WAW and WAR hazard by reordering and delaying writes
        Ip[0] = ((T7 * (Tl - Tm)) - (T9 * (To + Tp)));
        Im[0] = ((T7 * (To + Tp)) + (T9 * (Tl - Tm)));
        Ip[(rs[1])] = ((T8 * (Tl + Tm)) - (Ta * (Tp - To)));
        Im[(rs[1])] = ((T8 * (Tp - To)) + (Ta * (Tl + Tm)));

        // Now perform delayed writes — creates loop-carried anti-dependence if rs changes
        Rp[0] = temp_Rp0;
        Rm[0] = temp_Rm0;
        Rp[(rs[1])] = temp_Rpc1;
        Rm[(rs[1])] = temp_Rmc1;
    }
}
}
