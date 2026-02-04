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
    for (i = 0; i < local_subframe_size; i++) {
        int16_t val = local_speech[i];
        int32_t product = val * local_temp + 16384;
        local_speech[i] = (int16_t)(product >> 15);
    }
}
