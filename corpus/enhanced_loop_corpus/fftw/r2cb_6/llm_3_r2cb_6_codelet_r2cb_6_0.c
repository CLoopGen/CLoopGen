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
extern  E KP1_732050807;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T7, Tc, Te, T6, T8, T1, T2, T9, Td;
    E *cr_ptr = Cr;
    E *ci_ptr = Ci;
    E *r0_ptr = R0;
    E *r1_ptr = R1;
    INT s0 = 0, s1 = csr[1], s2 = csr[2], s3 = csr[3];
    INT t1 = csi[1], t2 = csi[2];
    INT u1 = rs[1], u2 = rs[2];

    T1 = cr_ptr[s0]; T2 = cr_ptr[s3];
    T3 = T1 - T2;
    T7 = T1 + T2;

    {
        E Ta = ci_ptr[t2], Tb = ci_ptr[t1];
        Tc = KP1_732050807 * (Ta - Tb);
        Te = KP1_732050807 * (Ta + Tb);
        T6 = cr_ptr[s2] - cr_ptr[s1];
        T8 = cr_ptr[s2] + cr_ptr[s1];
    }

    r1_ptr[u1] = (KP2_000000000 * T6) + T3;
    r0_ptr[0]   = (KP2_000000000 * T8) + T7;
    T9 = T7 - T8;
    r0_ptr[u2]  = T9 - Tc;
    r0_ptr[u1]  = T9 + Tc;
    Td = T3 - T6;
    r1_ptr[0]   = Td - Te;
    r1_ptr[u2]  = Td + Te;
}
}
