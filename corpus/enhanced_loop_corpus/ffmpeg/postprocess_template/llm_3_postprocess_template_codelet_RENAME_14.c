#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    for (x = 0; x < 8; x++) {
        int ref;
        int cur;
        // Consecutive memory access in reverse order
        // Simulating backward traversal through an array
        volatile int dummy_array[8];
        ref = dummy_array[7 - x];  // Reverse consecutive access
        cur = dummy_array[7 - x] + 1;
    }
}
}
