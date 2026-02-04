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
        if (j % 2 == 0) {
            for (i = 0; i < 4; i++) {
                Y[i] = Yo[i];
            }
        } else {
            for (i = 0; i < 4; i++) {
                Y[i] = Yo[i] + 1;
            }
        }
        Y += Ystride;
        Yo += oYstride;
    }
}
