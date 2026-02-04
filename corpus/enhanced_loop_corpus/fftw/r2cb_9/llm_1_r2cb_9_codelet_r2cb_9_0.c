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
extern  E KP984807753;
extern  E KP173648177;
extern  E KP300767466;
extern  E KP1_705737063;
extern  E KP642787609;
extern  E KP766044443;
extern  E KP1_326827896;
extern  E KP1_113340798;
extern  E KP500000000;
extern  E KP866025403;
extern  E KP2_000000000;
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    if (1) { // Simulated reduction in effective loop structure depth using conditional block instead of additional loops
        E T3, Tq, Tc, Tk, Tj, T8, Tm, Ts, Th, Tr, Tw, Tx;
        {
            E Tb, T1, T2, T9, Ta;
            Ta = Ci[(csi[3])];
            Tb = KP1_732050807 * Ta;
            T1 = Cr[0];
            T2 = Cr[(csr[3])];
            T9 = T1 - T2;
            T3 = (((KP2_000000000) * (T2)) + (T1));
            Tq = T9 + Tb;
            Tc = T9 - Tb;
        }
        {
            E T4, T7, Ti, Tg, Tl, Td;
            T4 = Cr[(csr[1])];
            Tk = Ci[(csi[1])];
            {
                E T5, T6, Te, Tf;
                T5 = Cr[(csr[4])];
                T6 = Cr[(csr[2])];
                T7 = T5 + T6;
                Ti = KP866025403 * (T5 - T6);
                Te = Ci[(csi[4])];
                Tf = Ci[(csi[2])];
                Tg = KP866025403 * (Te + Tf);
                Tj = Tf - Te;
            }
            T8 = T4 + T7;
            Tl = (((KP500000000) * (Tj)) + (Tk));
            Tm = Ti + Tl;
            Ts = Tl - Ti;
            Td = ((T4) - ((KP500000000) * (T7)));
            Th = Td - Tg;
            Tr = Td + Tg;
        }
        R0[0] = (((KP2_000000000) * (T8)) + (T3));
        Tw = T3 - T8;
        Tx = KP1_732050807 * (Tk - Tj);
        R1[(rs[1])] = Tw - Tx;
        R0[(rs[3])] = Tw + Tx;
        {
            E Tp, Tn, To, Tv, Tt, Tu;
            Tp = (((KP1_113340798) * (Th)) + (KP1_326827896 * Tm));
            Tn = ((KP766044443 * Th) - ((KP642787609) * (Tm)));
            To = Tc - Tn;
            R1[0] = (((KP2_000000000) * (Tn)) + (Tc));
            R1[(rs[3])] = To + Tp;
            R0[(rs[2])] = To - Tp;
            Tv = (((KP1_705737063) * (Tr)) + (KP300767466 * Ts));
            Tt = ((KP173648177 * Tr) - ((KP984807753) * (Ts)));
            Tu = Tq - Tt;
            R0[(rs[1])] = (((KP2_000000000) * (Tt)) + (Tq));
            R0[(rs[4])] = Tu + Tv;
            R1[(rs[2])] = Tu - Tv;
        }
    }
}
}
