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
    // Variant 2: Reduced computational complexity by flattening nested loops into a single loop
    // Uses linear iteration over combined index space with conditional checks to simulate original logic
    Int32 totalIterations = (maxLen - minLen + 1) * alphaSize;
    for (Int32 idx = 0; idx < totalIterations; idx++) {
        i = minLen + (idx / alphaSize);  // Compute current length group
        j = idx % alphaSize;             // Compute current symbol
        if (length[j] == i) {
            perm[pp] = j;
            pp++;
        }
    }
}
