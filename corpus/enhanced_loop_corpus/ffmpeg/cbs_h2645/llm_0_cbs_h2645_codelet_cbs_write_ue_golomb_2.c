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
    for (int j = 0; j < len; j++)
        for (i = 0; i <= j; i++)
            bits[len + i + 1] = (value + 1) >> (len - i - 1) & 1 ? '1' : '0';
}
