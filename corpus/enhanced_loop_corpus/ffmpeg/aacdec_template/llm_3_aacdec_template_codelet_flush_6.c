#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {5, 15, 25, 35, 45, 55, 65, 75};
    for (type = 3; type >= 0; type--) {
        // Memory Access Pattern Modification: Strided access (step of 2)
        volatile int val = arr[type * 2]; // Access elements at indices 6, 4, 2, 0
        (void)val;
    }
}
