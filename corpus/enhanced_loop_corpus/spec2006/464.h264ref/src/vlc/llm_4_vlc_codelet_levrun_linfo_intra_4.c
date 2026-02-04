#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 && nn != 0; i++) {
    if (nn % 2 == 0) {
        nn /= 2;
    } else {
        continue;
    }
}
}
