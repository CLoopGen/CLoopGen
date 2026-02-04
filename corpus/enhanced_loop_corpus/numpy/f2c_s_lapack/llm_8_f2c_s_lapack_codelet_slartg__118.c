#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *r__;
extern integer i__1;
extern integer i__;
extern real safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    *r__ *= safmx2;
    *r__ += safmx2;
}
}
