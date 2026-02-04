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
for (int idx = 0; idx < 16; idx++) {
    int j = idx / 4;
    int i = idx % 4;
    Y[i] = Yo[i];
    last[i] = Yo[i];
    if ((idx + 1) % 4 == 0) {
        Y += Ystride;
        Yo += oYstride;
    }
}
}
