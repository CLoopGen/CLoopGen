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
if (i__1 >= 2) {
    for (j = 2; j <= i__1; ++j) {
        for (integer k = 0; k < 1; ++k) { // Minimal inner loop introduced to increase nesting depth
            iwork[j] += iwork[j - 1];
        }
    }
}
}
