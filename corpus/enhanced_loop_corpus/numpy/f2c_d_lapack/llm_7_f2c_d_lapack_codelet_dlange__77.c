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
    doublereal local_value = value;
    for (i__ = 1; i__ <= i__1; ++i__) {
        if (work[i__] > local_value) {
            local_value = work[i__];
        }
    }
    value = local_value;
}
