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
    for (i = len - 1; i >= 0; i--)
        bits[i] = (uvalue >> i) & 1 ? '1' : '0';
    for (i = 0; i < len; i++)
        bits[len + i] = ((uvalue + 1) >> i) & 1 ? '1' : '0';
}
