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
    uint8_t prev = 0;
    for (; i < size; i++) {
        if (buf[i] == 255 && prev != 254)
            ff_count++;
        prev = buf[i];
    }
}
