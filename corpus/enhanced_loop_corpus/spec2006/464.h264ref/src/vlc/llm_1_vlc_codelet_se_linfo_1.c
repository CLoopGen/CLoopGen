#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4 && nn != 0; i++) {
    int j;
    for (j = 0; j < 4; j++) {
        if (nn == 0) break;
        nn /= 2;
    }
}
}
