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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    if (i >= 2) {
        E T1a, T4a, Tra, Taa, Tla, Tia, Tfa, Tka, Tja, T2a, T3a, T5a, Tga;
        E T1b, T4b, Trb, Tab, Tlb, Tib, Tfb, Tkb, Tjb, T2b, T3b, T5b, Tgb;

        // First iteration (original index)
        T1a = R0[0];
        T2a = R1[(rs[1])];
        T3a = R0[(rs[3])];
        T4a = T2a + T3a;
        Tra = T3a - T2a;
        {
            E T6a, T7a, T8a, T9a;
            T6a = R1[0];
            T7a = R0[(rs[2])];
            T8a = R1[(rs[3])];
            T9a = T7a + T8a;
            Taa = T6a + T9a;
            Tla = T8a - T7a;
            Tia = ((T6a) - ((KP500000000) * (T9a)));
        }
        {
            E Tb, Tc, Td, Te;
            Tb = R0[(rs[1])];
            Tc = R1[(rs[2])];
            Td = R0[(rs[4])];
            Te = Tc + Td;
            Tfa = Tb + Te;
            Tka = ((Tb) - ((KP500000000) * (Te)));
            Tja = Td - Tc;
        }
        Ci[(csi[3])] = KP866025403 * (Tfa - Taa);
        T5a = T1a + T4a;
        Tga = Taa + Tfa;
        Cr[(csr[3])] = ((T5a) - ((KP500000000) * (Tga)));
        Cr[0] = T5a + Tga;
        {
            E Tt, Th, Tm, Tn, To, Tp, Tq, Ts;
            Tt = KP866025403 * Tra;
            Th = ((T1a) - ((KP500000000) * (T4a)));
            Tm = (((KP766044443) * (Tia)) + (KP556670399 * Tla));
            Tn = (((KP173648177) * (Tka)) + (KP852868531 * Tja));
            To = Tm + Tn;
            Tp = ((KP663413948 * Tla) - ((KP642787609) * (Tia)));
            Tq = ((KP150383733 * Tja) - ((KP984807753) * (Tka)));
            Ts = Tp + Tq;
            Cr[(csr[1])] = Th + To;
            Ci[(csi[1])] = Tt + Ts;
            Cr[(csr[4])] = (((KP866025403) * (Tp - Tq)) + (Th)) - (KP500000000 * To);
            Ci[(csi[4])] = ((KP866025403 * (Tra + (Tn - Tm))) - ((KP500000000) * (Ts)));
            Ci[(csi[2])] = ((KP813797681 * Tja) - ((KP342020143) * (Tka))) + (-(((KP150383733) * (Tla)) + (KP984807753 * Tia))) - Tt;
            Cr[(csr[2])] = (((KP173648177) * (Tia)) + (Th)) + (-(((KP296198132) * (Tja)) + (KP939692620 * Tka))) - (KP852868531 * Tla);
        }

        // Second iteration (offset by ivs/ovs)
        T1b = R0[ivs];
        T2b = R1[ivs + (rs[1])];
        T3b = R0[ivs + (rs[3])];
        T4b = T2b + T3b;
        Trb = T3b - T2b;
        {
            E T6b, T7b, T8b, T9b;
            T6b = R1[ivs];
            T7b = R0[ivs + (rs[2])];
            T8b = R1[ivs + (rs[3])];
            T9b = T7b + T8b;
            Tab = T6b + T9b;
            Tlb = T8b - T7b;
            Tib = ((T6b) - ((KP500000000) * (T9b)));
        }
        {
            E Tb, Tc, Td, Te;
            Tb = R0[ivs + (rs[1])];
            Tc = R1[ivs + (rs[2])];
            Td = R0[ivs + (rs[4])];
            Te = Tc + Td;
            Tfb = Tb + Te;
            Tkb = ((Tb) - ((KP500000000) * (Te)));
            Tjb = Td - Tc;
        }
        Ci[(csi[3]) + ovs] = KP866025403 * (Tfb - Tab);
        T5b = T1b + T4b;
        Tgb = Tab + Tfb;
        Cr[(csr[3]) + ovs] = ((T5b) - ((KP500000000) * (Tgb)));
        Cr[ovs] = T5b + Tgb;
        {
            E Tt, Th, Tm, Tn, To, Tp, Tq, Ts;
            Tt = KP866025403 * Trb;
            Th = ((T1b) - ((KP500000000) * (T4b)));
            Tm = (((KP766044443) * (Tib)) + (KP556670399 * Tlb));
            Tn = (((KP173648177) * (Tkb)) + (KP852868531 * Tjb));
            To = Tm + Tn;
            Tp = ((KP663413948 * Tlb) - ((KP642787609) * (Tib)));
            Tq = ((KP150383733 * Tjb) - ((KP984807753) * (Tkb)));
            Ts = Tp + Tq;
            Cr[(csr[1]) + ovs] = Th + To;
            Ci[(csi[1]) + ovs] = Tt + Ts;
            Cr[(csr[4]) + ovs] = (((KP866025403) * (Tp - Tq)) + (Th)) - (KP500000000 * To);
            Ci[(csi[4]) + ovs] = ((KP866025403 * (Trb + (Tn - Tm))) - ((KP500000000) * (Ts)));
            Ci[(csi[2]) + ovs] = ((KP813797681 * Tjb) - ((KP342020143) * (Tkb))) + (-(((KP150383733) * (Tlb)) + (KP984807753 * Tib))) - Tt;
            Cr[(csr[2]) + ovs] = (((KP173648177) * (Tib)) + (Th)) + (-(((KP296198132) * (Tjb)) + (KP939692620 * Tkb))) - (KP852868531 * Tlb);
        }
    } else {
        E T1, T4, Tr, Ta, Tl, Ti, Tf, Tk, Tj, T2, T3, T5, Tg;
        T1 = R0[0];
        T2 = R1[(rs[1])];
        T3 = R0[(rs[3])];
        T4 = T2 + T3;
        Tr = T3 - T2;
        {
            E T6, T7, T8, T9;
            T6 = R1[0];
            T7 = R0[(rs[2])];
            T8 = R1[(rs[3])];
            T9 = T7 + T8;
            Ta = T6 + T9;
            Tl = T8 - T7;
            Ti = ((T6) - ((KP500000000) * (T9)));
        }
        {
            E Tb, Tc, Td, Te;
            Tb = R0[(rs[1])];
            Tc = R1[(rs[2])];
            Td = R0[(rs[4])];
            Te = Tc + Td;
            Tf = Tb + Te;
            Tk = ((Tb) - ((KP500000000) * (Te)));
            Tj = Td - Tc;
        }
        Ci[(csi[3])] = KP866025403 * (Tf - Ta);
        T5 = T1 + T4;
        Tg = Ta + Tf;
        Cr[(csr[3])] = ((T5) - ((KP500000000) * (Tg)));
        Cr[0] = T5 + Tg;
        {
            E Tt, Th, Tm, Tn, To, Tp, Tq, Ts;
            Tt = KP866025403 * Tr;
            Th = ((T1) - ((KP500000000) * (T4)));
            Tm = (((KP766044443) * (Ti)) + (KP556670399 * Tl));
            Tn = (((KP173648177) * (Tk)) + (KP852868531 * Tj));
            To = Tm + Tn;
            Tp = ((KP663413948 * Tl) - ((KP642787609) * (Ti)));
            Tq = ((KP150383733 * Tj) - ((KP984807753) * (Tk)));
            Ts = Tp + Tq;
            Cr[(csr[1])] = Th + To;
            Ci[(csi[1])] = Tt + Ts;
            Cr[(csr[4])] = (((KP866025403) * (Tp - Tq)) + (Th)) - (KP500000000 * To);
            Ci[(csi[4])] = ((KP866025403 * (Tr + (Tn - Tm))) - ((KP500000000) * (Ts)));
            Ci[(csi[2])] = ((KP813797681 * Tj) - ((KP342020143) * (Tk))) + (-(((KP150383733) * (Tl)) + (KP984807753 * Ti))) - Tt;
            Cr[(csr[2])] = (((KP173648177) * (Ti)) + (Th)) + (-(((KP296198132) * (Tj)) + (KP939692620 * Tk))) - (KP852868531 * Tl);
        }
    }
}
}
