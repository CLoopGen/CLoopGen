#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward traversal)
    int size = sizeof(double);
    for (i = 0; i < size; i += 2) {
        buf[i] = p[i];
    }
    // Handle odd-sized double if needed (ensure full coverage)
    if (sizeof(double) % 2 && i - 1 < size) {
        buf[i-1] = p[i-1];
    }
}
