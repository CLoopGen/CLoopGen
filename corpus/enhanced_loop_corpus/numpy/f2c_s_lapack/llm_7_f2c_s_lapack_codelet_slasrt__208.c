#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *d__;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real dmnmx;
extern integer start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = start + 1; i__ <= i__1; ++i__) {
    i__2 = start + 1;
    dmnmx = d__[i__]; // Introduce early read and WAW dependency on dmnmx
    for (j = i__; j >= i__2; --j) {
        real temp = d__[j - 1];
        if (dmnmx < temp) {
            d__[j] = temp;
            d__[j - 1] = dmnmx;
            dmnmx = temp; // Update dmnmx to propagate value forward — modifies data flow
        } else {
            d__[j] = dmnmx;
            goto L50;
        }
    }
  L50:
    d__[i__] = dmnmx; // Final write to close the WAW chain
}
}
