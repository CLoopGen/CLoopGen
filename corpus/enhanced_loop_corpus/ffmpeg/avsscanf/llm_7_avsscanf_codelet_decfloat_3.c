#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t x[128];
extern int i;
extern int a;
extern int z;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_y = 0;
    int local_z = z;
    for (i = 0; i < 2; i++) {
        int idx = a + i & (128 - 1);
        if (idx == local_z) {
            local_z = (local_z + 1 & (128 - 1)); // Remove WAR on z by using local copy
            x[local_z - 1] = 1; // Eliminate WAW on shared x by decoupling update timing
        }
        uint32_t val = x[idx];
        local_y = 1.0E+9L * local_y + val;
    }
    y = local_y; // Break loop-carried dependency on global y
    z = local_z; // Commit updated z only once after loop
}
