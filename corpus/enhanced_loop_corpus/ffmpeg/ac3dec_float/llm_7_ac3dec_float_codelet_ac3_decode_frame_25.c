#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ch;
extern uint8_t extended_channel_map[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extended_channel_map[0] = 0;
    for (ch = 1; ch < 16; ch++) {
        extended_channel_map[ch] = extended_channel_map[ch-1] + 1;
    }
}
