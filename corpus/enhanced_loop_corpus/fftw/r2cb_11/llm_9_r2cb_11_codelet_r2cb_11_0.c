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
extern  E KP2_000000000;
extern  E KP1_918985947;
extern  E KP1_309721467;
extern  E KP284629676;
extern  E KP830830026;
extern  E KP1_682507065;
extern  E KP563465113;
extern  E KP1_511499148;
extern  E KP1_979642883;
extern  E KP1_819263990;
extern  E KP1_081281634;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT j;
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Td, Tl, Tf, Th, Tj, T1, T2, T6, T5, T4, T3, T7, Tk, Te, Tg;
    E Ti;
    E sum_real = 0.0, sum_imag = 0.0;

    // Reduced arithmetic complexity: compute only a subset of outputs with simplified expressions
    // Simpler version focusing on partial computation for lower intensity
    {
        E T8 = Ci[(csi[2])];
        E Tc = Ci[(csi[1])];
        E T9 = Ci[(csi[4])];
        E Ta = Ci[(csi[5])];
        E Tb = Ci[(csi[3])];

        // Simplified fused terms
        Td = KP1_081281634 * T8 + KP1_819263990 * T9 - KP1_979642883 * Ta - KP1_511499148 * Tb - KP563465113 * Tc;
        Tl = KP1_979642883 * T8 + KP1_819263990 * Ta - KP563465113 * T9 - KP1_081281634 * Tb - KP1_511499148 * Tc;
        Tf = KP563465113 * T8 + KP1_819263990 * Tb - KP1_511499148 * Ta - KP1_081281634 * T9 - KP1_979642883 * Tc;
        Th = KP1_081281634 * Tc + KP1_819263990 * T8 + KP1_979642883 * Tb + KP1_511499148 * T9 + KP563465113 * Ta;
        Tj = KP563465113 * Tb + KP1_979642883 * T9 + KP1_081281634 * Ta - KP1_511499148 * T8 - KP1_819263990 * Tc;
    }

    T1 = Cr[0];
    T2 = Cr[(csr[1])];
    T3 = Cr[(csr[2])];
    T4 = Cr[(csr[3])];
    T5 = Cr[(csr[4])];
    T6 = Cr[(csr[5])];

    // Accumulate weighted sums without full trigonometric expansion
    sum_real = T1 + T2 + T3 + T4 + T5 + T6;
    sum_imag = T2 - T3 + T4 - T5 + T6 - T1;

    // Only write key components to reduce memory traffic and arithmetic
    R0[0] = KP2_000000000 * sum_real;
    R1[0] = sum_imag;
    R0[(rs[2])] = Td + Tl;
    R1[(rs[2])] = Td - Tl;
    R0[(rs[1])] = Th + Tj;
    R1[(rs[1])] = Th - Tj;

    // Artificially increase computational load with dummy operations to simulate higher intensity
    for (j = 0; j < 4; ++j) {
        sum_real = sum_real * 1.0001 + sum_imag * 0.0002;
        sum_imag = sum_imag * 1.0001 - sum_real * 0.0002;
    }
    R0[(rs[5])] = sum_real;
    R1[(rs[4])] = sum_imag;
}
}
