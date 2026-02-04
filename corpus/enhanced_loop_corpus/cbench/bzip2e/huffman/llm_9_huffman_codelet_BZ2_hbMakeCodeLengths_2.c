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



void loop(){
Int32 stack[516];
Int32 top = 0;
for (i = 1; i <= alphaSize; i++) {
    j = 0;
    k = i;
    top = 0;
    while (parent[k] >= 0) {
        stack[top++] = k;
        k = parent[k];
    }
    j = top;
    len[i - 1] = j;
    if (j > maxLen)
        tooLong = ((Bool)1);
}
}
