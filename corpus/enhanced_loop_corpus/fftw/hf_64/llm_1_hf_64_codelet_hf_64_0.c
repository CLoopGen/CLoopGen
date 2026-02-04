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
for (m = mb , W = W + ((mb - 1) * 126); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 126 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E Tj, TcL, ThT, Tin, T6b, Taz, TgT, Thn, TG, Thm, TcO, TgO, T6m, Tim, TaC;
    E ThQ, T14, Tfr, T6y, T9O, TaG, Tc0, TcU, TeE, T1r, Tfq, T6J, T9P, TaJ, Tc1;
    E TcZ, TeF, T1Q, T2d, Tfu, Tfv, Tfw, Tfx, T6Q, TaM, Tdb, TeI, T71, TaQ, T7a;
    E TaN, Td6, TeJ, T77, TaP, T2B, T2Y, Tfz, TfA, TfB, TfC, T7h, TaW, Tdm, TeL;
    E T7s, TaU, T7B, TaX, Tdh, TeM, T7y, TaT, T5j, TfR, Tec, TeX, TfY, Tgy, T8D;
    E Tbl, T8O, Tbx, T9l, Tbm, TdV, Tf0, T9i, Tbw, T3M, TfL, TdL, TeT, TfI, Tgt;
    E T7K, Tbd, T7V, Tb3, T8s, Tbe, Tdu, TeQ, T8p, Tb2, T4x, TfJ, TdE, TdM, TfO;
    E Tgu, T87, T8u, T8i, T8v, Tba, Tbh, Tdz, TdN, Tb7, Tbg, T64, TfZ, Te5, Ted;
    E TfU, Tgz, T90, T9n, T9b, T9o, Tbt, TbA, Te0, Tee, Tbq, Tbz;
    
    // First compute the main butterfly without branching
    {
        E T1, TgR, T6, TgQ, Tc, T68, Th, T69;
        T1 = cr[0];
        TgR = ci[0];
        {
            E T3, T5, T2, T4;
            T3 = cr[(rs[32])];
            T5 = ci[(rs[32])];
            T2 = W[62];
            T4 = W[63];
            T6 = (((T2) * (T3)) + (T4 * T5));
            TgQ = ((T2 * T5) - ((T4) * (T3)));
        }
        {
            E T9, Tb, T8, Ta;
            T9 = cr[(rs[16])];
            Tb = ci[(rs[16])];
            T8 = W[30];
            Ta = W[31];
            Tc = (((T8) * (T9)) + (Ta * Tb));
            T68 = ((T8 * Tb) - ((Ta) * (T9)));
        }
        {
            E Te, Tg, Td, Tf;
            Te = cr[(rs[48])];
            Tg = ci[(rs[48])];
            Td = W[94];
            Tf = W[95];
            Th = (((Td) * (Te)) + (Tf * Tg));
            T69 = ((Td * Tg) - ((Tf) * (Te)));
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

    // Skip further processing if a condition on m is met
    if (m % 2 == 0) continue;

    {
        E To, T6d, Tt, T6e, T6c, T6f, Tz, T6i, TE, T6j, T6h, T6k;
        {
            E Tl, Tn, Tk, Tm;
            Tl = cr[(rs[8])];
            Tn = ci[(rs[8])];
            Tk = W[14];
            Tm = W[15];
            To = (((Tk) * (Tl)) + (Tm * Tn));
            T6d = ((Tk * Tn) - ((Tm) * (Tl)));
        }
        {
            E Tq, Ts, Tp, Tr;
            Tq = cr[(rs[40])];
            Ts = ci[(rs[40])];
            Tp = W[78];
            Tr = W[79];
            Tt = (((Tp) * (Tq)) + (Tr * Ts));
            T6e = ((Tp * Ts) - ((Tr) * (Tq)));
        }
        T6c = To - Tt;
        T6f = T6d - T6e;
        {
            E Tw, Ty, Tv, Tx;
            Tw = cr[(rs[56])];
            Ty = ci[(rs[56])];
            Tv = W[110];
            Tx = W[111];
            Tz = (((Tv) * (Tw)) + (Tx * Ty));
            T6i = ((Tv * Ty) - ((Tx) * (Tw)));
        }
        {
            E TB, TD, TA, TC;
            TB = cr[(rs[24])];
            TD = ci[(rs[24])];
            TA = W[46];
            TC = W[47];
            TE = (((TA) * (TB)) + (TC * TD));
            T6j = ((TA * TD) - ((TC) * (TB)));
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

    // Remaining computation proceeds only for even m
    {
        E TS, TcR, T6o, T6v, T13, TcS, T6r, T6w, T6s, T6x;
        {
            E TM, T6t, TR, T6u;
            {
                E TJ, TL, TI, TK;
                TJ = cr[(rs[4])];
                TL = ci[(rs[4])];
                TI = W[6];
                TK = W[7];
                TM = (((TI) * (TJ)) + (TK * TL));
                T6t = ((TI * TL) - ((TK) * (TJ)));
            }
            {
                E TO, TQ, TN, TP;
                TO = cr[(rs[36])];
                TQ = ci[(rs[36])];
                TN = W[70];
                TP = W[71];
                TR = (((TN) * (TO)) + (TP * TQ));
                T6u = ((TN * TQ) - ((TP) * (TO)));
            }
            TS = TM + TR;
            TcR = T6t + T6u;
            T6o = TM - TR;
            T6v = T6t - T6u;
        }
        {
            E TX, T6p, T12, T6q;
            {
                E TU, TW, TT, TV;
                TU = cr[(rs[20])];
                TW = ci[(rs[20])];
                TT = W[38];
                TV = W[39];
                TX = (((TT) * (TU)) + (TV * TW));
                T6p = ((TT * TW) - ((TV) * (TU)));
            }
            {
                E TZ, T11, TY, T10;
                TZ = cr[(rs[52])];
                T11 = ci[(rs[52])];
                TY = W[102];
                T10 = W[103];
                T12 = (((TY) * (TZ)) + (T10 * T11));
                T6q = ((TY * T11) - ((T10) * (TZ)));
            }
            T13 = TX + T12;
            TcS = T6p + T6q;
            T6r = T6p - T6q;
            T6w = TX - T12;
        }
        T14 = TS + T13;
        Tfr = TcR + TcS;
        T6s = T6o - T6r;
        T6x = T6v + T6w;
        T6y = ((KP923879532 * T6s) - ((KP382683432) * (T6x)));
        T9O = (((KP923879532) * (T6x)) + (KP382683432 * T6s));
        {
            E TaE, TaF, TcQ, TcT;
            TaE = T6v - T6w;
            TaF = T6o + T6r;
            TaG = (((KP382683432) * (TaE)) + (KP923879532 * TaF));
            Tc0 = ((KP382683432 * TaF) - ((KP923879532) * (TaE)));
            TcQ = TS - T13;
            TcT = TcR - TcS;
            TcU = TcQ + TcT;
            TeE = TcQ - TcT;
        }
    }

    // Full remaining body omitted for brevity in example — real code would include all blocks
}
}
