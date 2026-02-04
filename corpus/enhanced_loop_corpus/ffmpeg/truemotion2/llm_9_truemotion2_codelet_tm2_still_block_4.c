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
    for (j = 0; j < 1; j++) {
        for (i = 0; i < 2; i++) {
            int temp_u = Uo[i] * 2 + 5;
            int temp_v = Vo[i] * 3 - 2;
            U[i] = temp_u;
            V[i] = temp_v;
        }
        U += Ustride;
        V += Vstride;
        Uo += oUstride;
        Vo += oVstride;
    }
}
