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
extern  E KP998026728;
extern  E KP062790519;
extern  E KP992114701;
extern  E KP125333233;
extern  E KP425779291;
extern  E KP904827052;
extern  E KP248689887;
extern  E KP968583161;
extern  E KP770513242;
extern  E KP637423989;
extern  E KP844327925;
extern  E KP535826794;
extern  E KP684547105;
extern  E KP728968627;
extern  E KP481753674;
extern  E KP876306680;
extern  E KP559016994;
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT step = 2;
for (m = mb; m < me; m += step, cr += ms * step, ci -= ms * step, W += 48 * step, (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;

    E T9, T5Q, T3y, T39, T5v, Ti, Tr, Ts, TZ, T18, T1z, T2k, T4l, T3h, T44;
    E T5d, T6C, T5C, T6o, T56, T6B, T5B, T6l, T2z, T4m, T3i, T47, T1K, T5w, T3c;
    E T3B, T5R, TB, TK, TL, T1i, T1r, T1A, T2P, T4o, T3k, T4b, T5s, T6F, T5F;
    E T6v, T5l, T6E, T5E, T6s, T34, T4p, T3l, T4e;

    for (INT iter = 0; iter < 2; ++iter) {
        R *local_cr = cr + (iter * ms);
        R *local_ci = ci - (iter * ms);
        R *local_W = W + (iter * 48);
        stride local_rs = rs;

        {
            E T1, T4, T7, T8, T3x, T3w, T37, T38;
            T1 = local_cr[0];
            {
                E T2, T3, T5, T6;
                T2 = local_cr[(local_rs[5])];
                T3 = local_ci[(local_rs[4])];
                T4 = T2 + T3;
                T5 = local_cr[(local_rs[10])];
                T6 = local_ci[(local_rs[9])];
                T7 = T5 + T6;
                T8 = T4 + T7;
                T3x = T5 - T6;
                T3w = T2 - T3;
            }
            E local_T9 = T1 + T8;
            E local_T5Q = (((KP951056516) * (T3w)) + (KP587785252 * T3x));
            E local_T3y = ((KP587785252 * T3w) - ((KP951056516) * (T3x)));
            E local_T37 = ((T1) - ((KP250000000) * (T8)));
            E local_T38 = KP559016994 * (T4 - T7);
            E local_T39 = local_T37 - local_T38;
            E local_T5v = local_T38 + local_T37;

            local_cr[0] = local_T9;
            local_ci[0] = local_T9; 
        }

        {
            E Ta, T27, T53, T2f, Th, T26, T10, T2p, T58, T2x, T17, T2o, Tj, T2n, T5a;
            E T2t, Tq, T2s, TR, T2b, T51, T2h, TY, T2g;
            {
                E Tg, T2e, Td, T2d;
                Ta = local_cr[(local_rs[1])];
                {
                    E Te, Tf, Tb, Tc;
                    Te = local_cr[(local_rs[11])];
                    Tf = local_ci[(local_rs[8])];
                    Tg = Te + Tf;
                    T2e = Te - Tf;
                    Tb = local_cr[(local_rs[6])];
                    Tc = local_ci[(local_rs[3])];
                    Td = Tb + Tc;
                    T2d = Tb - Tc;
                }
                T27 = KP559016994 * (Td - Tg);
                T53 = (((KP951056516) * (T2d)) + (KP587785252 * T2e));
                T2f = ((KP587785252 * T2d) - ((KP951056516) * (T2e)));
                Th = Td + Tg;
                T26 = ((Ta) - ((KP250000000) * (Th)));
            }
            {
                E T16, T2w, T13, T2v;
                T10 = local_ci[(local_rs[20])];
                {
                    E T14, T15, T11, T12;
                    T14 = local_cr[(local_rs[14])];
                    T15 = local_cr[(local_rs[19])];
                    T16 = T14 + T15;
                    T2w = T15 - T14;
                    T11 = local_ci[(local_rs[15])];
                    T12 = local_cr[(local_rs[24])];
                    T13 = T11 - T12;
                    T2v = T11 + T12;
                }
                T2p = KP559016994 * (T13 + T16);
                T58 = (((KP951056516) * (T2v)) + (KP587785252 * T2w));
                T2x = ((KP587785252 * T2v) - ((KP951056516) * (T2w)));
                T17 = T13 - T16;
                T2o = ((T10) - ((KP250000000) * (T17)));
            }
            {
                E Tp, T2m, Tm, T2l;
                Tj = local_cr[(local_rs[4])];
                {
                    E Tn, To, Tk, Tl;
                    Tn = local_ci[(local_rs[10])];
                    To = local_ci[(local_rs[5])];
                    Tp = Tn + To;
                    T2m = Tn - To;
                    Tk = local_cr[(local_rs[9])];
                    Tl = local_ci[0];
                    Tm = Tk + Tl;
                    T2l = Tk - Tl;
                }
                T2n = ((KP587785252 * T2l) - ((KP951056516) * (T2m)));
                T5a = (((KP951056516) * (T2l)) + (KP587785252 * T2m));
                T2t = KP559016994 * (Tm - Tp);
                Tq = Tm + Tp;
                T2s = ((Tj) - ((KP250000000) * (Tq)));
            }
            {
                E TX, T2a, TU, T29;
                TR = local_ci[(local_rs[23])];
                {
                    E TV, TW, TS, TT;
                    TV = local_ci[(local_rs[13])];
                    TW = local_cr[(local_rs[16])];
                    TX = TV - TW;
                    T2a = TV + TW;
                    TS = local_ci[(local_rs[18])];
                    TT = local_cr[(local_rs[21])];
                    TU = TS - TT;
                    T29 = TS + TT;
                }
                T2b = ((KP587785252 * T29) - ((KP951056516) * (T2a)));
                T51 = (((KP951056516) * (T29)) + (KP587785252 * T2a));
                T2h = KP559016994 * (TU - TX);
                TY = TU + TX;
                T2g = ((TR) - ((KP250000000) * (TY)));
            }
            Ti = Ta + Th;
            Tr = Tj + Tq;
            Ts = Ti + Tr;
            TZ = TR + TY;
            T18 = T10 + T17;
            T1z = TZ + T18;
            {
                E T2c, T42, T2j, T43, T28, T2i;
                T28 = T26 - T27;
                T2c = T28 - T2b;
                T42 = T28 + T2b;
                T2i = T2g - T2h;
                T2j = T2f + T2i;
                T43 = T2i - T2f;
                T2k = ((KP876306680 * T2c) - ((KP481753674) * (T2j)));
                T4l = (((KP728968627) * (T43)) + (KP684547105 * T42));
                T3h = (((KP876306680) * (T2j)) + (KP481753674 * T2c));
                T44 = ((KP728968627 * T42) - ((KP684547105) * (T43)));
            }
            {
                E T59, T6n, T5c, T6m, T57, T5b;
                T57 = T2t + T2s;
                T59 = T57 - T58;
                T6n = T57 + T58;
                T5b = T2o + T2p;
                T5c = T5a + T5b;
                T6m = T5b - T5a;
                T5d = ((KP535826794 * T59) - ((KP844327925) * (T5c)));
                T6C = (((KP637423989) * (T6m)) + (KP770513242 * T6n));
                T5C = (((KP535826794) * (T5c)) + (KP844327925 * T59));
                T6o = ((KP770513242 * T6m) - ((KP637423989) * (T6n)));
            }
            {
                E T52, T6j, T55, T6k, T50, T54;
                T50 = T27 + T26;
                T52 = T50 - T51;
                T6j = T50 + T51;
                T54 = T2h + T2g;
                T55 = T53 + T54;
                T6k = T54 - T53;
                T56 = ((KP968583161 * T52) - ((KP248689887) * (T55)));
                T6B = (((KP535826794) * (T6k)) + (KP844327925 * T6j));
                T5B = (((KP968583161) * (T55)) + (KP248689887 * T52));
                T6l = ((KP535826794 * T6j) - ((KP844327925) * (T6k)));
            }
            {
                E T2r, T45, T2y, T46, T2q, T2u;
                T2q = T2o - T2p;
                T2r = T2n + T2q;
                T45 = T2q - T2n;
                T2u = T2s - T2t;
                T2y = T2u - T2x;
                T46 = T2u + T2x;
                T2z = (((KP904827052) * (T2r)) + (KP425779291 * T2y));
                T4m = ((KP125333233 * T46) - ((KP992114701) * (T45)));
                T3i = ((KP904827052 * T2y) - ((KP425779291) * (T2r)));
                T47 = (((KP125333233) * (T45)) + (KP992114701 * T46));
            }
        }

        {
            E TM, TQ, T1U, T1L, T1N, T1Z, T1t, T1V, T1y, T1Y;
            {
                E TO, TP, T1B, T1M;
                TO = KP559016994 * (Ts - TL);
                TM = Ts + TL;
                TP = ((T9) - ((KP250000000) * (TM)));
                TQ = TO + TP;
                T1U = TP - TO;
                T1B = KP559016994 * (T1z - T1A);
                T1L = T1z + T1A;
                T1M = ((T1K) - ((KP250000000) * (T1L)));
                T1N = T1B + T1M;
                T1Z = T1M - T1B;
            }
            {
                E T19, T1s, T1w, T1x;
                T19 = TZ - T18;
                T1s = T1i - T1r;
                T1t = (((KP951056516) * (T19)) + (KP587785252 * T1s));
                T1V = ((KP587785252 * T19) - ((KP951056516) * (T1s)));
                T1w = Ti - Tr;
                T1x = TB - TK;
                T1y = (((KP951056516) * (T1w)) + (KP587785252 * T1x));
                T1Y = ((KP587785252 * T1w) - ((KP951056516) * (T1x)));
            }
            local_cr[0] = T9 + TM;
            local_ci[0] = T1K + T1L;
            {
                E T1u, T1O, TN, T1v;
                T1u = TQ - T1t;
                T1O = T1y + T1N;
                TN = local_W[8];
                T1v = local_W[9];
                local_cr[(local_rs[5])] = ((TN * T1u) - ((T1v) * (T1O)));
                local_ci[(local_rs[5])] = (((T1v) * (T1u)) + (TN * T1O));
            }
        }
    }
}
}
