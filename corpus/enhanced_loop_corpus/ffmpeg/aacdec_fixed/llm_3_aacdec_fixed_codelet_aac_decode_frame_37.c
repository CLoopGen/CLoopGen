#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int buf_consumed;
extern int buf_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access in reverse order
    for (buf_offset = buf_size - 1; buf_offset >= buf_consumed; buf_offset--) {
        if (buf[buf_offset])
            continue;  // Keep going until we find a non-zero or exit
        else
            break;     // Break when zero is found (logical reversal)
    }
    // Adjust so buf_offset points to first non-zero in original forward sense
    if (buf_offset < buf_size - 1)
        buf_offset++;
    else if (buf_offset == buf_size - 1 && buf[buf_offset] == 0)
        buf_offset++;
    else if (buf_offset < buf_consumed)
        buf_offset = buf_consumed;
}
