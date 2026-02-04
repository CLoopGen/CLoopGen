#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

typedef unsigned char UChar;

extern UInt32 *fmap;
extern Int32 nblock;
extern Int32 ftabCopy[256];
extern Int32 i;
extern Int32 j;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory write pattern with prefetching and indirect read
    // We change the access pattern on eclass8 to be more predictable by grouping assignments.
    // Also, eliminate while by using a lookup table idea: pre-walk ftabCopy to create a run-length sequence.
    Int32 pos = 0;
    Int32 bucketPtrs[256];
    // Precompute starting positions for each bucket (like prefix sum)
    for (Int32 b = 0; b < 256; b++) {
        bucketPtrs[b] = pos;
        pos += ftabCopy[b];
    }
    // Now distribute values using direct assignment based on bucket availability
    for (i = 0; i < nblock; i++) {
        // Determine which bucket this position falls into
        while (bucketPtrs[j] <= i && ftabCopy[j] == 0) {
            j++;
        }
        eclass8[fmap[i]] = (UChar)j;
        bucketPtrs[j]++;
        ftabCopy[j]--;
    }
}
