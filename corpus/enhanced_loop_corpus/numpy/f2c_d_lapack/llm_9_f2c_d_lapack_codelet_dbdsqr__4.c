#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *e;
extern integer *info;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; i__ += 2) {
        if (i__ + 1 <= i__1) {
            if (e[i__] != 0.) {
                ++(*info);
            }
            if (e[i__ + 1] != 0.) {
                ++(*info);
            }
        } else {
            if (e[i__] != 0.) {
                ++(*info);
            }
        }
    }
}
