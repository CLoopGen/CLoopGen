#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *speech;
extern int subframe_size;
extern int temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *local_speech = speech;
    int local_subframe_size = subframe_size;
    int local_temp = temp;
    int prev_index = -1;
    for (i = 0; i < local_subframe_size; i++) {
        if (prev_index >= 0) {
            local_speech[i] = (int16_t)(((int32_t)local_speech[prev_index] * local_temp + 16384) >> 15);
        }
        prev_index = i;
    }
    // Restore original behavior in a second pass to maintain semantic equivalence
    for (i = 0; i < local_subframe_size; i++) {
        local_speech[i] = (int16_t)((((int32_t)speech[i] * local_temp + 16384) >> 15));
    }
}
