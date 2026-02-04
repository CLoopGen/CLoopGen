#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern int patlen;
extern int skip[256];
extern uchar *pat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of iterating sequentially from 0 to patlen-1,
    // we traverse with a stride of 2, then handle remaining elements.
    // This changes the memory access pattern on 'pat' and 'skip'.
    int stride = 2;
    int limit = (patlen + stride - 1) / stride * stride;

    for (i = 0; i < limit; i += stride) {
        int idx1 = i;
        int idx2 = i + 1;

        if (idx1 < patlen)
            skip[pat[idx1]] = patlen - idx1 - 1;
        if (idx2 < patlen)
            skip[pat[idx2]] = patlen - idx2 - 1;
    }
}
