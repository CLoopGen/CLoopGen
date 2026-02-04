#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *d__;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer indices[256]; 
for (integer j = 0; j < i__1 && j < 256; ++j) {
    indices[j] = j + 1;
}
for (i__ = 0; i__ < i__1 && i__ < 256; ++i__) {
    integer idx = indices[i__];
    d__1 = sigmx;
    d__2 = d__[idx];
    sigmx = (d__1 >= d__2 ? d__1 : d__2);
}
}
