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
extern  E KP293892626;
extern  E KP475528258;
extern  E KP125000000;
extern  E KP500000000;
extern  E KP279508497;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 18); m < me; m = m + 2 , Rp = Rp + (ms * 2) , Ip = Ip + (ms * 2) , Rm = Rm - (ms * 2) , Im = Im - (ms * 2) , W = W + 36 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E Tw, TL, TM, T1W, T1X, T27, T1Z, T20, T26, TX, T1a, T1b, T1d, T1e, T1f;
    E T1q, T1t, T1u, T1x, T1A, T1B, T1g, T1h, T1i, Td, T25, T1k, T1F;
    E Tw2, TL2, TM2, T1W2, T1X2, T272, T1Z2, T202, T262, TX2, T1a2, T1b2, T1d2, T1e2, T1f2;
    E T1q2, T1t2, T1u2, T1x2, T1A2, T1B2, T1g2, T1h2, T1i2, Td2, T252, T1k2, T1F2;

    {
        E T3, T1D, T19, T1z, T7, Tb, TR, T1v, Tm, T1o, TK, T1s, Tv, T1p, T12;
        E T1y, TF, T1r, TW, T1w;
        {
            E T1, T2, T18, T14, T15, T16, T13, T17;
            T1 = Ip[0];
            T2 = Im[0];
            T18 = T1 + T2;
            T14 = Rm[0];
            T15 = Rp[0];
            T16 = T14 - T15;
            T3 = T1 - T2;
            T1D = T15 + T14;
            T13 = W[0];
            T17 = W[1];
            T19 = ((T13 * T16) - ((T17) * (T18)));
            T1z = (((T17) * (T16)) + (T13 * T18));
        }
        {
            E T5, T6, TO, T9, Ta, TQ, TN, TP;
            T5 = Ip[(rs[2])];
            T6 = Im[(rs[2])];
            TO = T5 - T6;
            T9 = Rp[(rs[2])];
            Ta = Rm[(rs[2])];
            TQ = T9 + Ta;
            T7 = T5 + T6;
            Tb = T9 - Ta;
            TN = W[6];
            TP = W[7];
            TR = ((TN * TO) - ((TP) * (TQ)));
            T1v = (((TP) * (TO)) + (TN * TQ));
        }
        {
            E Th, TJ, Tl, TH;
            {
                E Tf, Tg, Tj, Tk;
                Tf = Ip[(rs[1])];
                Tg = Im[(rs[1])];
                Th = Tf - Tg;
                TJ = Tf + Tg;
                Tj = Rp[(rs[1])];
                Tk = Rm[(rs[1])];
                Tl = Tj + Tk;
                TH = Tj - Tk;
            }
            {
                E Te, Ti, TG, TI;
                Te = W[2];
                Ti = W[3];
                Tm = ((Te * Th) - ((Ti) * (Tl)));
                T1o = (((Te) * (Tl)) + (Ti * Th));
                TG = W[4];
                TI = W[5];
                TK = (((TG) * (TH)) + (TI * TJ));
                T1s = ((TG * TJ) - ((TI) * (TH)));
            }
        }
        {
            E Tq, TZ, Tu, T11;
            {
                E To, Tp, Ts, Tt;
                To = Ip[(rs[3])];
                Tp = Im[(rs[3])];
                Tq = To + Tp;
                TZ = To - Tp;
                Ts = Rp[(rs[3])];
                Tt = Rm[(rs[3])];
                Tu = Ts - Tt;
                T11 = Ts + Tt;
            }
            {
                E Tn, Tr, TY, T10;
                Tn = W[13];
                Tr = W[12];
                Tv = (((Tn) * (Tq)) + (Tr * Tu));
                T1p = ((Tr * Tq) - ((Tn) * (Tu)));
                TY = W[10];
                T10 = W[11];
                T12 = ((TY * TZ) - ((T10) * (T11)));
                T1y = (((T10) * (TZ)) + (TY * T11));
            }
        }
        {
            E TA, TV, TE, TT;
            {
                E Ty, Tz, TC, TD;
                Ty = Ip[(rs[4])];
                Tz = Im[(rs[4])];
                TA = Ty - Tz;
                TV = Ty + Tz;
                TC = Rp[(rs[4])];
                TD = Rm[(rs[4])];
                TE = TC + TD;
                TT = TC - TD;
            }
            {
                E Tx, TB, TS, TU;
                Tx = W[14];
                TB = W[15];
                TF = ((Tx * TA) - ((TB) * (TE)));
                T1r = (((Tx) * (TE)) + (TB * TA));
                TS = W[16];
                TU = W[17];
                TW = (((TS) * (TT)) + (TU * TV));
                T1w = ((TS * TV) - ((TU) * (TT)));
            }
        }
        Tw = Tm - Tv;
        TL = TF - TK;
        TM = Tw + TL;
        T1W = T1v + T1w;
        T1X = T1y + T1z;
        T27 = T1W + T1X;
        T1Z = T1o + T1p;
        T20 = T1s + T1r;
        T26 = T1Z + T20;
        TX = TR - TW;
        T1a = T12 + T19;
        T1b = TX + T1a;
        T1d = T19 - T12;
        T1e = TR + TW;
        T1f = T1d - T1e;
        T1q = T1o - T1p;
        T1t = T1r - T1s;
        T1u = T1q + T1t;
        T1x = T1v - T1w;
        T1A = T1y - T1z;
        T1B = T1x + T1A;
        T1g = Tm + Tv;
        T1h = TK + TF;
        T1i = T1g + T1h;
        {
            E Tc, T1E, T4, T8;
            T4 = W[9];
            T8 = W[8];
            Tc = (((T4) * (T7)) + (T8 * Tb));
            T1E = ((T8 * T7) - ((T4) * (Tb)));
            Td = T3 - Tc;
            T25 = T1D + T1E;
            T1k = Tc + T3;
            T1F = T1D - T1E;
        }
    }

    {
        E T3_2, T1D_2, T19_2, T1z_2, T7_2, Tb_2, TR_2, T1v_2, Tm_2, T1o_2, TK_2, T1s_2, Tv_2, T1p_2, T12_2;
        E T1y_2, TF_2, T1r_2, TW_2, T1w_2;
        {
            E T1_2, T2_2, T18_2, T14_2, T15_2, T16_2, T13_2, T17_2;
            T1_2 = Ip[ms];
            T2_2 = Im[ms];
            T18_2 = T1_2 + T2_2;
            T14_2 = Rm[-ms];
            T15_2 = Rp[ms];
            T16_2 = T14_2 - T15_2;
            T3_2 = T1_2 - T2_2;
            T1D_2 = T15_2 + T14_2;
            T13_2 = W[18];
            T17_2 = W[19];
            T19_2 = ((T13_2 * T16_2) - ((T17_2) * (T18_2)));
            T1z_2 = (((T17_2) * (T16_2)) + (T13_2 * T18_2));
        }
        {
            E T5_2, T6_2, TO_2, T9_2, Ta_2, TQ_2, TN_2, TP_2;
            T5_2 = Ip[(rs[2]) + ms];
            T6_2 = Im[(rs[2]) + ms];
            TO_2 = T5_2 - T6_2;
            T9_2 = Rp[(rs[2]) + ms];
            Ta_2 = Rm[(rs[2]) - ms];
            TQ_2 = T9_2 + Ta_2;
            T7_2 = T5_2 + T6_2;
            Tb_2 = T9_2 - Ta_2;
            TN_2 = W[24];
            TP_2 = W[25];
            TR_2 = ((TN_2 * TO_2) - ((TP_2) * (TQ_2)));
            T1v_2 = (((TP_2) * (TO_2)) + (TN_2 * TQ_2));
        }
        {
            E Th_2, TJ_2, Tl_2, TH_2;
            {
                E Tf_2, Tg_2, Tj_2, Tk_2;
                Tf_2 = Ip[(rs[1]) + ms];
                Tg_2 = Im[(rs[1]) + ms];
                Th_2 = Tf_2 - Tg_2;
                TJ_2 = Tf_2 + Tg_2;
                Tj_2 = Rp[(rs[1]) + ms];
                Tk_2 = Rm[(rs[1]) - ms];
                Tl_2 = Tj_2 + Tk_2;
                TH_2 = Tj_2 - Tk_2;
            }
            {
                E Te_2, Ti_2, TG_2, TI_2;
                Te_2 = W[20];
                Ti_2 = W[21];
                Tm_2 = ((Te_2 * Th_2) - ((Ti_2) * (Tl_2)));
                T1o_2 = (((Te_2) * (Tl_2)) + (Ti_2 * Th_2));
                TG_2 = W[22];
                TI_2 = W[23];
                TK_2 = (((TG_2) * (TH_2)) + (TI_2 * TJ_2));
                T1s_2 = ((TG_2 * TJ_2) - ((TI_2) * (TH_2)));
            }
        }
        {
            E Tq_2, TZ_2, Tu_2, T11_2;
            {
                E To_2, Tp_2, Ts_2, Tt_2;
                To_2 = Ip[(rs[3]) + ms];
                Tp_2 = Im[(rs[3]) + ms];
                Tq_2 = To_2 + Tp_2;
                TZ_2 = To_2 - Tp_2;
                Ts_2 = Rp[(rs[3]) + ms];
                Tt_2 = Rm[(rs[3]) - ms];
                Tu_2 = Ts_2 - Tt_2;
                T11_2 = Ts_2 + Tt_2;
            }
            {
                E Tn_2, Tr_2, TY_2, T10_2;
                Tn_2 = W[31];
                Tr_2 = W[30];
                Tv_2 = (((Tn_2) * (Tq_2)) + (Tr_2 * Tu_2));
                T1p_2 = ((Tr_2 * Tq_2) - ((Tn_2) * (Tu_2)));
                TY_2 = W[28];
                T10_2 = W[29];
                T12_2 = ((TY_2 * TZ_2) - ((T10_2) * (T11_2)));
                T1y_2 = (((T10_2) * (TZ_2)) + (TY_2 * T11_2));
            }
        }
        {
            E TA_2, TV_2, TE_2, TT_2;
            {
                E Ty_2, Tz_2, TC_2, TD_2;
                Ty_2 = Ip[(rs[4]) + ms];
                Tz_2 = Im[(rs[4]) + ms];
                TA_2 = Ty_2 - Tz_2;
                TV_2 = Ty_2 + Tz_2;
                TC_2 = Rp[(rs[4]) + ms];
                TD_2 = Rm[(rs[4]) - ms];
                TE_2 = TC_2 + TD_2;
                TT_2 = TC_2 - TD_2;
            }
            {
                E Tx_2, TB_2, TS_2, TU_2;
                Tx_2 = W[32];
                TB_2 = W[33];
                TF_2 = ((Tx_2 * TA_2) - ((TB_2) * (TE_2)));
                T1r_2 = (((Tx_2) * (TE_2)) + (TB_2 * TA_2));
                TS_2 = W[34];
                TU_2 = W[35];
                TW_2 = (((TS_2) * (TT_2)) + (TU_2 * TV_2));
                T1w_2 = ((TS_2 * TV_2) - ((TU_2) * (TT_2)));
            }
        }
        Tw2 = Tm_2 - Tv_2;
        TL2 = TF_2 - TK_2;
        TM2 = Tw2 + TL2;
        T1W2 = T1v_2 + T1w_2;
        T1X2 = T1y_2 + T1z_2;
        T272 = T1W2 + T1X2;
        T1Z2 = T1o_2 + T1p_2;
        T202 = T1s_2 + T1r_2;
        T262 = T1Z2 + T202;
        TX2 = TR_2 - TW_2;
        T1a2 = T12_2 + T19_2;
        T1b2 = TX2 + T1a2;
        T1d2 = T19_2 - T12_2;
        T1e2 = TR_2 + TW_2;
        T1f2 = T1d2 - T1e2;
        T1q2 = T1o_2 - T1p_2;
        T1t2 = T1r_2 - T1s_2;
        T1u2 = T1q2 + T1t2;
        T1x2 = T1v_2 - T1w_2;
        T1A2 = T1y_2 - T1z_2;
        T1B2 = T1x2 + T1A2;
        T1g2 = Tm_2 + Tv_2;
        T1h2 = TK_2 + TF_2;
        T1i2 = T1g2 + T1h2;
        {
            E Tc_2, T1E_2, T4_2, T8_2;
            T4_2 = W[27];
            T8_2 = W[26];
            Tc_2 = (((T4_2) * (T7_2)) + (T8_2 * Tb_2));
            T1E_2 = ((T8_2 * T7_2) - ((T4_2) * (Tb_2)));
            Td2 = T3_2 - Tc_2;
            T252 = T1D_2 + T1E_2;
            T1k2 = Tc_2 + T3_2;
            T1F2 = T1D_2 - T1E_2;
        }
    }

    {
        E T1U, T1c, T1T, T22, T24, T1Y, T21, T23, T1V;
        T1U = KP279508497 * (TM - T1b);
        T1c = TM + T1b;
        T1T = ((KP500000000 * Td) - ((KP125000000) * (T1c)));
        T1Y = T1W - T1X;
        T21 = T1Z - T20;
        T22 = ((KP475528258 * T1Y) - ((KP293892626) * (T21)));
        T24 = (((KP475528258) * (T21)) + (KP293892626 * T1Y));
        Ip[0] = KP500000000 * (Td + T1c);
        T23 = T1U + T1T;
        Ip[(rs[4])] = T23 + T24;
        Im[(rs[3])] = T24 - T23;
        T1V = T1T - T1U;
        Ip[(rs[2])] = T1V + T22;
        Im[(rs[1])] = T22 - T1V;
    }

    {
        E T1U2, T1c2, T1T2, T222, T242, T1Y2, T212, T232, T1V2;
        T1U2 = KP279508497 * (TM2 - T1b2);
        T1c2 = TM2 + T1b2;
        T1T2 = ((KP500000000 * Td2) - ((KP125000000) * (T1c2)));
        T1Y2 = T1W2 - T1X2;
        T212 = T1Z2 - T202;
        T222 = ((KP475528258 * T1Y2) - ((KP293892626) * (T212)));
        T242 = (((KP475528258) * (T212)) + (KP293892626 * T1Y2));
        Ip[ms] = KP500000000 * (Td2 + T1c2);
        T232 = T1U2 + T1T2;
        Ip[(rs[4]) + ms] = T232 + T242;
        Im[(rs[3]) + ms] = T242 - T232;
        T1V2 = T1T2 - T1U2;
        Ip[(rs[2]) + ms] = T1V2 + T222;
        Im[(rs[1]) + ms] = T222 - T1V2;
    }

    {
        E T2a, T28, T29, T2e, T2g, T2c, T2d, T2f, T2b;
        T2a = KP279508497 * (T26 - T27);
        T28 = T26 + T27;
        T29 = ((KP500000000 * T25) - ((KP125000000) * (T28)));
        T2c = TX - T1a;
        T2d = Tw - TL;
        T2e = ((KP475528258 * T2c) - ((KP293892626) * (T2d)));
        T2g = (((KP475528258) * (T2d)) + (KP293892626 * T2c));
        Rp[0] = KP500000000 * (T25 + T28);
        T2f = T2a + T29;
        Rp[(rs[4])] = T2f - T2g;
        Rm[(rs[3])] = T2g + T2f;
        T2b = T29 - T2a;
        Rp[(rs[2])] = T2b - T2e;
        Rm[(rs[1])] = T2e + T2b;
    }

    {
        E T2a2, T282, T292, T2e2, T2g2, T2c2, T2d2, T2f2, T2b2;
        T2a2 = KP279508497 * (T262 - T272);
        T282 = T262 + T272;
        T292 = ((KP500000000 * T252) - ((KP125000000) * (T282)));
        T2c2 = TX2 - T1a2;
        T2d2 = Tw2 - TL2;
        T2e2 = ((KP475528258 * T2c2) - ((KP293892626) * (T2d2)));
        T2g2 = (((KP475528258) * (T2d2)) + (KP293892626 * T2c2));
        Rp[ms] = KP500000000 * (T252 + T282);
        T2f2 = T2a2 + T292;
        Rp[(rs[4]) + ms] = T2f2 - T2g2;
        Rm[(rs[3]) - ms] = T2g2 + T2f2;
        T2b2 = T292 - T2a2;
        Rp[(rs[2]) + ms] = T2b2 - T2e2;
        Rm[(rs[1]) - ms] = T2e2 + T2b2;
    }

    {
        E T1M, T1j, T1L, T1Q, T1S, T1O, T1P, T1R, T1N;
        T1M = KP279508497 * (T1i + T1f);
        T1j = T1f - T1i;
        T1L = (((KP500000000) * (T1k)) + (KP125000000 * T1j));
        T1O = T1A - T1x;
        T1P = T1q - T1t;
        T1Q = ((KP293892626 * T1O) - ((KP475528258) * (T1P)));
        T1S = (((KP293892626) * (T1P)) + (KP475528258 * T1O));
        Im[(rs[4])] = KP500000000 * (T1j - T1k);
        T1R = T1L - T1M;
        Ip[(rs[3])] = T1R + T1S;
        Im[(rs[2])] = T1S - T1R;
        T1N = T1L + T1M;
        Ip[(rs[1])] = T1N + T1Q;
        Im[0] = T1Q - T1N;
    }

    {
        E T1M2, T1j2, T1L2, T1Q2, T1S2, T1O2, T1P2, T1R2, T1N2;
        T1M2 = KP279508497 * (T1i2 + T1f2);
        T1j2 = T1f2 - T1i2;
        T1L2 = (((KP500000000) * (T1k2)) + (KP125000000 * T1j2));
        T1O2 = T1A2 - T1x2;
        T1P2 = T1q2 - T1t2;
        T1Q2 = ((KP293892626 * T1O2) - ((KP475528258) * (T1P2)));
        T1S2 = (((KP293892626) * (T1P2)) + (KP475528258 * T1O2));
        Im[(rs[4]) + ms] = KP500000000 * (T1j2 - T1k2);
        T1R2 = T1L2 - T1M2;
        Ip[(rs[3]) + ms] = T1R2 + T1S2;
        Im[(rs[2]) + ms] = T1S2 - T1R2;
        T1N2 = T1L2 + T1M2;
        Ip[(rs[1]) + ms] = T1N2 + T1Q2;
        Im[ms] = T1Q2 - T1N2;
    }

    {
        E T1C, T1G, T1H, T1n, T1J, T1l, T1m, T1K, T1I;
        T1C = KP279508497 * (T1u - T1B);
        T1G = T1u + T1B;
        T1H = ((KP500000000 * T1F) - ((KP125000000) * (T1G)));
        T1l = T1g - T1h;
        T1m = T1e + T1d;
        T1n = (((KP475528258) * (T1l)) + (KP293892626 * T1m));
        T1J = ((KP475528258 * T1m) - ((KP293892626) * (T1l)));
        Rm[(rs[4])] = KP500000000 * (T1F + T1G);
        T1K = T1H - T1C;
        Rp[(rs[3])] = T1J + T1K;
        Rm[(rs[2])] = T1K - T1J;
        T1I = T1C + T1H;
        Rp[(rs[1])] = T1n + T1I;
        Rm[0] = T1I - T1n;
    }

    {
        E T1C2, T1G2, T1H2, T1n2, T1J2, T1l2, T1m2, T1K2, T1I2;
        T1C2 = KP279508497 * (T1u2 - T1B2);
        T1G2 = T1u2 + T1B2;
        T1H2 = ((KP500000000 * T1F2) - ((KP125000000) * (T1G2)));
        T1l2 = T1g2 - T1h2;
        T1m2 = T1e2 + T1d2;
        T1n2 = (((KP475528258) * (T1l2)) + (KP293892626 * T1m2));
        T1J2 = ((KP475528258 * T1m2) - ((KP293892626) * (T1l2)));
        Rm[(rs[4]) - ms] = KP500000000 * (T1F2 + T1G2);
        T1K2 = T1H2 - T1C2;
        Rp[(rs[3]) + ms] = T1J2 + T1K2;
        Rm[(rs[2]) + ms] = T1K2 - T1J2;
        T1I2 = T1C2 + T1H2;
        Rp[(rs[1]) + ms] = T1n2 + T1I2;
        Rm[-ms] = T1I2 - T1n2;
    }
}
}
