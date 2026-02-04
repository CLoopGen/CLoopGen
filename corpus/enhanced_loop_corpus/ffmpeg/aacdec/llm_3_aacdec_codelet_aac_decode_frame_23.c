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
    // Variant 2: Consecutive reverse traversal from buf_size-1 down to buf_consumed
    for (buf_offset = buf_size - 1; buf_offset >= buf_consumed; buf_offset--) {
        if (buf[buf_offset])
            break;
    }
    // Ensure buf_offset points to the first (lowest index) non-zero in original order
    // If reverse scan found a later non-zero, we must re-scan forward from buf_consumed
    if (buf_offset >= buf_consumed && buf[buf_offset]) {
        int temp = buf_consumed;
        while (temp < buf_offset && !buf[temp]) temp++;
        buf_offset = temp;
    }
}
