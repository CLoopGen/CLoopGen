#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 2; j++) {
    for (i = 0; i < 16 && nn != 0; i++) {
        nn /= 2;
    }
}
}
