#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double s[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = m - 1; i >= 0; i--)
        s[i] = 0;
}
