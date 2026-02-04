#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2100];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    for (i = n - 1; i >= 0; i--)
        x[i] = 1 + (i / fn);
}
