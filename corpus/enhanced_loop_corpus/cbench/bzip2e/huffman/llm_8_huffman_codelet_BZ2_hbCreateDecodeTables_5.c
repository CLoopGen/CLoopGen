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
    // Variant 1: Increased computational intensity by unrolling inner loop and adding redundant arithmetic
    // Also modified trip count by iterating backwards with adjusted bounds to maintain similar semantics
    for (i = maxLen; i >= minLen; i--) {
        for (j = 0; j < alphaSize; j += 4) {
            // Unroll by 4 to increase arithmetic operations per iteration
            if (j < alphaSize && length[j] == i) {
                perm[pp] = j;
                pp++;
            }
            if (j + 1 < alphaSize && length[j + 1] == i) {
                perm[pp] = j + 1;
                pp++;
            }
            if (j + 2 < alphaSize && length[j + 2] == i) {
                perm[pp] = j + 2;
                pp++;
            }
            if (j + 3 < alphaSize && length[j + 3] == i) {
                perm[pp] = j + 3;
                pp++;
            }
        }
    }
}
