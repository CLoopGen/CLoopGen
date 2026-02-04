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
// Reduced trip count by factor of 2 and unrolled loop body with stride adjustment
for (m = mb; m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 12 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break; // Ensure safe unrolling

    E T3a, Tia, Tca, Tna, T6a, Tma, Tfa, Tja;
    E T3b, Tib, Tcb, Tnb, T6b, Tmb, Tfb, Tjb;

    // First iteration (m)
    {
        E T1, T2, Ta, Tb;
        T1 = Rp[0];
        T2 = Rm[(rs[1])];
        T3a = T1 + T2;
        Tia = T1 - T2;
        Ta = Ip[0];
        Tb = Im[(rs[1])];
        Tca = Ta - Tb;
        Tna = Ta + Tb;
    }
    {
        E T4, T5, Td, Te;
        T4 = Rp[(rs[1])];
        T5 = Rm[0];
        T6a = T4 + T5;
        Tma = T4 - T5;
        Td = Ip[(rs[1])];
        Te = Im[0];
        Tfa = Td - Te;
        Tja = Td + Te;
    }

    // Second iteration (m+1), offset by ms
    {
        E T1, T2, Ta, Tb;
        T1 = Rp[ms];
        T2 = Rm[(rs[1]) - ms];
        T3b = T1 + T2;
        Tib = T1 - T2;
        Ta = Ip[ms];
        Tb = Im[(rs[1]) - ms];
        Tcb = Ta - Tb;
        Tnb = Ta + Tb;
    }
    {
        E T4, T5, Td, Te;
        T4 = Rp[(rs[1]) + ms];
        T5 = Rm[ms];
        T6b = T4 + T5;
        Tmb = T4 - T5;
        Td = Ip[(rs[1]) + ms];
        Te = Im[ms];
        Tfb = Td - Te;
        Tjb = Td + Te;
    }

    // Update first iteration results
    Rp[0] = T3a + T6a;
    Rm[0] = Tca + Tfa;
    {
        E T8, Tg, T7, T9;
        T8 = T3a - T6a;
        Tg = Tca - Tfa;
        T7 = W[2];
        T9 = W[3];
        Rp[(rs[1])] = ((T7 * T8) - (T9 * Tg));
        Rm[(rs[1])] = ((T9 * T8) + (T7 * Tg));
    }
    {
        E Tk, To, Th, Tl;
        Tk = Tia - Tja;
        To = Tma + Tna;
        Th = W[0];
        Tl = W[1];
        Ip[0] = (Th * Tk) - (Tl * To);
        Im[0] = (Th * To) + (Tl * Tk);
    }
    {
        E Tq, Ts, Tp, Tr;
        Tq = Tia + Tja;
        Ts = Tna - Tma;
        Tp = W[4];
        Tr = W[5];
        Ip[(rs[1])] = (Tp * Tq) - (Tr * Ts);
        Im[(rs[1])] = (Tp * Ts) + (Tr * Tq);
    }

    // Update second iteration results
    Rp[ms] = T3b + T6b;
    Rm[ms] = Tcb + Tfb;
    {
        E T8, Tg, T7, T9;
        T8 = T3b - T6b;
        Tg = Tcb - Tfb;
        T7 = W[8];  // Offset in W for second stage
        T9 = W[9];
        Rp[(rs[1]) + ms] = (T7 * T8) - (T9 * Tg);
        Rm[(rs[1]) - ms] = (T9 * T8) + (T7 * Tg);
    }
    {
        E Tk, To, Th, Tl;
        Tk = Tib - Tjb;
        To = Tmb + Tnb;
        Th = W[6];
        Tl = W[7];
        Ip[ms] = (Th * Tk) - (Tl * To);
        Im[ms] = (Th * To) + (Tl * Tk);
    }
    {
        E Tq, Ts, Tp, Tr;
        Tq = Tib + Tjb;
        Ts = Tnb - Tmb;
        Tp = W[10];
        Tr = W[11];
        Ip[(rs[1]) + ms] = (Tp * Tq) - (Tr * Ts);
        Im[(rs[1]) - ms] = (Tp * Ts) + (Tr * Tq);
    }
}
}
