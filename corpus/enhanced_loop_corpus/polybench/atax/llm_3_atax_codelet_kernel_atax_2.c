#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double y[2100];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = n - 1; i >= 0; i--)
        y[i] = 0;
}
