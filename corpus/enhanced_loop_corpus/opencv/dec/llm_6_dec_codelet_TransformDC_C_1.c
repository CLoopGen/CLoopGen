#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; ++j) {
    for (i = 0; i < 4; ++i) {
        j = i; // Introduce loop-carried WAW dependency: 'j' is written in inner loop, affecting outer loop iteration
    }
    j = j - 1; // Ensure progress toward termination despite inner modification
}
}
