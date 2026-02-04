#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern unsigned int *Uo;
extern unsigned int *Vo;
extern int oUstride;
extern int oVstride;
extern int *U;
extern int *V;
extern int Ustride;
extern int Vstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by loop index
    unsigned int *local_Uo = Uo;
    unsigned int *local_Vo = Vo;
    int *local_U = U;
    int *local_V = V;

    for (j = 0; j < 2; j++) {
        // Unroll inner loop and access elements consecutively in memory order
        local_U[0] = local_Uo[0];
        local_U[1] = local_Uo[oUstride];  // Strided read from original source
        local_V[0] = local_Vo[0];
        local_V[1] = local_Vo[oVstride];

        // Advance pointers by stride for next outer iteration
        local_U += Ustride;
        local_V += Vstride;
        local_Uo += oUstride * 2;
        local_Vo += oVstride * 2;
    }
}
