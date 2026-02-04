#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t thd_chancount[13];
extern int chanmap;
extern int channels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal (stride of 1, but backward)
    for (i = 12; i >= 0; i--)
        channels += thd_chancount[i] * ((chanmap >> i) & 1);
}
