#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int len;
extern int frames;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (frames = 0; frames < len; frames++) {
        step = (buf[frames] & 1) ? 1 : 2;
        if (!(buf[frames] & 128)) break;
        frames += step - 1;
    }
}
