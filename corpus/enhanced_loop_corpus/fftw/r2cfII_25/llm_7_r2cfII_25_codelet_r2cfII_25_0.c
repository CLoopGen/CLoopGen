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
extern  E KP1_996053456;
extern  E KP062790519;
extern  E KP125581039;
extern  E KP998026728;
extern  E KP1_369094211;
extern  E KP728968627;
extern  E KP963507348;
extern  E KP876306680;
extern  E KP497379774;
extern  E KP968583161;
extern  E KP1_457937254;
extern  E KP684547105;
extern  E KP1_752613360;
extern  E KP481753674;
extern  E KP1_937166322;
extern  E KP248689887;
extern  E KP992114701;
extern  E KP250666467;
extern  E KP1_809654104;
extern  E KP425779291;
extern  E KP1_541026485;
extern  E KP637423989;
extern  E KP1_688655851;
extern  E KP535826794;
extern  E KP851558583;
extern  E KP904827052;
extern  E KP1_984229402;
extern  E KP125333233;
extern  E KP1_274847979;
extern  E KP770513242;
extern  E KP844327925;
extern  E KP1_071653589;
extern  E KP293892626;
extern  E KP475528258;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ivs , R1 = R1 + ivs , Cr = Cr + ovs , Ci = Ci + ovs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E TE, TR, T2i, T1z, TL, TS, TB, T2d, T1l, T1i, T2c, T9, T23, TZ, TW;
    E T22, Ti, T26, T16, T13, T25, Ts, T2a, T1e, T1b, T29, TP, TQ;
    E temp_storage_TL_TR_TS[3];  // Introduce temporary storage to modify data dependencies

    TE = R0[0];
    {
        E TI = R0[(rs[10])], TJ = R1[(rs[2])], TF = R0[(rs[5])], TG = R1[(rs[7])];
        temp_storage_TL_TR_TS[0] = TI - TJ;  // TK
        temp_storage_TL_TR_TS[1] = TF - TG;  // TH
        temp_storage_TL_TR_TS[2] = TI + TJ;  // T1y
        T1z = TF + TG;  // T1x
    }

    TL = temp_storage_TL_TR_TS[1] + temp_storage_TL_TR_TS[0];
    TR = KP559016994 * (temp_storage_TL_TR_TS[1] - temp_storage_TL_TR_TS[0]);
    T2i = ((KP951056516 * temp_storage_TL_TR_TS[2]) - ((KP587785252) * (T1z)));
    T1z = (((KP951056516) * (T1z)) + (KP587785252 * temp_storage_TL_TR_TS[2]));
    TS = ((TE) - ((KP250000000) * (TL)));

    temp_storage_TL_TR_TS[0] = TR + TS;

    {
        E Tt = R0[(rs[3])], Tu = R0[(rs[8])], Tv = R1[(rs[10])], Tw = Tu - Tv;
        E Tx = R1[0], Ty = R1[(rs[5])], Tz = Tx + Ty, TA = Tw - Tz;
        E T1k = Ty - Tx, T1j = Tu + Tv;
        TB = Tt + TA;
        T2d = ((KP475528258 * T1k) - ((KP293892626) * (T1j)));
        T1l = (((KP475528258) * (T1j)) + (KP293892626 * T1k));
        T1i = ((Tt) - ((KP250000000) * (TA))) + (KP559016994 * (Tw + Tz));
        T2c = ((Tt) - ((KP250000000) * (TA))) - (KP559016994 * (Tw + Tz));
    }

    {
        E T1 = R0[(rs[1])], T2 = R0[(rs[6])], T3 = R1[(rs[8])], T4 = T2 - T3;
        E T5 = R0[(rs[11])], T6 = R1[(rs[3])], T7 = T5 - T6, T8 = T4 + T7;
        E TY = T5 + T6, TX = T2 + T3;
        T9 = T1 + T8;
        T23 = ((KP475528258 * TY) - ((KP293892626) * (TX)));
        TZ = (((KP475528258) * (TX)) + (KP293892626 * TY));
        TW = (KP559016994 * (T4 - T7)) + ((T1) - ((KP250000000) * (T8)));
        T22 = ((T1) - ((KP250000000) * (T8))) - (KP559016994 * (T4 - T7));
    }

    {
        E Ta = R0[(rs[4])], Tb = R0[(rs[9])], Tc = R1[(rs[11])], Td = Tb - Tc;
        E Te = R1[(rs[1])], Tf = R1[(rs[6])], Tg = Te + Tf, Th = Td - Tg;
        E T15 = Tf - Te, T14 = Tb + Tc;
        Ti = Ta + Th;
        T26 = ((KP475528258 * T15) - ((KP293892626) * (T14)));
        T16 = (((KP475528258) * (T14)) + (KP293892626 * T15));
        T13 = ((Ta) - ((KP250000000) * (Th))) + (KP559016994 * (Td + Tg));
        T25 = ((Ta) - ((KP250000000) * (Th))) - (KP559016994 * (Td + Tg));
    }

    {
        E Tk = R0[(rs[2])], Tl = R0[(rs[7])], Tm = R1[(rs[9])], Tn = Tl - Tm;
        E To = R0[(rs[12])], Tp = R1[(rs[4])], Tq = To - Tp, Tr = Tn + Tq;
        E T1d = To + Tp, T1c = Tl + Tm;
        Ts = Tk + Tr;
        T2a = ((KP475528258 * T1d) - ((KP293892626) * (T1c)));
        T1e = (((KP475528258) * (T1c)) + (KP293892626 * T1d));
        T1b = (KP559016994 * (Tn - Tq)) + ((Tk) - ((KP250000000) * (Tr)));
        T29 = ((Tk) - ((KP250000000) * (Tr))) - (KP559016994 * (Tn - Tq));
    }

    TP = TB - Ts;
    TQ = T9 - Ti;
    Ci[(csi[2])] = ((KP587785252 * TP) - ((KP951056516) * (TQ)));
    Ci[(csi[7])] = (((KP587785252) * (TQ)) + (KP951056516 * TP));

    {
        E TM = TE + TL, Tj = T9 + Ti, TC = Ts + TB;
        E TD = KP559016994 * (Tj - TC), TN = Tj + TC;
        Cr[(csr[12])] = TM + TN;
        E TO = ((TM) - ((KP250000000) * (TN)));
        Cr[(csr[2])] = TD + TO;
        Cr[(csr[7])] = TO - TD;
    }

    {
        E TT = temp_storage_TL_TR_TS[0];
        {
            E T1H = ((KP1_071653589 * TZ) - ((KP844327925) * (TW)));
            E T1I = ((KP770513242 * T13) - ((KP1_274847979) * (T16)));
            E T1J = T1H - T1I, T1Y = T1H + T1I;
            E T1S = (((KP125333233) * (T1i)) + (KP1_984229402 * T1l));
            E T1T = (((KP904827052) * (T1b)) + (KP851558583 * T1e));
            E T1U = T1S - T1T, T1X = T1T + T1S;
            {
                E T1N = (((KP535826794) * (TW)) + (KP1_688655851 * TZ));
                E T1O = (((KP637423989) * (T13)) + (KP1_541026485 * T16));
                E T1P = T1N - T1O, T1V = T1N + T1O;
                E T1K = ((KP425779291 * T1b) - ((KP1_809654104) * (T1e)));
                E T1L = ((KP250666467 * T1l) - ((KP992114701) * (T1i)));
                E T1M = T1K - T1L, T1W = T1K + T1L;
                {
                    E T1p = (((KP844327925) * (T13)) + (KP1_071653589 * T16));
                    E T1q = (((KP248689887) * (TW)) + (KP1_937166322 * TZ));
                    E T1A = T1q + T1p;
                    E T1t = (((KP481753674) * (T1b)) + (KP1_752613360 * T1e));
                    E T1u = (((KP684547105) * (T1i)) + (KP1_457937254 * T1l));
                    E T1B = T1t + T1u;
                    E T1r = T1p - T1q;
                    E T1C = T1A + T1B;
                    E T1v = T1t - T1u;
                    {
                        E T10 = ((KP968583161 * TW) - ((KP497379774) * (TZ)));
                        E T17 = ((KP535826794 * T13) - ((KP1_688655851) * (T16)));
                        E T18 = T10 + T17;
                        E T1f = ((KP876306680 * T1b) - ((KP963507348) * (T1e)));
                        E T1m = ((KP728968627 * T1i) - ((KP1_369094211) * (T1l)));
                        E T1n = T1f + T1m;
                        E T1o = T18 + T1n;
                        E T1G = T10 - T17;
                        E T1D = T1f - T1m;
                        Cr[0] = TT + T1o;
                        Ci[0] = -(T1z + T1C);
                        E T1R = KP559016994 * (T1P + T1M);
                        E T1Q = (((KP250000000) * (T1M - T1P)) + (TT));
                        Cr[(csr[4])] = (((KP951056516) * (T1J)) + (T1Q)) + (((KP587785252) * (T1U)) + (T1R));
                        Cr[(csr[9])] = (((KP951056516) * (T1U)) + (T1Q)) + (-(((KP587785252) * (T1J)) + (T1R)));
                        E T20 = KP559016994 * (T1Y + T1X);
                        E T1Z = (((KP250000000) * (T1X - T1Y)) + (T1z));
                        Ci[(csi[9])] = (((KP587785252) * (T1V)) + (KP951056516 * T1W)) + T1Z - T20;
                        Ci[(csi[4])] = (((KP587785252) * (T1W)) + (T1Z)) + ((T20) - ((KP951056516) * (T1V)));
                        {
                            E T1E = (((KP250000000) * (T1C)) - (T1z));
                            E T1F = KP559016994 * (T1B - T1A);
                            Ci[(csi[5])] = (((KP951056516) * (T1D)) + (T1E)) + (-(((KP587785252) * (T1G)) + (T1F)));
                            Ci[(csi[10])] = (((KP951056516) * (T1G)) + (KP587785252 * T1D)) + T1E + T1F;
                            E T1s = ((TT) - ((KP250000000) * (T1o)));
                            E T1w = KP559016994 * (T18 - T1n);
                            Cr[(csr[5])] = (((KP587785252) * (T1r)) + (T1s)) + (((KP951056516) * (T1v)) - (T1w));
                            Cr[(csr[10])] = T1w + (((KP587785252) * (T1v)) + (T1s)) - (KP951056516 * T1r);
                        }
                    }
                }
            }
        }
    }

    {
        E T21 = TS - TR;
        {
            E T2x = ((KP1_071653589 * T2a) - ((KP844327925) * (T29)));
            E T2y = ((KP998026728 * T2c) - ((KP125581039) * (T2d)));
            E T2z = T2x + T2y, T2L = T2y - T2x;
            E T2I = ((KP1_752613360 * T23) - ((KP481753674) * (T22)));
            E T2J = (((KP904827052) * (T25)) + (KP851558583 * T26));
            E T2K = T2I + T2J, T2M = T2I - T2J;
            {
                E T2D = (((KP535826794) * (T29)) + (KP1_688655851 * T2a));
                E T2E = (((KP062790519) * (T2c)) + (KP1_996053456 * T2d));
                E T2F = T2D + T2E, T2P = T2E - T2D;
                E T2A = (((KP876306680) * (T22)) + (KP963507348 * T23));
                E T2B = ((KP1_809654104 * T26) - ((KP425779291) * (T25)));
                E T2C = T2A + T2B, T2Q = T2A - T2B;
                {
                    E T2j = ((KP1_984229402 * T26) - ((KP125333233) * (T25)));
                    E T2k = (((KP684547105) * (T22)) + (KP1_457937254 * T23));
                    E T2l = T2j - T2k;
                    E T2m = ((KP1_274847979 * T2d) - ((KP770513242) * (T2c)));
                    E T2n = (((KP998026728) * (T29)) + (KP125581039 * T2a));
                    E T2o = T2m - T2n;
                    E T2p = T2l + T2o;
                    E T2w = T2k + T2j;
                    E T2u = T2n + T2m;
                    {
                        E T24 = ((KP728968627 * T22) - ((KP1_369094211) * (T23)));
                        E T27 = (((KP992114701) * (T25)) + (KP250666467 * T26));
                        E T28 = T24 - T27;
                        E T2b = ((KP062790519 * T29) - ((KP1_996053456) * (T2a)));
                        E T2e = (((KP637423989) * (T2c)) + (KP1_541026485 * T2d));
                        E T2f = T2b - T2e;
                        E T2g = T28 + T2f;
                        E T2s = T24 + T27;
                        E T2h = T2b + T2e;
                        Cr[(csr[1])] = T21 + T2g;
                        Ci[(csi[1])] = T2p - T2i;
                        E T2H = KP559016994 * (T2C - T2F);
                        E T2G = ((T21) - ((KP250000000) * (T2C + T2F)));
                        Cr[(csr[8])] = (((KP951056516) * (T2z)) + (T2G)) + (-(((KP587785252) * (T2K)) + (T2H)));
                        Cr[(csr[3])] = (((KP951056516) * (T2K)) + (KP587785252 * T2z)) + T2G + T2H;
                        E T2O = KP559016994 * (T2M + T2L);
                        E T2N = (((KP250000000) * (T2L - T2M)) + (T2i));
                        Ci[(csi[3])] = T2N + (((KP587785252) * (T2P)) + (T2O)) - (KP951056516 * T2Q);
                        Ci[(csi[8])] = (((KP587785252) * (T2Q)) + (T2N)) + (((KP951056516) * (T2P)) - (T2O));
                        {
                            E T2t = ((T21) - ((KP250000000) * (T2g)));
                            E T2v = KP559016994 * (T28 - T2f);
                            Cr[(csr[6])] = (((KP951056516) * (T2u)) + (T2t)) + (-(((KP587785252) * (T2w)) + (T2v)));
                            Cr[(csr[11])] = (((KP951056516) * (T2w)) + (T2v)) + (((KP587785252) * (T2u)) + (T2t));
                            E T2q = KP250000000 * T2p;
                            E T2r = KP559016994 * (T2l - T2o);
                            Ci[(csi[6])] = (((KP951056516) * (T2h)) - (T2i + T2q)) + (-(((KP587785252) * (T2s)) + (T2r)));
                            Ci[(csi[11])] = (((KP951056516) * (T2s)) + (KP587785252 * T2h)) + T2r - (T2i + T2q);
                        }
                    }
                }
            }
        }
    }
}
}
