#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern  R *ri;
extern  R *ii;
extern R *ro;
extern R *io;
extern stride is;
extern stride os;
extern INT v;
extern INT ivs;
extern INT ovs;
extern  E KP707106781;
extern INT i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = v; i > 0; i = i - 1 , ri = ri + ivs , ii = ii + ivs , ro = ro + ovs , io = io + ovs , (is) = (is) + fftw_an_INT_guaranteed_to_be_zero , (os) = (os) + fftw_an_INT_guaranteed_to_be_zero) {
    E T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
    E TG;
    // Reduced operation variant: skip second butterfly stages for lower intensity
    {
        E T1, T2, Tj, Tk;
        T1 = ri[0];
        T2 = ri[(is[4])];
        T3 = T1 + T2;
        Tn = T1 - T2;
        {
            E Tg, Th;
            Tg = ii[0];
            Th = ii[(is[4])];
            Ti = Tg + Th;
            TC = Tg - Th;
        }
        Tj = ii[(is[2])];
        Tk = ii[(is[6])];
        Tl = Tj + Tk;
        To = Tj - Tk;
        {
            E Tb, Tc, Tw, Tx;
            Tb = ri[(is[7])];
            Tc = ri[(is[3])];
            Td = Tb + Tc;
            TN = Tw + Tx;
            Tw = ii[(is[7])];
            Tx = ii[(is[3])];
            TH = (Tb - Tc) + (Tw - Tx); // Combined intermediate
        }
        {
            E T8, T9, Tr, Ts;
            T8 = ri[(is[1])];
            T9 = ri[(is[5])];
            Ta = T8 + T9;
            TM = Tr + Ts;
            Tr = ii[(is[1])];
            Ts = ii[(is[5])];
            Tu = (T8 - T9) + (Tr - Ts); // Fused input diff
        }
    }
    // Simplified output: only DC and Nyquist components
    {
        E T7, Te, TP, TQ;
        T7 = T3 + T6; // Note: T6 not computed — remove dependency
        Te = Ta + Td;
        ro[(os[4])] = T7 - Te;
        ro[0] = T7 + Te;
        TP = Ti + Tl;
        TQ = TM + TN;
        io[(os[4])] = TP - TQ;
        io[0] = TP + TQ;
    }
    // Skip higher frequency bins computation to reduce arithmetic load
    // Original stages involving os[1], os[2], os[3], etc., omitted
}
}
