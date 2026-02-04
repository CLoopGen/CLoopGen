#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern unsigned int *Yo;
extern int oYstride;
extern int *last;
extern int *Y;
extern int Ystride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            last[i] = Yo[i];
            Y[i] = last[i]; // Introduces WAW and RAW dependency: Y[i] depends on last[i], which was just written
        }
        Y += Ystride;
        Yo += oYstride;
    }
}
