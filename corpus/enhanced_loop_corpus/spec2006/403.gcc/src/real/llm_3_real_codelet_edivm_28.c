#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short num[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the arrays from the last index to the first
    for (int j = (6 + 3) - 1; j >= 0; j--)
        num[j] = equot[j];
}
