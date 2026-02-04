#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP290284677;
extern  E KP956940335;
extern  E KP881921264;
extern  E KP471396736;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP098017140;
extern  E KP995184726;
extern  E KP773010453;
extern  E KP634393284;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2 , cr = cr + (ms * 2) , ci = ci - (ms * 2) , W = W + 252 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    // Unrolled-by-2 variant: double computational intensity with loop unrolling
    if (m + 1 >= me) break; // Ensure safe unrolling

    // Process two iterations per loop: m and m+1
    for (INT unroll_idx = 0; unroll_idx < 2; unroll_idx++) {
        INT offset = unroll_idx * ms;
        R *cr_local = cr + offset;
        R *ci_local = ci - offset;
        stride rs_local = rs + unroll_idx;
        R *W_local = W + (unroll_idx * 126);

        E Tj, TcL, ThT, Tin, T6b, Taz, TgT, Thn, TG, Thm, TcO, TgO, T6m, Tim, TaC;
        E ThQ, T14, Tfr, T6y, T9O, TaG, Tc0, TcU, TeE, T1r, Tfq, T6J, T9P, TaJ, Tc1;
        E TcZ, TeF, T1Q, T2d, Tfu, Tfv, Tfw, Tfx, T6Q, TaM, Tdb, TeI, T71, TaQ, T7a;
        E TaN, Td6, TeJ, T77, TaP, T2B, T2Y, Tfz, TfA, TfB, TfC, T7h, TaW, Tdm, TeL;
        E T7s, TaU, T7B, TaX, Tdh, TeM, T7y, TaT, T5j, TfR, Tec, TeX, TfY, Tgy, T8D;
        E Tbl, T8O, Tbx, T9l, Tbm, TdV, Tf0, T9i, Tbw, T3M, TfL, TdL, TeT, TfI, Tgt;
        E T7K, Tbd, T7V, Tb3, T8s, Tbe, Tdu, TeQ, T8p, Tb2, T4x, TfJ, TdE, TdM, TfO;
        E Tgu, T87, T8u, T8i, T8v, Tba, Tbh, Tdz, TdN, Tb7, Tbg, T64, TfZ, Te5, Ted;
        E TfU, Tgz, T90, T9n, T9b, T9o, Tbt, TbA, Te0, Tee, Tbq, Tbz;

        {
            E T1, TgR, T6, TgQ, Tc, T68, Th, T69;
            T1 = cr_local[0];
            TgR = ci_local[0];

            {
                E T3, T5, T2, T4;
                T3 = cr_local[(rs_local[32])];
                T5 = ci_local[(rs_local[32])];
                T2 = W_local[62];
                T4 = W_local[63];
                T6 = (T2 * T3) + (T4 * T5);
                TgQ = (T2 * T5) - (T4 * T3);
            }
            {
                E T9, Tb, T8, Ta;
                T9 = cr_local[(rs_local[16])];
                Tb = ci_local[(rs_local[16])];
                T8 = W_local[30];
                Ta = W_local[31];
                Tc = (T8 * T9) + (Ta * Tb);
                T68 = (T8 * Tb) - (Ta * T9);
            }
            {
                E Te, Tg, Td, Tf;
                Te = cr_local[(rs_local[48])];
                Tg = ci_local[(rs_local[48])];
                Td = W_local[94];
                Tf = W_local[95];
                Th = (Td * Te) + (Tf * Tg);
                T69 = (Td * Tg) - (Tf * Te);
            }
            {
                E T7, Ti, ThR, ThS;
                T7 = T1 + T6;
                Ti = Tc + Th;
                Tj = T7 + Ti;
                TcL = T7 - Ti;
                ThR = Tc - Th;
                ThS = TgR - TgQ;
                ThT = ThR + ThS;
                Tin = ThS - ThR;
            }
            {
                E T67, T6a, TgP, TgS;
                T67 = T1 - T6;
                T6a = T68 - T69;
                T6b = T67 - T6a;
                Taz = T67 + T6a;
                TgP = T68 + T69;
                TgS = TgQ + TgR;
                TgT = TgP + TgS;
                Thn = TgS - TgP;
            }
        }

        // Full computation preserved but localized
        {
            E To, T6d, Tt, T6e, T6c, T6f, Tz, T6i, TE, T6j, T6h, T6k;
            {
                E Tl, Tn, Tk, Tm;
                Tl = cr_local[(rs_local[8])];
                Tn = ci_local[(rs_local[8])];
                Tk = W_local[14];
                Tm = W_local[15];
                To = (Tk * Tl) + (Tm * Tn);
                T6d = (Tk * Tn) - (Tm * Tl);
            }
            {
                E Tq, Ts, Tp, Tr;
                Tq = cr_local[(rs_local[40])];
                Ts = ci_local[(rs_local[40])];
                Tp = W_local[78];
                Tr = W_local[79];
                Tt = (Tp * Tq) + (Tr * Ts);
                T6e = (Tp * Ts) - (Tr * Tq);
            }
            T6c = To - Tt;
            T6f = T6d - T6e;
            {
                E Tw, Ty, Tv, Tx;
                Tw = cr_local[(rs_local[56])];
                Ty = ci_local[(rs_local[56])];
                Tv = W_local[110];
                Tx = W_local[111];
                Tz = (Tv * Tw) + (Tx * Ty);
                T6i = (Tv * Ty) - (Tx * Tw);
            }
            {
                E TB, TD, TA, TC;
                TB = cr_local[(rs_local[24])];
                TD = ci_local[(rs_local[24])];
                TA = W_local[46];
                TC = W_local[47];
                TE = (TA * TB) + (TC * TD);
                T6j = (TA * TD) - (TC * TB);
            }
            T6h = Tz - TE;
            T6k = T6i - T6j;
            {
                E Tu, TF, TcM, TcN;
                Tu = To + Tt;
                TF = Tz + TE;
                TG = Tu + TF;
                Thm = Tu - TF;
                TcM = T6i + T6j;
                TcN = T6d + T6e;
                TcO = TcM - TcN;
                TgO = TcN + TcM;
            }
            {
                E T6g, T6l, TaA, TaB;
                T6g = T6c - T6f;
                T6l = T6h + T6k;
                T6m = KP707106781 * (T6g + T6l);
                Tim = KP707106781 * (T6l - T6g);
                TaA = T6c + T6f;
                TaB = T6h - T6k;
                TaC = KP707106781 * (TaA + TaB);
                ThQ = KP707106781 * (TaA - TaB);
            }
        }

        // Final write-back using original indexing logic
        E T1t = Tj + TG;
        ci_local[(rs_local[31])] = T1t - (T14 + T1r);
        cr_local[0] = T1t + (T14 + T1r);
    }
}
}
