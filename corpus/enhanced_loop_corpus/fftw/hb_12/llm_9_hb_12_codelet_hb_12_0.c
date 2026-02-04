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
extern  E KP500000000;
extern  E KP866025403;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m += 2 , cr = cr + (ms * 2) , ci = ci - (ms * 2) , W = W + 44 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;

    E T5_0, TH_0, T12_0, T1M_0, T1i_0, T1U_0, Tg_0, Tt_0, T19_0, T1X_0, T1p_0, T1P_0, Ta_0, TM_0, T15_0;
    E T1N_0, T1l_0, T1V_0, Tl_0, Ty_0, T1c_0, T1Y_0, T1s_0, T1Q_0;
    E T5_1, TH_1, T12_1, T1M_1, T1i_1, T1U_1, Tg_1, Tt_1, T19_1, T1X_1, T1p_1, T1P_1, Ta_1, TM_1, T15_1;
    E T1N_1, T1l_1, T1V_1, Tl_1, Ty_1, T1c_1, T1Y_1, T1s_1, T1Q_1;

    R *cr0 = cr, *ci0 = ci, *W0 = W;
    R *cr1 = cr + ms, *ci1 = ci - ms, *W1 = W + 22;

    #define LOAD_REAL(base, idx, rs_ptr) ((base)[(idx) == 0 ? 0 : (rs_ptr)[(idx)]])
    #define LOAD_IMAG(base, idx, rs_ptr) ((base)[(idx) == 0 ? 0 : (rs_ptr)[(idx)]])

    {
        E T1, TD, T4, T1g, TG, T11, T10, T1h;
        T1 = LOAD_REAL(cr0, 0, rs);
        TD = LOAD_IMAG(ci0, 11, rs);
        {
            E T2 = LOAD_REAL(cr0, 4, rs), T3 = LOAD_IMAG(ci0, 3, rs);
            T4 = T2 + T3;
            T1g = KP866025403 * (T2 - T3);
            E TE = LOAD_IMAG(ci0, 7, rs), TF = LOAD_REAL(cr0, 8, rs);
            TG = TE - TF;
            T11 = KP866025403 * (TE + TF);
        }
        T5_0 = T1 + T4;
        TH_0 = TD + TG;
        T10 = T1 - KP500000000 * T4;
        T12_0 = T10 - T11;
        T1M_0 = T10 + T11;
        T1h = TD - KP500000000 * TG;
        T1i_0 = T1g + T1h;
        T1U_0 = T1h - T1g;
    }

    {
        E Tc, Tp, Tf, T17, Ts, T1o, T18, T1n;
        Tc = LOAD_REAL(cr0, 3, rs);
        Tp = LOAD_IMAG(ci0, 8, rs);
        {
            E Td = LOAD_IMAG(ci0, 4, rs), Te = LOAD_IMAG(ci0, 0, rs);
            Tf = Td + Te;
            T17 = KP866025403 * (Td - Te);
            E Tq = LOAD_REAL(cr0, 7, rs), Tr = LOAD_REAL(cr0, 11, rs);
            Ts = Tq + Tr;
            T1o = KP866025403 * (Tq - Tr);
        }
        Tg_0 = Tc + Tf;
        Tt_0 = Tp - Ts;
        T18 = KP500000000 * Ts + Tp;
        T19_0 = T17 + T18;
        T1X_0 = T18 - T17;
        T1n = Tc - KP500000000 * Tf;
        T1p_0 = T1n + T1o;
        T1P_0 = T1n - T1o;
    }

    {
        E T6, TL, T9, T1j, TK, T14, T13, T1k;
        T6 = LOAD_IMAG(ci0, 5, rs);
        TL = LOAD_REAL(cr0, 6, rs);
        {
            E T7 = LOAD_IMAG(ci0, 1, rs), T8 = LOAD_REAL(cr0, 2, rs);
            T9 = T7 + T8;
            T1j = KP866025403 * (T7 - T8);
            E TI = LOAD_IMAG(ci0, 9, rs), TJ = LOAD_REAL(cr0, 10, rs);
            TK = TI - TJ;
            T14 = KP866025403 * (TI + TJ);
        }
        Ta_0 = T6 + T9;
        TM_0 = TK - TL;
        T13 = T6 - KP500000000 * T9;
        T15_0 = T13 + T14;
        T1N_0 = T13 - T14;
        T1k = KP500000000 * TK + TL;
        T1l_0 = T1j - T1k;
        T1V_0 = T1j + T1k;
    }

    {
        E Th, Tx, Tk, T1a, Tw, T1r, T1b, T1q;
        Th = LOAD_IMAG(ci0, 2, rs);
        Tx = LOAD_REAL(cr0, 9, rs);
        {
            E Ti = LOAD_REAL(cr0, 1, rs), Tj = LOAD_REAL(cr0, 5, rs);
            Tk = Ti + Tj;
            T1a = KP866025403 * (Ti - Tj);
            E Tu = LOAD_IMAG(ci0, 10, rs), Tv = LOAD_IMAG(ci0, 6, rs);
            Tw = Tu + Tv;
            T1r = KP866025403 * (Tv - Tu);
        }
        Tl_0 = Th + Tk;
        Ty_0 = Tw - Tx;
        T1b = KP500000000 * Tw + Tx;
        T1c_0 = T1a - T1b;
        T1Y_0 = T1a + T1b;
        T1q = Th - KP500000000 * Tk;
        T1s_0 = T1q + T1r;
        T1Q_0 = T1q - T1r;
    }

    {
        E Tb, Tm, TU, TW, TX, TY, TT, TV;
        Tb = T5_0 + Ta_0;
        Tm = Tg_0 + Tl_0;
        TU = Tb - Tm;
        TW = TH_0 + TM_0;
        TX = Tt_0 + Ty_0;
        TY = TW - TX;
        cr0[0] = Tb + Tm;
        ci0[0] = TW + TX;
        TT = W0[10]; TV = W0[11];
        cr0[(rs[6])] = TT * TU - TV * TY;
        ci0[(rs[6])] = TV * TU + TT * TY;
    }

    {
        E TA, TQ, TO, TS;
        TA = (T5_0 - Ta_0) - (Tt_0 - Ty_0);
        TQ = (T5_0 - Ta_0) + (Tt_0 - Ty_0);
        TO = (Tg_0 - Tl_0) + (TH_0 - TM_0);
        TS = (TH_0 - TM_0) - (Tg_0 - Tl_0);
        cr0[(rs[9])] = W0[16]*TA - W0[17]*TO;
        ci0[(rs[9])] = W0[16]*TO + W0[17]*TA;
        cr0[(rs[3])] = W0[4]*TQ - W0[5]*TS;
        ci0[(rs[3])] = W0[4]*TS + W0[5]*TQ;
    }

    {
        E T28 = (T1M_0 - T1N_0) - (T1X_0 + T1Y_0);
        E T2e = (T1M_0 - T1N_0) + (T1X_0 + T1Y_0);
        E T2c = (T1U_0 + T1V_0) + (T1P_0 - T1Q_0);
        E T2g = (T1U_0 + T1V_0) - (T1P_0 - T1Q_0);
        cr0[(rs[5])] = W0[8]*T28 - W0[9]*T2c;
        ci0[(rs[5])] = W0[8]*T2c + W0[9]*T28;
        cr0[(rs[11])] = W0[20]*T2e - W0[21]*T2g;
        ci0[(rs[11])] = W0[20]*T2g + W0[21]*T2e;
    }

    {
        E T1S = (T1M_0 + T1N_0) - (T1P_0 + T1Q_0);
        E T22 = (T1M_0 + T1N_0) + (T1P_0 + T1Q_0);
        E T20 = (T1U_0 - T1V_0) - (T1X_0 - T1Y_0);
        E T24 = (T1U_0 - T1V_0) + (T1X_0 - T1Y_0);
        cr0[(rs[2])] = W0[2]*T1S - W0[3]*T20;
        ci0[(rs[2])] = W0[3]*T1S + W0[2]*T20;
        cr0[(rs[8])] = W0[14]*T22 - W0[15]*T24;
        ci0[(rs[8])] = W0[15]*T22 + W0[14]*T24;
    }

    {
        E T1C = (T12_0 + T15_0) - (T1p_0 + T1s_0);
        E T1I = (T12_0 + T15_0) + (T1p_0 + T1s_0);
        E T1G = (T1i_0 + T1l_0) - (T19_0 + T1c_0);
        E T1K = (T1i_0 + T1l_0) + (T19_0 + T1c_0);
        cr0[(rs[10])] = W0[18]*T1C - W0[19]*T1G;
        ci0[(rs[10])] = W0[19]*T1C + W0[18]*T1G;
        cr0[(rs[4])] = W0[6]*T1I - W0[7]*T1K;
        ci0[(rs[4])] = W0[7]*T1I + W0[6]*T1K;
    }

    {
        E T1e = (T12_0 - T15_0) - (T19_0 - T1c_0);
        E T1w = (T12_0 - T15_0) + (T19_0 - T1c_0);
        E T1u = (T1i_0 - T1l_0) + (T1p_0 - T1s_0);
        E T1y = (T1i_0 - T1l_0) - (T1p_0 - T1s_0);
        cr0[(rs[1])] = W0[0]*T1e - W0[1]*T1u;
        ci0[(rs[1])] = W0[0]*T1u + W0[1]*T1e;
        cr0[(rs[7])] = W0[12]*T1w - W0[13]*T1y;
        ci0[(rs[7])] = W0[12]*T1y + W0[13]*T1w;
    }

    {
        E T1, TD, T4, T1g, TG, T11, T10, T1h;
        T1 = LOAD_REAL(cr1, 0, rs);
        TD = LOAD_IMAG(ci1, 11, rs);
        {
            E T2 = LOAD_REAL(cr1, 4, rs), T3 = LOAD_IMAG(ci1, 3, rs);
            T4 = T2 + T3;
            T1g = KP866025403 * (T2 - T3);
            E TE = LOAD_IMAG(ci1, 7, rs), TF = LOAD_REAL(cr1, 8, rs);
            TG = TE - TF;
            T11 = KP866025403 * (TE + TF);
        }
        T5_1 = T1 + T4;
        TH_1 = TD + TG;
        T10 = T1 - KP500000000 * T4;
        T12_1 = T10 - T11;
        T1M_1 = T10 + T11;
        T1h = TD - KP500000000 * TG;
        T1i_1 = T1g + T1h;
        T1U_1 = T1h - T1g;
    }

    {
        E Tc, Tp, Tf, T17, Ts, T1o, T18, T1n;
        Tc = LOAD_REAL(cr1, 3, rs);
        Tp = LOAD_IMAG(ci1, 8, rs);
        {
            E Td = LOAD_IMAG(ci1, 4, rs), Te = LOAD_IMAG(ci1, 0, rs);
            Tf = Td + Te;
            T17 = KP866025403 * (Td - Te);
            E Tq = LOAD_REAL(cr1, 7, rs), Tr = LOAD_REAL(cr1, 11, rs);
            Ts = Tq + Tr;
            T1o = KP866025403 * (Tq - Tr);
        }
        Tg_1 = Tc + Tf;
        Tt_1 = Tp - Ts;
        T18 = KP500000000 * Ts + Tp;
        T19_1 = T17 + T18;
        T1X_1 = T18 - T17;
        T1n = Tc - KP500000000 * Tf;
        T1p_1 = T1n + T1o;
        T1P_1 = T1n - T1o;
    }

    {
        E T6, TL, T9, T1j, TK, T14, T13, T1k;
        T6 = LOAD_IMAG(ci1, 5, rs);
        TL = LOAD_REAL(cr1, 6, rs);
        {
            E T7 = LOAD_IMAG(ci1, 1, rs), T8 = LOAD_REAL(cr1, 2, rs);
            T9 = T7 + T8;
            T1j = KP866025403 * (T7 - T8);
            E TI = LOAD_IMAG(ci1, 9, rs), TJ = LOAD_REAL(cr1, 10, rs);
            TK = TI - TJ;
            T14 = KP866025403 * (TI + TJ);
        }
        Ta_1 = T6 + T9;
        TM_1 = TK - TL;
        T13 = T6 - KP500000000 * T9;
        T15_1 = T13 + T14;
        T1N_1 = T13 - T14;
        T1k = KP500000000 * TK + TL;
        T1l_1 = T1j - T1k;
        T1V_1 = T1j + T1k;
    }

    {
        E Th, Tx, Tk, T1a, Tw, T1r, T1b, T1q;
        Th = LOAD_IMAG(ci1, 2, rs);
        Tx = LOAD_REAL(cr1, 9, rs);
        {
            E Ti = LOAD_REAL(cr1, 1, rs), Tj = LOAD_REAL(cr1, 5, rs);
            Tk = Ti + Tj;
            T1a = KP866025403 * (Ti - Tj);
            E Tu = LOAD_IMAG(ci1, 10, rs), Tv = LOAD_IMAG(ci1, 6, rs);
            Tw = Tu + Tv;
            T1r = KP866025403 * (Tv - Tu);
        }
        Tl_1 = Th + Tk;
        Ty_1 = Tw - Tx;
        T1b = KP500000000 * Tw + Tx;
        T1c_1 = T1a - T1b;
        T1Y_1 = T1a + T1b;
        T1q = Th - KP500000000 * Tk;
        T1s_1 = T1q + T1r;
        T1Q_1 = T1q - T1r;
    }

    {
        E Tb, Tm, TU, TW, TX, TY, TT, TV;
        Tb = T5_1 + Ta_1;
        Tm = Tg_1 + Tl_1;
        TU = Tb - Tm;
        TW = TH_1 + TM_1;
        TX = Tt_1 + Ty_1;
        TY = TW - TX;
        cr1[0] = Tb + Tm;
        ci1[0] = TW + TX;
        TT = W1[10]; TV = W1[11];
        cr1[(rs[6])] = TT * TU - TV * TY;
        ci1[(rs[6])] = TV * TU + TT * TY;
    }

    {
        E TA, TQ, TO, TS;
        TA = (T5_1 - Ta_1) - (Tt_1 - Ty_1);
        TQ = (T5_1 - Ta_1) + (Tt_1 - Ty_1);
        TO = (Tg_1 - Tl_1) + (TH_1 - TM_1);
        TS = (TH_1 - TM_1) - (Tg_1 - Tl_1);
        cr1[(rs[9])] = W1[16]*TA - W1[17]*TO;
        ci1[(rs[9])] = W1[16]*TO + W1[17]*TA;
        cr1[(rs[3])] = W1[4]*TQ - W1[5]*TS;
        ci1[(rs[3])] = W1[4]*TS + W1[5]*TQ;
    }

    {
        E T28 = (T1M_1 - T1N_1) - (T1X_1 + T1Y_1);
        E T2e = (T1M_1 - T1N_1) + (T1X_1 + T1Y_1);
        E T2c = (T1U_1 + T1V_1) + (T1P_1 - T1Q_1);
        E T2g = (T1U_1 + T1V_1) - (T1P_1 - T1Q_1);
        cr1[(rs[5])] = W1[8]*T28 - W1[9]*T2c;
        ci1[(rs[5])] = W1[8]*T2c + W1[9]*T28;
        cr1[(rs[11])] = W1[20]*T2e - W1[21]*T2g;
        ci1[(rs[11])] = W1[20]*T2g + W1[21]*T2e;
    }

    {
        E T1S = (T1M_1 + T1N_1) - (T1P_1 + T1Q_1);
        E T22 = (T1M_1 + T1N_1) + (T1P_1 + T1Q_1);
        E T20 = (T1U_1 - T1V_1) - (T1X_1 - T1Y_1);
        E T24 = (T1U_1 - T1V_1) + (T1X_1 - T1Y_1);
        cr1[(rs[2])] = W1[2]*T1S - W1[3]*T20;
        ci1[(rs[2])] = W1[3]*T1S + W1[2]*T20;
        cr1[(rs[8])] = W1[14]*T22 - W1[15]*T24;
        ci1[(rs[8])] = W1[15]*T22 + W1[14]*T24;
    }

    {
        E T1C = (T12_1 + T15_1) - (T1p_1 + T1s_1);
        E T1I = (T12_1 + T15_1) + (T1p_1 + T1s_1);
        E T1G = (T1i_1 + T1l_1) - (T19_1 + T1c_1);
        E T1K = (T1i_1 + T1l_1) + (T19_1 + T1c_1);
        cr1[(rs[10])] = W1[18]*T1C - W1[19]*T1G;
        ci1[(rs[10])] = W1[19]*T1C + W1[18]*T1G;
        cr1[(rs[4])] = W1[6]*T1I - W1[7]*T1K;
        ci1[(rs[4])] = W1[7]*T1I + W1[6]*T1K;
    }

    {
        E T1e = (T12_1 - T15_1) - (T19_1 - T1c_1);
        E T1w = (T12_1 - T15_1) + (T19_1 - T1c_1);
        E T1u = (T1i_1 - T1l_1) + (T1p_1 - T1s_1);
        E T1y = (T1i_1 - T1l_1) - (T1p_1 - T1s_1);
        cr1[(rs[1])] = W1[0]*T1e - W1[1]*T1u;
        ci1[(rs[1])] = W1[0]*T1u + W1[1]*T1e;
        cr1[(rs[7])] = W1[12]*T1w - W1[13]*T1y;
        ci1[(rs[7])] = W1[12]*T1y + W1[13]*T1w;
    }
}

}
