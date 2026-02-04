#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *delta;
extern integer i__1;
extern integer j;
extern doublereal eta;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access with offset base pointer (forward traversal using pointer arithmetic)
    doublereal *delta_base = delta + 1;  // Point to delta[1]
    for (j = 0; j < i__1; ++j) {
        delta_base[j] -= eta;
    }
}
