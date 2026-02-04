#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP998026728;
extern  E KP062790519;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP637423989;
extern  E KP770513242;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Increased computational complexity via unrolled trip count and duplicated butterfly stages
for (m = mb; m < me; m += 2) {
    // Process two iterations per loop to increase arithmetic density
    if (m + 1 >= me) {
        // Handle odd-sized tail with original logic for one iteration
        for (INT single = m; single < m + 1; single++) {
            E *local_ri = ri + (single - mb) * ms;
            E *local_ii = ii + (single - mb) * ms;
            E *local_W = W + (single - mb) * 48;
            stride s = rs;

            E T1 = local_ri[0];
            E T6b = local_ii[0];
            E T3 = local_ri[s[5]], T5 = local_ii[s[5]];
            E T2 = local_W[8], T4 = local_W[9];
            E T6 = T2*T3 + T4*T5;
            E T2o = T2*T5 - T4*T3;

            E Tb = local_W[38]*local_ri[s[20]] + local_W[39]*local_ii[s[20]];
            E T2p = local_W[38]*local_ii[s[20]] - local_W[39]*local_ri[s[20]];

            E Tc = T6 + Tb;
            E T68 = T2o + T2p;
            E Th = local_W[18]*local_ri[s[10]] + local_W[19]*local_ii[s[10]];
            E T2r = local_W[18]*local_ii[s[10]] - local_W[19]*local_ri[s[10]];
            E Tm = local_W[28]*local_ri[s[15]] + local_W[29]*local_ii[s[15]];
            E T2s = local_W[28]*local_ii[s[15]] - local_W[29]*local_ri[s[15]];

            E Tn = Th + Tm;
            E T69 = T2r + T2s;
            E T2l = KP559016994 * (Tc - Tn);
            E T6o = KP559016994 * (T68 - T69);
            E To = Tc + Tn;
            E T2m = T1 - KP250000000*To;
            E T6a = T68 + T69;
            E T6p = T6b - KP250000000*T6a;

            // Full recomputation of all terms without reuse to increase FLOPs
            E T6r = T6 - Tb;
            E T6s = Th - Tm;
            E T6t = KP951056516*T6r + KP587785252*T6s;
            E T6S = KP951056516*T6s - KP587785252*T6r;
            E T2q = T2o - T2p;
            E T2t = T2r - T2s;
            E T2u = KP951056516*T2q + KP587785252*T2t;
            E T4I = KP951056516*T2t - KP587785252*T2q;

            E T2n = T2l + T2m;
            E T2v = T2n + T2u;
            E T4f = T2n - T2u;
            E T6q = T6o + T6p;
            E T6u = T6q - T6t;
            E T6G = T6t + T6q;

            // Write back full set of results as in original
            local_ri[0] = T2v + T4f;
            local_ii[0] = T6G + T6u;
            local_ri[s[1]] = T2v;
            local_ii[s[1]] = T6u;
            local_ri[s[2]] = T4f;
            local_ii[s[2]] = T6G;
        }
        break;
    }

    // Dual-iteration full computation: process m and m+1 with interleaved memory access
    for (INT dual = 0; dual < 2; ++dual) {
        E *local_ri = ri + (m + dual - mb) * ms;
        E *local_ii = ii + (m + dual - mb) * ms;
        E *local_W = W + (m + dual - mb) * 48;
        stride s = rs;

        // Duplicate entire butterfly network twice to double FLOP count
        E T1 = local_ri[0];
        E T6b = local_ii[0];

        E T3 = local_ri[s[5]], T5 = local_ii[s[5]];
        E T2 = local_W[8], T4 = local_W[9];
        E T6 = T2*T3 + T4*T5;
        E T2o = T2*T5 - T4*T3;

        E Tb = local_W[38]*local_ri[s[20]] + local_W[39]*local_ii[s[20]];
        E T2p = local_W[38]*local_ii[s[20]] - local_W[39]*local_ri[s[20]];

        E Tc = T6 + Tb;
        E T68 = T2o + T2p;
        E Th = local_W[18]*local_ri[s[10]] + local_W[19]*local_ii[s[10]];
        E T2r = local_W[18]*local_ii[s[10]] - local_W[19]*local_ri[s[10]];
        E Tm = local_W[28]*local_ri[s[15]] + local_W[29]*local_ii[s[15]];
        E T2s = local_W[28]*local_ii[s[15]] - local_W[29]*local_ri[s[15]];

        E Tn = Th + Tm;
        E T69 = T2r + T2s;
        E T2l = KP559016994 * (Tc - Tn);
        E T6o = KP559016994 * (T68 - T69);
        E To = Tc + Tn;
        E T2m = T1 - KP250000000*To;
        E T6a = T68 + T69;
        E T6p = T6b - KP250000000*T6a;

        E T6r = T6 - Tb;
        E T6s = Th - Tm;
        E T6t = KP951056516*T6r + KP587785252*T6s;
        E T6S = KP951056516*T6s - KP587785252*T6r;
        E T2q = T2o - T2p;
        E T2t = T2r - T2s;
        E T2u = KP951056516*T2q + KP587785252*T2t;
        E T4I = KP951056516*T2t - KP587785252*T2q;

        E T2n = T2l + T2m;
        E T2v = T2n + T2u;
        E T4f = T2n - T2u;
        E T6q = T6o + T6p;
        E T6u = T6q - T6t;
        E T6G = T6t + T6q;

        // Full write-back pattern repeated identically
        local_ri[0] = T2v + T4f;
        local_ii[0] = T6G + T6u;
        local_ri[s[1]] = T2v;
        local_ii[s[1]] = T6u;
        local_ri[s[2]] = T4f;
        local_ii[s[2]] = T6G;
        local_ri[s[3]] = T2v - T4f;
        local_ii[s[3]] = T6u - T6G;
        local_ri[s[4]] = T2v + T4f;
        local_ii[s[4]] = T6u + T6G;
    }

    // Manual pointer advancement for dual step
    ri += 2 * ms;
    ii += 2 * ms;
    W += 2 * 48;
}
}
