#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *I;
extern R *O;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP1_662939224;
extern  E KP1_111140466;
extern  E KP390180644;
extern  E KP1_961570560;
extern  E KP707106781;
extern  E KP1_414213562;
extern  E KP765366864;
extern  E KP1_847759065;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 2 , I = I + 2*ivs , O = O + 2*ovs , (is) = (is) + 2*fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (i >= 2) {
        E T7a, Tla, T4a, Tka, Tda, Toa, Tga, Tna;
        E T7b, Tlb, T4b, Tkb, Tdb, Tob, Tgb, Tnb;
        {
            E T5a, T6a, T1a, T3a, T2a;
            T5a = I[(is[2])];
            T6a = I[(is[6])];
            T7a = (((KP1_847759065) * (T5a)) + (KP765366864 * T6a));
            Tla = ((KP765366864 * T5a) - ((KP1_847759065) * (T6a)));
            T1a = I[0];
            T2a = I[(is[4])];
            T3a = KP1_414213562 * T2a;
            T4a = T1a + T3a;
            Tka = T1a - T3a;
            {
                E T9a, Tfa, Tca, Tea, Taa, Tba;
                T9a = I[(is[1])];
                Tfa = I[(is[7])];
                Taa = I[(is[5])];
                Tba = I[(is[3])];
                Tca = KP707106781 * (Taa + Tba);
                Tea = KP707106781 * (Taa - Tba);
                Tda = T9a + Tca;
                Toa = Tea + Tfa;
                Tga = Tea - Tfa;
                Tna = T9a - Tca;
            }
        }
        {
            E T5b, T6b, T1b, T3b, T2b;
            T5b = I[ivs + (is[2])];
            T6b = I[ivs + (is[6])];
            T7b = (((KP1_847759065) * (T5b)) + (KP765366864 * T6b));
            Tlb = ((KP765366864 * T5b) - ((KP1_847759065) * (T6b)));
            T1b = I[ivs];
            T2b = I[ivs + (is[4])];
            T3b = KP1_414213562 * T2b;
            T4b = T1b + T3b;
            Tkb = T1b - T3b;
            {
                E T9b, Tfb, Tcb, Teb, Tab, Tbb;
                T9b = I[ivs + (is[1])];
                Tfb = I[ivs + (is[7])];
                Tab = I[ivs + (is[5])];
                Tbb = I[ivs + (is[3])];
                Tcb = KP707106781 * (Tab + Tbb);
                Teb = KP707106781 * (Tab - Tbb);
                Tdb = T9b + Tcb;
                Tob = Teb + Tfb;
                Tgb = Teb - Tfb;
                Tnb = T9b - Tcb;
            }
        }
        {
            E T8a, Tha, Tqa, Tra;
            T8a = T4a + T7a;
            Tha = ((KP1_961570560 * Tda) - ((KP390180644) * (Tga)));
            O[(os[7])] = T8a - Tha;
            O[0] = T8a + Tha;
            Tqa = Tka - Tla;
            Tra = (((KP1_111140466) * (Tna)) + (KP1_662939224 * Toa));
            O[(os[5])] = Tqa - Tra;
            O[(os[2])] = Tqa + Tra;

            E T8b, Thb, Tqb, Trb;
            T8b = T4b + T7b;
            Thb = ((KP1_961570560 * Tdb) - ((KP390180644) * (Tgb)));
            O[ovs + (os[7])] = T8b - Thb;
            O[ovs] = T8b + Thb;
            Tqb = Tkb - Tlb;
            Trb = (((KP1_111140466) * (Tnb)) + (KP1_662939224 * Tob));
            O[ovs + (os[5])] = Tqb - Trb;
            O[ovs + (os[2])] = Tqb + Trb;
        }
        {
            E Tia, Tja, Tma, Tpa;
            Tia = T4a - T7a;
            Tja = (((KP390180644) * (Tda)) + (KP1_961570560 * Tga));
            O[(os[4])] = Tia - Tja;
            O[(os[3])] = Tia + Tja;
            Tma = Tka + Tla;
            Tpa = ((KP1_662939224 * Tna) - ((KP1_111140466) * (Toa)));
            O[(os[6])] = Tma - Tpa;
            O[(os[1])] = Tma + Tpa;

            E Tib, Tjb, Tmb, Tpb;
            Tib = T4b - T7b;
            Tjb = (((KP390180644) * (Tdb)) + (KP1_961570560 * Tgb));
            O[ovs + (os[4])] = Tib - Tjb;
            O[ovs + (os[3])] = Tib + Tjb;
            Tmb = Tkb + Tlb;
            Tpb = ((KP1_662939224 * Tnb) - ((KP1_111140466) * (Tob)));
            O[ovs + (os[6])] = Tmb - Tpb;
            O[ovs + (os[1])] = Tmb + Tpb;
        }
    } else {
        i = i + 1;
        I = I - ivs;
        O = O - ovs;
        (is) = (is) - fftw_an_INT_guaranteed_to_be_zero;
        (os) = (os) - fftw_an_INT_guaranteed_to_be_zero;
        break;
    }
}
}
