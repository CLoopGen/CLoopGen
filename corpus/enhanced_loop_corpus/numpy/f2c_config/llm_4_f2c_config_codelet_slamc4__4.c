#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__1;
extern integer i__;
extern real b2;
extern real d2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1) {
        for (i__ = 1; i__ <= i__1; ++i__) {
            d2 += b2;
        }
    }
}
