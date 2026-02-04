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
    for (; i < size && buf[i] != 0; i++) {
        if (buf[i] == 255) {
            ff_count++;
        } else if (buf[i] == 0xAA) {
            continue;
        }
    }
}
