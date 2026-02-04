#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < wd_size; i += 2)
        buffer[i] = 0;
    // Handle odd-sized wd_size by setting last element if needed
    if (wd_size > 0 && (wd_size % 2) == 1)
        buffer[wd_size - 1] = 0;
}
