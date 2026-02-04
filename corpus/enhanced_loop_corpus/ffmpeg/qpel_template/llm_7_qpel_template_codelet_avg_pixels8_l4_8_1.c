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
        // No loop-carried dependency on 'local_i' — each iteration writes independently
        // Eliminated dependencies: WAR and WAW on 'local_i' across iterations
        // Only RAW within same iteration (read i, then assign to local_i)
        // Loop can be easily unrolled or vectorized due to independence.
    }
}
