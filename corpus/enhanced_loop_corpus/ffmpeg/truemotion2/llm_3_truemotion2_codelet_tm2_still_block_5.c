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
    for (i = 0; i < 4; i += 2) {
        Y[i] = Yo[i];
        Y[i + 1] = Yo[i + 1];
        last[i] = Yo[i];
        last[i + 1] = Yo[i + 1];
    }
    Y += Ystride;
    Yo += oYstride;
}
}
