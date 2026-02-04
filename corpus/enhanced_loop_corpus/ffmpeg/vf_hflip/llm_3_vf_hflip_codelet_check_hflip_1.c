#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int step;
extern int i;
extern int step_array[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a fixed index map (reverse order access via indices)
    int index_map[4] = {3, 2, 1, 0};
    for (i = 0; i < 4; i++) {
        step_array[index_map[i]] = step;
    }
}
