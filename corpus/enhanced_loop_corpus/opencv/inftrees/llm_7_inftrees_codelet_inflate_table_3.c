#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int min;
extern unsigned int max;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i;
    unsigned short local_count = 0;
    for (i = 1; i < max; i++) {
        local_count = count[i]; // Introduce RAW dependency: read after write to local_count
        if (local_count != 0) {
            min = i; // Introduce loop-carried dependence: 'min' updated based on loop index
            break;
        }
        count[i] = 0; // Add artificial WAW dependency on count[i] (write after potential prior write)
    }
}
