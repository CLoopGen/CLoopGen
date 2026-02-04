#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int val;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_val = (uint16_t)val;
    for (n = 0; n < len; n++) {
        dst[n] = temp_val;
    }
}
