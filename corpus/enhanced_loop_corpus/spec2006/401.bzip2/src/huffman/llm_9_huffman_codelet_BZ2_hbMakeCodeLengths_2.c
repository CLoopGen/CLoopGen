#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef int Int32;

typedef unsigned char Bool;

extern UChar *len;
extern Int32 alphaSize;
extern Int32 maxLen;
extern Int32 i;
extern Int32 j;
extern Int32 k;
extern Bool tooLong;
extern Int32 parent[516];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Int32 unroll_factor = 4;
    Int32 limit = alphaSize + (unroll_factor - alphaSize % unroll_factor) % unroll_factor;

    for (i = 1; i <= limit; i += unroll_factor) {
        for (Int32 u = 0; u < unroll_factor; u++) {
            Int32 idx = i + u;
            if (idx > alphaSize) continue;

            Int32 current = idx;
            Int32 count = 0;
            for (Int32 iter = 0; iter < maxLen + 10 && parent[current] >= 0; iter++) {
                current = parent[current];
                count++;
            }
            len[idx - 1] = count;
            if (count > maxLen) {
                tooLong = 1;
            }
        }
    }
}
