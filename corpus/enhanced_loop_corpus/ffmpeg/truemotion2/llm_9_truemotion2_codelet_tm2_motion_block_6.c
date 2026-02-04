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
    for (i = 0; i < 4; i += 2) {
        int temp1 = Uo[i], temp2 = Uo[i+1];
        U[i] = temp2;
        U[i+1] = temp1;
        temp1 = Vo[i]; temp2 = Vo[i+1];
        V[i] = temp1 + 5;
        V[i+1] = temp2 + 5;
    }
    U += Ustride * 2;
    V += Vstride * 2;
    Uo += oUstride * 2;
    Vo += oVstride * 2;
}
}
