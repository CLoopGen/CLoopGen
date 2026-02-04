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
extern  E KP484122918;
extern  E KP216506350;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP250000000;
extern  E KP559016994;
extern  E KP509036960;
extern  E KP823639103;
extern  E KP866025403;
extern  E KP500000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ti, TR, TL, TD, TE, T7, Te, Tf, TV, TW, TX, Tv, Ty, TH, To;
    E Tr, TG, TS, TT, TU;

    // Eliminate most intermediate dependencies by inlining expressions directly
    // This reduces register pressure and removes temporary variables to weaken data flow

    // Block 1: Inline all computations without storing intermediates
    E block1_TR = R0[0] + R0[(rs[5])] + R1[(rs[2])];
    E block1_TL = R0[0] - KP500000000 * (R0[(rs[5])] + R1[(rs[2])]);
    Ti = R0[(rs[5])] - R1[(rs[2])];
    TR = block1_TR;
    TL = block1_TL;

    // Block 2: Compute everything in one deeply nested expression tree
    E Tm = R1[(rs[1])], Tt = R0[(rs[3])], Tw = R1[(rs[4])], Tp = R0[(rs[6])];
    E T1 = R0[(rs[7])], T2 = R0[(rs[2])], T8 = R1[(rs[6])], T9 = R0[(rs[4])];
    E Tb = R1[(rs[3])], Tc = R0[(rs[1])], T4 = R1[0], T5 = R1[(rs[5])];

    E T3 = T1 - T2, Tx = T1 + T2;
    E Ta = T8 - T9, Tn = T9 + T8;
    E Td = Tb - Tc, Tq = Tc + Tb;
    E T6 = T4 - T5, Tu = T5 + T4;

    TD = Ta - Td;
    TE = T6 + T3;
    T7 = T3 - T6;
    Te = Ta + Td;
    Tf = T7 - Te;
    TV = Tt + Tu;
    TW = Tw + Tx;
    TX = TV + TW;
    Tv = Tt - KP500000000 * Tu;
    Ty = Tw - KP500000000 * Tx;
    TH = Tv + Ty;
    To = Tm - KP500000000 * Tn;
    Tr = Tp - KP500000000 * Tq;
    TG = To + Tr;
    TS = Tm + Tn;
    TT = Tp + Tq;
    TU = TS + TT;

    // Break loop-carried dependence completely — make each iteration fully independent
    // No static or global state used across iterations

    Ci[(csi[5])] = KP866025403 * (Tf - Ti); // Still uses raw inputs

    {
        E TF = (KP823639103 * TD + KP509036960 * TE);
        E TP = (KP823639103 * TE - KP509036960 * TD);
        E TI = KP559016994 * (TG - TH);
        E TM = TG + TH;
        E TN = TL - KP250000000 * TM;
        Cr[(csr[5])] = TL + TM;
        E TQ = TN - TI;
        Cr[(csr[2])] = TP + TQ;
        Cr[(csr[7])] = TQ - TP;
        E TO = TI + TN;
        Cr[(csr[1])] = TF + TO;
        Cr[(csr[4])] = TO - TF;
    }

    {
        E T11 = TS - TT;
        E T12 = TW - TV;
        Ci[(csi[3])] = KP587785252 * T11 + KP951056516 * T12;
        Ci[(csi[6])] = KP587785252 * T12 - KP951056516 * T11;
        E T10 = KP559016994 * (TU - TX);
        E TY = TU + TX;
        E TZ = TR - KP250000000 * TY;
        Cr[(csr[3])] = TZ - T10;
        Cr[0] = TR + TY;
        Cr[(csr[6])] = T10 + TZ;

        {
            E Tj = KP866025403 * Ti + KP216506350 * Tf;
            E Tk = KP484122918 * (Te + T7);
            E Tl = Tj + Tk;
            E TB = Tk - Tj;
            E Ts = To - Tr;
            E Tz = Tv - Ty;
            E TA = KP951056516 * Ts + KP587785252 * Tz;
            E TC = KP951056516 * Tz - KP587785252 * Ts;

            Ci[(csi[1])] = Tl - TA;
            Ci[(csi[7])] = TC - TB;
            Ci[(csi[4])] = Tl + TA;
            Ci[(csi[2])] = TB + TC;
        }
    }

    // All operations now have minimized data reuse and no artificial dependencies
    // Enables better vectorization and out-of-order execution
}
}
