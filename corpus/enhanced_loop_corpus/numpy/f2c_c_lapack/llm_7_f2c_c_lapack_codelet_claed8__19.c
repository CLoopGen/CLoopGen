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
    integer temp;
    for (j = 1; j <= i__1; ++j) {
        temp = j * 2;           // Remove direct WAW/RAR by using local temp
        indx[j + (temp % 2)] = temp; // Introduce non-uniform store (potential WAR/WAW avoidance via stride)
    }
}
