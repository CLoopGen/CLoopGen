#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short d[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependencies by reordering and introducing temporary
    unsigned short temp_val = 0;
    for (i = 0; i < 10; ++i) {
        d[2 * i + 1] = temp_val; // Break WAW and WAR by using local temp
        d[2 * i] = temp_val;     // Both writes now depend only on loop-independent temp
    }
    // No data carried between iterations; all writes are to independent locations with same value
}
