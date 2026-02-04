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
for (i = v; i > 0; i = i - 2 , R0 = R0 + (2 * ovs) , R1 = R1 + (2 * ovs) , Cr = Cr + (2 * ivs) , Ci = Ci + (2 * ivs) , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    if (i >= 2) {
        E T3, Ts, Ti, Td, Tc, T8, To, Tu, Tl, Tt, T9, Te;
        E T3b, Tsb, Tib, Tdb, Tcb, T8b, Tob, Tub, Tlb, Ttb, T9b, Teb;

        // First iteration (original logic)
        {
            E Th, T1, T2, Tf, Tg;
            Tg = Ci[(csi[1])];
            Th = KP1_732050807 * Tg;
            T1 = Cr[(csr[4])];
            T2 = Cr[(csr[1])];
            Tf = T2 - T1;
            T3 = (((KP2_000000000) * (T2)) + (T1));
            Ts = Tf - Th;
            Ti = Tf + Th;
        }
        {
            E T4, T7, Tm, Tk, Tn, Tj;
            T4 = Cr[(csr[3])];
            Td = Ci[(csi[3])];
            {
                E T5, T6, Ta, Tb;
                T5 = Cr[0];
                T6 = Cr[(csr[2])];
                T7 = T5 + T6;
                Tm = KP866025403 * (T6 - T5);
                Ta = Ci[(csi[2])];
                Tb = Ci[0];
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
        R0[0] = (((KP2_000000000) * (T8)) + (T3));
        T9 = T8 - T3;
        Te = KP1_732050807 * (Tc - Td);
        R1[(rs[1])] = T9 + Te;
        R0[(rs[3])] = Te - T9;
        {
            E Tr, Tp, Tq, Tx, Tv, Tw;
            Tr = ((KP300767466 * To) - ((KP1_705737063) * (Tl)));
            Tp = (((KP173648177) * (Tl)) + (KP984807753 * To));
            Tq = Ti - Tp;
            R0[(rs[1])] = -((((KP2_000000000) * (Tp)) + (Ti)));
            R0[(rs[4])] = Tr - Tq;
            R1[(rs[2])] = Tq + Tr;
            Tx = (((KP1_113340798) * (Tt)) + (KP1_326827896 * Tu));
            Tv = ((KP766044443 * Tt) - ((KP642787609) * (Tu)));
            Tw = Tv - Ts;
            R1[0] = (((KP2_000000000) * (Tv)) + (Ts));
            R1[(rs[3])] = Tx - Tw;
            R0[(rs[2])] = Tw + Tx;
        }

        // Second iteration (shifted by one index in vectorized fashion)
        {
            E Th, T1, T2, Tf, Tg;
            Tg = Ci[(csi[1]) + ivs];
            Th = KP1_732050807 * Tg;
            T1 = Cr[(csr[4]) + ivs];
            T2 = Cr[(csr[1]) + ivs];
            Tf = T2 - T1;
            T3b = (((KP2_000000000) * (T2)) + (T1));
            Tsb = Tf - Th;
            Tib = Tf + Th;
        }
        {
            E T4, T7, Tm, Tk, Tn, Tj;
            T4 = Cr[(csr[3]) + ivs];
            Tdb = Ci[(csi[3]) + ivs];
            {
                E T5, T6, Ta, Tb;
                T5 = Cr[0 + ivs];
                T6 = Cr[(csr[2]) + ivs];
                T7 = T5 + T6;
                Tm = KP866025403 * (T6 - T5);
                Ta = Ci[(csi[2]) + ivs];
                Tb = Ci[0 + ivs];
                Tcb = Ta - Tb;
                Tk = KP866025403 * (Tb + Ta);
            }
            T8b = T4 + T7;
            Tn = (((KP500000000) * (Tcb)) + (Tdb));
            Tob = Tm - Tn;
            Tub = Tm + Tn;
            Tj = (((KP500000000) * (T7)) - (T4));
            Tlb = Tj + Tk;
            Ttb = Tj - Tk;
        }
        R0[ovs] = (((KP2_000000000) * (T8b)) + (T3b));
        T9b = T8b - T3b;
        Teb = KP1_732050807 * (Tcb - Tdb);
        R1[(rs[1]) + ovs] = T9b + Teb;
        R0[(rs[3]) + ovs] = Teb - T9b;
        {
            E Tr, Tp, Tq, Tx, Tv, Tw;
            Tr = ((KP300767466 * Tob) - ((KP1_705737063) * (Tlb)));
            Tp = (((KP173648177) * (Tlb)) + (KP984807753 * Tob));
            Tq = Tib - Tp;
            R0[(rs[1]) + ovs] = -((((KP2_000000000) * (Tp)) + (Tib)));
            R0[(rs[4]) + ovs] = Tr - Tq;
            R1[(rs[2]) + ovs] = Tq + Tr;
            Tx = (((KP1_113340798) * (Ttb)) + (KP1_326827896 * Tub));
            Tv = ((KP766044443 * Ttb) - ((KP642787609) * (Tub)));
            Tw = Tv - Tsb;
            R1[ovs] = (((KP2_000000000) * (Tv)) + (Tsb));
            R1[(rs[3]) + ovs] = Tx - Tw;
            R0[(rs[2]) + ovs] = Tw + Tx;
        }
    }
}
}
