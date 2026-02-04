#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[25];
extern unsigned int seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (i = 0; i < 25; i++) {
            x[i] = seed;
            seed *= 1313;
            seed += 88897;
        }
    }
}
