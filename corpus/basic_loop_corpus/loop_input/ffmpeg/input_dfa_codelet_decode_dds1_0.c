#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *frame;
int width;
int i;
int offset;
int count;

static uint8_t frame_buffer[134217728]; // 128 MB buffer

void init_vars() {
    width = 1920;
    offset = 1922;
    count = 65536;
    
    frame = frame_buffer;
    
    for (int j = 0; j < 256; j++) {
        frame_buffer[j] = (uint8_t)(j * j + 31);
    }
    
    memset(frame_buffer + 256, 0xAA, sizeof(frame_buffer) - 256);
}