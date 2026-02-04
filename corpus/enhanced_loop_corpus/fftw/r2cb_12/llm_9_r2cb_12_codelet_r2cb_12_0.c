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
extern  E KP1_732050807;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j;
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ovs , R1 = R1 + 2*ovs , Cr = Cr + 2*ivs , Ci = Ci + 2*ivs , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + 2*fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i >= 1) {
        E T8, Tb, Tm, TA, Tw, Tx, Tp, TB, T3, Tr, Tg, T6, Ts, Tk;
        {
            E T9, Ta, Tn, To;
            T8 = Cr[(csr[3])];
            T9 = Cr[(csr[5])];
            Ta = Cr[(csr[1])];
            Tb = T9 + Ta;
            Tm = (((KP2_000000000) * (T8)) - (Tb));
            TA = KP1_732050807 * (T9 - Ta);
            Tw = Ci[(csi[3])];
            Tn = Ci[(csi[5])];
            To = Ci[(csi[1])];
            Tx = Tn + To;
            Tp = KP1_732050807 * (Tn - To);
            TB = (((KP2_000000000) * (Tw)) + (Tx));
        }
        {
            E Tf, T1, T2, Td, Te;
            Te = Ci[(csi[4])];
            Tf = KP1_732050807 * Te;
            T1 = Cr[0];
            T2 = Cr[(csr[4])];
            Td = T1 - T2;
            T3 = (((KP2_000000000) * (T2)) + (T1));
            Tr = Td - Tf;
            Tg = Td + Tf;
        }
        {
            E Tj, T4, T5, Th, Ti;
            Ti = Ci[(csi[2])];
            Tj = KP1_732050807 * Ti;
            T4 = Cr[(csr[6])];
            T5 = Cr[(csr[2])];
            Th = T4 - T5;
            T6 = (((KP2_000000000) * (T5)) + (T4));
            Ts = Th + Tj;
            Tk = Th - Tj;
        }
        {
            E T7, Tc, Tz, TC;
            T7 = T3 + T6;
            Tc = KP2_000000000 * (T8 + Tb);
            R0[(rs[3])] = T7 - Tc;
            R0[0] = T7 + Tc;
            {
                E Tl, Tq, TD, TE;
                Tl = Tg + Tk;
                Tq = Tm - Tp;
                R0[(rs[1])] = Tl - Tq;
                R0[(rs[4])] = Tl + Tq;
                TD = Tg - Tk;
                TE = TB - TA;
                R1[(rs[2])] = TD - TE;
                R1[(rs[5])] = TD + TE;
            }
            Tz = Tr - Ts;
            TC = TA + TB;
            R1[0] = Tz - TC;
            R1[(rs[3])] = Tz + TC;
            {
                E Tv, Ty, Tt, Tu;
                Tv = T3 - T6;
                Ty = KP2_000000000 * (Tw - Tx);
                R1[(rs[4])] = Tv - Ty;
                R1[(rs[1])] = Tv + Ty;
                Tt = Tr + Ts;
                Tu = Tm + Tp;
                R0[(rs[5])] = Tt - Tu;
                R0[(rs[2])] = Tt + Tu;
            }
        }
    }
    if (i >= 2) {
        E T8b, Tbb, Tmb, TAb, Twb, Txb, Tpb, TBb, T3b, Trb, Tgb, T6b, Tsb, Tkb;
        {
            E T9b, Tab, Tnb, Tob;
            T8b = Cr[(csr[3])+ivs];
            T9b = Cr[(csr[5])+ivs];
            Tab = Cr[(csr[1])+ivs];
            Tbb = T9b + Tab;
            Tmb = (((KP2_000000000) * (T8b)) - (Tbb));
            TAb = KP1_732050807 * (T9b - Tab);
            Twb = Ci[(csi[3])+ivs];
            Tnb = Ci[(csi[5])+ivs];
            Tob = Ci[(csi[1])+ivs];
            Txb = Tnb + Tob;
            Tpb = KP1_732050807 * (Tnb - Tob);
            TBb = (((KP2_000000000) * (Twb)) + (Txb));
        }
        {
            E Tfb, T1b, T2b, Tdb, Teb;
            Teb = Ci[(csi[4])+ivs];
            Tfb = KP1_732050807 * Teb;
            T1b = Cr[ivs];
            T2b = Cr[(csr[4])+ivs];
            Tdb = T1b - T2b;
            T3b = (((KP2_000000000) * (T2b)) + (T1b));
            Trb = Tdb - Tfb;
            Tgb = Tdb + Tfb;
        }
        {
            E Tjb, T4b, T5b, Thb, Tib;
            Tib = Ci[(csi[2])+ivs];
            Tjb = KP1_732050807 * Tib;
            T4b = Cr[(csr[6])+ivs];
            T5b = Cr[(csr[2])+ivs];
            Thb = T4b - T5b;
            T6b = (((KP2_000000000) * (T5b)) + (T4b));
            Tsb = Thb + Tjb;
            Tkb = Thb - Tjb;
        }
        {
            E T7b, Tcb, Tzb, TCb;
            T7b = T3b + T6b;
            Tcb = KP2_000000000 * (T8b + Tbb);
            R0[(rs[3])+ovs] = T7b - Tcb;
            R0[ovs] = T7b + Tcb;
            {
                E Tlb, Tqb, TDb, TEb;
                Tlb = Tgb + Tkb;
                Tqb = Tmb - Tpb;
                R0[(rs[1])+ovs] = Tlb - Tqb;
                R0[(rs[4])+ovs] = Tlb + Tqb;
                TDb = Tgb - Tkb;
                TEb = TBb - TAb;
                R1[(rs[2])+ovs] = TDb - TEb;
                R1[(rs[5])+ovs] = TDb + TEb;
            }
            Tzb = Trb - Tsb;
            TCb = TAb + TBb;
            R1[ovs] = Tzb - TCb;
            R1[(rs[3])+ovs] = Tzb + TCb;
            {
                E Tvb, Tyb, Ttb, Tub;
                Tvb = T3b - T6b;
                Tyb = KP2_000000000 * (Twb - Txb);
                R1[(rs[4])+ovs] = Tvb - Tyb;
                R1[(rs[1])+ovs] = Tvb + Tyb;
                Ttb = Trb + Tsb;
                Tub = Tmb + Tpb;
                R0[(rs[5])+ovs] = Ttb - Tub;
                R0[(rs[2])+ovs] = Ttb + Tub;
            }
        }
    }
}
}
