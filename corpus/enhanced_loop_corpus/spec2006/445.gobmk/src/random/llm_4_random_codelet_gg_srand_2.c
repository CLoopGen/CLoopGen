#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[25];
extern unsigned int seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 25; i++) {
    if (seed % 2 == 0) {
        x[i] = seed;
        seed *= 1313;
        seed += 88897;
    } else {
        seed += 1313;
        x[i] = seed;
        seed *= 88897;
    }
}
}
