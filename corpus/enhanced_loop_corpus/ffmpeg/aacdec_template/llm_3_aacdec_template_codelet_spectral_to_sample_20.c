#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int type;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {5, 15, 25, 35, 45, 55, 65, 75};
    int indices[] = {6, 4, 2, 0}; // Indirect access pattern via index array
    for (type = 3; type >= 0; type--) {
        // Memory Access Pattern Modification: Indirect access using an index array
        volatile int val = arr[indices[type]]; // Prevent optimization
        (void)val;
    }
}
