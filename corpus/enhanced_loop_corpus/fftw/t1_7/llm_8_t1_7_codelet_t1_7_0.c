#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP222520933;
extern  E KP900968867;
extern  E KP623489801;
extern  E KP433883739;
extern  E KP781831482;
extern  E KP974927912;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 12); m < me; m = m + 2 , ri = ri + (2 * ms) , ii = ii + (2 * ms) , W = W + 24 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;
    E T1, TR, Tc, TS, TC, TO, Tn, TT, TI, TP, Ty, TU, TF, TQ;
    E T1b, TRb, Tcb, TSb, TCb, TOb, Tnb, TTb, TIb, TPb, Tyb, TUb, TFb, TQb;

    // First iteration (original m)
    T1 = ri[0];
    TR = ii[0];
    {
        E T6, TA, Tb, TB;
        {
            E T3 = ri[(rs[1])], T5 = ii[(rs[1])], T2 = W[0], T4 = W[1];
            T6 = T2 * T3 + T4 * T5;
            TA = T2 * T5 - T4 * T3;
        }
        {
            E T8 = ri[(rs[6])], Ta = ii[(rs[6])], T7 = W[10], T9 = W[11];
            Tb = T7 * T8 + T9 * Ta;
            TB = T7 * Ta - T9 * T8;
        }
        Tc = T6 + Tb;
        TS = Tb - T6;
        TC = TA - TB;
        TO = TA + TB;
    }
    {
        E Th, TG, Tm, TH;
        {
            E Te = ri[(rs[2])], Tg = ii[(rs[2])], Td = W[2], Tf = W[3];
            Th = Td * Te + Tf * Tg;
            TG = Td * Tg - Tf * Te;
        }
        {
            E Tj = ri[(rs[5])], Tl = ii[(rs[5])], Ti = W[8], Tk = W[9];
            Tm = Ti * Tj + Tk * Tl;
            TH = Ti * Tl - Tk * Tj;
        }
        Tn = Th + Tm;
        TT = Tm - Th;
        TI = TG - TH;
        TP = TG + TH;
    }
    {
        E Ts, TD, Tx, TE;
        {
            E Tp = ri[(rs[3])], Tr = ii[(rs[3])], To = W[4], Tq = W[5];
            Ts = To * Tp + Tq * Tr;
            TD = To * Tr - Tq * Tp;
        }
        {
            E Tu = ri[(rs[4])], Tw = ii[(rs[4])], Tt = W[6], Tv = W[7];
            Tx = Tt * Tu + Tv * Tw;
            TE = Tt * Tw - Tv * Tu;
        }
        Ty = Ts + Tx;
        TU = Tx - Ts;
        TF = TD - TE;
        TQ = TD + TE;
    }
    ri[0] = T1 + Tc + Tn + Ty;
    ii[0] = TO + TP + TQ + TR;

    {
        E TJ, Tz, TX, TY;
        TJ = KP974927912 * TC - KP781831482 * TF - KP433883739 * TI;
        Tz = KP623489801 * Ty + T1 - (KP900968867 * Tn + KP222520933 * Tc);
        ri[(rs[5])] = Tz - TJ;
        ri[(rs[2])] = Tz + TJ;
        TX = KP974927912 * TS - KP781831482 * TU - KP433883739 * TT;
        TY = KP623489801 * TQ + TR - (KP900968867 * TP + KP222520933 * TO);
        ii[(rs[2])] = TX + TY;
        ii[(rs[5])] = TY - TX;
    }
    {
        E TL, TK, TV, TW;
        TL = KP781831482 * TC + KP974927912 * TI + KP433883739 * TF;
        TK = KP623489801 * Tc + T1 - (KP900968867 * Ty + KP222520933 * Tn);
        ri[(rs[6])] = TK - TL;
        ri[(rs[1])] = TK + TL;
        TV = KP781831482 * TS + KP974927912 * TT + KP433883739 * TU;
        TW = KP623489801 * TO + TR - (KP900968867 * TQ + KP222520933 * TP);
        ii[(rs[1])] = TV + TW;
        ii[(rs[6])] = TW - TV;
    }
    {
        E TN, TM, TZ, T10;
        TN = KP433883739 * TC + KP974927912 * TF - KP781831482 * TI;
        TM = KP623489801 * Tn + T1 - (KP222520933 * Ty + KP900968867 * Tc);
        ri[(rs[4])] = TM - TN;
        ri[(rs[3])] = TM + TN;
        TZ = KP433883739 * TS + KP974927912 * TU - KP781831482 * TT;
        T10 = KP623489801 * TP + TR - (KP222520933 * TQ + KP900968867 * TO);
        ii[(rs[3])] = TZ + T10;
        ii[(rs[4])] = T10 - TZ;
    }

    // Second iteration (m+1)
    T1b = ri[ms];
    TRb = ii[ms];
    {
        E T6b, TAb, Tbb, TBb;
        {
            E T3b = ri[ms + rs[1]], T5b = ii[ms + rs[1]], T2b = W[12], T4b = W[13];
            T6b = T2b * T3b + T4b * T5b;
            TAb = T2b * T5b - T4b * T3b;
        }
        {
            E T8b = ri[ms + rs[6]], Tab = ii[ms + rs[6]], T7b = W[22], T9b = W[23];
            Tbb = T7b * T8b + T9b * Tab;
            TBb = T7b * Tab - T9b * T8b;
        }
        Tcb = T6b + Tbb;
        TSb = Tbb - T6b;
        TCb = TAb - TBb;
        TOb = TAb + TBb;
    }
    {
        E Thb, TGb, Tmb, THb;
        {
            E Teb = ri[ms + rs[2]], Tgb = ii[ms + rs[2]], Tdb = W[14], Tfb = W[15];
            Thb = Tdb * Teb + Tfb * Tgb;
            TGb = Tdb * Tgb - Tfb * Teb;
        }
        {
            E Tjb = ri[ms + rs[5]], Tlb = ii[ms + rs[5]], Tib = W[20], Tkb = W[21];
            Tmb = Tib * Tjb + Tkb * Tlb;
            THb = Tib * Tlb - Tkb * Tjb;
        }
        Tnb = Thb + Tmb;
        TTb = Tmb - Thb;
        TIb = TGb - THb;
        TPb = TGb + THb;
    }
    {
        E Tsb, TDb, Txb, TEb;
        {
            E Tpb = ri[ms + rs[3]], Trb = ii[ms + rs[3]], Tob = W[16], Tqb = W[17];
            Tsb = Tob * Tpb + Tqb * Trb;
            TDb = Tob * Trb - Tqb * Tpb;
        }
        {
            E Tub = ri[ms + rs[4]], Twb = ii[ms + rs[4]], Ttb = W[18], Tvb = W[19];
            Txb = Ttb * Tub + Tvb * Twb;
            TEb = Ttb * Twb - Tvb * Tub;
        }
        Tyb = Tsb + Txb;
        TUb = Txb - Tsb;
        TFb = TDb - TEb;
        TQb = TDb + TEb;
    }
    ri[ms] = T1b + Tcb + Tnb + Tyb;
    ii[ms] = TOb + TPb + TQb + TRb;

    {
        E TJb, Tzb, TXb, TYb;
        TJb = KP974927912 * TCb - KP781831482 * TFb - KP433883739 * TIb;
        Tzb = KP623489801 * Tyb + T1b - (KP900968867 * Tnb + KP222520933 * Tcb);
        ri[ms + rs[5]] = Tzb - TJb;
        ri[ms + rs[2]] = Tzb + TJb;
        TXb = KP974927912 * TSb - KP781831482 * TUb - KP433883739 * TTb;
        TYb = KP623489801 * TQb + TRb - (KP900968867 * TPb + KP222520933 * TOb);
        ii[ms + rs[2]] = TXb + TYb;
        ii[ms + rs[5]] = TYb - TXb;
    }
    {
        E TLb, TKb, TVb, TWb;
        TLb = KP781831482 * TCb + KP974927912 * TIb + KP433883739 * TFb;
        TKb = KP623489801 * Tcb + T1b - (KP900968867 * Tyb + KP222520933 * Tnb);
        ri[ms + rs[6]] = TKb - TLb;
        ri[ms + rs[1]] = TKb + TLb;
        TVb = KP781831482 * TSb + KP974927912 * TTb + KP433883739 * TUb;
        TWb = KP623489801 * TOb + TRb - (KP900968867 * TQb + KP222520933 * TPb);
        ii[ms + rs[1]] = TVb + TWb;
        ii[ms + rs[6]] = TWb - TVb;
    }
    {
        E TNb, TMb, TZb, T10b;
        TNb = KP433883739 * TCb + KP974927912 * TFb - KP781831482 * TIb;
        TMb = KP623489801 * Tnb + T1b - (KP222520933 * Tyb + KP900968867 * Tcb);
        ri[ms + rs[4]] = TMb - TNb;
        ri[ms + rs[3]] = TMb + TNb;
        TZb = KP433883739 * TSb + KP974927912 * TUb - KP781831482 * TTb;
        T10b = KP623489801 * TPb + TRb - (KP222520933 * TQb + KP900968867 * TOb);
        ii[ms + rs[3]] = TZb + T10b;
        ii[ms + rs[4]] = T10b - TZb;
    }
}
}
