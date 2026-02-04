#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  char *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_low, temp_high;
    for (i = 0; s[i]; i++) {
        temp_low = (s[i] & 0x0F);
        temp_high = (s[i] >> 4);
        dst[0] = 0;
        dst[1] = temp_low;
        dst[2] = temp_high;
        dst += 3;
    }
}
