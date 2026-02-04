#include <stdio.h>

#include <inttypes.h>

extern unsigned char *md;
extern unsigned int len;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        md[i] = (unsigned char)(i & 255);
    }
    // Handle odd-length arrays by filling the last element if needed
    if (len > 0 && (len % 2) == 1) {
        md[len - 1] = (unsigned char)((len - 1) & 255);
    }
}
