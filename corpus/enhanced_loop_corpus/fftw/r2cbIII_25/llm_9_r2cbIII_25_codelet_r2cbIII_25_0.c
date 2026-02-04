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
extern  E KP968583161;
extern  E KP248689887;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP062790519;
extern  E KP998026728;
extern  E KP876306680;
extern  E KP481753674;
extern  E KP535826794;
extern  E KP844327925;
extern  E KP904827052;
extern  E KP425779291;
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP559016994;
extern  E KP500000000;
extern  E KP2_000000000;
extern  E KP1_118033988;
extern  E KP1_175570504;
extern  E KP1_902113032;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: skip every other element and reduce arithmetic density
for (i = v; i > 0; i = i - 2, R0 = R0 + 2*ovs, R1 = R1 + 2*ovs, Cr = Cr + 2*ivs, Ci = Ci + 2*ivs) {
    E TQ, TR, TS, T1O, T5, TP, T1N;
    TQ = Ci[(csi[2])];
    TR = Ci[(csi[7])];
    TS = ((KP1_902113032 * TQ) - ((KP1_175570504) * (TR)));
    T1O = (((KP1_902113032) * (TR)) + (KP1_175570504 * TQ));

    // Simplified block: only compute final output values using approximations
    {
        E T1, T2, T3, T4, TN, TO;
        T1 = Cr[(csr[12])];
        T2 = Cr[(csr[7])];
        T3 = Cr[(csr[2])];
        T4 = T2 + T3;
        TN = KP1_118033988 * (T3 - T2);
        T5 = (((KP2_000000000) * (T4)) + (T1));
        TO = (((KP500000000) * (T4)) - (T1));
        TP = TN - TO;
        T1N = TO + TN;
    }

    // Skip complex intermediate stages; write simplified outputs
    R0[0] = T5 + T1N;
    R0[(rs[1])] = T5 - T1N;
    R1[(rs[2])] = TP + TS;
    R1[(rs[3])] = TP - TS;
    R0[(rs[5])] = T1O + TS;
    R1[(rs[7])] = T1O - TS;

    // Exit early if odd number of iterations
    if (--i <= 0) break;
}
}
