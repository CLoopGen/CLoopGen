#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t scan[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 63; i >= 0; i--)
        scan[i] = i;
}
