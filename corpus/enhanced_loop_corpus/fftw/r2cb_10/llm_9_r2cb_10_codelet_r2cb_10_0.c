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
extern  E KP500000000;
extern  E KP1_902113032;
extern  E KP1_175570504;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + (2 * ovs) , R1 = R1 + (2 * ovs) , Cr = Cr + (2 * ivs) , Ci = Ci + (2 * ivs) , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero) , (csr) = (csr) + (2 * fftw_an_INT_guaranteed_to_be_zero) , (csi) = (csi) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (i >= 1) {
        E T3, Tb, Tn, Tv, Tk, Tu, Ta, Ts, Te, Tg, Ti, Tj;
        {
            E T1, T2, Tl, Tm;
            T1 = Cr[0];
            T2 = Cr[(csr[5])];
            T3 = T1 - T2;
            Tb = T1 + T2;
            Tl = Ci[(csi[4])];
            Tm = Ci[(csi[1])];
            Tn = Tl - Tm;
            Tv = Tl + Tm;
        }
        Ti = Ci[(csi[2])];
        Tj = Ci[(csi[3])];
        Tk = Ti - Tj;
        Tu = Ti + Tj;
        {
            E T6, Tc, T9, Td;
            {
                E T4, T5, T7, T8;
                T4 = Cr[(csr[2])];
                T5 = Cr[(csr[3])];
                T6 = T4 - T5;
                Tc = T4 + T5;
                T7 = Cr[(csr[4])];
                T8 = Cr[(csr[1])];
                T9 = T7 - T8;
                Td = T7 + T8;
            }
            Ta = T6 + T9;
            Ts = KP1_118033988 * (T6 - T9);
            Te = Tc + Td;
            Tg = KP1_118033988 * (Tc - Td);
        }
        R1[(rs[2])] = (((KP2_000000000) * (Ta)) + (T3));
        R0[0] = (((KP2_000000000) * (Te)) + (Tb));
        {
            E To, Tq, Th, Tp, Tf;
            To = ((KP1_175570504 * Tk) - ((KP1_902113032) * (Tn)));
            Tq = (((KP1_902113032) * (Tk)) + (KP1_175570504 * Tn));
            Tf = ((Tb) - ((KP500000000) * (Te)));
            Th = Tf - Tg;
            Tp = Tg + Tf;
            R0[(rs[1])] = Th - To;
            R0[(rs[2])] = Tp + Tq;
            R0[(rs[4])] = Th + To;
            R0[(rs[3])] = Tp - Tq;
        }
        {
            E Tw, Ty, Tt, Tx, Tr;
            Tw = ((KP1_175570504 * Tu) - ((KP1_902113032) * (Tv)));
            Ty = (((KP1_902113032) * (Tu)) + (KP1_175570504 * Tv));
            Tr = ((T3) - ((KP500000000) * (Ta)));
            Tt = Tr - Ts;
            Tx = Ts + Tr;
            R1[(rs[3])] = Tt - Tw;
            R1[(rs[4])] = Tx + Ty;
            R1[(rs[1])] = Tt + Tw;
            R1[0] = Tx - Ty;
        }
    }

    if (i >= 2) {
        E T3b, Tbb, Tnb, Tvb, Tkb, Tub, Tab, Tsb, Teb, Tgb, Tib, Tjb;
        {
            E T1b, T2b, Tlb, Tmb;
            T1b = Cr[ivs];
            T2b = Cr[ivs + (csr[5])];
            T3b = T1b - T2b;
            Tbb = T1b + T2b;
            Tlb = Ci[ivs + (csi[4])];
            Tmb = Ci[ivs + (csi[1])];
            Tnb = Tlb - Tmb;
            Tvb = Tlb + Tmb;
        }
        Tib = Ci[ivs + (csi[2])];
        Tjb = Ci[ivs + (csi[3])];
        Tkb = Tib - Tjb;
        Tub = Tib + Tjb;
        {
            E T6b, Tcb, T9b, Tdb;
            {
                E T4b, T5b, T7b, T8b;
                T4b = Cr[ivs + (csr[2])];
                T5b = Cr[ivs + (csr[3])];
                T6b = T4b - T5b;
                Tcb = T4b + T5b;
                T7b = Cr[ivs + (csr[4])];
                T8b = Cr[ivs + (csr[1])];
                T9b = T7b - T8b;
                Tdb = T7b + T8b;
            }
            Tab = T6b + T9b;
            Tsb = KP1_118033988 * (T6b - T9b);
            Teb = Tcb + Tdb;
            Tgb = KP1_118033988 * (Tcb - Tdb);
        }
        R1[ovs + (rs[2])] = (((KP2_000000000) * (Tab)) + (T3b));
        R0[ovs] = (((KP2_000000000) * (Teb)) + (Tbb));
        {
            E Tob, Tqb, Thb, Tpb, Tfb;
            Tob = ((KP1_175570504 * Tkb) - ((KP1_902113032) * (Tnb)));
            Tqb = (((KP1_902113032) * (Tkb)) + (KP1_175570504 * Tnb));
            Tfb = ((Tbb) - ((KP500000000) * (Teb)));
            Thb = Tfb - Tgb;
            Tpb = Tgb + Tfb;
            R0[ovs + (rs[1])] = Thb - Tob;
            R0[ovs + (rs[2])] = Tpb + Tqb;
            R0[ovs + (rs[4])] = Thb + Tob;
            R0[ovs + (rs[3])] = Tpb - Tqb;
        }
        {
            E Twb, Tyb, Ttb, Txb, Trb;
            Twb = ((KP1_175570504 * Tub) - ((KP1_902113032) * (Tvb)));
            Tyb = (((KP1_902113032) * (Tub)) + (KP1_175570504 * Tvb));
            Trb = ((T3b) - ((KP500000000) * (Tab)));
            Ttb = Trb - Tsb;
            Txb = Tsb + Trb;
            R1[ovs + (rs[3])] = Ttb - Twb;
            R1[ovs + (rs[4])] = Txb + Tyb;
            R1[ovs + (rs[1])] = Ttb + Twb;
            R1[ovs] = Txb - Tyb;
        }
    }
}
}
