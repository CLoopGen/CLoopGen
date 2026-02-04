#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i = 32;
    int64_t temp_layout = layout;
    int temp_channel = channel_id;
    for (; local_i > 0; local_i >>= 1) {
        int shift = local_i;
        int64_t mask = ((int64_t)1 << shift);
        if (temp_layout >= mask) {
            temp_channel += shift;
            temp_layout >>= shift;
        }
    }
    channel_id = temp_channel;
    layout = temp_layout;
}
