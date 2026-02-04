#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern int dc3;
extern int dc4;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_dc0 = 0, temp_dc1 = 0, temp_dc2 = 0, temp_dc3 = 0, temp_dc4 = 0;
    for (i = 0; i < 4; i++) {
        temp_dc0 += src[-1 + i * stride] + src[i - stride];
        temp_dc1 += src[4 + i - stride];
        temp_dc2 += src[-1 + (i + 4) * stride];
        temp_dc3 += src[-1 + (i + 8) * stride];
        temp_dc4 += src[-1 + (i + 12) * stride];
    }
    dc0 += temp_dc0;
    dc1 += temp_dc1;
    dc2 += temp_dc2;
    dc3 += temp_dc3;
    dc4 += temp_dc4;
}
