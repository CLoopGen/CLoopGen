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
    // Variant 1: Consecutive memory access with flattened indexing
    int idx = 0;
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            idx = j * 2 + i;  // Flatten 2D-like access into linear
            U[idx] = Uo[idx];
            V[idx] = Vo[idx];
        }
    }
}
