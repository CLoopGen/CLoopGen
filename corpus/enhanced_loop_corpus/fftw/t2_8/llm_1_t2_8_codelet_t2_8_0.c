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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 6); m < me; m = m + 2 , ri = ri + (ms * 2), ii = ii + (ms * 2), W = W + 12 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;
    {
        E T2_0, T5_0, T3_0, T6_0, T8_0, Tc_0, Tg_0, Ti_0, Tl_0, Tm_0, Tn_0, Tz_0, Tp_0, Tx_0;
        E T2_1, T5_1, T3_1, T6_1, T8_1, Tc_1, Tg_1, Ti_1, Tl_1, Tm_1, Tn_1, Tz_1, Tp_1, Tx_1;
        {
            E T4_0, Tb_0, T7_0, Ta_0;
            T2_0 = W[0];
            T5_0 = W[1];
            T3_0 = W[2];
            T6_0 = W[3];
            T4_0 = T2_0 * T3_0;
            Tb_0 = T5_0 * T3_0;
            T7_0 = T5_0 * T6_0;
            Ta_0 = T2_0 * T6_0;
            T8_0 = T4_0 - T7_0;
            Tc_0 = Ta_0 + Tb_0;
            Tg_0 = T4_0 + T7_0;
            Ti_0 = Ta_0 - Tb_0;
            Tl_0 = W[4];
            Tm_0 = W[5];
            Tn_0 = (((T2_0) * (Tl_0)) + (T5_0 * Tm_0));
            Tz_0 = ((Tg_0 * Tm_0) - ((Ti_0) * (Tl_0)));
            Tp_0 = ((T2_0 * Tm_0) - ((T5_0) * (Tl_0)));
            Tx_0 = (((Tg_0) * (Tl_0)) + (Ti_0 * Tm_0));
        }
        {
            E T4_1, Tb_1, T7_1, Ta_1;
            T2_1 = W[6];
            T5_1 = W[7];
            T3_1 = W[8];
            T6_1 = W[9];
            T4_1 = T2_1 * T3_1;
            Tb_1 = T5_1 * T3_1;
            T7_1 = T5_1 * T6_1;
            Ta_1 = T2_1 * T6_1;
            T8_1 = T4_1 - T7_1;
            Tc_1 = Ta_1 + Tb_1;
            Tg_1 = T4_1 + T7_1;
            Ti_1 = Ta_1 - Tb_1;
            Tl_1 = W[10];
            Tm_1 = W[11];
            Tn_1 = (((T2_1) * (Tl_1)) + (T5_1 * Tm_1));
            Tz_1 = ((Tg_1 * Tm_1) - ((Ti_1) * (Tl_1)));
            Tp_1 = ((T2_1 * Tm_1) - ((T5_1) * (Tl_1)));
            Tx_1 = (((Tg_1) * (Tl_1)) + (Ti_1 * Tm_1));
        }
        {
            E Tf_0, T1i_0, TL_0, T1d_0, TJ_0, T17_0, TV_0, TY_0, Ts_0, T1j_0, TO_0, T1a_0, TC_0, T16_0, TQ_0;
            E TT_0;
            {
                E T1_0, T1c_0, Te_0, T1b_0, T9_0, Td_0;
                T1_0 = ri[0];
                T1c_0 = ii[0];
                T9_0 = ri[(rs[4])];
                Td_0 = ii[(rs[4])];
                Te_0 = (((T8_0) * (T9_0)) + (Tc_0 * Td_0));
                T1b_0 = ((T8_0 * Td_0) - ((Tc_0) * (T9_0)));
                Tf_0 = T1_0 + Te_0;
                T1i_0 = T1c_0 - T1b_0;
                TL_0 = T1_0 - Te_0;
                T1d_0 = T1b_0 + T1c_0;
            }
            {
                E TF_0, TW_0, TI_0, TX_0;
                {
                    E TD_0, TE_0, TG_0, TH_0;
                    TD_0 = ri[(rs[7])];
                    TE_0 = ii[(rs[7])];
                    TF_0 = (((Tl_0) * (TD_0)) + (Tm_0 * TE_0));
                    TW_0 = ((Tl_0 * TE_0) - ((Tm_0) * (TD_0)));
                    TG_0 = ri[(rs[3])];
                    TH_0 = ii[(rs[3])];
                    TI_0 = (((T3_0) * (TG_0)) + (T6_0 * TH_0));
                    TX_0 = ((T3_0 * TH_0) - ((T6_0) * (TG_0)));
                }
                TJ_0 = TF_0 + TI_0;
                T17_0 = TW_0 + TX_0;
                TV_0 = TF_0 - TI_0;
                TY_0 = TW_0 - TX_0;
            }
            {
                E Tk_0, TM_0, Tr_0, TN_0;
                {
                    E Th_0, Tj_0, To_0, Tq_0;
                    Th_0 = ri[(rs[2])];
                    Tj_0 = ii[(rs[2])];
                    Tk_0 = (((Tg_0) * (Th_0)) + (Ti_0 * Tj_0));
                    TM_0 = ((Tg_0 * Tj_0) - ((Ti_0) * (Th_0)));
                    To_0 = ri[(rs[6])];
                    Tq_0 = ii[(rs[6])];
                    Tr_0 = (((Tn_0) * (To_0)) + (Tp_0 * Tq_0));
                    TN_0 = ((Tn_0 * Tq_0) - ((Tp_0) * (To_0)));
                }
                Ts_0 = Tk_0 + Tr_0;
                T1j_0 = Tk_0 - Tr_0;
                TO_0 = TM_0 - TN_0;
                T1a_0 = TM_0 + TN_0;
            }
            {
                E Tw_0, TR_0, TB_0, TS_0;
                {
                    E Tu_0, Tv_0, Ty_0, TA_0;
                    Tu_0 = ri[(rs[1])];
                    Tv_0 = ii[(rs[1])];
                    Tw_0 = (((T2_0) * (Tu_0)) + (T5_0 * Tv_0));
                    TR_0 = ((T2_0 * Tv_0) - ((T5_0) * (Tu_0)));
                    Ty_0 = ri[(rs[5])];
                    TA_0 = ii[(rs[5])];
                    TB_0 = (((Tx_0) * (Ty_0)) + (Tz_0 * TA_0));
                    TS_0 = ((Tx_0 * TA_0) - ((Tz_0) * (Ty_0)));
                }
                TC_0 = Tw_0 + TB_0;
                T16_0 = TR_0 + TS_0;
                TQ_0 = Tw_0 - TB_0;
                TT_0 = TR_0 - TS_0;
            }
            {
                E Tt_0, TK_0, T1f_0, T1g_0;
                Tt_0 = Tf_0 + Ts_0;
                TK_0 = TC_0 + TJ_0;
                ri[(rs[4])] = Tt_0 - TK_0;
                ri[0] = Tt_0 + TK_0;
                {
                    E T19_0, T1e_0, T15_0, T18_0;
                    T19_0 = T16_0 + T17_0;
                    T1e_0 = T1a_0 + T1d_0;
                    ii[0] = T19_0 + T1e_0;
                    ii[(rs[4])] = T1e_0 - T19_0;
                    T15_0 = Tf_0 - Ts_0;
                    T18_0 = T16_0 - T17_0;
                    ri[(rs[6])] = T15_0 - T18_0;
                    ri[(rs[2])] = T15_0 + T18_0;
                }
                T1f_0 = TJ_0 - TC_0;
                T1g_0 = T1d_0 - T1a_0;
                ii[(rs[2])] = T1f_0 + T1g_0;
                ii[(rs[6])] = T1g_0 - T1f_0;
                {
                    E T11_0, T1k_0, T14_0, T1h_0, T12_0, T13_0;
                    T11_0 = TL_0 - TO_0;
                    T1k_0 = T1i_0 - T1j_0;
                    T12_0 = TT_0 - TQ_0;
                    T13_0 = TV_0 + TY_0;
                    T14_0 = KP707106781 * (T12_0 - T13_0);
                    T1h_0 = KP707106781 * (T12_0 + T13_0);
                    ri[(rs[7])] = T11_0 - T14_0;
                    ii[(rs[5])] = T1k_0 - T1h_0;
                    ri[(rs[3])] = T11_0 + T14_0;
                    ii[(rs[1])] = T1h_0 + T1k_0;
                }
                {
                    E TP_0, T1m_0, T10_0, T1l_0, TU_0, TZ_0;
                    TP_0 = TL_0 + TO_0;
                    T1m_0 = T1j_0 + T1i_0;
                    TU_0 = TQ_0 + TT_0;
                    TZ_0 = TV_0 - TY_0;
                    T10_0 = KP707106781 * (TU_0 + TZ_0);
                    T1l_0 = KP707106781 * (TZ_0 - TU_0);
                    ri[(rs[5])] = TP_0 - T10_0;
                    ii[(rs[7])] = T1m_0 - T1l_0;
                    ri[(rs[1])] = TP_0 + T10_0;
                    ii[(rs[3])] = T1l_0 + T1m_0;
                }
            }
        }
        {
            E Tf_1, T1i_1, TL_1, T1d_1, TJ_1, T17_1, TV_1, TY_1, Ts_1, T1j_1, TO_1, T1a_1, TC_1, T16_1, TQ_1;
            E TT_1;
            {
                E T1_1, T1c_1, Te_1, T1b_1, T9_1, Td_1;
                T1_1 = ri[ms];
                T1c_1 = ii[ms];
                T9_1 = ri[ms + rs[4]];
                Td_1 = ii[ms + rs[4]];
                Te_1 = (((T8_1) * (T9_1)) + (Tc_1 * Td_1));
                T1b_1 = ((T8_1 * Td_1) - ((Tc_1) * (T9_1)));
                Tf_1 = T1_1 + Te_1;
                T1i_1 = T1c_1 - T1b_1;
                TL_1 = T1_1 - Te_1;
                T1d_1 = T1b_1 + T1c_1;
            }
            {
                E TF_1, TW_1, TI_1, TX_1;
                {
                    E TD_1, TE_1, TG_1, TH_1;
                    TD_1 = ri[ms + rs[7]];
                    TE_1 = ii[ms + rs[7]];
                    TF_1 = (((Tl_1) * (TD_1)) + (Tm_1 * TE_1));
                    TW_1 = ((Tl_1 * TE_1) - ((Tm_1) * (TD_1)));
                    TG_1 = ri[ms + rs[3]];
                    TH_1 = ii[ms + rs[3]];
                    TI_1 = (((T3_1) * (TG_1)) + (T6_1 * TH_1));
                    TX_1 = ((T3_1 * TH_1) - ((T6_1) * (TG_1)));
                }
                TJ_1 = TF_1 + TI_1;
                T17_1 = TW_1 + TX_1;
                TV_1 = TF_1 - TI_1;
                TY_1 = TW_1 - TX_1;
            }
            {
                E Tk_1, TM_1, Tr_1, TN_1;
                {
                    E Th_1, Tj_1, To_1, Tq_1;
                    Th_1 = ri[ms + rs[2]];
                    Tj_1 = ii[ms + rs[2]];
                    Tk_1 = (((Tg_1) * (Th_1)) + (Ti_1 * Tj_1));
                    TM_1 = ((Tg_1 * Tj_1) - ((Ti_1) * (Th_1)));
                    To_1 = ri[ms + rs[6]];
                    Tq_1 = ii[ms + rs[6]];
                    Tr_1 = (((Tn_1) * (To_1)) + (Tp_1 * Tq_1));
                    TN_1 = ((Tn_1 * Tq_1) - ((Tp_1) * (To_1)));
                }
                Ts_1 = Tk_1 + Tr_1;
                T1j_1 = Tk_1 - Tr_1;
                TO_1 = TM_1 - TN_1;
                T1a_1 = TM_1 + TN_1;
            }
            {
                E Tw_1, TR_1, TB_1, TS_1;
                {
                    E Tu_1, Tv_1, Ty_1, TA_1;
                    Tu_1 = ri[ms + rs[1]];
                    Tv_1 = ii[ms + rs[1]];
                    Tw_1 = (((T2_1) * (Tu_1)) + (T5_1 * Tv_1));
                    TR_1 = ((T2_1 * Tv_1) - ((T5_1) * (Tu_1)));
                    Ty_1 = ri[ms + rs[5]];
                    TA_1 = ii[ms + rs[5]];
                    TB_1 = (((Tx_1) * (Ty_1)) + (Tz_1 * TA_1));
                    TS_1 = ((Tx_1 * TA_1) - ((Tz_1) * (Ty_1)));
                }
                TC_1 = Tw_1 + TB_1;
                T16_1 = TR_1 + TS_1;
                TQ_1 = Tw_1 - TB_1;
                TT_1 = TR_1 - TS_1;
            }
            {
                E Tt_1, TK_1, T1f_1, T1g_1;
                Tt_1 = Tf_1 + Ts_1;
                TK_1 = TC_1 + TJ_1;
                ri[ms + rs[4]] = Tt_1 - TK_1;
                ri[ms] = Tt_1 + TK_1;
                {
                    E T19_1, T1e_1, T15_1, T18_1;
                    T19_1 = T16_1 + T17_1;
                    T1e_1 = T1a_1 + T1d_1;
                    ii[ms] = T19_1 + T1e_1;
                    ii[ms + rs[4]] = T1e_1 - T19_1;
                    T15_1 = Tf_1 - Ts_1;
                    T18_1 = T16_1 - T17_1;
                    ri[ms + rs[6]] = T15_1 - T18_1;
                    ri[ms + rs[2]] = T15_1 + T18_1;
                }
                T1f_1 = TJ_1 - TC_1;
                T1g_1 = T1d_1 - T1a_1;
                ii[ms + rs[2]] = T1f_1 + T1g_1;
                ii[ms + rs[6]] = T1g_1 - T1f_1;
                {
                    E T11_1, T1k_1, T14_1, T1h_1, T12_1, T13_1;
                    T11_1 = TL_1 - TO_1;
                    T1k_1 = T1i_1 - T1j_1;
                    T12_1 = TT_1 - TQ_1;
                    T13_1 = TV_1 + TY_1;
                    T14_1 = KP707106781 * (T12_1 - T13_1);
                    T1h_1 = KP707106781 * (T12_1 + T13_1);
                    ri[ms + rs[7]] = T11_1 - T14_1;
                    ii[ms + rs[5]] = T1k_1 - T1h_1;
                    ri[ms + rs[3]] = T11_1 + T14_1;
                    ii[ms + rs[1]] = T1h_1 + T1k_1;
                }
                {
                    E TP_1, T1m_1, T10_1, T1l_1, TU_1, TZ_1;
                    TP_1 = TL_1 + TO_1;
                    T1m_1 = T1j_1 + T1i_1;
                    TU_1 = TQ_1 + TT_1;
                    TZ_1 = TV_1 - TY_1;
                    T10_1 = KP707106781 * (TU_1 + TZ_1);
                    T1l_1 = KP707106781 * (TZ_1 - TU_1);
                    ri[ms + rs[5]] = TP_1 - T10_1;
                    ii[ms + rs[7]] = T1m_1 - T1l_1;
                    ri[ms + rs[1]] = TP_1 + T10_1;
                    ii[ms + rs[3]] = T1l_1 + T1m_1;
                }
            }
        }
    }
}
}
