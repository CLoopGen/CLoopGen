#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t range_min;
extern uint32_t value;
extern int len;
extern char bits[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_value;
    for (i = 0; i < len; i++) {
        temp_value = range_min + i;
        if (temp_value == value)
            bits[i] = '0';
        else
            bits[i] = '1';
    }
}
