#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *e;
extern integer *info;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i__1 >= 1) {
    i__ = 1;
    for (; i__ <= i__1; ) {
        if (e[i__] != 0.F) {
            ++(*info);
        }
        ++i__;
    }
}
}
