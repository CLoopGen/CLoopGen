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
    for (i = 0; i < len * 2; i += 2)
        bits[i] = ((uvalue + 2) >> (len - (i / 2) - 1)) & 1 ? '1' : '0';
}
