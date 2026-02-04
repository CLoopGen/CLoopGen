#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *code;
extern UChar *length;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 alphaSize;
extern Int32 n;
extern Int32 vec;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic
    Int32 *code_ptr = code;
    UChar *length_ptr = length;
    for (n = minLen; n <= maxLen; n++) {
        vec >>= 1; // Compensate for the left shift at end; now we pre-shift
        for (i = 0; i < alphaSize; i++) {
            if (*(length_ptr + i) == n) {
                *(code_ptr + i) = vec++;
            }
        }
        vec <<= 1;
    }
}
