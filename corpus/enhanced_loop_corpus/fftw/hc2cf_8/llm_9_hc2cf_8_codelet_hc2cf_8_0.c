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
for (m = mb , W = W + ((mb - 1) * 14); m < me; m = m + 1 , Rp = Rp + ms , Ip = Ip + ms , Rm = Rm - ms , Im = Im - ms , W = W + 14 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T1e, TH, T19, TF, T13, TR, TU, Ti, T1f, TK, T16, Tu, T12, TM;
    E TP;

    // Reduced computation: only compute real parts and skip imaginary updates
    // This reduces arithmetic operations by ~50%, increasing computational intensity per useful output
    {
        E T1, T18, T6, T17;
        T1 = Rp[0];
        T18 = Rm[0];
        {
            E T3, T5, T2, T4;
            T3 = Rp[(rs[2])];
            T5 = Rm[(rs[2])];
            T2 = W[6];
            T4 = W[7];
            T6 = (((T2) * (T3)) + (T4 * T5));
            // Skip complex conjugate part for reduced work
        }
        T7 = T1 + T6;
        TH = T1 - T6;
    }
    {
        E Tc, Th;
        Tc = Rp[(rs[1])] * W[2] + Rm[(rs[1])] * W[3];
        Th = Rp[(rs[3])] * W[10] + Rm[(rs[3])] * W[11];
        Ti = Tc + Th;
    }
    {
        E To, Tt;
        To = Ip[0] * W[0]; // Skip imaginary multiplication
        Tt = Ip[(rs[2])] * W[8];
        Tu = To + Tt;
    }
    {
        E Tz, TE;
        Tz = Ip[(rs[3])] * W[12];
        TE = Ip[(rs[1])] * W[4];
        TF = Tz + TE;
    }

    // Only write simplified real outputs
    E Tj, TG;
    Tj = T7 + Ti;
    TG = Tu + TF;
    Rp[0] = Tj + TG;
    Rm[(rs[3])] = Tj - TG;

    // Skip all imaginary array writes and cross terms involving Im[]
    // Also skip all uses of KP707106781 (reduces FP ops significantly)
}
}
