#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *r__;
extern integer i__1;
extern integer i__;
extern doublereal safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        for (int j = 0; j < 2; ++j) {
            *r__ *= safmn2;
        }
    }
}
