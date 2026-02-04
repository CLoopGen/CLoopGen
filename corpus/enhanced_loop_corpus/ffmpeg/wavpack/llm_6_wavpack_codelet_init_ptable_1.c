#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_value = value;
    for (int c = (rate + 128) >> 8; c--;)
        temp_value += (65536 - temp_value) >> 8;
    value = temp_value;
}
