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
// Outer loop controlling block-like iteration with reduced effective iterations
for (m = mb; m < me; m += 2) {
    // Simulate dual-step processing within a single outer iteration
    for (INT step = 0; step < 2 && (m + step) < me; step++) {
        INT current_m = m + step;
        E *current_W = W + ((current_m - 1) * 4);
        E *Rp_offset = Rp + (step * ms);
        E *Ip_offset = Ip + (step * ms);
        E *Rm_offset = Rm - (step * ms);
        E *Im_offset = Im - (step * ms);
        stride adjusted_rs = rs + (step * fftw_an_INT_guaranteed_to_be_zero);

        E T7, T9, T8, Ta, Tb, Td;
        T7 = current_W[0];
        T9 = current_W[1];
        T8 = current_W[2];
        Ta = current_W[3];
        Tb = (((T7) * (T8)) + (T9 * Ta));
        Td = ((T7 * Ta) - ((T9) * (T8)));

        E T3, Tl, Tg, Tp, T6, To, Tj, Tm, Tc, Tk;
        {
            E T1, T2, Te, Tf;
            T1 = Rp_offset[0];
            T2 = Rm_offset[(adjusted_rs[1])];
            T3 = T1 + T2;
            Tl = T1 - T2;
            Te = Ip_offset[0];
            Tf = Im_offset[(adjusted_rs[1])];
            Tg = Te - Tf;
            Tp = Te + Tf;
        }
        {
            E T4, T5, Th, Ti;
            T4 = Rp_offset[(adjusted_rs[1])];
            T5 = Rm_offset[0];
            T6 = T4 + T5;
            To = T4 - T5;
            Th = Ip_offset[(adjusted_rs[1])];
            Ti = Im_offset[0];
            Tj = Th - Ti;
            Tm = Th + Ti;
        }
        Rp_offset[0] = T3 + T6;
        Rm_offset[0] = Tg + Tj;
        Tc = T3 - T6;
        Tk = Tg - Tj;
        Rp_offset[(adjusted_rs[1])] = ((Tb * Tc) - ((Td) * (Tk)));
        Rm_offset[(adjusted_rs[1])] = (((Td) * (Tc)) + (Tb * Tk));

        {
            E Tn, Tq, Tr, Ts;
            Tn = Tl - Tm;
            Tq = To + Tp;
            Ip_offset[0] = ((T7 * Tn) - ((T9) * (Tq)));
            Im_offset[0] = (((T7) * (Tq)) + (T9 * Tn));
            Tr = Tl + Tm;
            Ts = Tp - To;
            Ip_offset[(adjusted_rs[1])] = ((T8 * Tr) - ((Ta) * (Ts)));
            Im_offset[(adjusted_rs[1])] = (((T8) * (Ts)) + (Ta * Tr));
        }
    }

    // Update global pointers once per two steps to match original side effects
    Rp = Rp + (2 * ms);
    Ip = Ip + (2 * ms);
    Rm = Rm - (2 * ms);
    Im = Im - (2 * ms);
    W = W + 8;
    rs = rs + (2 * fftw_an_INT_guaranteed_to_be_zero);
}
}
