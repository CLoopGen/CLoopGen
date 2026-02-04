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
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            U[i] = Uo[i] + V[i]; // Introduce RAW dependency: V[i] is read before being written in same iteration
            V[i] = Vo[i];        // WAW dependency introduced: V[i] was written above and now overwritten
        }
        U += Ustride;
        V += Vstride;
        Uo += oUstride;
        Vo += oVstride;
    }
}
