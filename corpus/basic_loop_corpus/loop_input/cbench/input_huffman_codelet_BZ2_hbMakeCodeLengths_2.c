#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

typedef unsigned char UChar;
typedef int Int32;
typedef unsigned char Bool;

UChar *len;
Int32 alphaSize = 256;
Int32 maxLen = 10;
Int32 i;
Int32 j;
Int32 k;
Bool tooLong;
Int32 parent[516];

void init_vars() {
    len = (UChar*)malloc(alphaSize * sizeof(UChar));
    for (i = 0; i < 516; i++) {
        parent[i] = -1;
    }
    for (i = 1; i <= alphaSize; i++) {
        k = i;
        j = 0;
        while (k < 516 && parent[k] >= 0) {
            k = parent[k];
            j++;
        }
        if (i - 1 < alphaSize) {
            len[i - 1] = j;
        }
        if (j > maxLen) {
            tooLong = 1;
        }
    }
}