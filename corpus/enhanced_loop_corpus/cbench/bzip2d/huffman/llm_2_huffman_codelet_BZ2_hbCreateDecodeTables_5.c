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
    // Variant 1: Memory Access Pattern Modification using strided access pattern
    // Instead of iterating by increasing j from 0 to alphaSize-1 in order,
    // we traverse the length array with a stride (e.g., stride of 2), then handle remainder.
    // This changes spatial locality and access pattern, potentially improving cache behavior
    // in some architectures or data layouts.

    Int32 stride = 2;
    for (i = minLen; i <= maxLen; i++) {
        // First pass: strided access
        for (j = 0; j < alphaSize; j += stride) {
            if (length[j] == i) {
                perm[pp] = j;
                pp++;
            }
        }
        // Second pass: handle offset positions (j=1, 1+stride, ...) to cover all elements
        for (j = 1; j < alphaSize; j += stride) {
            if (length[j] == i) {
                perm[pp] = j;
                pp++;
            }
        }
    }
}
