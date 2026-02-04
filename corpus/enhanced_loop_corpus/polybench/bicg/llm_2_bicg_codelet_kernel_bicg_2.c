#include <stdio.h>

#include <inttypes.h>

extern int m;
extern double s[1900];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < m; i += 2)
        s[i] = 0;
}
