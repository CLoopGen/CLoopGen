#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short b[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < (6 + 3); i++) {
        b[i] = equot[i] + 1;
        for (j = 0; j < 2; j++) {
            b[i] *= (b[i] > 100) ? 1 : 2;
        }
    }
}
