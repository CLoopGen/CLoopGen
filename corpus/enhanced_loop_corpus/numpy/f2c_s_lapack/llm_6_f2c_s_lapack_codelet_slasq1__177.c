#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *work;
extern integer i__1;
extern real r__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp = 0.0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp = work[i__];          // Introduce temporary to create WAW and WAR dependency with itself
        work[i__] = temp * temp;    // Use delayed value — creates intra-loop dependency on temp (loop-carried via temp)
        temp = work[i__];           // WAW on temp, though harmless; strengthens artificial dependency chain
    }
}
