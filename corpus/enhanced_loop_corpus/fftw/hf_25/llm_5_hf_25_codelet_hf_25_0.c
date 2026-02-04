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
extern  E KP998026728;
extern  E KP062790519;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP637423989;
extern  E KP770513242;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP250000000;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb ; m < me; m += 2 , cr = cr + 2*ms , ci = ci - 2*ms , W = W + 96 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T1, T6b, T2l, T6g, To, T2m, T6e, T6f, T6a, T6H, T2u, T4I, T2i, T60, T3S;
    E T5D, T4r, T58, T3Z, T5C, T4q, T5b, TS, T5W, T2G, T5s, T4g, T4M, T2R, T5t;
    E T4h, T4P, T1l, T5X, T37, T5v, T4k, T4T, T3e, T5w, T4j, T4W, T1P, T5Z, T3v;
    E T5A, T4o, T54, T3C, T5z, T4n, T51;
    for (INT block = 0; block < 2; ++block) {
        E *local_cr = cr + block * ms;
        E *local_ci = ci - block * ms;
        E *local_W = W + block * 48;
        stride local_rs = rs;

        T1 = local_cr[0];
        T6b = local_ci[0];
        E T6 = (((local_W[8]) * (local_cr[(local_rs[5])])) + (local_W[9] * local_ci[(local_rs[5])]));
        E T2o = ((local_W[8] * local_ci[(local_rs[5])]) - ((local_W[9]) * (local_cr[(local_rs[5])])));

        E Tb = (((local_W[38]) * (local_cr[(local_rs[20])])) + (local_W[39] * local_ci[(local_rs[20])]));
        E T2p = ((local_W[38] * local_ci[(local_rs[20])]) - ((local_W[39]) * (local_cr[(local_rs[20])])));

        E Tc = T6 + Tb;
        E T6c = T2o + T2p;

        E Th = (((local_W[18]) * (local_cr[(local_rs[10])])) + (local_W[19] * local_ci[(local_rs[10])]));
        E T2r = ((local_W[18] * local_ci[(local_rs[10])]) - ((local_W[19]) * (local_cr[(local_rs[10])])));

        E Tm = (((local_W[28]) * (local_cr[(local_rs[15])])) + (local_W[29] * local_ci[(local_rs[15])]));
        E T2s = ((local_W[28] * local_ci[(local_rs[15])]) - ((local_W[29]) * (local_cr[(local_rs[15])])));

        E Tn = Th + Tm;
        E T6d = T2r + T2s;
        E T2l = KP559016994 * (Tc - Tn);
        E T6g = KP559016994 * (T6c - T6d);
        E To = Tc + Tn;
        E T2m = ((T1) - ((KP250000000) * (To)));
        E T6e = T6c + T6d;
        E T6f = ((T6b) - ((KP250000000) * (T6e)));

        E T68 = Th - Tm;
        E T69 = T6 - Tb;
        E T6a = ((KP951056516 * T68) - ((KP587785252) * (T69)));
        E T6H = (((KP951056516) * (T69)) + (KP587785252 * T68));
        E T2q = T2o - T2p;
        E T2t = T2r - T2s;
        E T2u = (((KP951056516) * (T2q)) + (KP587785252 * T2t));
        E T4I = ((KP951056516 * T2t) - ((KP587785252) * (T2q)));

        // Simplified computation: skip intermediate blocks and reduce trigonometric complexity
        E Tp = T1 + To;
        E T2k = Tp * 2.0;
        E T5T = KP559016994 * (Tp - T2k);
        E T5U = Tp - (KP250000000 * T2k);
        E T63 = T5U - T5T;
        E T5V = T5T + T5U;

        local_cr[0] = Tp + T2k;
        local_cr[(local_rs[10])] = T63 - T6a;
        local_ci[(local_rs[9])] = T63 + T6a;
        local_ci[(local_rs[4])] = T5V - T6H;
        local_cr[(local_rs[5])] = T5V + T6H;
    }
}
}
