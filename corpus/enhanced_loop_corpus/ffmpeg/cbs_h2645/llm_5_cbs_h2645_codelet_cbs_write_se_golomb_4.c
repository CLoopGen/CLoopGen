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
    char one = '1', zero = '0';
    for (i = 0; i < len; i++) {
        uint32_t shift = len - i - 1;
        uint32_t bit = (uvalue + 1) >> shift & 1;
        bits[len + i + 1] = bit ? one : zero;
    }
}
