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
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 2 , Rp = Rp + (2 * ms) , Ip = Ip + (2 * ms) , Rm = Rm - (2 * ms) , Im = Im - (2 * ms) , W = W + 12 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T2a, T5a, T3a, T6a, T8a, Tca, Tga, Tia, Tla, Tma, Tna, Tza, Tpa, Txa;
    E T2b, T5b, T3b, T6b, T8b, Tcb, Tgb, Tib, Tlb, Tmb, Tnb, Tzb, Tpb, Txb;
    {
        E T4a, Tba, T7a, Taa, T4b, Tbb, T7b, Tab;
        T2a = W[0];
        T5a = W[1];
        T3a = W[2];
        T6a = W[3];
        T4a = T2a * T3a;
        Tba = T5a * T3a;
        T7a = T5a * T6a;
        Taa = T2a * T6a;
        T8a = T4a - T7a;
        Tca = Taa + Tba;
        Tga = T4a + T7a;
        Tia = Taa - Tba;
        Tla = W[4];
        Tma = W[5];
        Tna = (((T2a) * (Tla)) + (T5a * Tma));
        Tza = ((Tga * Tma) - ((Tia) * (Tla)));
        Tpa = ((T2a * Tma) - ((T5a) * (Tla)));
        Txa = (((Tga) * (Tla)) + (Tia * Tma));

        T2b = W[6];
        T5b = W[7];
        T3b = W[8];
        T6b = W[9];
        T4b = T2b * T3b;
        Tbb = T5b * T3b;
        T7b = T5b * T6b;
        Tab = T2b * T6b;
        T8b = T4b - T7b;
        Tcb = Tab + Tbb;
        Tgb = T4b + T7b;
        Tib = Tab - Tbb;
        Tlb = W[10];
        Tmb = W[11];
        Tnb = (((T2b) * (Tlb)) + (T5b * Tmb));
        Tzb = ((Tgb * Tmb) - ((Tib) * (Tlb)));
        Tpb = ((T2b * Tmb) - ((T5b) * (Tlb)));
        Txb = (((Tgb) * (Tlb)) + (Tib * Tmb));
    }
    {
        E Tfa, T1ia, TL_a, T1da, TJ_a, T17a, TV_a, TY_a, Tsa, T1ja, TO_a, T1aa, TC_a, T16a, TQ_a;
        E TT_a;
        {
            E T1a, T1ca, Tea, T1ba, T9a, Tda;
            T1a = Rp[0];
            T1ca = Rm[0];
            T9a = Rp[(rs[2])];
            Tda = Rm[(rs[2])];
            Tea = (((T8a) * (T9a)) + (Tca * Tda));
            T1ba = ((T8a * Tda) - ((Tca) * (T9a)));
            Tfa = T1a + Tea;
            T1ia = T1ca - T1ba;
            TL_a = T1a - Tea;
            T1da = T1ba + T1ca;
        }
        {
            E TFa, TWA, TIa, TXA;
            {
                E TDa, TEa, TGa, THa;
                TDa = Ip[(rs[3])];
                TEa = Im[(rs[3])];
                TFa = (((Tla) * (TDa)) + (Tma * TEa));
                TWA = ((Tla * TEa) - ((Tma) * (TDa)));
                TGa = Ip[(rs[1])];
                THa = Im[(rs[1])];
                TIa = (((T3a) * (TGa)) + (T6a * THa));
                TXA = ((T3a * THa) - ((T6a) * (TGa)));
            }
            TJ_a = TFa + TIa;
            T17a = TWA + TXA;
            TV_a = TFa - TIa;
            TY_a = TWA - TXA;
        }
        {
            E Tka, TMa, Tra, TNa;
            {
                E Tha, Tja, Toa, Tqa;
                Tha = Rp[(rs[1])];
                Tja = Rm[(rs[1])];
                Tka = (((Tga) * (Tha)) + (Tia * Tja));
                TMa = ((Tga * Tja) - ((Tia) * (Tha)));
                Toa = Rp[(rs[3])];
                Tqa = Rm[(rs[3])];
                Tra = (((Tna) * (Toa)) + (Tpa * Tqa));
                TNa = ((Tna * Tqa) - ((Tpa) * (Toa)));
            }
            Tsa = Tka + Tra;
            T1ja = Tka - Tra;
            TO_a = TMa - TNa;
            T1aa = TMa + TNa;
        }
        {
            E Twa, TRa, TBa, TSa;
            {
                E Tua, Tva, Tya, TAa;
                Tua = Ip[0];
                Tva = Im[0];
                Twa = (((T2a) * (Tua)) + (T5a * Tva));
                TRa = ((T2a * Tva) - ((T5a) * (Tua)));
                Tya = Ip[(rs[2])];
                TAa = Im[(rs[2])];
                TBa = (((Txa) * (Tya)) + (Tza * TAa));
                TSa = ((Txa * TAa) - ((Tza) * (Tya)));
            }
            TC_a = Twa + TBa;
            T16a = TRa + TSa;
            TQ_a = Twa - TBa;
            TT_a = TRa - TSa;
        }
        {
            E Tta, TKa, T1fa, T1ga;
            Tta = Tfa + Tsa;
            TKa = TC_a + TJ_a;
            Rm[(rs[3])] = Tta - TKa;
            Rp[0] = Tta + TKa;
            {
                E T19a, T1ea, T15a, T18a;
                T19a = T16a + T17a;
                T1ea = T1aa + T1da;
                Im[(rs[3])] = T19a - T1ea;
                Ip[0] = T19a + T1ea;
                T15a = Tfa - Tsa;
                T18a = T16a - T17a;
                Rm[(rs[1])] = T15a - T18a;
                Rp[(rs[2])] = T15a + T18a;
            }
            T1fa = TJ_a - TC_a;
            T1ga = T1da - T1aa;
            Im[(rs[1])] = T1fa - T1ga;
            Ip[(rs[2])] = T1fa + T1ga;
            {
                E T11a, T1ka, T14a, T1ha, T12a, T13a;
                T11a = TL_a - TO_a;
                T1ka = T1ia - T1ja;
                T12a = TT_a - TQ_a;
                T13a = TV_a + TY_a;
                T14a = KP707106781 * (T12a - T13a);
                T1ha = KP707106781 * (T12a + T13a);
                Rm[0] = T11a - T14a;
                Ip[(rs[1])] = T1ha + T1ka;
                Rp[(rs[3])] = T11a + T14a;
                Im[(rs[2])] = T1ha - T1ka;
            }
            {
                E TPa, T1ma, T10a, T1la, TUa, TZa;
                TPa = TL_a + TO_a;
                T1ma = T1ja + T1ia;
                TUa = TQ_a + TT_a;
                TZa = TV_a - TY_a;
                T10a = KP707106781 * (TUa + TZa);
                T1la = KP707106781 * (TZa - TUa);
                Rm[(rs[2])] = TPa - T10a;
                Ip[(rs[3])] = T1la + T1ma;
                Rp[(rs[1])] = TPa + T10a;
                Im[0] = T1la - T1ma;
            }
        }
    }
    {
        E Tfb, T1ib, TL_b, T1db, TJ_b, T17b, TV_b, TY_b, Tsb, T1jb, TO_b, T1ab, TC_b, T16b, TQ_b;
        E TT_b;
        {
            E T1b, T1cb, Teb, T1bb, T9b, Tdb;
            T1b = Rp[ms];
            T1cb = Rm[-ms];
            T9b = Rp[ms + (rs[2])];
            Tdb = Rm[-ms + (rs[2])];
            Teb = (((T8b) * (T9b)) + (Tcb * Tdb));
            T1bb = ((T8b * Tdb) - ((Tcb) * (T9b)));
            Tfb = T1b + Teb;
            T1ib = T1cb - T1bb;
            TL_b = T1b - Teb;
            T1db = T1bb + T1cb;
        }
        {
            E TFb, TWB, TIb, TXB;
            {
                E TDb, TEb, TGb, THb;
                TDb = Ip[ms + (rs[3])];
                TEb = Im[-ms + (rs[3])];
                TFb = (((Tlb) * (TDb)) + (Tmb * TEb));
                TWB = ((Tlb * TEb) - ((Tmb) * (TDb)));
                TGb = Ip[ms + (rs[1])];
                THb = Im[-ms + (rs[1])];
                TIb = (((T3b) * (TGb)) + (T6b * THb));
                TXB = ((T3b * THb) - ((T6b) * (TGb)));
            }
            TJ_b = TFb + TIb;
            T17b = TWB + TXB;
            TV_b = TFb - TIb;
            TY_b = TWB - TXB;
        }
        {
            E Tkb, TMb, Trb, TNb;
            {
                E Thb, Tjb, Tob, Tqb;
                Thb = Rp[ms + (rs[1])];
                Tjb = Rm[-ms + (rs[1])];
                Tkb = (((Tgb) * (Thb)) + (Tib * Tjb));
                TMb = ((Tgb * Tjb) - ((Tib) * (Thb)));
                Tob = Rp[ms + (rs[3])];
                Tqb = Rm[-ms + (rs[3])];
                Trb = (((Tnb) * (Tob)) + (Tpb * Tqb));
                TNb = ((Tnb * Tqb) - ((Tpb) * (Tob)));
            }
            Tsb = Tkb + Trb;
            T1jb = Tkb - Trb;
            TO_b = TMb - TNb;
            T1ab = TMb + TNb;
        }
        {
            E Twb, TRb, TBb, TSb;
            {
                E Tub, Tvb, Tyb, TAb;
                Tub = Ip[ms];
                Tvb = Im[-ms];
                Twb = (((T2b) * (Tub)) + (T5b * Tvb));
                TRb = ((T2b * Tvb) - ((T5b) * (Tub)));
                Tyb = Ip[ms + (rs[2])];
                TAb = Im[-ms + (rs[2])];
                TBb = (((Txb) * (Tyb)) + (Tzb * TAb));
                TSb = ((Txb * TAb) - ((Tzb) * (Tyb)));
            }
            TC_b = Twb + TBb;
            T16b = TRb + TSb;
            TQ_b = Twb - TBb;
            TT_b = TRb - TSb;
        }
        {
            E Ttb, TKb, T1fb, T1gb;
            Ttb = Tfb + Tsb;
            TKb = TC_b + TJ_b;
            Rm[ms + (rs[3])] = Ttb - TKb;
            Rp[ms] = Ttb + TKb;
            {
                E T19b, T1eb, T15b, T18b;
                T19b = T16b + T17b;
                T1eb = T1ab + T1db;
                Im[ms + (rs[3])] = T19b - T1eb;
                Ip[ms] = T19b + T1eb;
                T15b = Tfb - Tsb;
                T18b = T16b - T17b;
                Rm[ms + (rs[1])] = T15b - T18b;
                Rp[ms + (rs[2])] = T15b + T18b;
            }
            T1fb = TJ_b - TC_b;
            T1gb = T1db - T1ab;
            Im[ms + (rs[1])] = T1fb - T1gb;
            Ip[ms + (rs[2])] = T1fb + T1gb;
            {
                E T11b, T1kb, T14b, T1hb, T12b, T13b;
                T11b = TL_b - TO_b;
                T1kb = T1ib - T1jb;
                T12b = TT_b - TQ_b;
                T13b = TV_b + TY_b;
                T14b = KP707106781 * (T12b - T13b);
                T1hb = KP707106781 * (T12b + T13b);
                Rm[ms] = T11b - T14b;
                Ip[ms + (rs[1])] = T1hb + T1kb;
                Rp[ms + (rs[3])] = T11b + T14b;
                Im[ms + (rs[2])] = T1hb - T1kb;
            }
            {
                E TPb, T1mb, T10b, T1lb, TUb, TZb;
                TPb = TL_b + TO_b;
                T1mb = T1jb + T1ib;
                TUb = TQ_b + TT_b;
                TZb = TV_b - TY_b;
                T10b = KP707106781 * (TUb + TZb);
                T1lb = KP707106781 * (TZb - TUb);
                Rm[ms + (rs[2])] = TPb - T10b;
                Ip[ms + (rs[3])] = T1lb + T1mb;
                Rp[ms + (rs[1])] = TPb + T10b;
                Im[ms] = T1lb - T1mb;
            }
        }
    }
}
}
