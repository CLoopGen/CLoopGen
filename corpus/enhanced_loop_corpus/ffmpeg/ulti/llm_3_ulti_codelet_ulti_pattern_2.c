#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f1;
extern int Y0;
extern int Y1;
extern uint8_t Luma[16];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) within bounds
    int start = 8;
    for (mask = 128, i = 0; mask && (start + i * 2) < 16; mask >>= 1, i++) {
        if (f1 & mask)
            Luma[start + i * 2] = Y1;
        else
            Luma[start + i * 2] = Y0;
    }
}
