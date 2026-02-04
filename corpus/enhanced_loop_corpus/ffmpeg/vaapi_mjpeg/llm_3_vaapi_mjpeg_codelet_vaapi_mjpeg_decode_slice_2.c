#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int arr[8] = {5, 15, 25, 35, 45, 55, 65, 75};
    int indices[4] = {0, 2, 4, 6};
    for (i = 0; i < 4; i++) {
        // Indirect memory access: use an index array to access non-sequential elements
        int idx = indices[i];
        arr[idx] *= 2;
    }
}
