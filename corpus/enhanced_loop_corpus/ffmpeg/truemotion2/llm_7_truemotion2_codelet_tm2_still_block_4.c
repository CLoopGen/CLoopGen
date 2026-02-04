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
        // Eliminate loop-carried dependencies by unrolling and reordering operations
        U[0] = Uo[0];
        V[0] = Vo[0];
        U[1] = Uo[1];
        V[1] = Vo[1];

        // Remove pointer updates inside inner loop to break WAR dependencies
        // Move all pointer arithmetic after the data copy
        U += Ustride;
        V += Vstride;
        Uo += oUstride;
        Vo += oVstride;
    }
}
