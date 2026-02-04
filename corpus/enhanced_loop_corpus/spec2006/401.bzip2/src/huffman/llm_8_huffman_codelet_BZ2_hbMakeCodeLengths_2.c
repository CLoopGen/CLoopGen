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
    for (i = 1; i <= alphaSize; i++) {
        Int32 k_temp = i;
        Int32 depth = 0;
        for (Int32 p = parent[k_temp]; p >= 0; p = parent[k_temp]) {
            k_temp = p;
            depth++;
            if (depth > maxLen) {
                tooLong = 1;
                break;
            }
        }
        len[i - 1] = depth;
    }
}
