#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int vop_found;
extern int i;
extern int j;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Double-byte Prefetch with Unrolled Check
    for (i = 0; i < buf_size - 1 && !vop_found; i++) {
        // Process two consecutive bytes at once for improved spatial locality
        state = (state << 16) | (buf[i + 1] << 8) | buf[i];
        // Increase check range due to larger shift
        for (j = 0; j < 24; j++) {
            if (((state >> j) & 16777200) == 256) {
                vop_found = 1;
                break;
            }
        }
    }
    // Handle last byte if needed
    if (!vop_found && i < buf_size) {
        state = (state << 8) | buf[i];
        for (j = 0; j < 8; j++) {
            if (((state >> j) & 16777200) == 256) {
                vop_found = 1;
                break;
            }
        }
    }
}
