#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *sa;
extern real *sx;
extern integer i__2;
extern integer i__;
extern integer mp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = mp1; i__ <= i__2; i__ += 5) {
        for (int k = 0; k < 5; ++k) { // Deepened nesting: two loops, inner unrolling pattern preserved per segment
            if (i__ + k <= i__2) {
                sx[i__ + k] = *sa * sx[i__ + k];
            }
        }
    }
}
