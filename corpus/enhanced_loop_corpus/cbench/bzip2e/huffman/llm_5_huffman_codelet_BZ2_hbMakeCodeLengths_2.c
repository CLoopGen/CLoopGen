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
    j = 0;
    k = i;
    while_continue: ;
    if (parent[k] < 0) goto while_end;
    k = parent[k];
    j++;
    goto while_continue;
    while_end: ;
    len[i - 1] = j;
    if (j > maxLen)
        tooLong = ((Bool)1);
}
}
