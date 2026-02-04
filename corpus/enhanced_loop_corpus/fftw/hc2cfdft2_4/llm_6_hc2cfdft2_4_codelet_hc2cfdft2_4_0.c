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
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 4); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 8 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;
    E T1a, T3a, T2a, T4a, T5a, T9a;
    E T1b, T3b, T2b, T4b, T5b, T9b;
    T1a = W[0]; T3a = W[1]; T2a = W[2]; T4a = W[3];
    T1b = W[4]; T3b = W[5]; T2b = W[6]; T4b = W[7];
    T5a = T1a * T2a + T3a * T4a;
    T9a = T1a * T4a - T3a * T2a;
    T5b = T1b * T2b + T3b * T4b;
    T9b = T1b * T4b - T3b * T2b;

    E Tga, Tra, Tma, Txa, Tda, Twa, Tpa, Tsa;
    E Tgb, Trb, Tmb, Txb, Tdb, Twb, Tpb, Tsb;

    E Tea = Ip[0], Tfa = Im[0];
    E Tel = Tea + Tfa;
    E Tia = Rm[0], Tja = Rp[0], Tka = Tia - Tja;
    Tga = Tea - Tfa;
    Tra = Tja + Tia;
    Tma = T1a * Tka - T3a * Tel;
    Txa = T3a * Tka + T1a * Tel;

    E Teb = Ip[ms], Tfb = Im[ms];
    E Telb = Teb + Tfb;
    E Tib = Rm[ms], Tjb = Rp[ms], Tkb = Tib - Tjb;
    Tgb = Teb - Tfb;
    Trb = Tjb + Tib;
    Tmb = T1b * Tkb - T3b * Telb;
    Txb = T3b * Tkb + T1b * Telb;

    E T8a = Ip[rs[1]] - Im[rs[1]];
    E Toa = Ip[rs[1]] + Im[rs[1]];
    E Tca = Rp[rs[1]] + Rm[rs[1]];
    E Tna = Rp[rs[1]] - Rm[rs[1]];
    Tda = T5a * T8a - T9a * Tca;
    Twa = T2a * Toa - T4a * Tna;
    Tpa = T2a * Tna + T4a * Toa;
    Tsa = T5a * Tca + T9a * T8a;

    E T8b = Ip[rs[1]+ms] - Im[rs[1]+ms];
    E Tob = Ip[rs[1]+ms] + Im[rs[1]+ms];
    E Tcb = Rp[rs[1]+ms] + Rm[rs[1]+ms];
    E Tnb = Rp[rs[1]+ms] - Rm[rs[1]+ms];
    Tdb = T5b * T8b - T9b * Tcb;
    Twb = T2b * Tob - T4b * Tnb;
    Tpb = T2b * Tnb + T4b * Tob;
    Tsb = T5b * Tcb + T9b * T8b;

    E Tha = Tda + Tga, Tqa = Tma - Tpa;
    Ip[0] = KP500000000 * (Tha + Tqa);
    Im[rs[1]] = KP500000000 * (Tqa - Tha);
    E Tza = Tra + Tsa, TAa = Twa + Txa;
    Rm[rs[1]] = KP500000000 * (Tza - TAa);
    Rp[0] = KP500000000 * (Tza + TAa);

    E Tta = Tra - Tsa, Tua = Tpa + Tma;
    Rm[0] = KP500000000 * (Tta - Tua);
    Rp[rs[1]] = KP500000000 * (Tta + Tua);
    E Tva = Tga - Tda, Tya = Twa - Txa;
    Ip[rs[1]] = KP500000000 * (Tva + Tya);
    Im[0] = KP500000000 * (Tya - Tva);

    E Thb = Tdb + Tgb, Tqb = Tmb - Tpb;
    Ip[ms] = KP500000000 * (Thb + Tqb);
    Im[rs[1]+ms] = KP500000000 * (Tqb - Thb);
    E Tzb = Trb + Tsb, TAb = Twb + Txb;
    Rm[rs[1]+ms] = KP500000000 * (Tzb - TAb);
    Rp[ms] = KP500000000 * (Tzb + TAb);

    E Ttb = Trb - Tsb, Tub = Tpb + Tmb;
    Rm[ms] = KP500000000 * (Ttb - Tub);
    Rp[rs[1]+ms] = KP500000000 * (Ttb + Tub);
    E Tvb = Tgb - Tdb, Tyb = Twb - Txb;
    Ip[rs[1]+ms] = KP500000000 * (Tvb + Tyb);
    Im[ms] = KP500000000 * (Tyb - Tvb);
}
}
