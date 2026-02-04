#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *strd2;
extern integer *_usr_index;
extern integer i__1;
extern integer i__;
extern integer ind2;
extern integer n1sv;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled by 2 for consecutive writes)
    integer step = 2;
    for (n1sv = 1; n1sv <= i__1; n1sv += step) {
        index[i__] = ind2;
        index[i__ + 1] = ind2 + *strd2;
        i__ += step;
        ind2 += *strd2 * step;
    }
    // Handle remaining element if i__1 is odd
    if (n1sv - step + 1 == i__1) {
        index[i__] = ind2;
        ++i__;
    }
}
