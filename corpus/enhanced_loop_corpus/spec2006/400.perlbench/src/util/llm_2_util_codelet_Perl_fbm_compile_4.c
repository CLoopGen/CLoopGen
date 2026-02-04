#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

typedef unsigned int U32;

typedef size_t STRLEN;

typedef int I32;

extern const unsigned char PL_freq[];
extern U8 *s;
extern U32 i;
extern STRLEN len;
extern I32 rarest;
extern U32 frequency;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Process every second element in forward direction, then sweep remaining
    U32 stride = 2;
    for (i = 0; i < len; i += stride) {
        if (PL_freq[s[i]] < frequency) {
            rarest = i;
            frequency = PL_freq[s[i]];
        }
    }
    for (i = 1; i < len; i += stride) {
        if (PL_freq[s[i]] < frequency) {
            rarest = i;
            frequency = PL_freq[s[i]];
        }
    }
}
