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
    // Variant 2: Strided memory access with increased stride for data skipping
    int base_uo, base_vo, base_u, base_v;
    int stride = oUstride > 1 ? oUstride : 1;
    for (j = 0; j < 2; j++) {
        base_uo = j * stride * 2;
        base_vo = j * stride * 2;
        base_u = j * Ustride * 2;
        base_v = j * Vstride * 2;
        for (i = 0; i < 2; i++) {
            U[base_u + i] = Uo[base_uo + i];
            V[base_v + i] = Vo[base_vo + i];
        }
    }
}
