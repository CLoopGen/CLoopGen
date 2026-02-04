#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 && nn != 0; i++) {
    nn /= 2;
    nn -= (nn > 0) ? 1 : 0;
}
}
