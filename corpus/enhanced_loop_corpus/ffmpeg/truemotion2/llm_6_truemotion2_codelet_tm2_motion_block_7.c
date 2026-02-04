#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern unsigned int *Yo;
extern int oYstride;
extern int *Y;
extern int Ystride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[4];
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            temp[i] = Yo[i]; // Introduce temporary storage to break direct WAW and RAW dependencies with Y
        }
        for (i = 0; i < 4; i++) {
            Y[i] = temp[i]; // Decouple write to Y: introduces intra-loop dependency via temp, removes immediate RAW/WAW between iterations
        }
        Y += Ystride;
        Yo += oYstride;
    }
}
