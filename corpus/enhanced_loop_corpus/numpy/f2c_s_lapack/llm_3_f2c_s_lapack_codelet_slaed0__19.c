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
    // Variant 2: Reverse consecutive access with offset indexing
    integer k;
    for (k = i__1; k >= 2; --k) {
        iwork[k] += iwork[k - 1];
    }
}
