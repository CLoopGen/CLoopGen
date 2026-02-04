#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal (reverse iteration)
    for (i = (6 + 3) - 1; i >= 2; i--)
        equot[i] = 0;
}
