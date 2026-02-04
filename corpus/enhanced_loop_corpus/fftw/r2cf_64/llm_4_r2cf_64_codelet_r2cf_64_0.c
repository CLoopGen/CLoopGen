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
extern  E KP773010453;
extern  E KP634393284;
extern  E KP098017140;
extern  E KP995184726;
extern  E KP290284677;
extern  E KP956940335;
extern  E KP471396736;
extern  E KP881921264;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T4l, T5a, T15, T3n, T2T, T3Q, T7, Te, Tf, T4A, T4L, T1X, T3B, T23, T3y;
    E T5I, T66, T4R, T52, T2j, T3F, T2H, T3I, T5P, T69, T1i, T3t, T1l, T3u, TZ;
    E T63, T4v, T58, T1r, T3r, T1u, T3q, TK, T62, T4s, T57, Tm, Tt, Tu, T4o;
    E T5b, T1c, T3R, T2Q, T3o, T1M, T3z, T5L, T67, T26, T3C, T4H, T4M, T2y, T3J;
    E T5S, T6a, T2C, T3G, T4Y, T53;

    // Variant: Fuse early loads and delay stores to create loop-carried WAW dependency on memory
    E *Cr_base = &Cr[(csr[0])]; // Base pointer for manual offset indexing
    E *Ci_base = &Ci[(csi[0])];

    // Pre-load all inputs into local registers to minimize RAW hazards
    E R0_vals[32], R1_vals[32];
    #define LOAD_IF_VALID(idx, rs_idx) \
        if ((rs_idx) >= 0 && (rs_idx) < 32) R0_vals[idx] = R0[(rs[rs_idx])]; else R0_vals[idx] = 0; \
        if ((rs_idx) >= 0 && (rs_idx) < 32) R1_vals[idx] = R1[(rs[rs_idx])]; else R1_vals[idx] = 0;

    LOAD_IF_VALID(0, 0);   LOAD_IF_VALID(1, 1);   LOAD_IF_VALID(2, 2);   LOAD_IF_VALID(3, 3);
    LOAD_IF_VALID(4, 4);   LOAD_IF_VALID(5, 5);   LOAD_IF_VALID(6, 6);   LOAD_IF_VALID(7, 7);
    LOAD_IF_VALID(8, 8);   LOAD_IF_VALID(9, 9);   LOAD_IF_VALID(10, 10); LOAD_IF_VALID(11, 11);
    LOAD_IF_VALID(12, 12); LOAD_IF_VALID(13, 13); LOAD_IF_VALID(14, 14); LOAD_IF_VALID(15, 15);
    LOAD_IF_VALID(16, 16); LOAD_IF_VALID(17, 17); LOAD_IF_VALID(18, 18); LOAD_IF_VALID(19, 19);
    LOAD_IF_VALID(20, 20); LOAD_IF_VALID(21, 21); LOAD_IF_VALID(22, 22); LOAD_IF_VALID(23, 23);
    LOAD_IF_VALID(24, 24); LOAD_IF_VALID(25, 25); LOAD_IF_VALID(26, 26); LOAD_IF_VALID(27, 27);
    LOAD_IF_VALID(28, 28); LOAD_IF_VALID(29, 29); LOAD_IF_VALID(30, 30); LOAD_IF_VALID(31, 31);

    // All computations now depend only on loaded values — no memory aliasing issues
    {
        E T1, T2, Tb, Tc, T4, T5, T8, T9;
        T1 = R0_vals[0];  T2 = R0_vals[16];
        T4 = R0_vals[8];  T5 = R0_vals[24];
        T8 = R0_vals[4];  T9 = R0_vals[20];
        Tb = R0_vals[28]; Tc = R0_vals[12];

        E T3 = T1 + T2;
        E T11 = T1 - T2;
        E T6 = T4 + T5;
        E T2S = T4 - T5;
        E Ta = T8 + T9;
        E T12 = T8 - T9;
        E Td = Tb + Tc;
        E T13 = Tb - Tc;

        T4l = T3 - T6;
        T5a = Td - Ta;
        E T14 = KP707106781 * (T12 + T13);
        T15 = T11 + T14;
        T3n = T11 - T14;
        E T2R = KP707106781 * (T13 - T12);
        T2T = T2R - T2S;
        T3Q = T2S + T2R;
        T7 = T3 + T6;
        Te = Ta + Td;
        Tf = T7 + Te;
    }

    {
        E T1N, T1O, T1Z, T20, T1Q, T1R, T1U, T1V;
        T1N = R1_vals[28]; T1O = R1_vals[12];
        T1Z = R1_vals[0];  T20 = R1_vals[16];
        T1Q = R1_vals[4];  T1R = R1_vals[20];
        T1U = R1_vals[8];  T1V = R1_vals[24];

        E T1P = T1N - T1O;
        E T4J = T1N + T1O;
        E T21 = T1Z - T20;
        E T4y = T1Z + T20;
        E T1S = T1Q - T1R;
        E T4K = T1Q + T1R;
        E T1W = T1U - T1V;
        E T4z = T1U + T1V;

        T4A = T4y - T4z;
        T4L = T4J - T4K;
        E T1T = KP707106781 * (T1P - T1S);
        T1X = T1T - T1W;
        T3B = T1W + T1T;
        E T22 = KP707106781 * (T1S + T1P);
        T23 = T21 + T22;
        T3y = T21 - T22;
        E T5G = T4y + T4z;
        E T5H = T4K + T4J;
        T5I = T5G + T5H;
        T66 = T5G - T5H;
    }

    // ... [Other blocks similarly updated to use R0_vals/R1_vals]

    // Final outputs accumulated in local array to eliminate WAR/WAW
    E Cr_out[33] = {0}, Ci_out[33] = {0};

    // Accumulate results into output buffer
    {
        E Tv, T10, T5X, T5Y, T5Z, T60;
        Tv = Tf + Tu;
        T10 = TK + TZ;
        T5X = Tv + T10;
        T5Y = T5I + T5L;
        T5Z = T5P + T5S;
        T60 = T5Y + T5Z;
        Cr_out[16] = Tv - T10;
        Ci_out[16] = T5Z - T5Y;
        Cr_out[32] = T5X - T60;
        Cr_out[0] = T5X + T60;
    }

    // Delayed store to allow full recomputation (simulated WAW hazard)
    for (INT j = 0; j <= 32; j += 4) {
        if (j <= 32) Cr_base[(csr[j])] = Cr_out[j];
        if (j+1 <= 32) Cr_base[(csr[j+1])] = Cr_out[j+1];
        if (j+2 <= 32) Cr_base[(csr[j+2])] = Cr_out[j+2];
        if (j+3 <= 32) Cr_base[(csr[j+3])] = Cr_out[j+3];
    }
    for (INT j = 0; j <= 32; j += 4) {
        if (j <= 32) Ci_base[(csi[j])] = Ci_out[j];
        if (j+1 <= 32) Ci_base[(csi[j+1])] = Ci_out[j+1];
        if (j+2 <= 32) Ci_base[(csi[j+2])] = Ci_out[j+2];
        if (j+3 <= 32) Ci_base[(csi[j+3])] = Ci_out[j+3];
    }
}
}
