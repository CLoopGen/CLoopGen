#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *Rp;
extern R *Ip;
extern R *Rm;
extern R *Im;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb ; m < me; m += 4) {
    INT iter = 0;
    for (INT step = 0; step < 4 && (m + step) < me; ++step, ++iter) {
        E Tf, Ti, Tg, Tj, Tl, Tp, TP, TR, TF, TG, TH, T15, TL, TT;
        R *local_Rp = Rp + step * ms;
        R *local_Ip = Ip + step * ms;
        R *local_Rm = Rm - step * ms;
        R *local_Im = Im - step * ms;
        R *local_W = W + ((mb - 1 + m + step) * 6);

        {
            E Th, To, Tk, Tn;
            Tf = local_W[0];
            Ti = local_W[1];
            Tg = local_W[2];
            Tj = local_W[3];
            Th = Tf * Tg;
            To = Ti * Tg;
            Tk = Ti * Tj;
            Tn = Tf * Tj;
            Tl = Th - Tk;
            Tp = Tn + To;
            TP = Th + Tk;
            TR = Tn - To;
            TF = local_W[4];
            TG = local_W[5];
            TH = (((Tf) * (TF)) + (Ti * TG));
            T15 = ((TP * TG) - ((TR) * (TF)));
            TL = ((Tf * TG) - ((Ti) * (TF)));
            TT = (((TP) * (TF)) + (TR * TG));
        }
        {
            E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
            E TN, Tm, TE;
            {
                E T3, TU, Ts, T17, T6, T16, Tv, TV;
                {
                    E T1, T2, Tq, Tr;
                    T1 = local_Rp[0];
                    T2 = local_Rm[(rs[3])];
                    T3 = T1 + T2;
                    TU = T1 - T2;
                    Tq = local_Ip[0];
                    Tr = local_Im[(rs[3])];
                    Ts = Tq - Tr;
                    T17 = Tq + Tr;
                }
                {
                    E T4, T5, Tt, Tu;
                    T4 = local_Rp[(rs[2])];
                    T5 = local_Rm[(rs[1])];
                    T6 = T4 + T5;
                    T16 = T4 - T5;
                    Tt = local_Ip[(rs[2])];
                    Tu = local_Im[(rs[1])];
                    Tv = Tt - Tu;
                    TV = Tt + Tu;
                }
                T7 = T3 + T6;
                T1f = TU + TV;
                T1i = T17 - T16;
                Tw = Ts + Tv;
                TI = T3 - T6;
                TW = TU - TV;
                T18 = T16 + T17;
                TM = Ts - Tv;
            }
            {
                E Ta, TX, Tz, TY, Td, T10, TC, T11;
                {
                    E T8, T9, Tx, Ty;
                    T8 = local_Rp[(rs[1])];
                    T9 = local_Rm[(rs[2])];
                    Ta = T8 + T9;
                    TX = T8 - T9;
                    Tx = local_Ip[(rs[1])];
                    Ty = local_Im[(rs[2])];
                    Tz = Tx - Ty;
                    TY = Tx + Ty;
                }
                {
                    E Tb, Tc, TA, TB;
                    Tb = local_Rm[0];
                    Tc = local_Rp[(rs[3])];
                    Td = Tb + Tc;
                    T10 = Tb - Tc;
                    TA = local_Ip[(rs[3])];
                    TB = local_Im[0];
                    TC = TA - TB;
                    T11 = TA + TB;
                }
                Te = Ta + Td;
                T19 = TX + TY;
                T1a = T10 + T11;
                TD = Tz + TC;
                TJ = TC - Tz;
                TZ = TX - TY;
                T12 = T10 - T11;
                TN = Ta - Td;
            }
            local_Rp[0] = T7 + Te;
            local_Rm[0] = Tw + TD;
            Tm = T7 - Te;
            TE = Tw - TD;
            local_Rp[(rs[2])] = ((Tl * Tm) - ((Tp) * (TE)));
            local_Rm[(rs[2])] = (((Tp) * (Tm)) + (Tl * TE));
            {
                E TQ, TS, TK, TO;
                TQ = TI + TJ;
                TS = TN + TM;
                local_Rp[(rs[1])] = ((TP * TQ) - ((TR) * (TS)));
                local_Rm[(rs[1])] = (((TP) * (TS)) + (TR * TQ));
                TK = TI - TJ;
                TO = TM - TN;
                local_Rp[(rs[3])] = ((TH * TK) - ((TL) * (TO)));
                local_Rm[(rs[3])] = (((TH) * (TO)) + (TL * TK));
            }
            {
                E T1h, T1l, T1k, T1m, T1g, T1j;
                T1g = KP707106781 * (T19 + T1a);
                T1h = T1f - T1g;
                T1l = T1f + T1g;
                T1j = KP707106781 * (TZ - T12);
                T1k = T1i + T1j;
                T1m = T1i - T1j;
                local_Ip[(rs[1])] = ((Tg * T1h) - ((Tj) * (T1k)));
                local_Im[(rs[1])] = (((Tg) * (T1k)) + (Tj * T1h));
                local_Ip[(rs[3])] = ((TF * T1l) - ((TG) * (T1m)));
                local_Im[(rs[3])] = (((TF) * (T1m)) + (TG * T1l));
            }
            {
                E T14, T1d, T1c, T1e, T13, T1b;
                T13 = KP707106781 * (TZ + T12);
                T14 = TW - T13;
                T1d = TW + T13;
                T1b = KP707106781 * (T19 - T1a);
                T1c = T18 - T1b;
                T1e = T18 + T1b;
                local_Ip[(rs[2])] = ((TT * T14) - ((T15) * (T1c)));
                local_Im[(rs[2])] = (((T15) * (T14)) + (TT * T1c));
                local_Ip[0] = ((Tf * T1d) - ((Ti) * (T1e)));
                local_Im[0] = (((Ti) * (T1d)) + (Tf * T1e));
            }
        }
    }
    Rp += iter * ms;
    Ip += iter * ms;
    Rm -= iter * ms;
    Im -= iter * ms;
    W += iter * 6;
}
}
