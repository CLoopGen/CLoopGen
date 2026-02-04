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
    // Variant 2: Eliminate loop-carried dependencies by precomputing values
    // All writes are now independent — no RAW, WAR, or WAW across iterations
    integer base = ind1 - *strd1;  // Adjust to start from correct offset
    for (n2sv = 1; n2sv <= i__1; ++n2sv) {
        integer temp_val = base + (*strd1) * n2sv;
        index[i__ + (n2sv - 1)] = temp_val;  // Use stride-based indexing
    }
    // Update side effects after loop
    i__ += i__1;
    ind1 = base + (*strd1) * i__1;
}
