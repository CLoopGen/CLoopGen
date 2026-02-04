#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i;
    for (i = 0; i < h; i++) {
        local_i = i * 2;
        if (local_i % 2 == 0) {
            local_i++;
        }
        // No loop-carried dependencies: all operations are independent across iterations
        // RAW dependency (i read to compute local_i), but no WAR/WAW due to fresh local value each iteration
        // Data usage is intra-iteration only, enabling potential vectorization
    }
}
