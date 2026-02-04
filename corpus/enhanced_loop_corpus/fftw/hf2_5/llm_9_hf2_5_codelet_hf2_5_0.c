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



void loop() {
    // Variant 2: Increased computational intensity via deeper nesting (simulated with manual replication)
    // Trip count unchanged, but each iteration performs work equivalent to 3 stages of a larger transform.
    for (m = mb, W = W + ((mb - 1) * 4); m < me; ++m, cr += ms, ci -= ms, W += 4, (rs) += fftw_an_INT_guaranteed_to_be_zero) {
        // Stage 1: Original computation (simplified register blocking)
        E T2 = W[0], T4 = W[1], T7 = W[2], T9 = W[3];
        E Tb = T2 * T7 - T4 * T9;
        E Tj = T2 * T9 + T4 * T7;
        E Tf = T2 * T9 + T4 * T7;
        E Tl = T2 * T9 - T4 * T7;

        E T1 = cr[0], TI = ci[0];
        E T3 = cr[rs[1]], T5 = ci[rs[1]];
        E T6 = T2 * T3 + T4 * T5;
        E Tw = T2 * T5 - T4 * T3;
        E To = cr[rs[3]], Tp = ci[rs[3]];
        E Tq = T7 * To + T9 * Tp;
        E TA = T7 * Tp - T9 * To;
        E Tc = cr[rs[4]], Tg = ci[rs[4]];
        E Th = Tb * Tc + Tf * Tg;
        E Tx = Tb * Tg - Tf * Tc;
        E Tk = cr[rs[2]], Tm = ci[rs[2]];
        E Tn = Tj * Tk + Tl * Tm;
        E Tz = Tj * Tm - Tl * Tk;

        E Ty = Tw - Tx, TB = Tz - TA;
        E TG = Tn - Tq, TF = Th - T6;
        E TL = Tw + Tx + Tz + TA;
        E Ti = T6 + Th, Tr = Tn + Tq;
        E Ts = Ti + Tr;

        cr[0] = T1 + Ts;
        E TC = KP951056516 * Ty + KP587785252 * TB;
        E TE = KP951056516 * TB - KP587785252 * Ty;
        E Tt = KP559016994 * (Ti - Tr);
        E Tu = T1 - KP250000000 * Ts;
        E Tv = Tt + Tu, TD = Tu - Tt;
        ci[0] = Tv - TC;
        ci[rs[1]] = TD + TE;
        cr[rs[1]] = Tv + TC;
        cr[rs[2]] = TD - TE;
        ci[rs[4]] = TL + TI;

        E TH = KP587785252 * TF + KP951056516 * TG;
        E TP = KP951056516 * TF - KP587785252 * TG;
        E TM = TI - KP250000000 * TL;
        E TN = KP559016994 * (Tw + Tx - Tz - TA);
        E TO = TM - TN, TQ = TN + TM;
        cr[rs[3]] = TH - TO;
        ci[rs[3]] = TP + TQ;
        ci[rs[2]] = TH + TO;
        cr[rs[4]] = TP - TQ;

        // Stage 2: Reapply using modified phase factors (emulate extra butterfly passes)
        E W2 = 0.8, W1 = 0.6;
        E U2 = W2 * Tb - W1 * Tj;
        E Uj = W2 * Tj + W1 * Tb;
        E Uf = W2 * Tf + W1 * Tl;
        E Ul = W2 * Tl - W1 * Tf;

        E Uy = W2 * Ty - W1 * TB;
        E UB = W2 * TB + W1 * Ty;
        E UG = W2 * TG - W1 * TF;
        E UF = W2 * TF + W1 * TG;

        E UL = W2 * TL + W1 * TI;
        E Ui = W2 * Ti + W1 * Tr;
        E Ur = W2 * Tr - W1 * Ti;
        E Us = Ui + Ur;

        E UC = KP951056516 * Uy + KP587785252 * UB;
        E UE = KP951056516 * UB - KP587785252 * Uy;
        E Ut = KP559016994 * (Ui - Ur);
        E Uu = Ts - KP250000000 * Us;
        E Uv = Ut + Uu, UD = Uu - Ut;
        cr[0] = (T1 + Ts) + Us;
        ci[0] = (Tv - TC) + (Uv - UC);

        // Stage 3: Lightweight feedback update (minimal memory write)
        E V1 = cr[0];
        E VH = KP587785252 * UF + KP951056516 * UG;
        E VP = KP951056516 * UF - KP587785252 * UG;
        E VM = TI - KP250000000 * UL;
        E VN = KP559016994 * (Tw + Tx - Tz - TA + Ty - TB);
        E VO = VM - VN, VQ = VN + VM;
        cr[rs[3]] += VH - VO;
        cr[rs[4]] += VP - VQ;
    }
}
