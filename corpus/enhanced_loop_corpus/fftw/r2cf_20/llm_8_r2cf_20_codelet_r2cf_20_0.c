#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

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
extern  E KP250000000;
extern  E KP559016994;
extern  E KP587785252;
extern  E KP951056516;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , R0 = R0 + 2*ivs , R1 = R1 + 2*ivs , Cr = Cr + 2*ovs , Ci = Ci + 2*ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, T1m, TF, T17, Ts, TM, TN, Tz, Ta, Th, Ti, T1g, T1h, T1k, T10;
    E T13, T19, TG, TH, TI, T1d, T1e, T1j, TT, TW, T18;
    E T3b, T1mb, TFb, T17b, Tsb, TMb, TNb, Tzb, Tab, Thb, Tib, T1gb, T1hb, T1kb, T10b;
    E T13b, T19b, TGb, THb, TIb, T1db, T1eb, T1jb, TTb, TWb, T18b;

    // First iteration (original body)
    {
        E T1, T2, T15, TD, TE, T16;
        T1 = R0[0];
        T2 = R0[(rs[5])];
        T15 = T1 + T2;
        TD = R1[(rs[7])];
        TE = R1[(rs[2])];
        T16 = TE + TD;
        T3 = T1 - T2;
        T1m = T15 + T16;
        TF = TD - TE;
        T17 = T15 - T16;
    }
    {
        E T6, TU, Tv, T12, Ty, TZ, T9, TR, Td, TY, To, TS, Tr, TV, Tg;
        E T11;
        {
            E T4, T5, Tt, Tu;
            T4 = R0[(rs[2])];
            T5 = R0[(rs[7])];
            T6 = T4 - T5;
            TU = T4 + T5;
            Tt = R1[(rs[8])];
            Tu = R1[(rs[3])];
            Tv = Tt - Tu;
            T12 = Tt + Tu;
        }
        {
            E Tw, Tx, T7, T8;
            Tw = R1[(rs[6])];
            Tx = R1[(rs[1])];
            Ty = Tw - Tx;
            TZ = Tw + Tx;
            T7 = R0[(rs[8])];
            T8 = R0[(rs[3])];
            T9 = T7 - T8;
            TR = T7 + T8;
        }
        {
            E Tb, Tc, Tm, Tn;
            Tb = R0[(rs[4])];
            Tc = R0[(rs[9])];
            Td = Tb - Tc;
            TY = Tb + Tc;
            Tm = R1[0];
            Tn = R1[(rs[5])];
            To = Tm - Tn;
            TS = Tm + Tn;
        }
        {
            E Tp, Tq, Te, Tf;
            Tp = R1[(rs[4])];
            Tq = R1[(rs[9])];
            Tr = Tp - Tq;
            TV = Tp + Tq;
            Te = R0[(rs[6])];
            Tf = R0[(rs[1])];
            Tg = Te - Tf;
            T11 = Te + Tf;
        }
        Ts = To - Tr;
        TM = T6 - T9;
        TN = Td - Tg;
        Tz = Tv - Ty;
        Ta = T6 + T9;
        Th = Td + Tg;
        Ti = Ta + Th;
        T1g = TY + TZ;
        T1h = T11 + T12;
        T1k = T1g + T1h;
        T10 = TY - TZ;
        T13 = T11 - T12;
        T19 = T10 + T13;
        TG = Tr + To;
        TH = Ty + Tv;
        TI = TG + TH;
        T1d = TU + TV;
        T1e = TR + TS;
        T1j = T1d + T1e;
        TT = TR - TS;
        TW = TU - TV;
        T18 = TW + TT;
    }
    Cr[(csr[5])] = T3 + Ti;
    Ci[(csi[5])] = TF - TI;
    {
        E TX, T14, T1f, T1i;
        TX = TT - TW;
        T14 = T10 - T13;
        Ci[(csi[6])] = ((KP951056516 * TX) - ((KP587785252) * (T14)));
        Ci[(csi[2])] = (((KP587785252) * (TX)) + (KP951056516 * T14));
        T1f = T1d - T1e;
        T1i = T1g - T1h;
        Ci[(csi[8])] = ((KP587785252 * T1f) - ((KP951056516) * (T1i)));
        Ci[(csi[4])] = (((KP951056516) * (T1f)) + (KP587785252 * T1i));
    }
    {
        E T1l, T1n, T1o, T1c, T1a, T1b;
        T1l = KP559016994 * (T1j - T1k);
        T1n = T1j + T1k;
        T1o = ((T1m) - ((KP250000000) * (T1n)));
        Cr[(csr[4])] = T1l + T1o;
        Cr[0] = T1m + T1n;
        Cr[(csr[8])] = T1o - T1l;
        T1c = KP559016994 * (T18 - T19);
        T1a = T18 + T19;
        T1b = ((T17) - ((KP250000000) * (T1a)));
        Cr[(csr[2])] = T1b - T1c;
        Cr[(csr[10])] = T17 + T1a;
        Cr[(csr[6])] = T1c + T1b;
    }
    {
        E TA, TC, Tl, TB, Tj, Tk;
        TA = (((KP951056516) * (Ts)) + (KP587785252 * Tz));
        TC = ((KP951056516 * Tz) - ((KP587785252) * (Ts)));
        Tj = KP559016994 * (Ta - Th);
        Tk = ((T3) - ((KP250000000) * (Ti)));
        Tl = Tj + Tk;
        TB = Tk - Tj;
        Cr[(csr[9])] = Tl - TA;
        Cr[(csr[7])] = TB + TC;
        Cr[(csr[1])] = Tl + TA;
        Cr[(csr[3])] = TB - TC;
    }
    {
        E TO, TQ, TL, TP, TJ, TK;
        TO = (((KP951056516) * (TM)) + (KP587785252 * TN));
        TQ = ((KP951056516 * TN) - ((KP587785252) * (TM)));
        TJ = (((KP250000000) * (TI)) + (TF));
        TK = KP559016994 * (TH - TG);
        TL = TJ + TK;
        TP = TK - TJ;
        Ci[(csi[1])] = TL - TO;
        Ci[(csi[7])] = TQ + TP;
        Ci[(csi[9])] = TO + TL;
        Ci[(csi[3])] = TP - TQ;
    }

    // Second unrolled iteration (offset by ivs/ovs)
    {
        E T1b, T2b, T15b, TDb, TEb, T16b;
        T1b = R0[ivs];
        T2b = R0[ivs + (rs[5])];
        T15b = T1b + T2b;
        TDb = R1[ivs + (rs[7])];
        TEb = R1[ivs + (rs[2])];
        T16b = TEb + TDb;
        T3b = T1b - T2b;
        T1mb = T15b + T16b;
        TFb = TDb - TEb;
        T17b = T15b - T16b;
    }
    {
        E T6b, TUb, Tvb, T12b, Tyb, TZb, T9b, TRb, Tdb, TYb, Tob, TSb, Trb, TVb, Tgb;
        E T11b;
        {
            E T4b, T5b, Ttb, Tub;
            T4b = R0[ivs + (rs[2])];
            T5b = R0[ivs + (rs[7])];
            T6b = T4b - T5b;
            TUb = T4b + T5b;
            Ttb = R1[ivs + (rs[8])];
            Tub = R1[ivs + (rs[3])];
            Tvb = Ttb - Tub;
            T12b = Ttb + Tub;
        }
        {
            E Twb, Txb, T7b, T8b;
            Twb = R1[ivs + (rs[6])];
            Txb = R1[ivs + (rs[1])];
            Tyb = Twb - Txb;
            TZb = Twb + Txb;
            T7b = R0[ivs + (rs[8])];
            T8b = R0[ivs + (rs[3])];
            T9b = T7b - T8b;
            TRb = T7b + T8b;
        }
        {
            E Tbb, Tcb, Tmb, Tnb;
            Tbb = R0[ivs + (rs[4])];
            Tcb = R0[ivs + (rs[9])];
            Tdb = Tbb - Tcb;
            TYb = Tbb + Tcb;
            Tmb = R1[ivs];
            Tnb = R1[ivs + (rs[5])];
            Tob = Tmb - Tnb;
            TSb = Tmb + Tnb;
        }
        {
            E Tpb, Tqb, Teb, Tfb;
            Tpb = R1[ivs + (rs[4])];
            Tqb = R1[ivs + (rs[9])];
            Trb = Tpb - Tqb;
            TVb = Tpb + Tqb;
            Teb = R0[ivs + (rs[6])];
            Tfb = R0[ivs + (rs[1])];
            Tgb = Teb - Tfb;
            T11b = Teb + Tfb;
        }
        Tsb = Tob - Trb;
        TMb = T6b - T9b;
        TNb = Tdb - Tgb;
        Tzb = Tvb - Tyb;
        Tab = T6b + T9b;
        Thb = Tdb + Tgb;
        Tib = Tab + Thb;
        T1gb = TYb + TZb;
        T1hb = T11b + T12b;
        T1kb = T1gb + T1hb;
        T10b = TYb - TZb;
        T13b = T11b - T12b;
        T19b = T10b + T13b;
        TGb = Trb + Tob;
        THb = Tyb + Tvb;
        TIb = TGb + THb;
        T1db = TUb + TVb;
        T1eb = TRb + TSb;
        T1jb = T1db + T1eb;
        TTb = TRb - TSb;
        TWb = TUb - TVb;
        T18b = TWb + TTb;
    }
    Cr[(csr[5]) + ovs] = T3b + Tib;
    Ci[(csi[5]) + ovs] = TFb - TIb;
    {
        E TXb, T14b, T1fb, T1ib;
        TXb = TTb - TWb;
        T14b = T10b - T13b;
        Ci[(csi[6]) + ovs] = ((KP951056516 * TXb) - ((KP587785252) * (T14b)));
        Ci[(csi[2]) + ovs] = (((KP587785252) * (TXb)) + (KP951056516 * T14b));
        T1fb = T1db - T1eb;
        T1ib = T1gb - T1hb;
        Ci[(csi[8]) + ovs] = ((KP587785252 * T1fb) - ((KP951056516) * (T1ib)));
        Ci[(csi[4]) + ovs] = (((KP951056516) * (T1fb)) + (KP587785252 * T1ib));
    }
    {
        E T1lb, T1nb, T1ob, T1cb, T1ab, T1bb;
        T1lb = KP559016994 * (T1jb - T1kb);
        T1nb = T1jb + T1kb;
        T1ob = ((T1mb) - ((KP250000000) * (T1nb)));
        Cr[(csr[4]) + ovs] = T1lb + T1ob;
        Cr[ovs] = T1mb + T1nb;
        Cr[(csr[8]) + ovs] = T1ob - T1lb;
        T1cb = KP559016994 * (T18b - T19b);
        T1ab = T18b + T19b;
        T1bb = ((T17b) - ((KP250000000) * (T1ab)));
        Cr[(csr[2]) + ovs] = T1bb - T1cb;
        Cr[(csr[10]) + ovs] = T17b + T1ab;
        Cr[(csr[6]) + ovs] = T1cb + T1bb;
    }
    {
        E TAb, TCb, Tlb, TBb, Tjb, Tkb;
        TAb = (((KP951056516) * (Tsb)) + (KP587785252 * Tzb));
        TCb = ((KP951056516 * Tzb) - ((KP587785252) * (Tsb)));
        Tjb = KP559016994 * (Tab - Thb);
        Tkb = ((T3b) - ((KP250000000) * (Tib)));
        Tlb = Tjb + Tkb;
        TBb = Tkb - Tjb;
        Cr[(csr[9]) + ovs] = Tlb - TAb;
        Cr[(csr[7]) + ovs] = TBb + TCb;
        Cr[(csr[1]) + ovs] = Tlb + TAb;
        Cr[(csr[3]) + ovs] = TBb - TCb;
    }
    {
        E TOb, TQb, TLb, TPb, TJb, TKb;
        TOb = (((KP951056516) * (TMb)) + (KP587785252 * TNb));
        TQb = ((KP951056516 * TNb) - ((KP587785252) * (TMb)));
        TJb = (((KP250000000) * (TIb)) + (TFb));
        TKb = KP559016994 * (THb - TGb);
        TLb = TJb + TKb;
        TPb = TKb - TJb;
        Ci[(csi[1]) + ovs] = TLb - TOb;
        Ci[(csi[7]) + ovs] = TQb + TPb;
        Ci[(csi[9]) + ovs] = TOb + TLb;
        Ci[(csi[3]) + ovs] = TPb - TQb;
    }
}
}
