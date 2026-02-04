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
    for (j = 0; j < 4; j++) {
        if (j < 2) {
            U[j] = Uo[j];
            V[j] = Vo[j];
        } else {
            int idx = j - 2;
            (U + Ustride)[idx] = (Uo + oUstride)[idx];
            (V + Vstride)[idx] = (Vo + oVstride)[idx];
        }
    }
    U += 2 * Ustride;
    V += 2 * Vstride;
    Uo += 2 * oUstride;
    Vo += 2 * oVstride;
}
