#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern doublereal tmp[4];
extern doublereal temp;
extern integer jpiv[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= 2; ++i__) {
    integer offset = 4 - i__ - 1;
    if (jpiv[offset] != 4 - i__) {
        temp = tmp[offset];
        tmp[offset] = tmp[jpiv[offset] - 1];
        tmp[jpiv[offset] - 1] = temp;
        
        temp = tmp[2 - i__];
        tmp[2 - i__] = tmp[i__];
        tmp[i__] = temp;
    }
}
}
