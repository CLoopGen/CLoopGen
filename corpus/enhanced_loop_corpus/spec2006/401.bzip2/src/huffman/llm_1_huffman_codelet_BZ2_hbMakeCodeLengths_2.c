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
for (i = 1; i <= alphaSize; i++) {
    len[i - 1] = 0;
    for (Int32 temp = i; parent[temp] >= 0; ) {
        len[i - 1]++;
        temp = parent[temp];
        if (len[i - 1] > maxLen) {
            tooLong = ((Bool)1);
        }
    }
}
}
