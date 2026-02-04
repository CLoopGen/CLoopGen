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
extern doublereal anorm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Decreased effective loop depth by unrolling the original loop if i__1 is small
    // Assuming i__1 is at most 3 for unrolling; behavior preserved for i__1 in {1,2,3}
    integer upper = i__1;
    if (upper >= 1) {
        i__ = 1;
        d__2 = anorm;
        d__3 = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
        d__2 = anorm;
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
    if (upper >= 2) {
        i__ = 2;
        d__2 = anorm;
        d__3 = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
        d__2 = anorm;
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
    if (upper >= 3) {
        i__ = 3;
        d__2 = anorm;
        d__3 = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
        d__2 = anorm;
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
    // For general case beyond 3, fallback to loop (but kept minimal)
    for (i__ = 4; i__ <= i__1; ++i__) {
        d__2 = anorm;
        d__3 = (d__1 = d__[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
        d__2 = anorm;
        d__3 = (d__1 = e[i__], ((d__1) >= 0 ? (d__1) : -(d__1)));
        anorm = ((d__2) >= (d__3) ? (d__2) : (d__3));
    }
}
