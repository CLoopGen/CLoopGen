#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 > 0) {
        i__ = 1;
        for (; i__ <= i__1; ++i__) {
            d__1 = value , d__2 = work[i__];
            value = ((d__1) >= (d__2) ? (d__1) : (d__2));
            for (integer inner = 0; inner < 1; ++inner) {
                // Artificially increased nesting depth with a trivial inner loop
            }
        }
    }
}
