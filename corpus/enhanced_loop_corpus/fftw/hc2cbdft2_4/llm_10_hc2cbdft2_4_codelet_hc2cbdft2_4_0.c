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
for (m = mb; m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 6) {
    E T3, Tl, T6, Tm;
    E T1 = Rp[0];
    E T2 = Rm[(rs[1])];
    T3 = T1 + T2;
    E Tf = T1 - T2;
    E Ta = Ip[0];
    E Tb = Im[(rs[1])];
    E Tc = Ta + Tb;
    Tl = Ta - Tb;

    E T4 = Rp[(rs[1])];
    E T5 = Rm[0];
    T6 = T4 + T5;
    E T9 = T4 - T5;
    E Tg = Ip[(rs[1])];
    E Th = Im[0];
    E Ti = Tg + Th;
    Tm = Tg - Th;

    E T7 = T3 + T6;
    E Tn = Tl + Tm;
    E T8 = W[0];
    E Te = W[1];
    E Tk = T8 * (T9 + Tc) + Te * (Tf - Ti);
    E To = T8 * (Tf - Ti) - Te * (T9 + Tc);

    Rp[0] = T7 - Tk;
    Ip[0] = Tn + To;
    Rm[0] = T7 + Tk;
    Im[0] = To - Tn;

    E Tp = W[2], Tr = W[3];
    E Tt = Tp * (T3 - T6) - Tr * (Tl - Tm);
    E Tz = Tr * (T3 - T6) + Tp * (Tl - Tm);

    E Tu = W[4], Tw = W[5];
    E Ty = Tu * (Tc - T9) + Tw * (Tf + Ti);
    E TA = Tu * (Tf + Ti) - Tw * (Tc - T9);

    Rp[(rs[1])] = Tt - Ty;
    Ip[(rs[1])] = Tz + TA;
    Rm[(rs[1])] = Tt + Ty;
    Im[(rs[1])] = TA - Tz;
}

}
