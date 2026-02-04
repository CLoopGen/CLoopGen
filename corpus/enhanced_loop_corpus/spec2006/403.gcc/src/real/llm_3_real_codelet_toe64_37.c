#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern unsigned short i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2 (using pointer arithmetic)
    for (i = 0; i < 8; i += 2) {
        *(q - (i >> 1)) = *(p + (i >> 1));
    }
}
