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
    Int32 temp_len[516];
    for (i = 1; i <= alphaSize; i++) {
        j = 0;
        k = i;
        for (; parent[k] >= 0; ) {
            k = parent[k];
            j++;
        }
        temp_len[i - 1] = j;
        if (j > maxLen && !tooLong) {
            tooLong = ((Bool)1);
        }
    }
    // Eliminate loop-carried dependency by decoupling len write from control flow
    for (i = 1; i <= alphaSize; i++) {
        len[i - 1] = temp_len[i - 1];
    }
}
