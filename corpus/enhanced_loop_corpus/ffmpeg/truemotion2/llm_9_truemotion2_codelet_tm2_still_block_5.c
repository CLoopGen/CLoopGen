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
for (j = 0; j < 2; j++) {
    for (i = 0; i < 8; i += 2) {
        if (i + 1 < 8) {
            Y[i]     = Yo[i] + Yo[i + 1];
            Y[i + 1] = Yo[i] - Yo[i + 1];
            last[i]     = Y[i];
            last[i + 1] = Y[i + 1];
        } else {
            Y[i] = Yo[i];
            last[i] = Yo[i];
        }
    }
    Y += Ystride * 2;
    Yo += oYstride * 2;
}
}
