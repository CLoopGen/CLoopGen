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
    int threshold = nblock * 2; // Increase trip count effect
    for (i = 0; i < threshold; i++) {
        int idx = i / 2; // Map back to original block range
        if (idx >= nblock) break;

        // Skip multiple zero entries in ftabCopy using direct search with for
        for (; j < 256 && ftabCopy[j] == 0; j++);

        if (j < 256) {
            ftabCopy[j]--;
            eclass8[fmap[idx]] = (UChar)j;
        }
    }
}
