#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int current_pos;
extern int startcode_found;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-direction scan – first forward even indices, then odd
    // Simulates a reordered access pattern by splitting the loop into two phases
    int step = 2;
    for (i = current_pos + ((current_pos % 2) ? 1 : 0); i < buf_size - 4; i += step)
        if (buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1 && buf[i + 3] == 182) {
            startcode_found = !(buf[i + 4] & 64);
            break;
        }
    // If not found in first phase and no early break, continue with alternate offset
    if (!startcode_found && current_pos % 2 == 0) {
        for (i = current_pos + 1; i < buf_size - 4; i += step)
            if (buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1 && buf[i + 3] == 182) {
                startcode_found = !(buf[i + 4] & 64);
                break;
            }
    }
}
