#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short num[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Access every second element in both arrays, then fill the gaps in a second pass
    for (int j = 0; j < (6 + 3); j += 2)
        num[j] = equot[j];
    for (int j = 1; j < (6 + 3); j += 2)
        num[j] = equot[j];
}
