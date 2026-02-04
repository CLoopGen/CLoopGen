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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , cr = cr + (2 * ms) , ci = ci - (2 * ms) , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T7a, T9a, T8a, Taa, Tba, Tda;
    E T7b, T9b, T8b, Tab, Tbb, Tdb;
    T7a = W[0];
    T9a = W[1];
    T8a = W[2];
    Taa = W[3];
    Tba = (((T7a) * (T8a)) + (T9a * Taa));
    Tda = ((T7a * Taa) - ((T9a) * (T8a)));

    T7b = W[4];
    T9b = W[5];
    T8b = W[6];
    Tab = W[7];
    Tbb = (((T7b) * (T8b)) + (T9b * Tab));
    Tdb = ((T7b * Tab) - ((T9b) * (T8b)));

    {
        E T3a, Tla, T6a, Toa, Tga, Tpa, Tja, Tma, Tca, Tka;
        E T3b, Tlb, T6b, Tob, Tgb, Tpb, Tjb, Tmb, Tcb, Tkb;

        {
            E T1a, T2a, T4a, T5a;
            T1a = cr[0];
            T2a = ci[(rs[1])];
            T3a = T1a + T2a;
            Tla = T1a - T2a;
            T4a = cr[(rs[1])];
            T5a = ci[0];
            T6a = T4a + T5a;
            Toa = T4a - T5a;

            E T1b, T2b, T4b, T5b;
            T1b = cr[ms];
            T2b = ci[(rs[1]) + ms];
            T3b = T1b + T2b;
            Tlb = T1b - T2b;
            T4b = cr[(rs[1]) + ms];
            T5b = ci[ms];
            T6b = T4b + T5b;
            Tob = T4b - T5b;
        }
        {
            E Tea, Tfa, Tha, Tia;
            Tea = ci[(rs[3])];
            Tfa = cr[(rs[2])];
            Tga = Tea - Tfa;
            Tpa = Tea + Tfa;
            Tha = ci[(rs[2])];
            Tia = cr[(rs[3])];
            Tja = Tha - Tia;
            Tma = Tha + Tia;

            E Teb, Tfb, Thb, Tib;
            Teb = ci[(rs[3]) - ms];
            Tfb = cr[(rs[2]) + ms];
            Tgb = Teb - Tfb;
            Tpb = Teb + Tfb;
            Thb = ci[(rs[2]) - ms];
            Tib = cr[(rs[3]) + ms];
            Tjb = Thb - Tib;
            Tmb = Thb + Tib;
        }

        cr[0] = T3a + T6a;
        ci[0] = Tga + Tja;
        Tca = T3a - T6a;
        Tka = Tga - Tja;
        cr[(rs[2])] = ((Tba * Tca) - ((Tda) * (Tka)));
        ci[(rs[2])] = (((Tda) * (Tca)) + (Tba * Tka));

        cr[ms] = T3b + T6b;
        ci[ms] = Tgb + Tjb;
        Tcb = T3b - T6b;
        Tkb = Tgb - Tjb;
        cr[(rs[2]) + ms] = ((Tbb * Tcb) - ((Tdb) * (Tkb)));
        ci[(rs[2]) + ms] = (((Tdb) * (Tcb)) + (Tbb * Tkb));

        {
            E Tna, Tqa, Tra, Tsa;
            Tna = Tla - Tma;
            Tqa = Toa + Tpa;
            cr[(rs[1])] = ((T7a * Tna) - ((T9a) * (Tqa)));
            ci[(rs[1])] = (((T7a) * (Tqa)) + (T9a * Tna));
            Tra = Tla + Tma;
            Tsa = Tpa - Toa;
            cr[(rs[3])] = ((T8a * Tra) - ((Taa) * (Tsa)));
            ci[(rs[3])] = (((T8a) * (Tsa)) + (Taa * Tra));

            E Tnb, Tqb, Trb, Tsb;
            Tnb = Tlb - Tmb;
            Tqb = Tob + Tpb;
            cr[(rs[1]) + ms] = ((T7b * Tnb) - ((T9b) * (Tqb)));
            ci[(rs[1]) + ms] = (((T7b) * (Tqb)) + (T9b * Tnb));
            Trb = Tlb + Tmb;
            Tsb = Tpb - Tob;
            cr[(rs[3]) - ms] = ((T8b * Trb) - ((Tab) * (Tsb)));
            ci[(rs[3]) - ms] = (((T8b) * (Tsb)) + (Tab * Trb));
        }
    }
}
}
