#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;
extern int align;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_ff_count = 0;
    for (i = 0; i < size && i < align; i++) {
        local_ff_count += (buf[i] == 255);
    }
    ff_count += local_ff_count;
}
