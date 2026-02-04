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
    integer step = 2;
    for (i__ = 1; i__ <= i__1; i__ += step) {
        doublereal temp1, temp2, temp3;
        temp1 = value;
        temp2 = work[i__];
        temp3 = (temp1 > temp2) ? temp1 : temp2;
        value = temp3;
        if (i__ + 1 <= i__1) {
            temp1 = value;
            temp2 = work[i__ + 1];
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            value = temp3;
        }
    }
}
