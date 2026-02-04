#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t count;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* count_array = (uint64_t*)aligned_alloc(32, 4 * sizeof(uint64_t));
    for (i = 0; i < 1000000000 / 4UL; i++) {
        for (j = 0; j < 4; j++) {
            count_array[j]++; // Consecutive memory access across iterations
        }
    }
    count = count_array[0] + count_array[1] + count_array[2] + count_array[3];
    free(count_array);
}
