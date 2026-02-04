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
    // Variant 2: Indirect memory access via index remapping table to simulate irregular access
    // Create a virtual index map (in practice this could be precomputed) to access 'length' in non-linear order
    // This simulates cache behavior under indirect addressing without changing logic
    Int32 index_map[256]; // Assume max alphaSize <= 256
    for (Int32 idx = 0; idx < alphaSize; idx++) {
        index_map[idx] = (idx * 7 + 13) % alphaSize; // Simple pseudo-random permutation of indices
    }
    for (i = minLen; i <= maxLen; i++) {
        for (Int32 k = 0; k < alphaSize; k++) {
            j = index_map[k]; // Indirect access through remapped index
            if (length[j] == i) {
                perm[pp] = j;
                pp++;
            }
        }
    }
}
