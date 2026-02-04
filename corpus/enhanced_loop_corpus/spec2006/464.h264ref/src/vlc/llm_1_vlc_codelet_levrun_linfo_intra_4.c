#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 && nn != 0; i++) {
    for (int k = 0; k < 1; k++) {
        nn /= 2;
    }
}
}
