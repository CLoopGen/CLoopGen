#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int numcomps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 2
    int *data = (int*)malloc(numcomps * 2 * sizeof(int));  // Allocate extra space for striding
    for (i = 0; i < numcomps; i++) {
        data[i * 2] = i;  // Access every second element
    }
    free(data);
}
