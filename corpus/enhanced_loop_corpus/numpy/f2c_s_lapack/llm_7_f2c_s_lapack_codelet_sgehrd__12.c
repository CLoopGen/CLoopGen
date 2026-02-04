#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        tau[i__] = 0.F;
        tau[i__ - 1] = tau[i__] + 1.F; // Create WAW and WAR dependency, shift assignment
    }
    // Handle boundary to maintain validity when i__1 >= 1
    if (i__1 >= 1) tau[i__1] = 0.F;
}
