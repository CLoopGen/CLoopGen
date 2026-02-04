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
for (m = mb; m < me; m += 2, cr = cr + (2 * ms), ci = ci - (2 * ms), W = W + 16, (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;

    E T11, T14, T12, T15, T17, T2z, T2B, T1c, T18, T1d, T1g, T1k, T2F, T2L, T3t;
    E T4H, T3h, T3V, T3b, T4v, T4T, T4X, T6t, T71, T6z, T75, T81, T8x, T8f, T8z;
    E T2R, T2V, T8p, T8t, T4r, T4t, T53, T69, T3n, T3r, T7P, T7T, T4P, T4R, T6F;
    E T6R, T1f, T2X, T1j, T2Y, T1l, T31, T2d, T2Z, T49, T4h, T4c, T4i, T4d, T4n;
    E T4f, T4j;

    for (INT step = 0; step < 2; ++step) {
        INT idx = step * 8;
        INT offset = step * ms;
        R* local_cr = cr + offset;
        R* local_ci = ci - offset;
        stride local_rs = rs + step;
        R* local_W = W + idx;

        T11 = local_W[0]; T14 = local_W[1]; T12 = local_W[2]; T15 = local_W[3];
        T17 = T11 * T12 + T14 * T15;
        T2z = T11 * T12 - T14 * T15;
        T2B = T11 * T15 + T14 * T12;
        T1c = T11 * T15 - T14 * T12;
        T18 = local_W[4]; T1d = local_W[5]; T1g = local_W[6]; T1k = local_W[7];

        E T1f = T17 * T18 + T1c * T1d;
        E T2X = T17 * T18 - T1c * T1d;
        E T1j = T17 * T1d - T1c * T18;
        E T2Y = T17 * T1d + T1c * T18;
        E T1l = T1f * T1g + T1j * T1k;
        E T31 = T2X * T1k - T2Y * T1g;
        E T2d = T1f * T1k - T1j * T1g;
        E T2Z = T2X * T1g + T2Y * T1k;

        E Tf = local_cr[0] + local_ci[local_rs[15]];
        E Tu = (local_cr[local_rs[2]] + local_cr[local_rs[10]]) + (local_cr[local_rs[6]] + local_cr[local_rs[14]]);
        E TK = (local_cr[local_rs[1]] + local_cr[local_rs[9]]) + (local_cr[local_rs[5]] + local_cr[local_rs[13]]);
        E TZ = (local_ci[0] + local_ci[local_rs[7]]) + (local_ci[local_rs[3]] + local_ci[local_rs[11]]);

        E Tv = Tf + Tu;
        E T10 = TK + TZ;
        cr[offset] = Tv + T10;
        ci[offset] = (Tf - Tu) + (TK - TZ);
        cr[local_rs[16] + offset] = T2Z * (Tv - T10) - T31 * ((Tf - Tu) - (TK - TZ));
        ci[local_rs[16] + offset] = T31 * (Tv - T10) + T2Z * ((Tf - Tu) - (TK - TZ));
    }
}
}
