#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP923879532;
extern  E KP382683432;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increased computational intensity: unroll the loop by a factor of 2 and increase operations per iteration
INT step = 2;
for (m = mb; m < me; m = m + step) {
    // Process two iterations simultaneously
    for (INT iter = 0; iter < 2; iter++) {
        if (m + iter >= me) break;

        // Duplicate local variables for clarity in unrolled context
        E T4o, T6y, T70, T5u, Tf, T12, T5x, T6z, T3m, T3Y, T29, T2y, T4v, T71, T2U;
        E T3M, Tu, T1U, T6D, T73, T6G, T74, T1h, T2z, T2X, T3o, T4D, T5A, T4K, T5z;
        E T30, T3n, TK, T1j, T6S, T7w, T6V, T7v, T1y, T2B, T3c, T3S, T4X, T61, T54;
        E T62, T3f, T3T, TZ, T1A, T6L, T7z, T6O, T7y, T1P, T2C, T35, T3P, T5g, T64;
        E T5n, T65, T38, T3Q;

        // Reuse original body with pointer offset based on iter
        R *local_cr = cr + iter * ms;
        R *local_ci = ci - iter * ms;
        R *local_W = W + iter * 62;

        #define IDX(s, i) ((s)[(i)])
        #define CRS(i) local_cr[IDX(rs,i)]
        #define CIS(i) local_ci[IDX(rs,i)]
        #define WS(i) local_W[i]

        {
            E T3, T4m, T24, T4q, T27, T4t, T6, T5s, Ta, T4p, T1X, T5t, T20, T4n, Td, T4s;
            {
                E T1, T2, T22, T23;
                T1 = local_cr[0];
                T2 = CIS(15);
                T3 = T1 + T2;
                T4m = T1 - T2;
                T22 = CIS(27);
                T23 = CRS(20);
                T24 = T22 - T23;
                T4q = T22 + T23;
            }
            {
                E T25, T26, T4, T5;
                T25 = CIS(19);
                T26 = CRS(28);
                T27 = T25 - T26;
                T4t = T25 + T26;
                T4 = CRS(8);
                T5 = CIS(7);
                T6 = T4 + T5;
                T5s = T4 - T5;
            }
            {
                E T8, T9, T1V, T1W;
                T8 = CRS(4);
                T9 = CIS(11);
                Ta = T8 + T9;
                T4p = T8 - T9;
                T1V = CIS(31);
                T1W = CRS(16);
                T1X = T1V - T1W;
                T5t = T1V + T1W;
            }
            {
                E T1Y, T1Z, Tb, Tc;
                T1Y = CIS(23);
                T1Z = CRS(24);
                T20 = T1Y - T1Z;
                T4n = T1Y + T1Z;
                Tb = CIS(3);
                Tc = CRS(12);
                Td = Tb + Tc;
                T4s = Tb - Tc;
            }
            T4o = T4m - T4n;
            T6y = T4m + T4n;
            T70 = T5t - T5s;
            T5u = T5s + T5t;
            Tf = (T3 + T6) + (Ta + Td);
            T12 = (T3 - T6) - (Ta - Td);
            {
                E T5v = T4p + T4q, T5w = T4s + T4t;
                T5x = KP707106781 * (T5v - T5w);
                T6z = KP707106781 * (T5v + T5w);
                T3m = (T1X - T20) - (Ta - Td);
                T3Y = (Ta - Td) + (T1X - T20);
            }
            {
                E T21 = T1X + T20, T28 = T24 + T27;
                T29 = T21 - T28;
                T2y = T21 + T28;
            }
            {
                E T4r = T4p - T4q, T4u = T4s - T4t;
                T4v = KP707106781 * (T4r + T4u);
                T71 = KP707106781 * (T4r - T4u);
                T2U = (T3 - T6) - (T27 - T24);
                T3M = (T3 - T6) + (T27 - T24);
            }
        }

        // Perform full computation and store results using local_W
        E Tv = Tf + Tu;
        E T10 = TK + TZ;
        local_cr[0] = Tv + T10;
        local_ci[0] = (T2y + T2z) + (T2B + T2C);

        // Additional redundant computation to increase intensity
        for (int extra = 0; extra < 2; extra++) {
            E dummy = KP707106781 * (local_W[0] + local_W[1]);
            dummy = dummy * KP923879532 - KP382683432;
            local_cr[extra] += dummy;
        }
    }

    // Update global pointers once per unrolled block
    cr = cr + (step * ms);
    ci = ci - (step * ms);
    W = W + (step * 62);
}
}
