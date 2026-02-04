#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip2;
extern uchar *pat;
extern int i;
extern int lastpatchar;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index map (simulated using reverse traversal order)
    // Instead of sequential access, we use a precomputed indirect index list (emulated with reverse indexing)
    // This simulates a non-sequential, indirect access pattern useful for cache behavior analysis

    // Simulate indirect access by iterating backwards — effectively changing access order
    for (i = patlen - 2; i >= 0; --i) {
        if (pat[i] == lastpatchar)
            skip2 = patlen - i - 1;
    }
}
