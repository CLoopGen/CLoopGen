#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[8] = {0};
for (j = 0; j < 8; ++j) {
    for (i = 0; i < 8; ++i) {
        const int delta0 = temp[i] + j;
        const int delta1 = delta0 * 2;
        temp[i] = delta1;
        // Introduce loop-carried dependence on temp[i]: each iteration in j-loop depends on previous j
        // RAW hazard: temp[i] read before write in next j iteration
        // WAW hazard: temp[i] written in each j iteration — dependence across outer loop
        // Dependencies are now carried between iterations of the outer loop
    }
}
}
