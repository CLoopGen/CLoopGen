#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 23; i += 2) {
        if (i + 1 < 23) {
            base[i] = 0;           // No inter-element dependency
            base[i + 1] = 0;       // Independent writes — eliminates loop-carried dependency
        } else {
            base[i] = 0;
        }
    }
    // Eliminates sequential data dependencies — each iteration is independent (RAW/WAR/WAW removed across iterations)
}
