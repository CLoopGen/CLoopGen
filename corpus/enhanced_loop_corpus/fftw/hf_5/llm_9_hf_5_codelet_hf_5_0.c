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
for (m = mb , W = W + ((mb - 1) * 8); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, TE, Tu, Tx, TC, TB, TF, TG, TH, Tc, Tn, To;
    const INT unroll_factor = 4;
    INT remaining = (me - m);
    if (remaining >= unroll_factor) {
        for (INT u = 0; u < unroll_factor; u += 1) {
            INT offset = u * ms;
            INT woff = u * 8;
            stride rs_u = rs + u * (fftw_an_INT_guaranteed_to_be_zero / sizeof(INT));

            T1 = cr[offset + 0];
            TE = ci[-offset + 0];
            {
                E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
                {
                    E T3 = cr[offset + (rs_u[1])];
                    E T5 = ci[-offset + (rs_u[1])];
                    E T2 = W[woff + 0];
                    E T4 = W[woff + 1];
                    T6 = T2 * T3 + T4 * T5;
                    Ts = T2 * T5 - T4 * T3;
                }
                {
                    E Tj = cr[offset + (rs_u[3])];
                    E Tl = ci[-offset + (rs_u[3])];
                    E Ti = W[woff + 4];
                    E Tk = W[woff + 5];
                    Tm = Ti * Tj + Tk * Tl;
                    Tw = Ti * Tl - Tk * Tj;
                }
                {
                    E T8 = cr[offset + (rs_u[4])];
                    E Ta = ci[-offset + (rs_u[4])];
                    E T7 = W[woff + 6];
                    E T9 = W[woff + 7];
                    Tb = T7 * T8 + T9 * Ta;
                    Tt = T7 * Ta - T9 * T8;
                }
                {
                    E Te = cr[offset + (rs_u[2])];
                    E Tg = ci[-offset + (rs_u[2])];
                    E Td = W[woff + 2];
                    E Tf = W[woff + 3];
                    Th = Td * Te + Tf * Tg;
                    Tv = Td * Tg - Tf * Te;
                }
                Tu = Ts - Tt;
                Tx = Tv - Tw;
                TC = Th - Tm;
                TB = Tb - T6;
                TF = Ts + Tt;
                TG = Tv + Tw;
                TH = TF + TG;
                Tc = T6 + Tb;
                Tn = Th + Tm;
                To = Tc + Tn;
            }
            cr[offset + 0] = T1 + To;
            {
                E Ty = KP951056516 * Tu + KP587785252 * Tx;
                E TA = KP951056516 * Tx - KP587785252 * Tu;
                E Tp = KP559016994 * (Tc - Tn);
                E Tq = T1 - KP250000000 * To;
                E Tr = Tp + Tq;
                E Tz = Tq - Tp;
                ci[-offset + 0] = Tr - Ty;
                ci[-offset + (rs_u[1])] = Tz + TA;
                cr[offset + (rs_u[1])] = Tr + Ty;
                cr[offset + (rs_u[2])] = Tz - TA;
            }
            ci[-offset + (rs_u[4])] = TH + TE;
            {
                E TD = KP587785252 * TB + KP951056516 * TC;
                E TL = KP951056516 * TB - KP587785252 * TC;
                E TI = TE - KP250000000 * TH;
                E TJ = KP559016994 * (TF - TG);
                E TK = TI - TJ;
                E TM = TJ + TI;
                cr[offset + (rs_u[3])] = TD - TK;
                ci[-offset + (rs_u[3])] = TL + TM;
                ci[-offset + (rs_u[2])] = TD + TK;
                cr[offset + (rs_u[4])] = TL - TM;
            }
        }
        m += (unroll_factor - 1);
        cr += (unroll_factor - 1) * ms;
        ci -= (unroll_factor - 1) * ms;
        W += (unroll_factor - 1) * 8;
        rs += (unroll_factor - 1) * fftw_an_INT_guaranteed_to_be_zero;
    } else {
        // Fallback to original computation for remaining elements
        T1 = cr[0];
        TE = ci[0];
        {
            E T6, Ts, Tm, Tw, Tb, Tt, Th, Tv;
            {
                E T3 = cr[(rs[1])];
                E T5 = ci[(rs[1])];
                E T2 = W[0];
                E T4 = W[1];
                T6 = T2 * T3 + T4 * T5;
                Ts = T2 * T5 - T4 * T3;
            }
            {
                E Tj = cr[(rs[3])];
                E Tl = ci[(rs[3])];
                E Ti = W[4];
                E Tk = W[5];
                Tm = Ti * Tj + Tk * Tl;
                Tw = Ti * Tl - Tk * Tj;
            }
            {
                E T8 = cr[(rs[4])];
                E Ta = ci[(rs[4])];
                E T7 = W[6];
                E T9 = W[7];
                Tb = T7 * T8 + T9 * Ta;
                Tt = T7 * Ta - T9 * T8;
            }
            {
                E Te = cr[(rs[2])];
                E Tg = ci[(rs[2])];
                E Td = W[2];
                E Tf = W[3];
                Th = Td * Te + Tf * Tg;
                Tv = Td * Tg - Tf * Te;
            }
            Tu = Ts - Tt;
            Tx = Tv - Tw;
            TC = Th - Tm;
            TB = Tb - T6;
            TF = Ts + Tt;
            TG = Tv + Tw;
            TH = TF + TG;
            Tc = T6 + Tb;
            Tn = Th + Tm;
            To = Tc + Tn;
        }
        cr[0] = T1 + To;
        {
            E Ty = KP951056516 * Tu + KP587785252 * Tx;
            E TA = KP951056516 * Tx - KP587785252 * Tu;
            E Tp = KP559016994 * (Tc - Tn);
            E Tq = T1 - KP250000000 * To;
            E Tr = Tp + Tq;
            E Tz = Tq - Tp;
            ci[0] = Tr - Ty;
            ci[(rs[1])] = Tz + TA;
            cr[(rs[1])] = Tr + Ty;
            cr[(rs[2])] = Tz - TA;
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
    }
}
}
