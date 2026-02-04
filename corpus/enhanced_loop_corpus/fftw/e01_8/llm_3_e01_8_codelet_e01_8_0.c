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
for (i = v; i > 0; i = i - 1 , I = I + ivs , O = O + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, Tl, T4, Tk, Td, To, Tg, Tn;
    // Use local array indices through indirect lookup tables to simulate irregular access pattern
    static const INT input_index_map[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    static const INT output_index_map[8] = {0, 6, 2, 5, 4, 3, 1, 7}; // remapped output order
    E temp_input[8];

    // Preload inputs using strided indirect access based on is[] scaling
    for (INT j = 0; j < 8; ++j) {
        temp_input[j] = I[(is[input_index_map[j]])];
    }

    {
        E T5 = temp_input[2], T6 = temp_input[6];
        T7 = (KP1_847759065 * T5) + (KP765366864 * T6);
        Tl = (KP765366864 * T5) - (KP1_847759065 * T6);

        E T1 = temp_input[0], T2 = temp_input[4];
        T4 = T1 + (KP1_414213562 * T2);
        Tk = T1 - (KP1_414213562 * T2);

        E T9 = temp_input[1], Tf = temp_input[7];
        E Ta = temp_input[5], Tb = temp_input[3];
        E Tc = KP707106781 * (Ta + Tb);
        E Te = KP707106781 * (Ta - Tb);
        Td = T9 + Tc;
        To = Te + Tf;
        Tg = Te - Tf;
        Tn = T9 - Tc;
    }

    // Write outputs using remapped index positions via os[]
    E temp_output[8];
    temp_output[0]  = (T4 + T7) + ((KP1_961570560 * Td) - (KP390180644 * Tg));
    temp_output[7]  = (T4 + T7) - ((KP1_961570560 * Td) - (KP390180644 * Tg));
    temp_output[2]  = (Tk - Tl) + ((KP1_111140466 * Tn) + (KP1_662939224 * To));
    temp_output[5]  = (Tk - Tl) - ((KP1_111140466 * Tn) + (KP1_662939224 * To));
    temp_output[3]  = (T4 - T7) + ((KP390180644 * Td) + (KP1_961570560 * Tg));
    temp_output[4]  = (T4 - T7) - ((KP390180644 * Td) + (KP1_961570560 * Tg));
    temp_output[1]  = (Tk + Tl) + ((KP1_662939224 * Tn) - (KP1_111140466 * To));
    temp_output[6]  = (Tk + Tl) - ((KP1_662939224 * Tn) - (KP1_111140466 * To));

    for (INT j = 0; j < 8; ++j) {
        O[(os[output_index_map[j]])] = temp_output[j];
    }
}
}
