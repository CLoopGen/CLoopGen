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
    int temp_U[2], temp_V[2];
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            temp_U[i] = Uo[i];
            temp_V[i] = Vo[i];
        }
        for (i = 0; i < 2; i++) {
            U[i] = temp_U[i];
            V[i] = temp_V[i];
        }
        U += Ustride;
        V += Vstride;
        Uo += oUstride;
        Vo += oVstride;
    }
}
