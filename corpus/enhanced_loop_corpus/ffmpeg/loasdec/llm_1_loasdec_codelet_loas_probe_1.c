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
    uint32_t header;
    uint8_t* temp_buf;
    for (; buf2 < end; buf2 = temp_buf) {
        header = ((((const uint8_t *)(buf2))[0] << 16) | (((const uint8_t *)(buf2))[1] << 8) | ((const uint8_t *)(buf2))[2]);
        if ((header >> 13) != 695)
            break;
        fsize = (header & 8191) + 3;
        if (fsize < 7)
            break;
        fsize = ((fsize) > (end - buf2) ? (end - buf2) : (fsize));
        temp_buf = buf2 + fsize;
        frames++;
        for (int inner = 0; inner < 1; inner++) {
            if (temp_buf >= end || ((((const uint8_t *)(temp_buf))[0] << 16) | (((const uint8_t *)(temp_buf))[1] << 8) | ((const uint8_t *)(temp_buf))[2]) >> 13 != 695) {
                break;
            }
        }
        buf2 = temp_buf;
    }
    max_frames = ((max_frames) > (frames) ? (max_frames) : (frames));
    if (buf == buf0)
        first_frames = frames;
}
}
