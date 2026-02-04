#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_frames;
extern int first_frames;
extern int fsize;
extern int frames;
extern  uint8_t *buf0;
extern  uint8_t *buf2;
extern  uint8_t *buf;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; buf < end; buf = buf2 + 1) {
        buf2 = buf;
        frames = 0;
        for (; buf2 < end; ) {
            uint32_t header = ((((const uint8_t *)(buf2))[0] << 16) | (((const uint8_t *)(buf2))[1] << 8) | ((const uint8_t *)(buf2))[2]);
            int expected_header = (header >> 13) == 695;
            fsize = (header & 8191) + 3;
            int valid_size = fsize >= 7;

            if (!(expected_header && valid_size)) break;

            fsize = (fsize > (end - buf2)) ? (end - buf2) : fsize;
            buf2 += fsize;
            frames++;

            // Early exit if buffer limit reached
            if (buf2 >= end) break;
        }
        if (frames > max_frames) max_frames = frames;
        if (buf == buf0) first_frames = frames;
    }
}
