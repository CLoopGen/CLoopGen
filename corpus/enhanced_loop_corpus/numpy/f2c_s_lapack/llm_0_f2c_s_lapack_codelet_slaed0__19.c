#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (integer k = 1; k <= i__1; ++k) {
    for (j = 2; j <= k; ++j) {
        iwork[j] += iwork[j - 1];
    }
}
}
