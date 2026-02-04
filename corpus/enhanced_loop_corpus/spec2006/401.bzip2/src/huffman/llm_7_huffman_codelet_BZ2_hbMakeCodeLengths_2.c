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
    Int32 local_tooLong = tooLong;
    for (i = 1; i <= alphaSize; i++) {
        j = 0;
        k = i;
        // Unroll the traversal logic using a fixed upper bound to remove while
        for (Int32 depth = 0; depth < 516 && k >= 0 && parent[k] >= 0; depth++) {
            k = parent[k];
            j++;
        }
        len[i - 1] = (UChar)j;
        // Introduce WAR dependency on local_tooLong with delayed update
        if (j > maxLen) {
            local_tooLong = ((Bool)1);
        }
    }
    tooLong = local_tooLong; // Write final flag once, reducing WAW across iterations
}
