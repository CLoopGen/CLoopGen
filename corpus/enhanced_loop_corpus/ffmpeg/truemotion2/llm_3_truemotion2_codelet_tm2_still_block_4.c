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
    // Variant 2: Strided access with fixed offset pattern using array indexing
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            // Use strided access through scaled indexing instead of pointer update
            U[j * Ustride + i] = Uo[j * oUstride + i];
            V[j * Vstride + i] = Vo[j * oVstride + i];
        }
    }

    // Final pointer updates to maintain external state consistency (if used outside)
    U += 2 * Ustride;
    V += 2 * Vstride;
    Uo += 2 * oUstride;
    Vo += 2 * oVstride;
}
