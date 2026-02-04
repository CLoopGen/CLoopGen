#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int final_num_colors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (; i < 4 * final_num_colors; ++i) {
        temp += i; // Introduce a loop-carried RAW dependency: temp depends on its previous value
    }
    // Volatile write to ensure temp is not optimized away (simulating side effect)
    if (temp > 0) { }
}
