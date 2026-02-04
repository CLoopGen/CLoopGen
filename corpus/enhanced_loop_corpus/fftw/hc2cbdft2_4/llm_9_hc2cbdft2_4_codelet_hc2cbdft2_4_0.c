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
for (m = mb; m < me; m += 2 , Rp = Rp + 2*ms , Ip = Ip + 2*ms , Rm = Rm - 2*ms , Im = Im - 2*ms , W = W + 12 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T3a, Tla, T6a, Tma, Tda, Tja, Txa, Tva, Tsa, Tqa;
    E T3b, Tlb, T6b, Tmb, Tdb, Tjb, Txb, Tvb, Tsb, Tqb;
    {
        E Tfa, Tca, T9a, Tia;
        {
            E T1a, T2a, Taa, Tba;
            T1a = Rp[0];
            T2a = Rm[(rs[1])];
            T3a = T1a + T2a;
            Tfa = T1a - T2a;
            Taa = Ip[0];
            Tba = Im[(rs[1])];
            Tca = Taa + Tba;
            Tla = Taa - Tba;
        }
        {
            E T4a, T5a, Tga, Tha;
            T4a = Rp[(rs[1])];
            T5a = Rm[0];
            T6a = T4a + T5a;
            T9a = T4a - T5a;
            Tga = Ip[(rs[1])];
            Tha = Im[0];
            Tia = Tga + Tha;
            Tma = Tga - Tha;
        }
        Tda = T9a + Tca;
        Tja = Tfa - Tia;
        Txa = Tfa + Tia;
        Tva = Tca - T9a;
        Tsa = Tla - Tma;
        Tqa = T3a - T6a;
    }
    {
        E Tfb, Tcb, T9b, Tib;
        {
            E T1b, T2b, Tab, Tbb;
            T1b = Rp[ms];
            T2b = Rm[(rs[1]) - ms];
            T3b = T1b + T2b;
            Tfb = T1b - T2b;
            Tab = Ip[ms];
            Tbb = Im[(rs[1]) - ms];
            Tcb = Tab + Tbb;
            Tlb = Tab - Tbb;
        }
        {
            E T4b, T5b, Tgb, Thb;
            T4b = Rp[(rs[1]) + ms];
            T5b = Rm[ms];
            T6b = T4b + T5b;
            T9b = T4b - T5b;
            Tgb = Ip[(rs[1]) + ms];
            Thb = Im[ms];
            Tib = Tgb + Thb;
            Tmb = Tgb - Thb;
        }
        Tdb = T9b + Tcb;
        Tjb = Tfb - Tib;
        Txb = Tfb + Tib;
        Tvb = Tcb - T9b;
        Tsb = Tlb - Tmb;
        Tqb = T3b - T6b;
    }
    {
        E T7a, Tna, Tka, Toa, T8a, Tea;
        T7a = T3a + T6a;
        Tna = Tla + Tma;
        T8a = W[0];
        Tea = W[1];
        Tka = (((T8a) * (Tda)) + (Tea * Tja));
        Toa = ((T8a * Tja) - ((Tea) * (Tda)));
        Rp[0] = T7a - Tka;
        Ip[0] = Tna + Toa;
        Rm[0] = T7a + Tka;
        Im[0] = Toa - Tna;
    }
    {
        E T7b, Tnb, Tkb, Tob, T8b, Teb;
        T7b = T3b + T6b;
        Tnb = Tlb + Tmb;
        T8b = W[6];
        Teb = W[7];
        Tkb = (((T8b) * (Tdb)) + (Teb * Tjb));
        Tob = ((T8b * Tjb) - ((Teb) * (Tdb)));
        Rp[ms] = T7b - Tkb;
        Ip[ms] = Tnb + Tob;
        Rm[ms] = T7b + Tkb;
        Im[ms] = Tob - Tnb;
    }
    {
        E Tta, Tza, Tya, TAa;
        {
            E Tpa, Tra, Tua, Twa;
            Tpa = W[2];
            Tra = W[3];
            Tta = ((Tpa * Tqa) - ((Tra) * (Tsa)));
            Tza = (((Tra) * (Tqa)) + (Tpa * Tsa));
            Tua = W[4];
            Twa = W[5];
            Tya = (((Tua) * (Tva)) + (Twa * Txa));
            TAa = ((Tua * Txa) - ((Twa) * (Tva)));
        }
        Rp[(rs[1])] = Tta - Tya;
        Ip[(rs[1])] = Tza + TAa;
        Rm[(rs[1])] = Tta + Tya;
        Im[(rs[1])] = TAa - Tza;
    }
    {
        E Ttb, Tzb, Tyb, TAb;
        {
            E Tpb, Trb, Tub, Twb;
            Tpb = W[8];
            Trb = W[9];
            Ttb = ((Tpb * Tqb) - ((Trb) * (Tsb)));
            Tzb = (((Trb) * (Tqb)) + (Tpb * Tsb));
            Tub = W[10];
            Twb = W[11];
            Tyb = (((Tub) * (Tvb)) + (Twb * Txb));
            TAb = ((Tub * Txb) - ((Twb) * (Tvb)));
        }
        Rp[(rs[1]) + ms] = Ttb - Tyb;
        Ip[(rs[1]) + ms] = Tzb + TAb;
        Rm[(rs[1]) - ms] = Ttb + Tyb;
        Im[(rs[1]) - ms] = TAb - Tzb;
    }
}

}
