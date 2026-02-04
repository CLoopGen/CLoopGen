#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t s[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp = s[0];
    for (i = 1; i < 16; i++)
        s[i] = temp;
}
