#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char bits[65];
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = k - 1; i >= 0; i--)
        bits[i] = '0';
}
