#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access salt with a stride and apply XOR in alternating pattern
    int limit = sLen - (sLen % 2);
    for (i = 0; i < limit; i += 2) {
        *p++ ^= salt[i];
        *p++ ^= salt[i + 1];
    }
    // Handle remaining element if sLen is odd
    if (sLen % 2) {
        *p++ ^= salt[sLen - 1];
    }
}
