#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int values[4];
    for (type = 0; type < 4; type++) {
        values[type] = type * 2;
    }
    // Eliminates loop-carried dependencies by writing to distinct array elements
    // No RAW, WAR, or WAW dependencies between iterations — fully parallelizable
}
