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
        Int32 temp_parent[516];
        for (Int32 idx = 0; idx < 516; idx++) {
            temp_parent[idx] = parent[idx];
        }
        j = 0;
        k = i;
        for (; temp_parent[k] >= 0 && k != 0; ) {
            k = temp_parent[k];
            j++;
            temp_parent[k] = -1; // Eliminate future reads (WAW introduced)
        }
        len[i - 1] = j;
        if (j > maxLen) {
            tooLong = ((Bool)1);
        }
    }
}
