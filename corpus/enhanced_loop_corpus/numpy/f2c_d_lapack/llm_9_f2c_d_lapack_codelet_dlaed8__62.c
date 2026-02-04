#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indxq;
extern integer *perm;
extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 2; j <= i__1 * 2; j += 2) {
        perm[j/2] = indxq[indx[j/2]];
        perm[j/2] = perm[j/2] ^ 1;
    }
}
