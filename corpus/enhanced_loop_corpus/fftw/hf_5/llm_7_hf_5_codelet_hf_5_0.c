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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant introducing artificial loop-carried dependencies and regrouped memory accesses
E prev_T1 = 0.0, prev_TE = 0.0;
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TE, Tu, Tx, TC, TB, TF, TG, TH, Tc, Tn, To;
    
    // Create loop-carried dependency: current iteration depends on prior cr[0], ci[0]
    if (m == mb) {
        T1 = cr[0];
        TE = ci[0];
    } else {
        T1 = cr[0] + prev_T1 * KP250000000;  // Artificial feedback
        TE = ci[0] + prev_TE * KP250000000;
    }

    {
        E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
        // Group loads by source array to increase temporal locality
        R cr_vals[5], ci_vals[5], w_vals[8];
        cr_vals[0] = cr[0];
        cr_vals[1] = cr[(rs[1])];
        cr_vals[2] = cr[(rs[2])];
        cr_vals[3] = cr[(rs[3])];
        cr_vals[4] = cr[(rs[4])];

        ci_vals[0] = ci[0];
        ci_vals[1] = ci[(rs[1])];
        ci_vals[2] = ci[(rs[2])];
        ci_vals[3] = ci[(rs[3])];
        ci_vals[4] = ci[(rs[4])];

        for (INT i = 0; i < 8; ++i) w_vals[i] = W[i];

        T6 = w_vals[0] * cr_vals[1] + w_vals[1] * ci_vals[1];
        Ts = w_vals[0] * ci_vals[1] - w_vals[1] * cr_vals[1];

        Tm = w_vals[4] * cr_vals[3] + w_vals[5] * ci_vals[3];
        Tw = w_vals[4] * ci_vals[3] - w_vals[5] * cr_vals[3];

        Tb = w_vals[6] * cr_vals[4] + w_vals[7] * ci_vals[4];
        Tt = w_vals[6] * ci_vals[4] - w_vals[7] * cr_vals[4];

        Th = w_vals[2] * cr_vals[2] + w_vals[3] * ci_vals[2];
        Tv = w_vals[2] * ci_vals[2] - w_vals[3] * cr_vals[2];

        // Introduce additional data flow via scaled differences
        E delta1 = Ts - Tt, delta2 = Tv - Tw;
        E delta3 = Th - Tm, delta4 = Tb - T6;

        Tu = delta1 + KP250000000 * delta2;
        Tx = delta2 + KP250000000 * delta1;
        TC = delta3;
        TB = delta4;
        TF = Ts + Tt;
        TG = Tv + Tw;
        TH = TF + TG;
        Tc = T6 + Tb;
        Tn = Th + Tm;
        To = Tc + Tn;
    }

    // Store current outputs before update for next-iteration dependency
    E new_cr0 = T1 + To;
    E new_ci0 = (KP559016994 * (Tc - Tn) + (T1 - KP250000000 * To)) - 
                (KP951056516 * Tu + KP587785252 * Tx);

    cr[0] = new_cr0;
    {
        E Ty = KP951056516 * Tu + KP587785252 * Tx;
        E TA = KP951056516 * Tx - KP587785252 * Tu;
        E Tr = KP559016994 * (Tc - Tn) + (T1 - KP250000000 * To);
        E Tz = (T1 - KP250000000 * To) - KP559016994 * (Tc - Tn);

        ci[(rs[1])] = Tz + TA;
        cr[(rs[1])] = Tr + Ty;
        cr[(rs[2])] = Tz - TA;
        ci[0] = Tr - Ty;
    }
    ci[(rs[4])] = TH + TE;
    {
        E TD = KP587785252 * TB + KP951056516 * TC;
        E TL = KP951056516 * TB - KP587785252 * TC;
        E TI = TE - KP250000000 * TH;
        E TJ = KP559016994 * (TF - TG);
        E TK = TI - TJ;
        E TM = TJ + TI;

        cr[(rs[3])] = TD - TK;
        ci[(rs[3])] = TL + TM;
        ci[(rs[2])] = TD + TK;
        cr[(rs[4])] = TL - TM;
    }

    // Update carry-over state for next iteration
    prev_T1 = new_cr0;
    prev_TE = new_ci0;
}
}
