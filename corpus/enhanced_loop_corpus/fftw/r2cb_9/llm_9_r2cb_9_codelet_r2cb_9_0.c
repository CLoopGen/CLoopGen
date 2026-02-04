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
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i >= 1) {
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
    if (i >= 2) {
        E T3b, Tqb, Tcb, Tkb, Tjb, T8b, Tmb, Tsb, Thb, Trb, Twb, Txb;
        {
            E Tbb, T1b, T2b, T9b, Tab;
            Tab = Ci[(csi[3]) + ivs];
            Tbb = KP1_732050807 * Tab;
            T1b = Cr[ivs];
            T2b = Cr[(csr[3]) + ivs];
            T9b = T1b - T2b;
            T3b = (((KP2_000000000) * (T2b)) + (T1b));
            Tqb = T9b + Tbb;
            Tcb = T9b - Tbb;
        }
        {
            E T4b, T7b, Tib, Tgb, Tlb, Tdb;
            T4b = Cr[(csr[1]) + ivs];
            Tkb = Ci[(csi[1]) + ivs];
            {
                E T5b, T6b, Teb, Tfb;
                T5b = Cr[(csr[4]) + ivs];
                T6b = Cr[(csr[2]) + ivs];
                T7b = T5b + T6b;
                Tib = KP866025403 * (T5b - T6b);
                Teb = Ci[(csi[4]) + ivs];
                Tfb = Ci[(csi[2]) + ivs];
                Tgb = KP866025403 * (Teb + Tfb);
                Tjb = Tfb - Teb;
            }
            T8b = T4b + T7b;
            Tlb = (((KP500000000) * (Tjb)) + (Tkb));
            Tmb = Tib + Tlb;
            Tsb = Tlb - Tib;
            Tdb = ((T4b) - ((KP500000000) * (T7b)));
            Thb = Tdb - Tgb;
            Trb = Tdb + Tgb;
        }
        R0[ovs] = (((KP2_000000000) * (T8b)) + (T3b));
        Twb = T3b - T8b;
        Txb = KP1_732050807 * (Tkb - Tjb);
        R1[(rs[1]) + ovs] = Twb - Txb;
        R0[(rs[3]) + ovs] = Twb + Txb;
        {
            E Tpb, Tnb, Tob, Tvb, Ttb, Tub;
            Tpb = (((KP1_113340798) * (Thb)) + (KP1_326827896 * Tmb));
            Tnb = ((KP766044443 * Thb) - ((KP642787609) * (Tmb)));
            Tob = Tcb - Tnb;
            R1[ovs] = (((KP2_000000000) * (Tnb)) + (Tcb));
            R1[(rs[3]) + ovs] = Tob + Tpb;
            R0[(rs[2]) + ovs] = Tob - Tpb;
            Tvb = (((KP1_705737063) * (Trb)) + (KP300767466 * Tsb));
            Ttb = ((KP173648177 * Trb) - ((KP984807753) * (Tsb)));
            Tub = Tqb - Ttb;
            R0[(rs[1]) + ovs] = (((KP2_000000000) * (Ttb)) + (Tqb));
            R0[(rs[4]) + ovs] = Tub + Tvb;
            R1[(rs[2]) + ovs] = Tub - Tvb;
        }
    }
}
}
