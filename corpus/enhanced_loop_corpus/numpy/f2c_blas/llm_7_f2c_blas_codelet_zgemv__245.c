#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *y;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp_index = 0;
    for (i__ = 1; i__ <= i__1; ++i__) {
        temp_index = i__ + 1; // Introduce temporary variable to break direct WAW/RAW
        if (i__ < i__1) {
            y[temp_index].r = 0.0;
            y[temp_index].i = 0.0;
        }
    }
    // Handle boundary case to preserve semantics approximately
    if (i__1 >= 1) {
        y[1].r = 0.0;
        y[1].i = 0.0;
    }
}
