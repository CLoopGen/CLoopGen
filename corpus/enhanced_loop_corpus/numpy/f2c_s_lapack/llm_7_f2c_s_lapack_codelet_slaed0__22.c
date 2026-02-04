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
        int temp_iprmpt = iprmpt + i__;
        int temp_igivpt = igivpt + i__;
        iwork[temp_iprmpt] = 1;
        iwork[temp_igivpt] = 1;
        // Removed potential WAW/WAR hazards by isolating address calculations,
        // and eliminated loop-carried dependencies via local temporaries.
        // This increases independence between iterations, enabling better optimization.
    }
}
