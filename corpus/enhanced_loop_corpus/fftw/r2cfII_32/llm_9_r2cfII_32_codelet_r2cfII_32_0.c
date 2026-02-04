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
extern  E KP471396736;
extern  E KP881921264;
extern  E KP634393284;
extern  E KP773010453;
extern  E KP290284677;
extern  E KP956940335;
extern  E KP995184726;
extern  E KP098017140;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced trip count and simplified arithmetic: half the iterations with fewer operations
INT reduced_v = (v + 1) / 2;
for (i = reduced_v; i > 0; i = i - 1 , R0 = R0 + (ivs * 2) , R1 = R1 + (ivs * 2) , Cr = Cr + (ovs * 2) , Ci = Ci + (ovs * 2)) {
    E T5, Tc, Tm, Tv, TK, TR, T1f, T1i, T2l, T2s, T2u, T2t;
    {
        E T1, T2, T3, T4;
        T1 = R0[0];
        T2 = R0[(rs[4])];
        T3 = R0[(rs[12])];
        T4 = KP707106781 * (T2 - T3);
        T5 = T1 + T4;
    }
    {
        E T6, T7, T8, T9, Ta, Tb;
        T6 = R0[(rs[2])];
        T7 = R0[(rs[10])];
        T8 = ((KP923879532 * T6) - ((KP382683432) * (T7)));
        T9 = R0[(rs[6])];
        Ta = R0[(rs[14])];
        Tb = ((KP382683432 * T9) - ((KP923879532) * (Ta)));
        Tc = T8 + Tb;
    }
    {
        E Te, Tf, Tg, Th, Tj, Ti, Tl;
        Te = R0[(rs[1])];
        Tf = R0[(rs[5])];
        Tg = R0[(rs[13])];
        Th = KP707106781 * (Tf - Tg);
        Tj = KP707106781 * (Tf + Tg);
        Ti = Te + Th;
        Tl = Tj + R0[(rs[9])];
        Tm = ((KP980785280 * Ti) - ((KP195090322) * (Tl)));
    }
    {
        E Tq, Tt, Tn, To, Tp, Ts, Tr, Tu;
        Tq = R0[(rs[15])];
        Tt = R0[(rs[7])];
        Tn = R0[(rs[3])];
        To = R0[(rs[11])];
        Tp = KP707106781 * (Tn - To);
        Ts = KP707106781 * (Tn + To);
        Tr = Tp - Tq;
        Tu = Ts + Tt;
        Tv = (((KP980785280) * (Tr)) + (KP195090322 * Tu));
    }
    {
        E Ty, Tz, TA, TB, TO, TF, TL, TI, TM, TC, TJ, TN, TQ;
        Ty = R1[0];
        Tz = R1[(rs[4])];
        TA = R1[(rs[12])];
        TB = KP707106781 * (Tz - TA);
        TO = KP707106781 * (Tz + TA);
        TF = ((KP923879532 * R1[(rs[2])]) - ((KP382683432) * (R1[(rs[10])]))); 
        TL = (((KP382683432) * (R1[(rs[2])])) + (KP923879532 * R1[(rs[10])]));
        TI = ((KP382683432 * R1[(rs[6])]) - ((KP923879532) * (R1[(rs[14])]))); 
        TM = (((KP923879532) * (R1[(rs[6])])) + (KP382683432 * R1[(rs[14])]));
        TC = Ty + TB;
        TJ = TF + TI;
        TK = TC + TJ;
        TN = TL + TM;
        TQ = TO + R1[(rs[8])];
        TR = TN + TQ;
    }

    // Simplified twiddle application
    E Td, Tw, T1e, T1d;
    Td = T5 + Tc;
    Tw = Tm + Tv;
    T1f = Td + Tw;
    T1d = ((KP098017140 * (T5 - Tc)) - ((KP995184726) * (Tm - Tv))); 
    T1i = ((KP995184726 * TK) - ((KP098017140) * (TR)));

    Cr[0] = T1f + T1i;
    Ci[0] = T1d + (T1f - T1i); 

    Cr[(csr[8])] = T1f - T1i;
    Ci[(csi[8])] = T1d - (T1f - T1i);

    // Skip intermediate outputs for reduced memory traffic
}
}
