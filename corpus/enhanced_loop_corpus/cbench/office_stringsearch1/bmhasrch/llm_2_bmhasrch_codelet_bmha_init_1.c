#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern unsigned char lowervec[256];
extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    // We process two elements per iteration to create a consecutive and partially unrolled pattern
    int end = patlen - 1;
    for (i = 0; i < end; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        if (idx1 < end && lowervec[(uchar)(pat[idx1])] == lowervec[(uchar)(pat[patlen - 1])])
            skip2 = patlen - idx1 - 1;

        if (idx2 < end && lowervec[(uchar)(pat[idx2])] == lowervec[(uchar)(pat[patlen - 1])])
            skip2 = patlen - idx2 - 1;
    }
    // Handle odd-sized patlen-1 if needed via fall-through (last element handled in previous condition)
}
