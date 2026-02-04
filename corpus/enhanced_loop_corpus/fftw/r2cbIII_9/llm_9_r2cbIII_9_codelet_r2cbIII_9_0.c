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
extern  E KP642787609;
extern  E KP766044443;
extern  E KP1_326827896;
extern  E KP1_113340798;
extern  E KP984807753;
extern  E KP173648177;
extern  E KP1_705737063;
extern  E KP300767466;
extern  E KP500000000;
extern  E KP866025403;
extern  E KP2_000000000;
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v / 4; i > 0; i = i - 1 , R0 = R0 + (4 * ovs) , R1 = R1 + (4 * ovs) , Cr = Cr + (4 * ivs) , Ci = Ci + (4 * ivs) , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    INT j;
    for (j = 0; j < 4; ++j) {
        E T3, Ts, Ti, Td, Tc, T8, To, Tu, Tl, Tt, T9, Te;
        {
            E Th, T1, T2, Tf, Tg;
            Tg = Ci[(csi[1]) + j * ivs];
            Th = KP1_732050807 * Tg;
            T1 = Cr[(csr[4]) + j * ivs];
            T2 = Cr[(csr[1]) + j * ivs];
            Tf = T2 - T1;
            T3 = (((KP2_000000000) * (T2)) + (T1));
            Ts = Tf - Th;
            Ti = Tf + Th;
        }
        {
            E T4, T7, Tm, Tk, Tn, Tj;
            T4 = Cr[(csr[3]) + j * ivs];
            Td = Ci[(csi[3]) + j * ivs];
            {
                E T5, T6, Ta, Tb;
                T5 = Cr[0 + j * ivs];
                T6 = Cr[(csr[2]) + j * ivs];
                T7 = T5 + T6;
                Tm = KP866025403 * (T6 - T5);
                Ta = Ci[(csi[2]) + j * ivs];
                Tb = Ci[0 + j * ivs];
                Tc = Ta - Tb;
                Tk = KP866025403 * (Tb + Ta);
            }
            T8 = T4 + T7;
            Tn = (((KP500000000) * (Tc)) + (Td));
            To = Tm - Tn;
            Tu = Tm + Tn;
            Tj = (((KP500000000) * (T7)) - (T4));
            Tl = Tj + Tk;
            Tt = Tj - Tk;
        }
        R0[j * ovs] = (((KP2_000000000) * (T8)) + (T3));
        T9 = T8 - T3;
        Te = KP1_732050807 * (Tc - Td);
        R1[(rs[1]) + j * ovs] = T9 + Te;
        R0[(rs[3]) + j * ovs] = Te - T9;
        {
            E Tr, Tp, Tq, Tx, Tv, Tw;
            Tr = ((KP300767466 * To) - ((KP1_705737063) * (Tl)));
            Tp = (((KP173648177) * (Tl)) + (KP984807753 * To));
            Tq = Ti - Tp;
            R0[(rs[1]) + j * ovs] = -((((KP2_000000000) * (Tp)) + (Ti)));
            R0[(rs[4]) + j * ovs] = Tr - Tq;
            R1[(rs[2]) + j * ovs] = Tq + Tr;
            Tx = (((KP1_113340798) * (Tt)) + (KP1_326827896 * Tu));
            Tv = ((KP766044443 * Tt) - ((KP642787609) * (Tu)));
            Tw = Tv - Ts;
            R1[j * ovs] = (((KP2_000000000) * (Tv)) + (Ts));
            R1[(rs[3]) + j * ovs] = Tx - Tw;
            R0[(rs[2]) + j * ovs] = Tw + Tx;
        }
    }
}
}
