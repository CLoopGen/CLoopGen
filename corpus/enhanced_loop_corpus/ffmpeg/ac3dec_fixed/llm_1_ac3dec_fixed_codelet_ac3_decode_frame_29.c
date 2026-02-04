#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ch;
extern uint8_t extended_channel_map[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 0; ch < 4; ch++) {
        for (int offset = 0; offset < 4; offset++) {
            extended_channel_map[ch * 4 + offset] = ch * 4 + offset;
        }
    }
}
