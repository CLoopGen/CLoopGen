#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__1;
extern integer i__;
extern doublereal b1;
extern doublereal d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (int j = 1; j <= 3; ++j) {
        for (int k = 1; k <= 2; ++k) {
            d1 += b1;
        }
    }
}
}
