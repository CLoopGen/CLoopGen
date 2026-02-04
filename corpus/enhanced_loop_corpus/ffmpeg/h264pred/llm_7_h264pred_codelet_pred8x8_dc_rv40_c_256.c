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
    uint32_t local_dc0 = 0; // Remove dependence on initial dc0 value (eliminate RAW)
    for (i = 0; i < 4; i++) {
        uint8_t a = src[-1 + i * stride];
        uint8_t b = src[i - stride];
        uint8_t c = src[4 + i - stride];
        uint8_t d = src[-1 + (i + 4) * stride];
        local_dc0 += a + b + c + d; // Accumulate locally, no use of external dc0
    }
    dc0 = local_dc0; // Single write to dc0 after loop: breaks RAW and WAW dependencies
}
