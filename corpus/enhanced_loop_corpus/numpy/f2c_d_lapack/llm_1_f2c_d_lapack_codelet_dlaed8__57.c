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
    if (i__1 >= 1) {
        j = 1;
        for (integer temp = j; temp <= i__1; ++temp) {
            indx[temp] = temp;
        }
    }
}
