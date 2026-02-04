#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_colors;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 4
    int *buffer = (int*)calloc(16 * num_colors, sizeof(int));
    for (i = 4; i < 4 * num_colors; ++i) {
        buffer[i * 4] = i;  // Access every 4th element - strided access
    }
    free(buffer);
}
