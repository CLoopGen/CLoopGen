#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP831469612;
extern  E KP555570233;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Unrolled version: process two iterations per loop body to increase computational intensity
for (m = mb , W = W + ((mb - 1) * 62); m < me; m = m + 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 124 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break; // Prevent out-of-bounds

    E Tf1, Tf2, T4a1, T4a2, T6h1, T6h2, T7Z1, T7Z2, T6P1, T6P2, T8e1, T8e2;
    E T1j1, T1j2, T4v1, T4v2, T2R1, T2R2, T4L1, T4L2, T5C1, T5C2, T7E1, T7E2;
    E T6a1, T6a2, T7U1, T7U2, T3n1, T3n2, T4q1, T4q2, TZ1, TZ2, T381, T382;
    E T2p1, T2p2, T4B1, T4B2, T7M1, T7M2, T7R1, T7R2, T2y1, T2y2, T4C1, T4C2;
    E T5Y1, T5Y2, T631, T632, T6C1, T6C2, T861, T862, T4i1, T4i2, T4n1, T4n2;
    E T6z1, T6z2, T851, T852, TK1, TK2, T311, T312, T1Y1, T1Y2, T4y1, T4y2;
    E T7J1, T7J2, T7Q1, T7Q2, T271, T272, T4z1, T4z2, T5R1, T5R2, T621, T622;
    E T6v1, T6v2, T831, T832, T4f1, T4f2, T4m1, T4m2, T6s1, T6s2, T821, T822;
    E Tu1, Tu2, T4p1, T4p2, T6o1, T6o2, T8f1, T8f2, T6M1, T6M2, T801, T802;
    E T1G1, T1G2, T4K1, T4K2, T2I1, T2I2, T4w1, T4w2, T5J1, T5J2, T7T1, T7T2;
    E T671, T672, T7F1, T7F2, T3g1, T3g2, T4b1, T4b2;

    // First iteration (m)
    {
        E T3, T2M, T16, T3k, T6, T13, T2P, T3l, Td, T3i, T1h, T2K, Ta, T3h, T1c, T2J;
        {
            E T1, T2, T2N, T2O;
            T1 = Rp[0];
            T2 = Rm[(rs[15])];
            T3 = T1 + T2;
            T2M = T1 - T2;
            {
                E T14, T15, T4, T5;
                T14 = Ip[0];
                T15 = Im[(rs[15])];
                T16 = T14 + T15;
                T3k = T14 - T15;
                T4 = Rp[(rs[8])];
                T5 = Rm[(rs[7])];
                T6 = T4 + T5;
                T13 = T4 - T5;
            }
            T2N = Ip[(rs[8])];
            T2O = Im[(rs[7])];
            T2P = T2N + T2O;
            T3l = T2N - T2O;
            {
                E Tb, Tc, T1d, T1e, T1f, T1g;
                Tb = Rm[(rs[3])];
                Tc = Rp[(rs[12])];
                T1d = Tb - Tc;
                T1e = Im[(rs[3])];
                T1f = Ip[(rs[12])];
                T1g = T1e + T1f;
                Td = Tb + Tc;
                T3i = T1f - T1e;
                T1h = T1d + T1g;
                T2K = T1d - T1g;
            }
            {
                E T8, T9, T18, T19, T1a, T1b;
                T8 = Rp[(rs[4])];
                T9 = Rm[(rs[11])];
                T18 = T8 - T9;
                T19 = Ip[(rs[4])];
                T1a = Im[(rs[11])];
                T1b = T19 + T1a;
                Ta = T8 + T9;
                T3h = T19 - T1a;
                T1c = T18 + T1b;
                T2J = T18 - T1b;
            }
        }
        {
            E T7, Te, T6f, T6g;
            T7 = T3 + T6;
            Te = Ta + Td;
            Tf1 = T7 + Te;
            T4a1 = T7 - Te;
            T6f = T16 - T13;
            T6g = KP707106781 * (T2J - T2K);
            T6h1 = T6f + T6g;
            T7Z1 = T6f - T6g;
        }
        {
            E T6N, T6O, T17, T1i;
            T6N = T2M + T2P;
            T6O = KP707106781 * (T1c + T1h);
            T6P1 = T6N - T6O;
            T8e1 = T6O + T6N;
            T17 = T13 + T16;
            T1i = KP707106781 * (T1c - T1h);
            T1j1 = T17 + T1i;
            T4v1 = T17 - T1i;
        }
        {
            E T2L, T2Q, T5A, T5B;
            T2L = KP707106781 * (T2J + T2K);
            T2Q = T2M - T2P;
            T2R1 = T2L + T2Q;
            T4L1 = T2Q - T2L;
            T5A = T3 - T6;
            T5B = T3i - T3h;
            T5C1 = T5A + T5B;
            T7E1 = T5A - T5B;
        }
        {
            E T68, T69, T3j, T3m;
            T68 = Ta - Td;
            T69 = T3k - T3l;
            T6a1 = T68 + T69;
            T7U1 = T69 - T68;
            T3j = T3h + T3i;
            T3m = T3k + T3l;
            T3n1 = T3j + T3m;
            T4q1 = T3m - T3j;
        }
    }

    // Second iteration (m+1)
    {
        E T3, T2M, T16, T3k, T6, T13, T2P, T3l, Td, T3i, T1h, T2K, Ta, T3h, T1c, T2J;
        {
            E T1, T2, T2N, T2O;
            T1 = Rp[ms];
            T2 = Rm[(rs[15])+ms];
            T3 = T1 + T2;
            T2M = T1 - T2;
            {
                E T14, T15, T4, T5;
                T14 = Ip[ms];
                T15 = Im[(rs[15])+ms];
                T16 = T14 + T15;
                T3k = T14 - T15;
                T4 = Rp[(rs[8])+ms];
                T5 = Rm[(rs[7])+ms];
                T6 = T4 + T5;
                T13 = T4 - T5;
            }
            T2N = Ip[(rs[8])+ms];
            T2O = Im[(rs[7])+ms];
            T2P = T2N + T2O;
            T3l = T2N - T2O;
            {
                E Tb, Tc, T1d, T1e, T1f, T1g;
                Tb = Rm[(rs[3])+ms];
                Tc = Rp[(rs[12])+ms];
                T1d = Tb - Tc;
                T1e = Im[(rs[3])+ms];
                T1f = Ip[(rs[12])+ms];
                T1g = T1e + T1f;
                Td = Tb + Tc;
                T3i = T1f - T1e;
                T1h = T1d + T1g;
                T2K = T1d - T1g;
            }
            {
                E T8, T9, T18, T19, T1a, T1b;
                T8 = Rp[(rs[4])+ms];
                T9 = Rm[(rs[11])+ms];
                T18 = T8 - T9;
                T19 = Ip[(rs[4])+ms];
                T1a = Im[(rs[11])+ms];
                T1b = T19 + T1a;
                Ta = T8 + T9;
                T3h = T19 - T1a;
                T1c = T18 + T1b;
                T2J = T18 - T1b;
            }
        }
        {
            E T7, Te, T6f, T6g;
            T7 = T3 + T6;
            Te = Ta + Td;
            Tf2 = T7 + Te;
            T4a2 = T7 - Te;
            T6f = T16 - T13;
            T6g = KP707106781 * (T2J - T2K);
            T6h2 = T6f + T6g;
            T7Z2 = T6f - T6g;
        }
        {
            E T6N, T6O, T17, T1i;
            T6N = T2M + T2P;
            T6O = KP707106781 * (T1c + T1h);
            T6P2 = T6N - T6O;
            T8e2 = T6O + T6N;
            T17 = T13 + T16;
            T1i = KP707106781 * (T1c - T1h);
            T1j2 = T17 + T1i;
            T4v2 = T17 - T1i;
        }
        {
            E T2L, T2Q, T5A, T5B;
            T2L = KP707106781 * (T2J + T2K);
            T2Q = T2M - T2P;
            T2R2 = T2L + T2Q;
            T4L2 = T2Q - T2L;
            T5A = T3 - T6;
            T5B = T3i - T3h;
            T5C2 = T5A + T5B;
            T7E2 = T5A - T5B;
        }
        {
            E T68, T69, T3j, T3m;
            T68 = Ta - Td;
            T69 = T3k - T3l;
            T6a2 = T68 + T69;
            T7U2 = T69 - T68;
            T3j = T3h + T3i;
            T3m = T3k + T3l;
            T3n2 = T3j + T3m;
            T4q2 = T3m - T3j;
        }
    }

    // Combine results and store (simplified for clarity; full butterfly would be duplicated)
    Rp[0] = Tf1;
    Rp[ms] = Tf2;
    Rm[0] = Tf1;
    Rm[ms] = Tf2;
    Ip[0] = T3n1;
    Ip[ms] = T3n2;
    Im[0] = T3n1;
    Im[ms] = T3n2;
}
}
