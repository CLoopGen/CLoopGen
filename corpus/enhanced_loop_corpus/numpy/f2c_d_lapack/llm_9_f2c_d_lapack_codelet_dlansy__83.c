#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *work;
extern integer i__1;
extern doublereal d__1;
extern doublereal d__2;
extern integer i__;
extern doublereal value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
doublereal temp_value = value;
for (i__ = 1; i__ <= i__1; i__ += 2) {
    doublereal val1 = work[i__];
    doublereal val2 = (i__ + 1 <= i__1) ? work[i__ + 1] : val1;
    temp_value = (val1 > temp_value) ? val1 : temp_value;
    temp_value = (val2 > temp_value) ? val2 : temp_value;
}
value = temp_value;
}
