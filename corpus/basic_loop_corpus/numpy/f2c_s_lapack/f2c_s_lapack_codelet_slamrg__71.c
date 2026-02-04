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
for (n1sv = 1; n1sv <= i__1; ++n1sv) {
    index[i__] = ind2;
    ++i__;
    ind2 += *strd2;
}

}
