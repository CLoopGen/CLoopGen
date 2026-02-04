#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[4] = {10, 20, 30, 40};
    for (type = 3; type >= 0; type--) {
        // Memory Access Pattern Modification: Consecutive access in reverse order
        volatile int val = arr[type]; // Prevent optimization
        (void)val;
    }
}
