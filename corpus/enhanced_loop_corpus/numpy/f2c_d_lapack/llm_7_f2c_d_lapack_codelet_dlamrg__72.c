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
    integer temp_ind1 = ind1;
    for (n2sv = 1; n2sv <= i__1; ++n2sv) {
        index[i__] = temp_ind1;
        temp_ind1 += *dtrd1;
        ++i__;
    }
    ind1 = temp_ind1;
}
