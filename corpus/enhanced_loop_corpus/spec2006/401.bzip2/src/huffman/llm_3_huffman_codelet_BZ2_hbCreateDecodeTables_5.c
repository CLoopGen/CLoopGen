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
    // Variant 2: Indirect memory access using a precomputed index array (simulated via arithmetic)
    Int32 idx;
    for (i = minLen; i <= maxLen; i++) {
        for (j = 0; j < alphaSize; j++) {
            idx = (j * 7) % alphaSize;  // Simulate indirect access via hash-like indexing
            if (length[idx] == i) {
                perm[pp] = idx;
                pp++;
            }
        }
    }
}
