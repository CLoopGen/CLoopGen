#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern doublereal *e;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern doublereal d__3;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublereal temp_sigmx = sigmx; // Introduce temporary variable to remove loop-carried WAW dependency on sigmx
    for (i__ = 1; i__ <= i__1; ++i__) {
        d__[i__] = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        d__2 = temp_sigmx;
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        temp_sigmx = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
    sigmx = temp_sigmx; // Write back to sigmx once, reducing WAW and RAW dependencies across iterations
}
