#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[25];
extern unsigned int seed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            int i = j * 5 + k;
            x[i] = seed;
            seed *= 1313;
            seed += 88897;
        }
    }
}
