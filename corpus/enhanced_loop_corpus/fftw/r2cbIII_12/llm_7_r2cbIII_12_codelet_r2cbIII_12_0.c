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
extern  E KP1_414213562;
extern  E KP2_000000000;
extern  E KP500000000;
extern  E KP866025403;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i < 1) break;
    E T5a, Twa, Tba, Tea, Txa, Tsa, Taa, TAa, Tga, Tja, Tza, Tpa, Tta, Tua;
    E T5b, Twb, Tbb, Teb, Txb, Tsb, Tab, TAb, Tgb, Tjb, Tzb, Tpb, Ttb, Tub;
    {
        E T1, T2, T3, T4;
        T1 = Cr[(csr[1])];
        T2 = Cr[(csr[5])];
        T3 = Cr[(csr[2])];
        T4 = T2 + T3;
        T5a = T1 + T4;
        Twa = KP866025403 * (T2 - T3);
        Tba = T1 - (KP500000000 * T4);
    }
    {
        E Tq, Tc, Td, Tr;
        Tq = Ci[(csi[1])];
        Tc = Ci[(csi[5])];
        Td = Ci[(csi[2])];
        Tr = Td - Tc;
        Tea = KP866025403 * (Tc + Td);
        Txa = (KP500000000 * Tr) + Tq;
        Tsa = Tq - Tr;
    }
    {
        E T6, T7, T8, T9;
        T6 = Cr[(csr[4])];
        T7 = Cr[0];
        T8 = Cr[(csr[3])];
        T9 = T7 + T8;
        Taa = T6 + T9;
        TAa = KP866025403 * (T7 - T8);
        Tga = T6 - (KP500000000 * T9);
    }
    {
        E To, Th, Ti, Tn;
        To = Ci[(csi[4])];
        Th = Ci[0];
        Ti = Ci[(csi[3])];
        Tn = Ti - Th;
        Tja = KP866025403 * (Th + Ti);
        Tza = (KP500000000 * Tn) + To;
        Tpa = Tn - To;
    }

    R0[0] = KP2_000000000 * (T5a + Taa);
    R0[(rs[3])] = KP2_000000000 * (Tsa + Tpa);
    Tta = Tpa - Tsa;
    Tua = T5a - Taa;
    R1[(rs[1])] = KP1_414213562 * (Tta - Tua);
    R1[(rs[4])] = KP1_414213562 * (Tua + Tta);

    {
        E Tf, Tk, Tv, Ty, TB, TC;
        Tf = Tba - Tea;
        Tk = Tga + Tja;
        Tv = Tf - Tk;
        Ty = Twa + Txa;
        TB = Tza - TAa;
        TC = Ty + TB;
        R0[(rs[2])] = -(KP2_000000000 * (Tf + Tk));
        R0[(rs[5])] = KP2_000000000 * (TB - Ty);
        R1[0] = KP1_414213562 * (Tv - TC);
        R1[(rs[3])] = KP1_414213562 * (Tv + TC);
    }
    {
        E Tl, Tm, TF, TD, TE, TG;
        Tl = Tba + Tea;
        Tm = Tga - Tja;
        TF = Tm - Tl;
        TD = TAa + Tza;
        TE = Txa - Twa;
        TG = TE + TD;
        R0[(rs[4])] = KP2_000000000 * (Tl + Tm);
        R1[(rs[2])] = KP1_414213562 * (TF + TG);
        R0[(rs[1])] = KP2_000000000 * (TD - TE);
        R1[(rs[5])] = KP1_414213562 * (TF - TG);
    }

    if (i == 1) continue;

    {
        E T1, T2, T3, T4;
        T1 = Cr[(csr[1]) + ivs];
        T2 = Cr[(csr[5]) + ivs];
        T3 = Cr[(csr[2]) + ivs];
        T4 = T2 + T3;
        T5b = T1 + T4;
        Twb = KP866025403 * (T2 - T3);
        Tbb = T1 - (KP500000000 * T4);
    }
    {
        E Tq, Tc, Td, Tr;
        Tq = Ci[(csi[1]) + ivs];
        Tc = Ci[(csi[5]) + ivs];
        Td = Ci[(csi[2]) + ivs];
        Tr = Td - Tc;
        Teb = KP866025403 * (Tc + Td);
        Txb = (KP500000000 * Tr) + Tq;
        Tsb = Tq - Tr;
    }
    {
        E T6, T7, T8, T9;
        T6 = Cr[(csr[4]) + ivs];
        T7 = Cr[ivs];
        T8 = Cr[(csr[3]) + ivs];
        T9 = T7 + T8;
        Tab = T6 + T9;
        TAb = KP866025403 * (T7 - T8);
        Tgb = T6 - (KP500000000 * T9);
    }
    {
        E To, Th, Ti, Tn;
        To = Ci[(csi[4]) + ivs];
        Th = Ci[ivs];
        Ti = Ci[(csi[3]) + ivs];
        Tn = Ti - Th;
        Tjb = KP866025403 * (Th + Ti);
        Tzb = (KP500000000 * Tn) + To;
        Tpb = Tn - To;
    }

    R0[ovs] = KP2_000000000 * (T5b + Tab);
    R0[(rs[3]) + ovs] = KP2_000000000 * (Tsb + Tpb);
    Ttb = Tpb - Tsb;
    Tub = T5b - Tab;
    R1[(rs[1]) + ovs] = KP1_414213562 * (Ttb - Tub);
    R1[(rs[4]) + ovs] = KP1_414213562 * (Tub + Ttb);

    {
        E Tf, Tk, Tv, Ty, TB, TC;
        Tf = Tbb - Teb;
        Tk = Tgb + Tjb;
        Tv = Tf - Tk;
        Ty = Twb + Txb;
        TB = Tzb - TAb;
        TC = Ty + TB;
        R0[(rs[2]) + ovs] = -(KP2_000000000 * (Tf + Tk));
        R0[(rs[5]) + ovs] = KP2_000000000 * (TB - Ty);
        R1[ovs] = KP1_414213562 * (Tv - TC);
        R1[(rs[3]) + ovs] = KP1_414213562 * (Tv + TC);
    }
    {
        E Tl, Tm, TF, TD, TE, TG;
        Tl = Tbb + Teb;
        Tm = Tgb - Tjb;
        TF = Tm - Tl;
        TD = TAb + Tzb;
        TE = Txb - Twb;
        TG = TE + TD;
        R0[(rs[4]) + ovs] = KP2_000000000 * (Tl + Tm);
        R1[(rs[2]) + ovs] = KP1_414213562 * (TF + TG);
        R0[(rs[1]) + ovs] = KP2_000000000 * (TD - TE);
        R1[(rs[5]) + ovs] = KP1_414213562 * (TF - TG);
    }
}

}
