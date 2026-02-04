#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_ff_count = 0;
    for (; i < size; i++) {
        temp_ff_count += (buf[i] == 255);
    }
    ff_count += temp_ff_count;
}
