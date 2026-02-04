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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 10); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 20 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T4, Tv, Tr, TL, Tb, Tc, Ty, TP, To, TB, Tj, TQ, Tp, Tq, TE;
    E TM;
    {
        E Ta, Tx, T7, Tw, T2, T3;
        T2 = Rp[0];
        T3 = Rm[(rs[2])];
        T4 = T2 + T3;
        Tv = T2 - T3;
        {
            E T8, T9, T5, T6;
            T8 = Rm[(rs[1])];
            T9 = Rp[(rs[1])];
            Ta = T8 + T9;
            Tx = T8 - T9;
            T5 = Rp[(rs[2])];
            T6 = Rm[0];
            T7 = T5 + T6;
            Tw = T5 - T6;
        }
        Tr = KP866025403 * (T7 - Ta);
        TL = KP866025403 * (Tw - Tx);
        Tb = T7 + Ta;
        Tc = ((T4) - ((KP500000000) * (Tb)));
        Ty = Tw + Tx;
        TP = ((Tv) - ((KP500000000) * (Ty)));
    }
    {
        E Tf, TC, Ti, TD, Td, Te;
        Td = Ip[(rs[1])];
        Te = Im[(rs[1])];
        Tf = Td - Te;
        TC = Te + Td;
        {
            E Tm, Tn, Tg, Th;
            Tm = Ip[0];
            Tn = Im[(rs[2])];
            To = Tm - Tn;
            TB = Tm + Tn;
            Tg = Ip[(rs[2])];
            Th = Im[0];
            Ti = Tg - Th;
            TD = Tg + Th;
        }
        Tj = KP866025403 * (Tf - Ti);
        TQ = KP866025403 * (TC + TD);
        Tp = Tf + Ti;
        Tq = ((To) - ((KP500000000) * (Tp)));
        TE = TC - TD;
        TM = (((KP500000000) * (TE)) + (TB));
    }
    {
        E TJ, TT, TS, TU;
        TJ = T4 + Tb;
        TT = To + Tp;
        {
            E TN, TR, TK, TO;
            TN = TL + TM;
            TR = TP - TQ;
            TK = W[0];
            TO = W[1];
            TS = (((TK) * (TN)) + (TO * TR));
            TU = ((TK * TR) - ((TO) * (TN)));
        }
        Rp[0] = TJ - TS;
        Ip[0] = TT + TU;
        Rm[0] = TJ + TS;
        Im[0] = TU - TT;
    }
    {
        E TZ, T15, T14, T16;
        {
            E TW, TY, TV, TX;
            TW = Tc + Tj;
            TY = Tr + Tq;
            TV = W[6];
            TX = W[7];
            TZ = ((TV * TW) - ((TX) * (TY)));
            T15 = (((TX) * (TW)) + (TV * TY));
        }
        {
            E T11, T13, T10, T12;
            T11 = TM - TL;
            T13 = TP + TQ;
            T10 = W[8];
            T12 = W[9];
            T14 = (((T10) * (T11)) + (T12 * T13));
            T16 = ((T10 * T13) - ((T12) * (T11)));
        }
        Rp[(rs[2])] = TZ - T14;
        Ip[(rs[2])] = T15 + T16;
        Rm[(rs[2])] = TZ + T14;
        Im[(rs[2])] = T16 - T15;
    }
    {
        E Tt, TH, TG, TI;
        {
            E Tk, Ts, T1, Tl;
            Tk = Tc - Tj;
            Ts = Tq - Tr;
            T1 = W[3];
            Tl = W[2];
            Tt = (((T1) * (Tk)) + (Tl * Ts));
            TH = ((Tl * Tk) - ((T1) * (Ts)));
        }
        {
            E Tz, TF, Tu, TA;
            Tz = Tv + Ty;
            TF = TB - TE;
            Tu = W[4];
            TA = W[5];
            TG = ((Tu * Tz) - ((TA) * (TF)));
            TI = (((TA) * (Tz)) + (Tu * TF));
        }
        Ip[(rs[1])] = Tt + TG;
        Rp[(rs[1])] = TH - TI;
        Im[(rs[1])] = TG - Tt;
        Rm[(rs[1])] = TH + TI;
    }

    {
        E T4b, Tvb, Trb, TLb, Tbb, Tcb, Tyb, TPb, Tob, TBb, Tjb, TQb, Tpb, Tqb, TEb;
        E TMb;
        {
            E Tab, Txb, T7b, Twb, T2b, T3b;
            T2b = Rp[ms];
            T3b = Rm[(rs[2]) - ms];
            T4b = T2b + T3b;
            Tvb = T2b - T3b;
            {
                E T8b, T9b, T5b, T6b;
                T8b = Rm[(rs[1]) - ms];
                T9b = Rp[(rs[1]) + ms];
                Tab = T8b + T9b;
                Txb = T8b - T9b;
                T5b = Rp[(rs[2]) + ms];
                T6b = Rm[-ms];
                T7b = T5b + T6b;
                Twb = T5b - T6b;
            }
            Trb = KP866025403 * (T7b - Tab);
            TLb = KP866025403 * (Twb - Txb);
            Tbb = T7b + Tab;
            Tcb = ((T4b) - ((KP500000000) * (Tbb)));
            Tyb = Twb + Txb;
            TPb = ((Tvb) - ((KP500000000) * (Tyb)));
        }
        {
            E Tfb, TCb, Tib, TDb, Tdb, Teb;
            Tdb = Ip[(rs[1]) + ms];
            Teb = Im[(rs[1]) - ms];
            Tfb = Tdb - Teb;
            TCb = Teb + Tdb;
            {
                E Tmb, Tnb, Tgb, Thb;
                Tmb = Ip[ms];
                Tnb = Im[(rs[2]) - ms];
                Tob = Tmb - Tnb;
                TBb = Tmb + Tnb;
                Tgb = Ip[(rs[2]) + ms];
                Thb = Im[-ms];
                Tib = Tgb - Thb;
                TDb = Tgb + Thb;
            }
            Tjb = KP866025403 * (Tfb - Tib);
            TQb = KP866025403 * (TCb + TDb);
            Tpb = Tfb + Tib;
            Tqb = ((Tob) - ((KP500000000) * (Tpb)));
            TEb = TCb - TDb;
            TMb = (((KP500000000) * (TEb)) + (TBb));
        }
        {
            E TJb, TTb, TSb, TUb;
            TJb = T4b + Tbb;
            TTb = Tob + Tpb;
            {
                E TNb, TRb, TKb, TOb;
                TNb = TLb + TMb;
                TRb = TPb - TQb;
                TKb = W[10];
                TOb = W[11];
                TSb = (((TKb) * (TNb)) + (TOb * TRb));
                TUb = ((TKb * TRb) - ((TOb) * (TNb)));
            }
            Rp[ms] = TJb - TSb;
            Ip[ms] = TTb + TUb;
            Rm[-ms] = TJb + TSb;
            Im[-ms] = TUb - TTb;
        }
        {
            E TZb, T15b, T14b, T16b;
            {
                E TWb, TYb, TVb, TXb;
                TWb = Tcb + Tjb;
                TYb = Trb + Tqb;
                TVb = W[16];
                TXb = W[17];
                TZb = ((TVb * TWb) - ((TXb) * (TYb)));
                T15b = (((TXb) * (TWb)) + (TVb * TYb));
            }
            {
                E T11b, T13b, T10b, T12b;
                T11b = TMb - TLb;
                T13b = TPb + TQb;
                T10b = W[18];
                T12b = W[19];
                T14b = (((T10b) * (T11b)) + (T12b * T13b));
                T16b = ((T10b * T13b) - ((T12b) * (T11b)));
            }
            Rp[(rs[2]) + ms] = TZb - T14b;
            Ip[(rs[2]) + ms] = T15b + T16b;
            Rm[(rs[2]) - ms] = TZb + T14b;
            Im[(rs[2]) - ms] = T16b - T15b;
        }
        {
            E Ttb, THb, TGb, TIb;
            {
                E Tkb, Tsb, T1b, Tlb;
                Tkb = Tcb - Tjb;
                Tsb = Tqb - Trb;
                T1b = W[13];
                Tlb = W[12];
                Ttb = (((T1b) * (Tkb)) + (Tlb * Tsb));
                THb = ((Tlb * Tkb) - ((T1b) * (Tsb)));
            }
            {
                E Tzb, TFb, Tub, TAb;
                Tzb = Tvb + Tyb;
                TFb = TBb - TEb;
                Tub = W[14];
                TAb = W[15];
                TGb = ((Tub * Tzb) - ((TAb) * (TFb)));
                TIb = (((TAb) * (Tzb)) + (Tub * TFb));
            }
            Ip[(rs[1]) + ms] = Ttb + TGb;
            Rp[(rs[1]) + ms] = THb - TIb;
            Im[(rs[1]) - ms] = TGb - Ttb;
            Rm[(rs[1]) - ms] = THb + TIb;
        }
}

}
}
