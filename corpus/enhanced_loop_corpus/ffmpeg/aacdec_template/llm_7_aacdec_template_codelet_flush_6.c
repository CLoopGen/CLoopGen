#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int data[4];
    for (type = 3; type >= 0; type--) {
        data[type] = type * 2; // Write to array (WAW on array element)
        if (type < 3) {
            data[type] += data[type + 1]; // RAW dependency: use of data[type+1] before writing data[type]
        }
    }
    // Eliminate loop-carried dependency by ensuring each iteration writes to distinct memory location
}
