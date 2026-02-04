#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

typedef unsigned char UChar;
typedef int Int32;
typedef unsigned char Bool;

UChar *len;
Int32 alphaSize = 500;
Int32 maxLen = 10;
Int32 i;
Int32 j;
Int32 k;
Bool tooLong;
Int32 parent[516];

void init_vars() {
    len = (UChar*)calloc(alphaSize, sizeof(UChar));
    for (Int32 idx = 0; idx < 516; idx++) {
        parent[idx] = -1;
    }
    for (Int32 idx = 1; idx <= alphaSize; idx++) {
        int depth = 0;
        int node = idx;
        while (node < 516 && parent[node] >= 0) {
            node = parent[node];
            depth++;
        }
        if (depth > maxLen) {
            tooLong = 1;
        }
    }
}