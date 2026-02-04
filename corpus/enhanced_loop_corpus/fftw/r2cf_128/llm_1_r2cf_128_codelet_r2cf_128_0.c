#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

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
extern  E KP803207531;
extern  E KP595699304;
extern  E KP146730474;
extern  E KP989176509;
extern  E KP740951125;
extern  E KP671558954;
extern  E KP049067674;
extern  E KP998795456;
extern  E KP242980179;
extern  E KP970031253;
extern  E KP514102744;
extern  E KP857728610;
extern  E KP336889853;
extern  E KP941544065;
extern  E KP427555093;
extern  E KP903989293;
extern  E KP098017140;
extern  E KP995184726;
extern  E KP634393284;
extern  E KP773010453;
extern  E KP881921264;
extern  E KP471396736;
extern  E KP956940335;
extern  E KP290284677;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP195090322;
extern  E KP980785280;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E TcD, TdU, T27, T7r, T5S, T8y, Tf, Ta5, Tu, Tbq, TcG, TdV, T2e, T8z, T5V;
    E T7s, TK, Ta6, TcK, TdX, T2o, T5X, T7w, T8B, TZ, Ta7, TcN, TdY, T2x, T5Y;
    E T7z, T8C, T1g, Taa, TcU, TeA, TcX, Tez, T1v, Tab, T2M, T6z, T7E, T9e, T7H;
    E T9d, T2T, T6A, T4X, T6L, Tdz, TeL, TdK, TeP, T5G, T6P, T8d, T9p, TaV, Tc3;
    E Tbi, Tc4, T8o, T9t, T3I, T6H, Tde, TeH, Tdp, TeF, T4r, T6F, T7U, T9l, Tao;
    E TbW, TaL, TbX, T85, T9j, T1L, Tad, Td3, Tew, Td6, Tex, T20, Tae, T37, T6x;
    E T7L, T9a, T7O, T9b, T3e, T6w, TbZ, Tc0, T3Z, T4s, Tds, TeI, T4g, T4t, T80;
    E T87, Tdl, TeE, T7X, T86, TaD, TaM, Tc6, Tc7, T5e, T5H, TdN, TeM, T5v, T5I;
    E T8j, T8q, TdG, TeO, T8g, T8p, Tba, Tbj;
    
    if (i % 2 == 0) {
        goto process_even;
    } else {
        goto process_odd;
    }

process_even:
    {
        E T3, T23, Td, T25, T6, T5R, Ta, T24;
        {
            E T1, T2, Tb, Tc;
            T1 = R0[0];
            T2 = R0[(rs[32])];
            T3 = T1 + T2;
            T23 = T1 - T2;
            Tb = R0[(rs[56])];
            Tc = R0[(rs[24])];
            Td = Tb + Tc;
            T25 = Tb - Tc;
        }
        {
            E T4, T5, T8, T9;
            T4 = R0[(rs[16])];
            T5 = R0[(rs[48])];
            T6 = T4 + T5;
            T5R = T4 - T5;
            T8 = R0[(rs[8])];
            T9 = R0[(rs[40])];
            Ta = T8 + T9;
            T24 = T8 - T9;
        }
        TcD = T3 - T6;
        TdU = Td - Ta;
        {
            E T26, T5Q, T7, Te;
            T26 = KP707106781 * (T24 + T25);
            T27 = T23 + T26;
            T7r = T23 - T26;
            T5Q = KP707106781 * (T25 - T24);
            T5S = T5Q - T5R;
            T8y = T5R + T5Q;
            T7 = T3 + T6;
            Te = Ta + Td;
            Tf = T7 + Te;
            Ta5 = T7 - Te;
        }
    }
    {
        E Ti, T28, Ts, T2c, Tl, T29, Tp, T2b;
        {
            E Tg, Th, Tq, Tr;
            Tg = R0[(rs[4])];
            Th = R0[(rs[36])];
            Ti = Tg + Th;
            T28 = Tg - Th;
            Tq = R0[(rs[12])];
            Tr = R0[(rs[44])];
            Ts = Tq + Tr;
            T2c = Tq - Tr;
        }
        {
            E Tj, Tk, Tn, To;
            Tj = R0[(rs[20])];
            Tk = R0[(rs[52])];
            Tl = Tj + Tk;
            T29 = Tj - Tk;
            Tn = R0[(rs[60])];
            To = R0[(rs[28])];
            Tp = Tn + To;
            T2b = Tn - To;
        }
        {
            E Tm, Tt, TcE, TcF;
            Tm = Ti + Tl;
            Tt = Tp + Ts;
            Tu = Tm + Tt;
            Tbq = Tt - Tm;
            TcE = Ti - Tl;
            TcF = Tp - Ts;
            TcG = KP707106781 * (TcE + TcF);
            TdV = KP707106781 * (TcF - TcE);
        }
        {
            E T2a, T2d, T5T, T5U;
            T2a = ((KP923879532 * T28) - ((KP382683432) * (T29)));
            T2d = (((KP923879532) * (T2b)) + (KP382683432 * T2c));
            T2e = T2a + T2d;
            T8z = T2d - T2a;
            T5T = ((KP382683432 * T2b) - ((KP923879532) * (T2c)));
            T5U = (((KP382683432) * (T28)) + (KP923879532 * T29));
            T5V = T5T - T5U;
            T7s = T5U + T5T;
        }
    }
    goto skip_odd;

process_odd:
    {
        E Ty, T2g, TB, T2m, TF, T2l, TI, T2j;
        {
            E Tw, Tx, Tz, TA;
            Tw = R0[(rs[2])];
            Tx = R0[(rs[34])];
            Ty = Tw + Tx;
            T2g = Tw - Tx;
            Tz = R0[(rs[18])];
            TA = R0[(rs[50])];
            TB = Tz + TA;
            T2m = Tz - TA;
            {
                E TD, TE, T2h, TG, TH, T2i;
                TD = R0[(rs[10])];
                TE = R0[(rs[42])];
                T2h = TD - TE;
                TG = R0[(rs[58])];
                TH = R0[(rs[26])];
                T2i = TG - TH;
                TF = TD + TE;
                T2l = KP707106781 * (T2i - T2h);
                TI = TG + TH;
                T2j = KP707106781 * (T2h + T2i);
            }
        }
        {
            E TC, TJ, TcI, TcJ;
            TC = Ty + TB;
            TJ = TF + TI;
            TK = TC + TJ;
            Ta6 = TC - TJ;
            TcI = Ty - TB;
            TcJ = TI - TF;
            TcK = (((KP923879532) * (TcI)) + (KP382683432 * TcJ));
            TdX = ((KP923879532 * TcJ) - ((KP382683432) * (TcI)));
        }
        {
            E T2k, T2n, T7u, T7v;
            T2k = T2g + T2j;
            T2n = T2l - T2m;
            T2o = (((KP980785280) * (T2k)) + (KP195090322 * T2n));
            T5X = ((KP980785280 * T2n) - ((KP195090322) * (T2k)));
            T7u = T2g - T2j;
            T7v = T2m + T2l;
            T7w = (((KP831469612) * (T7u)) + (KP555570233 * T7v));
            T8B = ((KP831469612 * T7v) - ((KP555570233) * (T7u)));
        }
    }

skip_odd:

    for (INT j = 0; j < 1; ++j) {
        E TN, T2p, TQ, T2v, TU, T2u, TX, T2s;
        {
            E TL, TM, TO, TP;
            TL = R0[(rs[62])];
            TM = R0[(rs[30])];
            TN = TL + TM;
            T2p = TL - TM;
            TO = R0[(rs[14])];
            TP = R0[(rs[46])];
            TQ = TO + TP;
            T2v = TO - TP;
            {
                E TS, TT, T2q, TV, TW, T2r;
                TS = R0[(rs[6])];
                TT = R0[(rs[38])];
                T2q = TS - TT;
                TV = R0[(rs[54])];
                TW = R0[(rs[22])];
                T2r = TV - TW;
                TU = TS + TT;
                T2u = KP707106781 * (T2r - T2q);
                TX = TV + TW;
                T2s = KP707106781 * (T2q + T2r);
            }
        }
        {
            E TR, TY, TcL, TcM;
            TR = TN + TQ;
            TY = TU + TX;
            TZ = TR + TY;
            Ta7 = TR - TY;
            TcL = TN - TQ;
            TcM = TX - TU;
            TcN = ((KP923879532 * TcL) - ((KP382683432) * (TcM)));
            TdY = (((KP382683432) * (TcL)) + (KP923879532 * TcM));
        }
        {
            E T2t, T2w, T7x, T7y;
            T2t = T2p + T2s;
            T2w = T2u - T2v;
            T2x = ((KP980785280 * T2t) - ((KP195090322) * (T2w)));
            T5Y = (((KP195090322) * (T2t)) + (KP980785280 * T2w));
            T7x = T2p - T2s;
            T7y = T2v + T2u;
            T7z = ((KP831469612 * T7x) - ((KP555570233) * (T7y)));
            T8C = (((KP555570233) * (T7x)) + (KP831469612 * T7y));
        }
    }

    continue_main_loop:
    ;
}
}
