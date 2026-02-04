#include <stdio.h>

#include <inttypes.h>

extern unsigned char smbuf[256];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2 (forward traversal, updating every second element)
    for (i = 1; i <= 255; i += 2)
        smbuf[i - 1] = (i * 2) & 255;
}
