#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_j = 0;
for (i = 0; i < 6; i++) {
    for (j = prev_j + 1; j < 64; j++) { // Introduce loop-carried RAW dependency: j depends on prev_j from prior outer loop iteration
        prev_j = j;
    }
    if (prev_j >= 64) {
        prev_j = 0; // Reset to create a controlled dependency across outer iterations
    }
}

}
