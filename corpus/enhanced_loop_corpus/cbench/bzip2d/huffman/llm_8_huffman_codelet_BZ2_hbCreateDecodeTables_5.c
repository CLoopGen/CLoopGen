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
    // Variant 1: Increased computational intensity by unrolling inner loop and adding redundant arithmetic operations
    // Also modified trip count of outer loop to step by 2, reducing iterations but increasing work per iteration
    for (i = minLen; i <= maxLen; i += 2) {
        for (j = 0; j < alphaSize - 3; j += 4) {
            if (length[j] == i) {
                perm[pp] = j;
                pp++;
            }
            if (length[j+1] == i) {
                perm[pp] = j+1;
                pp++;
            }
            if (length[j+2] == i) {
                perm[pp] = j+2;
                pp++;
            }
            if (length[j+3] == i) {
                perm[pp] = j+3;
                pp++;
            }
        }
        // Handle remaining elements
        for (; j < alphaSize; j++) {
            if (length[j] == i) {
                perm[pp] = j;
                pp++;
            }
        }
        // Add dummy arithmetic to increase computation per outer loop iteration
        pp += (pp & 1); // Conditional increment based on parity
    }
}
