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

    // First block: always compute basic values
    T8 = Cr[(csr[3])];
    Tb = Cr[(csr[5])] + Cr[(csr[1])];
    Tw = Ci[(csi[3])];
    Tx = Ci[(csi[5])] + Ci[(csi[1])];

    // Conditional path based on loop index parity and magnitude
    if (i % 3 == 0) {
        E T9 = Cr[(csr[5])], Ta = Cr[(csr[1])];
        Tm = ((KP2_000000000) * T8) - Tb;
        TA = KP1_732050807 * (T9 - Ta);
        Tp = KP1_732050807 * (Ci[(csi[5])] - Ci[(csi[1])]);
        TB = ((KP2_000000000) * Tw) + Tx;
    } else if (i < v / 2) {
        // Alternate fast path with fused operations
        Tm = (KP2_000000000) * (T8 - Cr[(csr[5])]) - Cr[(csr[1])];
        TA = KP1_732050807 * (Cr[(csr[5])] - Cr[(csr[1])]);
        Tp = KP1_732050807 * (Ci[(csi[5])] - Ci[(csi[1])]);
        TB = (KP2_000000000) * Tw + Tx;
    } else {
        // Default full path
        E T9, Ta, Tn, To;
        T9 = Cr[(csr[5])];
        Ta = Cr[(csr[1])];
        Tm = (((KP2_000000000) * (T8)) - (Tb));
        TA = KP1_732050807 * (T9 - Ta);
        Tn = Ci[(csi[5])];
        To = Ci[(csi[1])];
        Tp = KP1_732050807 * (Tn - To);
        TB = (((KP2_000000000) * (Tw)) + (Tx));
    }

    // Unconditionally compute middle blocks with possible early bypass
    {
        E Tf, T1, T2, Td, Te;
        Te = Ci[(csi[4])];
        Tf = KP1_732050807 * Te;
        T1 = Cr[0];
        T2 = Cr[(csr[4])];
        Td = T1 - T2;
        T3 = (((KP2_000000000) * (T2)) + (T1));
        if (i % 4 != 0) {
            Tr = Td - Tf;
            Tg = Td + Tf;
        } else {
            Tr = Td;
            Tg = Td;
        }
    }

    {
        E Tj, T4, T5, Th, Ti;
        Ti = Ci[(csi[2])];
        Tj = KP1_732050807 * Ti;
        T4 = Cr[(csr[6])];
        T5 = Cr[(csr[2])];
        Th = T4 - T5;
        T6 = (((KP2_000000000) * (T5)) + (T4));
        if (i > v / 3) {
            Ts = Th + Tj;
            Tk = Th - Tj;
        } else {
            Ts = Th;
            Tk = Th;
        }
    }

    // Final store operations with conditional masking
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
