#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t rv34_mb_max_sizes[6];
extern int mb_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_index = 0;
    for (i = 0; i < 5; i++) {
        temp_index = i;  // Introduce temporary variable with WAW dependency on itself across iterations
        if (rv34_mb_max_sizes[temp_index] >= mb_size - 1)
            break;
    }
    i = temp_index;  // Update original loop index only at end (converts loop-carried dependency into final assignment)
}
