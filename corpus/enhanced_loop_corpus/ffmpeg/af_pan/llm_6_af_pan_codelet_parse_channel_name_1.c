#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_channel = channel_id;
    int64_t temp_layout = layout;
    for (i = 32; i > 0; i >>= 1) {
        if (temp_layout >= ((int64_t)1 << i)) {
            temp_channel += i;
            temp_layout >>= i;
        }
    }
    channel_id = temp_channel;
}
