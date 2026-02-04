#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *strd1;
extern integer *_usr_index;
extern integer i__1;
extern integer i__;
extern integer ind1;
extern integer n2sv;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive memory access with reversed loop order
    for (n2sv = i__1; n2sv >= 1; --n2sv) {
        index[i__] = ind1;
        ++i__;
        ind1 += *strd1;
    }
}
