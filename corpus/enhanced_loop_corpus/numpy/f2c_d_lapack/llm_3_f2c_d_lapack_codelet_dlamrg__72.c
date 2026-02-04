#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *dtrd1;
extern integer *_usr_index;
extern integer i__1;
extern integer i__;
extern integer ind1;
extern integer n2sv;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 2: Indirect memory access using an offset array (simulated via arithmetic)
    // Assume _usr_index now used as base, and we access indirectly via a calculated offset pattern
    integer base_offset = 0;
    for (n2sv = 1; n2sv <= i__1; ++n2sv) {
        base_offset = (i__ * 3 + 1) % (*dtrd1 > 0 ? *dtrd1 : 1);  // Non-linear indirect-like index
        index[base_offset] = ind1;
        ++i__;
        ind1 += *dtrd1;
    }
}
