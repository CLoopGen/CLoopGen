#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP939692620;
extern  E KP296198132;
extern  E KP342020143;
extern  E KP813797681;
extern  E KP984807753;
extern  E KP150383733;
extern  E KP642787609;
extern  E KP663413948;
extern  E KP852868531;
extern  E KP173648177;
extern  E KP556670399;
extern  E KP766044443;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T3, T4, Tr, Ta, Tl, Ti, Tf, Tk, Tj, T5, Tg;
    T1 = R0[0];
    T2 = R1[(rs[1])];
    T3 = R0[(rs[3])];
    T4 = T2 + T3;
    Tr = T3 - T2;

    E T6 = R1[0];
    E T7 = R0[(rs[2])];
    E T8 = R1[(rs[3])];
    E T9 = T7 + T8;
    Ta = T6 + T9;
    Tl = T8 - T7;
    Ti = T6 - KP500000000 * T9;

    E Tb = R0[(rs[1])];
    E Tc = R1[(rs[2])];
    E Td = R0[(rs[4])];
    E Te = Tc + Td;
    Tf = Tb + Te;
    Tk = Tb - KP500000000 * Te;
    Tj = Td - Tc;

    T5 = T1 + T4;
    Tg = Ta + Tf;

    Cr[0] = T5 + Tg;
    Cr[(csr[3])] = T5 - KP500000000 * Tg;
    Ci[(csi[3])] = KP866025403 * (Tf - Ta);

    E Tt = KP866025403 * Tr;
    E Th = T1 - KP500000000 * T4;
    E Tm = KP766044443 * Ti + KP556670399 * Tl;
    E Tn = KP173648177 * Tk + KP852868531 * Tj;
    E To = Tm + Tn;
    E Tp = KP663413948 * Tl - KP642787609 * Ti;
    E Tq = KP150383733 * Tj - KP984807753 * Tk;
    E Ts = Tp + Tq;

    Cr[(csr[1])] = Th + To;
    Ci[(csi[1])] = Tt + Ts;
    Cr[(csr[4])] = KP866025403 * (Tp - Tq) + Th - KP500000000 * To;
    Ci[(csi[4])] = KP866025403 * (Tr + Tn - Tm) - KP500000000 * Ts;
    Ci[(csi[2])] = KP813797681 * Tj - KP342020143 * Tk - (KP150383733 * Tl + KP984807753 * Ti) - Tt;
    Cr[(csr[2])] = KP173648177 * Ti + Th - (KP296198132 * Tj + KP939692620 * Tk) - KP852868531 * Tl;
}
}
