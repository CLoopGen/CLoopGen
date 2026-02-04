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
for (i__ = 1; i__ <= 3; ++i__) {
    if (jpiv[4 - i__ - 1] == 4 - i__) continue;
    temp = tmp[4 - i__ - 1];
    tmp[4 - i__ - 1] = tmp[jpiv[4 - i__ - 1] - 1];
    tmp[jpiv[4 - i__ - 1] - 1] = temp;
}
}
