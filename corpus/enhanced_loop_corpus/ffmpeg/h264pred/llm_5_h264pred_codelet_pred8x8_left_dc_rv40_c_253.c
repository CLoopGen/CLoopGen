#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        uint32_t* row = (uint32_t*)(src + i * stride);
        if (i >= 4) {
            row[0] = dc0;
        } else {
            row[1] = dc0;
        }
        row[0] = row[1] = dc0; // redundant write after condition, preserves original effect
    }
}
