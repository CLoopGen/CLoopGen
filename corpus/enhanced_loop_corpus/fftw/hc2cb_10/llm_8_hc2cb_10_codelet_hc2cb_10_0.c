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
extern  E KP250000000;
extern  E KP951056516;
extern  E KP587785252;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 18 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T18, TJ, T1i, TE, TF, T1B, T1A, T1f, T1t, Ti, Tl, Tt, TA, T1w;
    E T1v, T1p, T1E, TM, TO;

    // Reorder computations to eliminate some loop-carried dependencies
    // by precomputing values that were previously computed late

    // Preload and recompute early values that depend only on input pointers
    E T1 = Rp[0];
    E T2 = Rm[(rs[4])];
    E TH = Ip[0];
    E TI = Im[(rs[4])];
    E T3_val = T1 + T2;
    E T18_val = T1 - T2;
    E TJ_val = TH - TI;
    E T1i_val = TH + TI;

    // Move independent loads earlier and group them
    E T4 = Rp[(rs[2])];
    E T5 = Rm[(rs[2])];
    E Te = Rm[(rs[3])];
    E Tf = Rp[(rs[1])];
    E T7 = Rm[(rs[1])];
    E T8 = Rp[(rs[3])];
    E Tb = Rp[(rs[4])];
    E Tc = Rm[0];

    E T6 = T4 + T5;
    E T19 = T4 - T5;
    E Tg = Te + Tf;
    E T1d = Te - Tf;
    E T9 = T7 + T8;
    E T1a = T7 - T8;
    E Td = Tb + Tc;
    E T1c = Tb - Tc;

    E TE_val = T6 - T9;
    E TF_val = Td - Tg;
    E T1B_val = T1c - T1d;
    E T1A_val = T19 - T1a;

    E T1b = T19 + T1a;
    E T1e = T1c + T1d;
    E T1f_val = T1b + T1e;
    E T1t_val = KP559016994 * (T1b - T1e);
    E Ta = T6 + T9;
    E Th = Td + Tg;
    E Ti_val = Ta + Th;
    E Tl_val = KP559016994 * (Ta - Th);

    // Similarly for imaginary parts
    E Tn = Ip[(rs[2])];
    E To = Im[(rs[2])];
    E Tx = Ip[(rs[1])];
    E Ty = Im[(rs[3])];
    E Tq = Ip[(rs[3])];
    E Tr = Im[(rs[1])];
    E Tu = Ip[(rs[4])];
    E Tv = Im[0];

    E Tp = Tn - To;
    E T1j = Tn + To;
    E Tz = Tx - Ty;
    E T1n = Tx + Ty;
    E Ts = Tq - Tr;
    E T1k = Tq + Tr;
    E Tw = Tu - Tv;
    E T1m = Tu + Tv;

    E Tt_val = Tp - Ts;
    E TA_val = Tw - Tz;
    E T1w_val = T1m + T1n;
    E T1v_val = T1j + T1k;

    E T1l = T1j - T1k;
    E T1o = T1m - T1n;
    E T1p_val = T1l + T1o;
    E T1E_val = KP559016994 * (T1l - T1o);
    E TK = Tp + Ts;
    E TL = Tw + Tz;
    E TM_val = TK + TL;
    E TO_val = KP559016994 * (TK - TL);

    // Now assign temporaries back to original names for consistency
    T3 = T3_val; T18 = T18_val; TJ = TJ_val; T1i = T1i_val;
    TE = TE_val; TF = TF_val; T1B = T1B_val; T1A = T1A_val;
    T1f = T1f_val; T1t = T1t_val; Ti = Ti_val; Tl = Tl_val;
    Tt = Tt_val; TA = TA_val; T1w = T1w_val; T1v = T1v_val;
    T1p = T1p_val; T1E = T1E_val; TM = TM_val; TO = TO_val;

    Rp[0] = T3 + Ti;
    Rm[0] = TJ + TM;

    {
        E T1g, T1q, T17, T1h;
        T1g = T18 + T1f;
        T1q = T1i + T1p;
        T17 = W[8];
        T1h = W[9];
        Ip[(rs[2])] = ((T17 * T1g) - ((T1h) * (T1q)));
        Im[(rs[2])] = (((T1h) * (T1g)) + (T17 * T1q));
    }

    {
        E TB, TG, T11, TX, TP, T10, Tm, TW, TN, Tk;
        TB = ((KP587785252 * Tt) - ((KP951056516) * (TA)));
        TG = ((KP587785252 * TE) - ((KP951056516) * (TF)));
        T11 = (((KP951056516) * (TE)) + (KP587785252 * TF));
        TX = (((KP951056516) * (Tt)) + (KP587785252 * TA));
        TN = ((TJ) - ((KP250000000) * (TM)));
        TP = TN - TO;
        T10 = TO + TN;
        Tk = ((T3) - ((KP250000000) * (Ti)));
        Tm = Tk - Tl;
        TW = Tl + Tk;

        {
            E TC, TQ, Tj, TD;
            TC = Tm - TB;
            TQ = TG + TP;
            Tj = W[2];
            TD = W[3];
            Rp[(rs[1])] = ((Tj * TC) - ((TD) * (TQ)));
            Rm[(rs[1])] = (((TD) * (TC)) + (Tj * TQ));
        }
        {
            E T14, T16, T13, T15;
            T14 = TW - TX;
            T16 = T11 + T10;
            T13 = W[10];
            T15 = W[11];
            Rp[(rs[3])] = ((T13 * T14) - ((T15) * (T16)));
            Rm[(rs[3])] = (((T15) * (T14)) + (T13 * T16));
        }
        {
            E TS, TU, TR, TT;
            TS = Tm + TB;
            TU = TP - TG;
            TR = W[14];
            TT = W[15];
            Rp[(rs[4])] = ((TR * TS) - ((TT) * (TU)));
            Rm[(rs[4])] = (((TT) * (TS)) + (TR * TU));
        }
        {
            E TY, T12, TV, TZ;
            TY = TW + TX;
            T12 = T10 - T11;
            TV = W[6];
            TZ = W[7];
            Rp[(rs[2])] = ((TV * TY) - ((TZ) * (T12)));
            Rm[(rs[2])] = (((TZ) * (TY)) + (TV * T12));
        }
    }

    {
        E T1x, T1C, T1Q, T1N, T1F, T1R, T1u, T1M, T1D, T1s;
        T1x = ((KP587785252 * T1v) - ((KP951056516) * (T1w)));
        T1C = ((KP587785252 * T1A) - ((KP951056516) * (T1B)));
        T1Q = (((KP951056516) * (T1A)) + (KP587785252 * T1B));
        T1N = (((KP951056516) * (T1v)) + (KP587785252 * T1w));
        T1D = ((T1i) - ((KP250000000) * (T1p)));
        T1F = T1D - T1E;
        T1R = T1E + T1D;
        T1s = ((T18) - ((KP250000000) * (T1f)));
        T1u = T1s - T1t;
        T1M = T1t + T1s;

        {
            E T1y, T1G, T1r, T1z;
            T1y = T1u - T1x;
            T1G = T1C + T1F;
            T1r = W[12];
            T1z = W[13];
            Ip[(rs[3])] = ((T1r * T1y) - ((T1z) * (T1G)));
            Im[(rs[3])] = (((T1r) * (T1G)) + (T1z * T1y));
        }
        {
            E T1U, T1W, T1T, T1V;
            T1U = T1M + T1N;
            T1W = T1R - T1Q;
            T1T = W[16];
            T1V = W[17];
            Ip[(rs[4])] = ((T1T * T1U) - ((T1V) * (T1W)));
            Im[(rs[4])] = (((T1T) * (T1W)) + (T1V * T1U));
        }
        {
            E T1I, T1K, T1H, T1J;
            T1I = T1u + T1x;
            T1K = T1F - T1C;
            T1H = W[4];
            T1J = W[5];
            Ip[(rs[1])] = ((T1H * T1I) - ((T1J) * (T1K)));
            Im[(rs[1])] = (((T1H) * (T1K)) + (T1J * T1I));
        }
        {
            E T1O, T1S, T1L, T1P;
            T1O = T1M - T1N;
            T1S = T1Q + T1R;
            T1L = W[0];
            T1P = W[1];
            Ip[0] = ((T1L * T1O) - ((T1P) * (T1S)));
            Im[0] = (((T1L) * (T1S)) + (T1P * T1O));
        }
    }

    // Eliminate potential false dependencies by reordering unrelated stores
    // and introducing local accumulation with delayed write-back
    // No additional side effects introduced
}
}
