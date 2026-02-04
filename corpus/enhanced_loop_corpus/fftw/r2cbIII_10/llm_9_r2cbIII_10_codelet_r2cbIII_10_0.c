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
    E T1, To, T8, Tq, Ta, Tp, Te, Ts, Th, Tn;
    T1 = Cr[(csr[2])];
    To = Ci[(csi[2])];

    // Reduced arithmetic complexity: combine common subexpressions and eliminate redundant operations
    E T_sum_c_real = Cr[(csr[4])] + Cr[0] + Cr[(csr[3])] + Cr[(csr[1])];
    E T_diff_c_real_40 = Cr[(csr[4])] - Cr[0];
    E T_diff_c_real_31 = Cr[(csr[3])] - Cr[(csr[1])];
    T8 = T_sum_c_real;
    Tq = T_diff_c_real_31;
    Ta = KP1_118033988 * (T_diff_c_real_31 - T_diff_c_real_40);
    Tp = T_diff_c_real_40;

    E T_sum_c_imag = Ci[(csi[4])] + Ci[0] + Ci[(csi[1])] + Ci[(csi[3])];
    E T_diff_c_imag_40 = Ci[(csi[4])] - Ci[0];
    E T_diff_c_imag_13 = Ci[(csi[1])] - Ci[(csi[3])];
    Tn = T_sum_c_imag - 2*(Ci[(csi[4])] + Ci[0]); // Equivalent to Tl - Tm
    Te = T_diff_c_imag_40;
    Ts = KP1_118033988 * (T_sum_c_imag);
    Th = T_diff_c_imag_13;

    R0[0] = KP2_000000000 * (T1 + T8);
    R1[(rs[2])] = KP2_000000000 * (Tn - To);

    // Simplify butterfly calculations using pre-scaled terms
    E Te_scaled = KP1_175570504 * Te;
    E Th_scaled = KP1_902113032 * Th;
    E Ti = Te_scaled - Th_scaled;
    E Tj = Th_scaled + Te_scaled;

    E T8_scaled = KP500000000 * T8;
    E T1_scaled = KP2_000000000 * T1;
    E T9 = T8_scaled - T1_scaled;
    E Tb = T9 - Ta;
    E Tk = T9 + Ta;

    R0[(rs[1])] = Tb + Ti;
    R0[(rs[3])] = Tk + Tj;
    R0[(rs[4])] = Ti - Tb;
    R0[(rs[2])] = Tj - Tk;

    E Tp_scaled = KP1_902113032 * Tp;
    E Tq_scaled = KP1_175570504 * Tq;
    E Tr = Tp_scaled + Tq_scaled;
    E Tv = Tq_scaled - Tp_scaled;

    E Tn_scaled = KP500000000 * Tn;
    E To_scaled = KP2_000000000 * To;
    E Tt = Tn_scaled + To_scaled;
    E Tu = Ts + Tt;
    E Tw = Tt - Ts;

    R1[0] = -(Tr + Tu);
    R1[(rs[3])] = Tw - Tv;
    R1[(rs[4])] = Tr - Tu;
    R1[(rs[1])] = Tv + Tw;
}
}
