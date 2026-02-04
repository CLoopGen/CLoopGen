#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (type = 0; type < 4; type++) {
        temp += type;
    }
    // Introduces a loop-carried dependency (RAW): each iteration depends on the previous value of 'temp'
    // Also introduces a WAW dependency on 'temp' across iterations
}
