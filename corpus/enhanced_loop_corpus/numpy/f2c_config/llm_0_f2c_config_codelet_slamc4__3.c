#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__1;
extern integer i__;
extern real b1;
extern real d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (integer j = 1; j <= 5; ++j) {
        d1 += b1;
    }
}
}
