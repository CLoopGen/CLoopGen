#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {15, 25, 35, 45, 55, 65, 75, 85};
    int indices[4] = {0, 2, 4, 6};
    for (type = 0; type < 4; type++) {
        // Indirect memory access: using an index array to access non-consecutive elements
        int val = arr[indices[type]];
        // Simulate use of val
        if (val > 0) __asm__ volatile("" : "+r" (val));
    }
}
