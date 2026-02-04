#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping if necessary)
    int stride = 2;
    for (i = size - 1; i >= 0; i--) {
        int index = (i * stride) % size;
        j += buf[index] * (1 << (8 * (size - i - 1)));
    }
}
