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
real temp_value = value;
for (i__ = 1; i__ <= i__1; ++i__) {
    if (work[i__] < temp_value) continue;
    temp_value = work[i__];
}
value = (doublereal)temp_value;
}
