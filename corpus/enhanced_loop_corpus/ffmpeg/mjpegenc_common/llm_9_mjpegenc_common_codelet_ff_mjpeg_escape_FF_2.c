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
    for (i = 0; i < size && i < align && ff_count < 100; i++) {
        uint8_t val = buf[i];
        uint8_t masked = val & 0xFF;
        if (masked == 255)
            ff_count += 1;
    }
}
