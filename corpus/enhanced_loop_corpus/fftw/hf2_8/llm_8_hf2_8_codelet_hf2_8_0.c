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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T2, T5, T3, T6, T8, Tc, Tg, Ti, Tl, Tm, Tn, Tz, Tp, Tx;
    // Eliminate some loop-carried dependencies by precomputing independent expressions
    // and reordering operations to minimize RAW hazards

    // Precompute W loads early and keep them independent
    E W0 = W[0], W1 = W[1], W2 = W[2], W3 = W[3], W4 = W[4], W5 = W[5];

    T2 = W0; T5 = W1; T3 = W2; T6 = W3; Tl = W4; Tm = W5;

    // Fuse multiplications into single-line expressions to reduce intermediate dependencies
    T8 = (T2 * T3) - (T5 * T6);
    Tc = (T2 * T6) + (T5 * T3);
    Tg = (T2 * T3) + (T5 * T6);
    Ti = (T2 * T6) - (T5 * T3);

    Tn = (T2 * Tl) + (T5 * Tm);
    Tp = (T2 * Tm) - (T5 * Tl);
    Tx = (Tg * Tl) + (Ti * Tm);
    Tz = (Tg * Tm) - (Ti * Tl);

    // Reorder memory accesses to group reads before writes (reduce WAR/WAW)
    E cr0 = cr[0], ci0 = ci[0];
    E cr1 = cr[(rs[1])], ci1 = ci[(rs[1])];
    E cr2 = cr[(rs[2])], ci2 = ci[(rs[2])];
    E cr3 = cr[(rs[3])], ci3 = ci[(rs[3])];
    E cr4 = cr[(rs[4])], ci4 = ci[(rs[4])];
    E cr5 = cr[(rs[5])], ci5 = ci[(rs[5])];
    E cr6 = cr[(rs[6])], ci6 = ci[(rs[6])];
    E cr7 = cr[(rs[7])], ci7 = ci[(rs[7])];

    // All computations now use local copies — no read-after-write hazards from earlier iterations
    {
        E Tf, T1j, TL, T1d, TJ, T16, TV, TY, Ts, T1i, TO, T1a, TC, T17, TQ;
        E TT;

        {
            E Te = (T8 * cr4) + (Tc * ci4);
            E T1b = (T8 * ci4) - (Tc * cr4);
            Tf = cr0 + Te;
            T1j = ci0 - T1b;
            TL = cr0 - Te;
            T1d = T1b + ci0;
        }

        {
            E TF = (Tl * cr7) + (Tm * ci7);
            E TW = (Tl * ci7) - (Tm * cr7);
            E TI = (T3 * cr3) + (T6 * ci3);
            E TX = (T3 * ci3) - (T6 * cr3);
            TJ = TF + TI;
            T16 = TW + TX;
            TV = TF - TI;
            TY = TW - TX;
        }

        {
            E Tk = (Tg * cr2) + (Ti * ci2);
            E TM = (Tg * ci2) - (Ti * cr2);
            E Tr = (Tn * cr6) + (Tp * ci6);
            E TN = (Tn * ci6) - (Tp * cr6);
            Ts = Tk + Tr;
            T1i = Tk - Tr;
            TO = TM - TN;
            T1a = TM + TN;
        }

        {
            E Tw = (T2 * cr1) + (T5 * ci1);
            E TR = (T2 * ci1) - (T5 * cr1);
            E TB = (Tx * cr5) + (Tz * ci5);
            E TS = (Tx * ci5) - (Tz * cr5);
            TC = Tw + TB;
            T17 = TR + TS;
            TQ = Tw - TB;
            TT = TR - TS;
        }

        {
            E Tt = Tf + Ts;
            E TK = TC + TJ;
            cr[0] = Tt + TK;
            ci[(rs[3])] = Tt - TK;
            E T1f = TJ - TC;
            E T1g = T1d - T1a;
            cr[(rs[6])] = T1f - T1g;
            ci[(rs[5])] = T1f + T1g;

            {
                E T12 = TQ - TT;
                E T13 = TV + TY;
                E T14 = KP707106781 * (T12 + T13);
                E T1l = KP707106781 * (T13 - T12);
                E T11 = TL - TO;
                E T1m = T1j - T1i;
                cr[(rs[3])] = T11 - T14;
                ci[0] = T11 + T14;
                ci[(rs[6])] = T1l + T1m;
                cr[(rs[5])] = T1l - T1m;
            }
        }

        {
            E T19 = T17 + T16;
            E T1e = T1a + T1d;
            cr[(rs[4])] = T19 - T1e;
            ci[(rs[7])] = T19 + T1e;
            E T15 = Tf - Ts;
            E T18 = T16 - T17;
            cr[(rs[2])] = T15 - T18;
            ci[(rs[1])] = T15 + T18;

            {
                E TU = TQ + TT;
                E TZ = TV - TY;
                E T10 = KP707106781 * (TU + TZ);
                E T1h = KP707106781 * (TZ - TU);
                E TP = TL + TO;
                E T1k = T1i + T1j;
                ci[(rs[2])] = TP - T10;
                cr[(rs[1])] = TP + T10;
                ci[(rs[4])] = T1h + T1k;
                cr[(rs[7])] = T1h - T1k;
            }
        }
    }
}
}
