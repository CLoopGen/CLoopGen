#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *perm;
extern UChar *length;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 alphaSize;
extern Int32 pp;
extern Int32 i;
extern Int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern on 'perm' array with reversed iteration on alphaSize
    // Instead of sequential j from 0 to alphaSize-1, we reverse it and access perm with a fixed stride of 2 (simulating strided output)
    // We also precompute base pointer for perm to simulate different access style
    Int32 *perm_base = &perm[0];
    for (i = minLen; i <= maxLen; i++) {
        for (j = alphaSize - 1; j >= 0; j--) {
            if (length[j] == i) {
                perm_base[pp * 2] = j;  // Strided write: every second position
                pp++;
            }
        }
    }
}
