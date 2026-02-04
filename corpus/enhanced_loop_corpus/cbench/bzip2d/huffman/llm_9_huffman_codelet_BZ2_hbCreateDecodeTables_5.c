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
    // Variant 2: Reduced computational intensity by flattening nested loops into a single loop with manual indexing
    // Uses combined index to simulate two-dimensional traversal with fewer control checks
    Int32 totalIterations = (maxLen - minLen + 1) * alphaSize;
    Int32 currentLen, currentAlpha;

    for (i = 0; i < totalIterations; i++) {
        currentLen = minLen + (i / alphaSize);  // Determine current length group
        currentAlpha = i % alphaSize;           // Determine current alphabet index

        if (length[currentAlpha] == currentLen) {
            perm[pp] = currentAlpha;
            pp++;
        }
    }
}
