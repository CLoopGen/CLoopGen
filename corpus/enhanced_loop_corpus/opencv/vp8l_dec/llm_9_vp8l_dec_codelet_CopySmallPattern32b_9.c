#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count and simplified arithmetic to lower computational load
    for (i = 0; i < (length >> 2); ++i) {
        // Perform minimal operation: single arithmetic expression
        volatile int result = (i + i) & 0xFFFF;
    }
}
