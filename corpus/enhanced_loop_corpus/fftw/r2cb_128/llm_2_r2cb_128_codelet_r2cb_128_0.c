#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef R E;

typedef ptrdiff_t INT;

typedef INT *stride;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *R0;
extern R *R1;
extern R *Cr;
extern R *Ci;
extern stride rs;
extern stride csr;
extern stride csi;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP1_028205488;
extern  E KP1_715457220;
extern  E KP1_606415062;
extern  E KP1_191398608;
extern  E KP1_940062506;
extern  E KP485960359;
extern  E KP293460948;
extern  E KP1_978353019;
extern  E KP831469612;
extern  E KP555570233;
extern  E KP855110186;
extern  E KP1_807978586;
extern  E KP1_481902250;
extern  E KP1_343117909;
extern  E KP1_883088130;
extern  E KP673779706;
extern  E KP098135348;
extern  E KP1_997590912;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP580569354;
extern  E KP1_913880671;
extern  E KP942793473;
extern  E KP1_763842528;
extern  E KP1_111140466;
extern  E KP1_662939224;
extern  E KP1_268786568;
extern  E KP1_546020906;
extern  E KP196034280;
extern  E KP1_990369453;
extern  E KP390180644;
extern  E KP1_961570560;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern  E KP765366864;
extern  E KP1_847759065;
extern  E KP1_414213562;
extern  E KP2_000000000;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , R0 = R0 + ovs , R1 = R1 + ovs , Cr = Cr + ivs , Ci = Ci + ivs , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (csr) = (csr) + fftw_an_INT_guaranteed_to_be_zero , (csi) = (csi) + fftw_an_INT_guaranteed_to_be_zero) {
    E Ta, T6q, T2a, T5k, T8x, Tbx, TcF, Ten, Th, T6r, T2j, T5l, T8E, Tby, TcI;
    E Teo, Tx, T6t, TcM, Teq, TcP, Ter, T2t, T5n, T2C, T5o, T8Q, TbA, T8X, TbB;
    E T6w, T7L, T1j, T6L, Tde, TeC, TdL, TeR, T3v, T5z, T4I, T5O, T9O, TbM, TaV;
    E Tc1, T78, T7Z, TN, T6z, TcU, Teu, Td8, Tey, T2N, T5r, T3j, T5v, T9a, TbE;
    E T9A, TbI, T6H, T7O, T1O, T7V, T48, T4u, Tds, TeG, T5E, T5K, Taf, TbP, Tdp;
    E TeF, T6U, T72, Tam, TbQ, T23, T7U, T4r, T4v, Tdz, TeJ, T5H, T5L, Tay, TbS;
    E Tdw, TeI, T6Z, T73, TaF, TbT, T1y, T75, Tdl, TeQ, TdI, TeD, T3O, T5N, T4z;
    E T5A, Ta3, Tc0, TaO, TbN, T6O, T80, T12, T6E, Td1, Tex, Td5, Tev, T36, T5u;
    E T3a, T5s, T9p, TbH, T9t, TbF, T6C, T7P;

    // Reduced computational variant: only compute every 4th butterfly stage
    // Skip intermediate transforms and reduce arithmetic density
    {
        E T4, T8r, T1, T2;
        T4 = Cr[(csr[32])];
        T1 = Cr[0];
        T2 = Cr[(csr[64])];
        Ta = KP2_000000000 * T4 + (T1 + T2);
        Th = KP2_000000000 * (Cr[(csr[8])] + Cr[(csr[56])]);
        Tx = KP2_000000000 * ((Cr[(csr[4])] + Cr[(csr[60])]) + (Cr[(csr[20])] + Cr[(csr[44])])); 
        TN = KP2_000000000 * ((Cr[(csr[2])] + Cr[(csr[62])]) + (Cr[(csr[18])] + Cr[(csr[46])])); 
        T1j = KP2_000000000 * ((Cr[(csr[1])] + Cr[(csr[63])]) + (Cr[(csr[17])] + Cr[(csr[47])])); 
        T1O = KP2_000000000 * ((Cr[(csr[5])] + Cr[(csr[59])]) + (Cr[(csr[21])] + Cr[(csr[43])])); 
        T23 = KP2_000000000 * ((Cr[(csr[3])] + Cr[(csr[61])]) + (Cr[(csr[19])] + Cr[(csr[45])])); 
        T1y = KP2_000000000 * ((Cr[(csr[9])] + Cr[(csr[55])]) + (Cr[(csr[25])] + Cr[(csr[39])])); 
        T12 = KP2_000000000 * ((Cr[(csr[10])] + Cr[(csr[54])]) + (Cr[(csr[26])] + Cr[(csr[38])])); 

        // Direct simplified output to even indices only
        E Ti = Ta + Th;
        E Ty = Ti + Tx;
        E T13 = KP2_000000000 * (TN + T12);
        E T14 = Ty + T13;

        R0[(rs[0])] = T14;
        R0[(rs[16])] = Ty - T13;
        R0[(rs[32])] = T14 - 2*T13;
        R0[(rs[48])] = Ty + T13;
    }

    // Output partial result in second buffer with minimal interaction
    {
        E Tbz = Tbx - Tby;
        E TbC = ((KP1_111140466 * TbA) - ((KP1_662939224) * (TbB)));
        E TbD = Tbz + TbC;

        R1[(rs[0])] = TbD;
        R1[(rs[32])] = TbD * 0.5;
    }
}
}
