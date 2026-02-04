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
extern  E KP250000000;
extern  E KP587785252;
extern  E KP951056516;
extern  E KP559016994;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , cr = cr + (2 * ms) , ci = ci - (2 * ms) , W = W + 8 , (rs) = (rs) + 2 * fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E Th1, Tk1, Ti1, Tl1, Tn1, TP1, Tx1, TN1;
    E Th2, Tk2, Ti2, Tl2, Tn2, TP2, Tx2, TN2;
    {
        E Tj1, Tw1, Tm1, Tv1;
        Th1 = W[0];
        Tk1 = W[1];
        Ti1 = W[2];
        Tl1 = W[3];
        Tj1 = Th1 * Ti1;
        Tw1 = Tk1 * Ti1;
        Tm1 = Tk1 * Tl1;
        Tv1 = Th1 * Tl1;
        Tn1 = Tj1 + Tm1;
        TP1 = Tv1 + Tw1;
        Tx1 = Tv1 - Tw1;
        TN1 = Tj1 - Tm1;

        E Tj2, Tw2, Tm2, Tv2;
        Th2 = W[4];
        Tk2 = W[5];
        Ti2 = W[6];
        Tl2 = W[7];
        Tj2 = Th2 * Ti2;
        Tw2 = Tk2 * Ti2;
        Tm2 = Tk2 * Tl2;
        Tv2 = Th2 * Tl2;
        Tn2 = Tj2 + Tm2;
        TP2 = Tv2 + Tw2;
        Tx2 = Tv2 - Tw2;
        TN2 = Tj2 - Tm2;
    }
    {
        E T1_1, Tp1, TK1, TA1, T8_1, To1, T9_1, Tt1, TI1, TC1, Tg1, TB1;
        E T1_2, Tp2, TK2, TA2, T8_2, To2, T9_2, Tt2, TI2, TC2, Tg2, TB2;
        {
            E T4_1, Ty1, T7_1, Tz1;
            T1_1 = cr[0];
            {
                E T2_1, T3_1, T5_1, T6_1;
                T2_1 = cr[(rs[1])];
                T3_1 = ci[0];
                T4_1 = T2_1 + T3_1;
                Ty1 = T2_1 - T3_1;
                T5_1 = cr[(rs[2])];
                T6_1 = ci[(rs[1])];
                T7_1 = T5_1 + T6_1;
                Tz1 = T5_1 - T6_1;
            }
            Tp1 = KP559016994 * (T4_1 - T7_1);
            TK1 = (((KP951056516) * (Ty1)) + (KP587785252 * Tz1));
            TA1 = ((KP587785252 * Ty1) - ((KP951056516) * (Tz1)));
            T8_1 = T4_1 + T7_1;
            To1 = ((T1_1) - ((KP250000000) * (T8_1)));

            E T4_2, Ty2, T7_2, Tz2;
            T1_2 = cr[ms];
            {
                E T2_2, T3_2, T5_2, T6_2;
                T2_2 = cr[(rs[1]) + ms];
                T3_2 = ci[0 - ms];
                T4_2 = T2_2 + T3_2;
                Ty2 = T2_2 - T3_2;
                T5_2 = cr[(rs[2]) + ms];
                T6_2 = ci[(rs[1]) - ms];
                T7_2 = T5_2 + T6_2;
                Tz2 = T5_2 - T6_2;
            }
            Tp2 = KP559016994 * (T4_2 - T7_2);
            TK2 = (((KP951056516) * (Ty2)) + (KP587785252 * Tz2));
            TA2 = ((KP587785252 * Ty2) - ((KP951056516) * (Tz2)));
            T8_2 = T4_2 + T7_2;
            To2 = ((T1_2) - ((KP250000000) * (T8_2)));
        }
        {
            E Tc1, Tr1, Tf1, Ts1;
            T9_1 = ci[(rs[4])];
            {
                E Ta1, Tb1, Td1, Te1;
                Ta1 = ci[(rs[3])];
                Tb1 = cr[(rs[4])];
                Tc1 = Ta1 - Tb1;
                Tr1 = Ta1 + Tb1;
                Td1 = ci[(rs[2])];
                Te1 = cr[(rs[3])];
                Tf1 = Td1 - Te1;
                Ts1 = Td1 + Te1;
            }
            Tt1 = ((KP587785252 * Tr1) - ((KP951056516) * (Ts1)));
            TI1 = (((KP951056516) * (Tr1)) + (KP587785252 * Ts1));
            TC1 = KP559016994 * (Tc1 - Tf1);
            Tg1 = Tc1 + Tf1;
            TB1 = ((T9_1) - ((KP250000000) * (Tg1)));

            E Tc2, Tr2, Tf2, Ts2;
            T9_2 = ci[(rs[4]) - ms];
            {
                E Ta2, Tb2, Td2, Te2;
                Ta2 = ci[(rs[3]) - ms];
                Tb2 = cr[(rs[4]) + ms];
                Tc2 = Ta2 - Tb2;
                Tr2 = Ta2 + Tb2;
                Td2 = ci[(rs[2]) - ms];
                Te2 = cr[(rs[3]) + ms];
                Tf2 = Td2 - Te2;
                Ts2 = Td2 + Te2;
            }
            Tt2 = ((KP587785252 * Tr2) - ((KP951056516) * (Ts2)));
            TI2 = (((KP951056516) * (Tr2)) + (KP587785252 * Ts2));
            TC2 = KP559016994 * (Tc2 - Tf2);
            Tg2 = Tc2 + Tf2;
            TB2 = ((T9_2) - ((KP250000000) * (Tg2)));
        }
        cr[0] = T1_1 + T8_1;
        ci[0] = T9_1 + Tg1;
        cr[ms] = T1_2 + T8_2;
        ci[-ms] = T9_2 + Tg2;

        {
            E Tu1, TF1, TE1, TG1, Tq1, TD1;
            Tq1 = To1 - Tp1;
            Tu1 = Tq1 - Tt1;
            TF1 = Tq1 + Tt1;
            TD1 = TB1 - TC1;
            TE1 = TA1 + TD1;
            TG1 = TD1 - TA1;
            cr[(rs[2])] = ((Tn1 * Tu1) - ((Tx1) * (TE1)));
            ci[(rs[2])] = (((Tn1) * (TE1)) + (Tx1 * Tu1));
            cr[(rs[3])] = ((Ti1 * TF1) - ((Tl1) * (TG1)));
            ci[(rs[3])] = (((Ti1) * (TG1)) + (Tl1 * TF1));

            E Tu2, TF2, TE2, TG2, Tq2, TD2;
            Tq2 = To2 - Tp2;
            Tu2 = Tq2 - Tt2;
            TF2 = Tq2 + Tt2;
            TD2 = TB2 - TC2;
            TE2 = TA2 + TD2;
            TG2 = TD2 - TA2;
            cr[(rs[2]) + ms] = ((Tn2 * Tu2) - ((Tx2) * (TE2)));
            ci[(rs[2]) - ms] = (((Tn2) * (TE2)) + (Tx2 * Tu2));
            cr[(rs[3]) + ms] = ((Ti2 * TF2) - ((Tl2) * (TG2)));
            ci[(rs[3]) - ms] = (((Ti2) * (TG2)) + (Tl2 * TF2));
        }
        {
            E TJ1, TO1, TM1, TQ1, TH1, TL1;
            TH1 = Tp1 + To1;
            TJ1 = TH1 - TI1;
            TO1 = TH1 + TI1;
            TL1 = TC1 + TB1;
            TM1 = TK1 + TL1;
            TQ1 = TL1 - TK1;
            cr[(rs[1])] = ((Th1 * TJ1) - ((Tk1) * (TM1)));
            ci[(rs[1])] = (((Th1) * (TM1)) + (Tk1 * TJ1));
            cr[(rs[4])] = ((TN1 * TO1) - ((TP1) * (TQ1)));
            ci[(rs[4])] = (((TN1) * (TQ1)) + (TP1 * TO1));

            E TJ2, TO2, TM2, TQ2, TH2, TL2;
            TH2 = Tp2 + To2;
            TJ2 = TH2 - TI2;
            TO2 = TH2 + TI2;
            TL2 = TC2 + TB2;
            TM2 = TK2 + TL2;
            TQ2 = TL2 - TK2;
            cr[(rs[1]) + ms] = ((Th2 * TJ2) - ((Tk2) * (TM2)));
            ci[(rs[1]) - ms] = (((Th2) * (TM2)) + (Tk2 * TJ2));
            cr[(rs[4]) + ms] = ((TN2 * TO2) - ((TP2) * (TQ2)));
            ci[(rs[4]) - ms] = (((TN2) * (TQ2)) + (TP2 * TO2));
        }
    }
}
}
