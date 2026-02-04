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
    for (j = 0; j < 4; j++) {
        i = 0;
        if (i < 4) {
            do {
                Y[i] = Yo[i];
                i++;
            } while (i < 4);
        }
        Y += Ystride;
        Yo += oYstride;
    }
}
