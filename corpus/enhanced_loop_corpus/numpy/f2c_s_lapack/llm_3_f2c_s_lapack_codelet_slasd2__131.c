#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer i__;
extern integer nlp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with pointer arithmetic
    integer *base = coltyp + nlp2;
    ptrdiff_t count = i__1 - nlp2 + 1;
    for (ptrdiff_t j = 0; j < count; ++j) {
        base[j] = 2;
    }
}
