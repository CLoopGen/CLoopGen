#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int len;
extern int frames;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int keep_going = 1;
    for (frames = 1; keep_going && frames < len; frames++) {
        keep_going = (buf[frames] & 128);
    }
    if (frames > len) frames = len;
}
