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
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T8, Tb, Tm, TA, Tw, Tx, Tp, TB, T3, Tr, Tg, T6, Ts, Tk;
    E T_cache[16];  // Simulate out-of-order computation and reorder operations
    INT offset_T = 0;

    // Reorder computations to introduce artificial WAW and WAR hazards via delayed writes
    // First, precompute values that don't depend on others

    T_cache[offset_T++] = Cr[(csr[3])]; // T8 placeholder
    T_cache[offset_T++] = Cr[(csr[5])]; 
    T_cache[offset_T++] = Cr[(csr[1])];
    T_cache[offset_T++] = Ci[(csi[3])];
    T_cache[offset_T++] = Ci[(csi[5])];
    T_cache[offset_T++] = Ci[(csi[1])];
    T_cache[offset_T++] = Ci[(csi[4])];
    T_cache[offset_T++] = Cr[0];
    T_cache[offset_T++] = Cr[(csr[4])];
    T_cache[offset_T++] = Ci[(csi[2])];
    T_cache[offset_T++] = Cr[(csr[6])];
    T_cache[offset_T++] = Cr[(csr[2])];

    // Now compute intermediate results with staggered assignments to create loop-carried dependency illusion
    {
        E T9 = T_cache[1], Ta = T_cache[2], Tn = T_cache[4], To = T_cache[5];
        Tb = T9 + Ta;
        Tx = Tn + To;
        TA = KP1_732050807 * (T9 - Ta);
        Tp = KP1_732050807 * (Tn - To);
        T8 = T_cache[0];
        Tw = T_cache[3];
        Tm = (((KP2_000000000) * (T8)) - (Tb));
        TB = (((KP2_000000000) * (Tw)) + (Tx));
    }
    {
        E Te = T_cache[6], T1 = T_cache[7], T2 = T_cache[8];
        T3 = (((KP2_000000000) * (T2)) + (T1));
        Tr = (T1 - T2) - (KP1_732050807 * Te);
        Tg = (T1 - T2) + (KP1_732050807 * Te);
    }
    {
        E Ti = T_cache[9], T4 = T_cache[10], T5 = T_cache[11];
        T6 = (((KP2_000000000) * (T5)) + (T4));
        Ts = (T4 - T5) + (KP1_732050807 * Ti);
        Tk = (T4 - T5) - (KP1_732050807 * Ti);
    }

    // Final stage: resolve outputs with reordered but semantically equivalent expressions
    {
        E T7 = T3 + T6;
        E Tc = KP2_000000000 * (T8 + Tb);
        R0[(rs[3])] = T7 - Tc;
        R0[0] = T7 + Tc;

        {
            E Tl = Tg + Tk;
            E Tq = Tm - Tp;
            R0[(rs[1])] = Tl - Tq;
            R0[(rs[4])] = Tl + Tq;

            E TD = Tg - Tk;
            E TE = TB - TA;
            R1[(rs[2])] = TD - TE;
            R1[(rs[5])] = TD + TE;
        }

        E Tz = Tr - Ts;
        E TC = TA + TB;
        R1[0] = Tz - TC;
        R1[(rs[3])] = Tz + TC;

        {
            E Tv = T3 - T6;
            E Ty = KP2_000000000 * (Tw - Tx);
            R1[(rs[4])] = Tv - Ty;
            R1[(rs[1])] = Tv + Ty;

            E Tt = Tr + Ts;
            E Tu = Tm + Tp;
            R0[(rs[5])] = Tt - Tu;
            R0[(rs[2])] = Tt + Tu;
        }
    }
}
}
