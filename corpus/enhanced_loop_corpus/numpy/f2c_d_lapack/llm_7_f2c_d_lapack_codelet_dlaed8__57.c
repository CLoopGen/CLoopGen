#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *indx;
extern integer i__1;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    integer temp = 0;
    for (j = 1; j <= i__1; ++j) {
        temp = j;           // Remove loop-carried dependency: use local temp
        indx[j] = temp;     // WAW and WAR hazards eliminated by using temporary
    }
}
