#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *EM;
extern int i;
extern int maskedDBLen;
extern unsigned char *DB;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    int stride = 2;
    int n = maskedDBLen - (maskedDBLen % stride); // Make sure we don't go out of bounds
    for (i = 0; i < n; i += stride) {
        DB[i] ^= EM[i];
        if (i + 1 < maskedDBLen) {
            DB[i + 1] ^= EM[i + 1];
        }
    }
    // Handle remaining element if maskedDBLen is odd
    if (n < maskedDBLen) {
        DB[maskedDBLen - 1] ^= EM[maskedDBLen - 1];
    }
}
