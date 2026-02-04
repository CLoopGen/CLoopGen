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
    for (Int32 depth = 0, current = i; depth <= maxLen + 10 && parent[current] >= 0; depth++) {
        current = parent[current];
        if (depth + 1 > maxLen) {
            tooLong = ((Bool)1);
        }
        for (Int32 update = i; update <= i; update++) { // Artificial nesting to increase depth
            if (parent[current] < 0) {
                len[i - 1] = depth + 1;
            }
        }
    }
    // Final assignment in case inner loop didn't assign due to unrolling logic
    if (parent[i] < 0) {
        len[i - 1] = 0;
    } else if (len[i - 1] == 0 && tooLong != 1) {
        // Recover length using a linear traversal if not set
        Int32 temp = i, count = 0;
        while (parent[temp] >= 0) {
            temp = parent[temp];
            count++;
        }
        len[i - 1] = count;
    }
}
}
