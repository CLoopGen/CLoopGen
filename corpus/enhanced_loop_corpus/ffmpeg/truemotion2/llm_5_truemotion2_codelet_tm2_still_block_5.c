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
    int processed = 0;
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0) {
            Y[i] = Yo[i];
            last[i] = Yo[i];
            processed++;
        }
    }
    if (processed > 0) {
        Y += Ystride;
        Yo += oYstride;
    }
}
}
