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
extern  E KP900968867;
extern  E KP222520933;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP974927912;
extern  E KP781831482;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, TB, T6, Tv, Tn, Ts, Tk, Tt, Td, Ty, T9, Tw, Tg, Tz, T1;
    E T2;
    T1 = R0[0];
    T2 = R1[(rs[3])];
    T3 = T1 - T2;
    TB = T1 + T2;
    {
        E T4, T5, Tl, Tm;
        T4 = R0[(rs[2])];
        T5 = R1[(rs[5])];
        T6 = T4 - T5;
        Tv = T4 + T5;
        Tl = R0[(rs[6])];
        Tm = R1[(rs[2])];
        Tn = Tl - Tm;
        Ts = Tl + Tm;
    }
    {
        E Ti, Tj, Tb, Tc;
        Ti = R0[(rs[1])];
        Tj = R1[(rs[4])];
        Tk = Ti - Tj;
        Tt = Ti + Tj;
        Tb = R0[(rs[3])];
        Tc = R1[(rs[6])];
        Td = Tb - Tc;
        Ty = Tb + Tc;
    }
    {
        E T7, T8, Te, Tf;
        T7 = R0[(rs[5])];
        T8 = R1[(rs[1])];
        T9 = T7 - T8;
        Tw = T7 + T8;
        Te = R0[(rs[4])];
        Tf = R1[0];
        Tg = Te - Tf;
        Tz = Te + Tf;
    }
    {
        E Tp, Tr, Tq, Ta, To, Th;
        Tp = Tn - Tk;
        Tr = Tg - Td;
        Tq = T9 - T6;
        // Introduce temporary variables to break direct WAW and WAR dependencies
        E temp1 = ((KP781831482) * (Tp)) + (KP974927912 * Tq);
        E temp2 = ((KP433883739) * (Tq)) + (KP781831482 * Tr);
        E temp3 = ((KP433883739) * (Tp)) + (KP974927912 * Tr);
        Ci[(csi[1])] = temp1 + (KP433883739 * Tr);
        Ci[(csi[5])] = temp2 - (KP974927912 * Tp);
        Ci[(csi[3])] = temp3 - (KP781831482 * Tq);
        Ta = T6 + T9;
        To = Tk + Tn;
        Th = Td + Tg;
        // Reorder computation to reduce dependency chain length
        E partA = (KP623489801) * (Ta);
        E partB = (KP222520933) * (Th);
        E partC = (KP900968867) * (To);
        Cr[(csr[3])] = partA + T3 - (partB + partC);
        Cr[(csr[7])] = T3 + To + Ta + Th;
        Cr[(csr[1])] = (KP623489801) * (To) + T3 - ((KP900968867) * (Th) + (KP222520933) * (Ta));
        Cr[(csr[5])] = (KP623489801) * (Th) + T3 - ((KP900968867) * (Ta) + (KP222520933) * (To));
    }
    {
        E Tu, TA, Tx, TC, TE, TD;
        Tu = Ts - Tt;
        TA = Ty - Tz;
        Tx = Tv - Tw;
        // Modify write order and use temporaries to alter data flow
        E c2_val = ((KP974927912) * (Tu)) + (KP433883739 * Tx) + (KP781831482 * TA);
        E c6_val = ((KP974927912) * (Tx)) + (KP433883739 * TA) - (KP781831482 * Tu);
        E c4_val = (KP974927912 * TA) - (KP781831482 * Tx) - (KP433883739 * Tu);
        Ci[(csi[2])] = c2_val;
        Ci[(csi[6])] = c6_val;
        Ci[(csi[4])] = c4_val;
        TC = Tt + Ts;
        TE = Tv + Tw;
        TD = Ty + Tz;
        // Break long expression into parts to expose more ILP
        E cr6_part = (KP623489801) * (TC);
        E cr6_corr = (KP900968867) * (TD) + (KP222520933) * (TE);
        Cr[(csr[6])] = cr6_part + TB - cr6_corr;
        Cr[(csr[2])] = (KP623489801) * (TD) + TB - ((KP900968867) * (TE) + (KP222520933) * (TC));
        Cr[(csr[4])] = (KP623489801) * (TE) + TB - ((KP222520933) * (TD) + (KP900968867) * (TC));
        Cr[0] = TB + TC + TE + TD;
    }
}
}
