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
for (j = 0; j < 2; j++) {
    for (i = 0; i < 8; i += 2) {
        Y[i]     = Yo[i];
        Y[i + 1] = Yo[i + 1];
    }
    Y += 2 * Ystride;
    Yo += 2 * oYstride;
}
}
