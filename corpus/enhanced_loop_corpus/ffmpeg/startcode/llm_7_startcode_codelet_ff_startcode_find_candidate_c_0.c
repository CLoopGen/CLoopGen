#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_buf;
    for (; i < size; i++) {
        local_buf = buf[i]; // Introduce temporary to remove direct RAW hazard in conditional
        if (!local_buf)
            break;
        buf[i] = local_buf; // Reassign same value: introduces WAR/WAW but preserves semantics
    }
}
