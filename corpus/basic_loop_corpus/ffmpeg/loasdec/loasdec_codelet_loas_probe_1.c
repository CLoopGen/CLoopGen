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
    for (frames = 0; buf2 < end; frames++) {
        uint32_t header = ((((const uint8_t *)(buf2))[0] << 16) | (((const uint8_t *)(buf2))[1] << 8) | ((const uint8_t *)(buf2))[2]);
        if ((header >> 13) != 695)
            break;
        fsize = (header & 8191) + 3;
        if (fsize < 7)
            break;
        fsize = ((fsize) > (end - buf2) ? (end - buf2) : (fsize));
        buf2 += fsize;
    }
    max_frames = ((max_frames) > (frames) ? (max_frames) : (frames));
    if (buf == buf0)
        first_frames = frames;
}

}
