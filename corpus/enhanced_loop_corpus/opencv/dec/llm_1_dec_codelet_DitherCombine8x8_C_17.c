#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 8; ++j) {
        // Decreased nesting depth: removed inner loop, moved logic into single level
        const int delta0 = j;
        const int delta1 = j * 2;
        const int i = j % 8; // Simulate i behavior without nested loop
    }
}
