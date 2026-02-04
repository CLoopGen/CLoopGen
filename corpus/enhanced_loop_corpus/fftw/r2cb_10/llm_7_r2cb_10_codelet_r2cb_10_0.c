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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tb, Tn, Tv, Tk, Tu, Ta, Ts, Te, Tg, Ti, Tj;
    E T_cache[10];  // Introduce artificial WAW and WAR hazards via staged write-back

    // Staged computation: break dependency chain by delaying final stores
    {
        E T1 = Cr[0];
        E T2 = Cr[(csr[5])];
        T_cache[0] = T1 - T2;  // T3
        T_cache[1] = T1 + T2;  // Tb
        E Tl = Ci[(csi[4])];
        E Tm = Ci[(csi[1])];
        T_cache[2] = Tl - Tm;  // Tn
        T_cache[3] = Tl + Tm;  // Tv
    }

    Ti = Ci[(csi[2])];
    Tj = Ci[(csi[3])];
    T_cache[4] = Ti - Tj;  // Tk
    T_cache[5] = Ti + Tj;  // Tu

    {
        E T6, Tc, T9, Td;
        {
            E T4 = Cr[(csr[2])];
            E T5 = Cr[(csr[3])];
            T6 = T4 - T5;
            Tc = T4 + T5;
            E T7 = Cr[(csr[4])];
            E T8 = Cr[(csr[1])];
            T9 = T7 - T8;
            Td = T7 + T8;
        }
        T_cache[6] = T6 + T9;  // Ta
        T_cache[7] = KP1_118033988 * (T6 - T9);  // Ts
        T_cache[8] = Tc + Td;  // Te
        T_cache[9] = KP1_118033988 * (Tc - Td);  // Tg
    }

    // Reintroduce reads after writes to create artificial loop-carried dependencies
    T3 = T_cache[0];
    Tb = T_cache[1];
    Tn = T_cache[2];
    Tv = T_cache[3];
    Tk = T_cache[4];
    Tu = T_cache[5];
    Ta = T_cache[6];
    Ts = T_cache[7];
    Te = T_cache[8];
    Tg = T_cache[9];

    // Add artificial loop-carried dependency via reuse of computed values in a feedback manner
    static E prev_Tb = 0, prev_Te = 0;
    E delta_b = Tb - prev_Tb;
    E delta_e = Te - prev_Te;
    prev_Tb = Tb;
    prev_Te = Te;

    R1[(rs[2])] = (((KP2_000000000) * (Ta)) + (T3)) + delta_e;  // modified with loop-carried diff
    R0[0] = (((KP2_000000000) * (Te)) + (Tb)) + delta_b;

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
}
