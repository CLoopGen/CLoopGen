#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos += 2)
        values[pos] = 0.;
}
