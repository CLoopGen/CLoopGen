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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , Rp = Rp + (2*ms) , Ip = Ip + (2*ms) , Rm = Rm - (2*ms) , Im = Im - (2*ms) , W = W + 8 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
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
        E T3a, Tla, Tga, Tpa, T6a, Toa, Tja, Tma, Tca, Tka;
        E T3b, Tlb, Tgb, Tpb, T6b, Tob, Tjb, Tmb, Tcb, Tkb;
        {
            E T1a, T2a, Tea, Tfa;
            T1a = Rp[0];
            T2a = Rm[(rs[1])];
            T3a = T1a + T2a;
            Tla = T1a - T2a;
            Tea = Ip[0];
            Tfa = Im[(rs[1])];
            Tga = Tea - Tfa;
            Tpa = Tea + Tfa;

            E T1b, T2b, Teb, Tfb;
            T1b = Rp[ms];
            T2b = Rm[(rs[1]) - ms];
            T3b = T1b + T2b;
            Tlb = T1b - T2b;
            Teb = Ip[ms];
            Tfb = Im[(rs[1]) - ms];
            Tgb = Teb - Tfb;
            Tpb = Teb + Tfb;
        }
        {
            E T4a, T5a, Tha, Tia;
            T4a = Rp[(rs[1])];
            T5a = Rm[0];
            T6a = T4a + T5a;
            Toa = T4a - T5a;
            Tha = Ip[(rs[1])];
            Tia = Im[0];
            Tja = Tha - Tia;
            Tma = Tha + Tia;

            E T4b, T5b, Thb, Tib;
            T4b = Rp[(rs[1]) + ms];
            T5b = Rm[-ms];
            T6b = T4b + T5b;
            Tob = T4b - T5b;
            Thb = Ip[(rs[1]) + ms];
            Tib = Im[-ms];
            Tjb = Thb - Tib;
            Tmb = Thb + Tib;
        }
        Rp[0] = T3a + T6a;
        Rm[0] = Tga + Tja;
        Tca = T3a - T6a;
        Tka = Tga - Tja;
        Rp[(rs[1])] = ((Tba * Tca) - ((Tda) * (Tka)));
        Rm[(rs[1])] = (((Tda) * (Tca)) + (Tba * Tka));

        Rp[ms] = T3b + T6b;
        Rm[-ms] = Tgb + Tjb;
        Tcb = T3b - T6b;
        Tkb = Tgb - Tjb;
        Rp[(rs[1]) + ms] = ((Tbb * Tcb) - ((Tdb) * (Tkb)));
        Rm[(rs[1]) - ms] = (((Tdb) * (Tcb)) + (Tbb * Tkb));

        {
            E Tna, Tqa, Tra, Tsa;
            Tna = Tla - Tma;
            Tqa = Toa + Tpa;
            Ip[0] = ((T7a * Tna) - ((T9a) * (Tqa)));
            Im[0] = (((T7a) * (Tqa)) + (T9a * Tna));
            Tra = Tla + Tma;
            Tsa = Tpa - Toa;
            Ip[(rs[1])] = ((T8a * Tra) - ((Taa) * (Tsa)));
            Im[(rs[1])] = (((T8a) * (Tsa)) + (Taa * Tra));
        }
        {
            E Tnb, Tqb, Trb, Tsb;
            Tnb = Tlb - Tmb;
            Tqb = Tob + Tpb;
            Ip[ms] = ((T7b * Tnb) - ((T9b) * (Tqb)));
            Im[ms] = (((T7b) * (Tqb)) + (T9b * Tnb));
            Trb = Tlb + Tmb;
            Tsb = Tpb - Tob;
            Ip[(rs[1]) + ms] = ((T8b * Trb) - ((Tab) * (Tsb)));
            Im[(rs[1]) + ms] = (((T8b) * (Tsb)) + (Tab * Trb));
        }
    }
}
}
