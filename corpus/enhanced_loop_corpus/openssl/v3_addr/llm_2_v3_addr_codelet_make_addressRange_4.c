#include <stdio.h>

#include <inttypes.h>

extern unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, backward from length-1)
    int stride = 2;
    for (i = length - (length % stride); i > 0 && max[i - 1] == 255; i -= stride)
        ;
}
