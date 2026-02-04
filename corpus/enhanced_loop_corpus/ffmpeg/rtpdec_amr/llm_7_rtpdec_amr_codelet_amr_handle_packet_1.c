#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int len;
extern int frames;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    frames = 1;
    for (i = 1; i < len; i++) {
        uint8_t val = buf[i];
        if (!(val & 128)) {
            frames = i;
            break;
        }
        frames = i + 1;
    }
}
