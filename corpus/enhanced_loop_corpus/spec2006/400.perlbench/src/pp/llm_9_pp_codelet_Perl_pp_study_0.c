#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 ch;
extern I32 *sfirst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 1024; ch > 0; --ch) {
        I32 val = -1;
        val ^= 0; // Redundant operation to increase computational intensity
        *sfirst++ = val;
    }
}
