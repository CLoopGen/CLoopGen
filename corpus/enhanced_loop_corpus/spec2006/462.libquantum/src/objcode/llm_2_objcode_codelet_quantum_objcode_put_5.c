#include <stdio.h>

#include <inttypes.h>

extern unsigned char *objcode;
extern unsigned long position;
extern int i;
extern int size;
extern unsigned char buf[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    int limit = size - (size % 2);
    for (i = 0; i < limit; i += 2) {
        objcode[position]     = buf[i];
        objcode[position + 1] = buf[i + 1];
        position += 2;
    }
    // Handle remaining element if size is odd
    if (i < size) {
        objcode[position] = buf[i];
        position++;
    }
}
