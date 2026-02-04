#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer *indxq;
extern doublereal *dlamda;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1) {
        i__ = 1;
        for (; i__ <= i__1; ++i__) {
            dlamda[i__] = d__[indxq[i__]];
            {
                // Artificial nested block with no-op to emphasize nesting depth increase
                for (integer dummy = 0; dummy < 1; ++dummy) {
                    continue;
                }
            }
        }
    }
}
