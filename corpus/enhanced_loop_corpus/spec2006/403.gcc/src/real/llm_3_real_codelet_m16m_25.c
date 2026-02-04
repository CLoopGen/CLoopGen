#include <stdio.h>

#include <inttypes.h>

extern unsigned short c[];
extern unsigned short p[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) within bounds
    for (i = 2; i < 9; i += 2) {
        c[i] = p[i];
    }
}
