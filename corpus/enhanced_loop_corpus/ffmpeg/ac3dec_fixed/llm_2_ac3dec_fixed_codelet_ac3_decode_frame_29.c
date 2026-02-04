#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ch;
extern uint8_t extended_channel_map[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (int ch = 0; ch < 16; ch += 2)
        extended_channel_map[ch] = ch;
    for (int ch = 1; ch < 16; ch += 2)
        extended_channel_map[ch] = ch;
}
