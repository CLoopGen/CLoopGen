#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern uint32_t uvalue;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp = uvalue + 1;
    for (i = 0; i < len; i++) {
        bits[len + i + 1] = (temp >> (len - i - 1)) & 1 ? '1' : '0';
    }
}
