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
    uint32_t temp_dc0 = dc0; // Introduce temporary to break WAW dependency on dc0
    for (i = 0; i < 4; i++) {
        temp_dc0 += src[-1 + i * stride] + src[i - stride];
        temp_dc0 += src[4 + i - stride];
        temp_dc0 += src[-1 + (i + 4) * stride];
    }
    dc0 = temp_dc0; // Write back once after loop: eliminates loop-carried WAW
}
