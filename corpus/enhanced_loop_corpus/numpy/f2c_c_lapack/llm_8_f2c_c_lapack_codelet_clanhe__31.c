#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *work;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 1; i__ <= i__1; ++i__) {
        r__1 = value;
        r__2 = work[i__] * 2.0f;
        value = (doublereal)((r__1) >= (r__2) ? (r__1) : (r__2));
        work[i__] += 1.5f;
    }
}
