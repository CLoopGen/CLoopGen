#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int len;
extern int frames;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_frames = 1;
    for (; temp_frames < len; temp_frames++) {
        if (!(buf[temp_frames] & 128)) {
            break;
        }
    }
    frames = temp_frames;
}
