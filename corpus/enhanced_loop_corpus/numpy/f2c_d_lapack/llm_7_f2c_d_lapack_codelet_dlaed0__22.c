#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *iwork;
extern integer i__1;
extern integer i__;
extern integer igivpt;
extern integer iprmpt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = 0; i__ <= i__1; ++i__) {
        int temp_iprmpt = iwork[iprmpt + i__]; // Introduce temporary to break WAW and WAR hazards
        int temp_igivpt = iwork[igivpt + i__];
        iwork[iprmpt + i__] = temp_iprmpt + 1;   // Update based on prior value — creates loop-carried dependence
        iwork[igivpt + i__] = temp_igivpt + 1;
    }
}
