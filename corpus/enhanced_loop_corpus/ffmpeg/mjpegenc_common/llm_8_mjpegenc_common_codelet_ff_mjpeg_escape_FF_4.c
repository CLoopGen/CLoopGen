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
    int step = 2;
    for (; i < size; i += step) {
        if (buf[i] == 255)
            ff_count++;
        if (i + 1 < size && buf[i + 1] == 255)
            ff_count++;
    }
}
