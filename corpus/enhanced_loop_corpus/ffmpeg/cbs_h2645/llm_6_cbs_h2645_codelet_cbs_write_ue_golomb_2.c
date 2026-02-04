#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t value;
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_value;
    for (i = 0; i < len; i++) {
        temp_value = value + i;
        bits[len + i + 1] = (temp_value >> (len - i - 1)) & 1 ? '1' : '0';
    }
}
