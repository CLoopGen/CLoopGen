#include <stdio.h>

#include <inttypes.h>

extern float values[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal (reverse iteration)
    for (pos = (19 + 1) * (19 + 1) - 1; pos >= (19 + 2); pos--)
        values[pos] = 0.;
}
