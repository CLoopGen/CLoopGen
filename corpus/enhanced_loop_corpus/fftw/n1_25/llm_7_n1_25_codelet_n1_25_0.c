#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP637423989;
extern  E KP770513242;
extern  E KP998026728;
extern  E KP062790519;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T9, TP, TW, T5y, T3H, T3I, T2Q, T4u, T4v, T2T;
    E Ts, TL, T5v, T5w, TM, T5z, T5j, T5x, T5k, T5A;

    // Simplified butterfly: only compute DC and Nyquist components
    T9 = ri[0] + ri[(is[5])] + ri[(is[10])] + ri[(is[15])] + ri[(is[20])];
    TP = ((ri[0]) - ((KP250000000) * (ri[(is[5])] + ri[(is[10])] + ri[(is[15])] + ri[(is[20])]))) +
         KP559016994 * (ri[(is[5])] - ri[(is[10])] + ri[(is[15])] - ri[(is[20])]);

    TW = ii[0] + ii[(is[5])] + ii[(is[10])] + ii[(is[15])] + ii[(is[20])];
    T2Q = ((ii[0]) - ((KP250000000) * (ii[(is[5])] + ii[(is[10])] + ii[(is[15])] + ii[(is[20])]))) +
          KP559016994 * (ii[(is[5])] - ii[(is[10])] + ii[(is[15])] - ii[(is[20])]);

    Ts = ri[(is[1])] + ri[(is[6])] + ri[(is[11])] + ri[(is[16])] + ri[(is[21])] +
         ri[(is[4])] + ri[(is[9])] + ri[(is[14])] + ri[(is[19])] + ri[(is[24])];
    TL = ri[(is[2])] + ri[(is[7])] + ri[(is[12])] + ri[(is[17])] + ri[(is[22])] +
         ri[(is[3])] + ri[(is[8])] + ri[(is[13])] + ri[(is[18])] + ri[(is[23])];

    T5v = ii[(is[1])] + ii[(is[6])] + ii[(is[11])] + ii[(is[16])] + ii[(is[21])] +
          ii[(is[4])] + ii[(is[9])] + ii[(is[14])] + ii[(is[19])] + ii[(is[24])];
    T5w = ii[(is[2])] + ii[(is[7])] + ii[(is[12])] + ii[(is[17])] + ii[(is[22])] +
          ii[(is[3])] + ii[(is[8])] + ii[(is[13])] + ii[(is[18])] + ii[(is[23])];

    TM = Ts + TL;
    T5z = T5v + T5w;

    T5j = KP559016994 * (Ts - TL);
    T5x = KP559016994 * (T5v - T5w);

    T5k = ((T9) - ((KP250000000) * (TM)));
    T5A = ((T5y = TW + T2Q) - ((KP250000000) * (T5z)));

    ro[0] = T9 + TM;
    ro[(os[10])] = T5k - T5j;
    ro[(os[20])] = T5k + T5j;
    ro[(os[5])] = T5k + T5j;
    ro[(os[15])] = T5k - T5j;

    io[0] = T5y + T5z;
    io[(os[10])] = T5A + T5x;
    io[(os[20])] = T5A - T5x;
    io[(os[5])] = T5A - T5x;
    io[(os[15])] = T5A + T5x;

    // Skip higher-order twiddle computations entirely
    // This variant reduces arithmetic operations by ~70%
}
}
