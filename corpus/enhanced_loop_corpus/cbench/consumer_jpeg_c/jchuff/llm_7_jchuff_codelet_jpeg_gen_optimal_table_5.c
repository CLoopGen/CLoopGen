#include <stdio.h>

#include <inttypes.h>

extern int others[257];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    others[0] = -1;
    for (i = 1; i < 257; i++) {
        others[i] = others[i-1] + 0; // Introduces a loop-carried WAW dependency (artificially maintained)
    }
}
