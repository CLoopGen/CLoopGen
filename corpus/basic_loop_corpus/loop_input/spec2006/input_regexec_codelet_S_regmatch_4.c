#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char U8;

char *e;
int m;
const unsigned char PL_utf8skip[256] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x00-0x0F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x10-0x1F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x20-0x2F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x30-0x3F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x40-0x4F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x50-0x5F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x60-0x6F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x70-0x7F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x80-0x8F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0x90-0x9F
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0xA0-0xAF
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  // 0xB0-0xBF
    1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  // 0xC0-0xCF
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,  // 0xD0-0xDF
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,  // 0xE0-0xEF
    4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1   // 0xF0-0xFF
};

char *PL_regeol;
char *locinput;

static char *buffer;
static size_t data_size = 64 * 1024 * 1024;  // 64 MB to target ~0.01 sec runtime

void init_vars() {
    buffer = (char*)malloc(data_size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with mixed UTF-8 like byte patterns to exercise utf8skip
    for (size_t i = 0; i < data_size; ) {
        int r = rand() % 100;
        if (r < 70) {
            // Single-byte ASCII (70%)
            buffer[i] = (rand() % 95) + 32;
            i++;
        } else if (r < 85 && i + 1 < data_size) {
            // Two-byte UTF-8 (15%)
            buffer[i] = 0xC0 | ((rand() % 32) >> 6);
            buffer[i+1] = 0x80 | (rand() % 64);
            i += 2;
        } else if (r < 95 && i + 2 < data_size) {
            // Three-byte UTF-8 (10%)
            buffer[i] = 0xE0 | ((rand() % 16) >> 4);
            buffer[i+1] = 0x80 | ((rand() % 64) >> 2);
            buffer[i+2] = 0x80 | (rand() % 64);
            i += 3;
        } else if (i + 3 < data_size) {
            // Four-byte UTF-8 (5%)
            buffer[i] = 0xF0 | ((rand() % 8) >> 2);
            buffer[i+1] = 0x80 | ((rand() % 64) >> 2);
            buffer[i+2] = 0x80 | ((rand() % 64) >> 2);
            buffer[i+3] = 0x80 | (rand() % 64);
            i += 4;
        } else {
            // Fallback to ASCII
            buffer[i] = (rand() % 95) + 32;
            i++;
        }
    }

    locinput = buffer;
    PL_regeol = buffer + data_size - 4;  // Leave room to avoid boundary issues
    e = locinput;
    m = 1000000;  // Set high enough to traverse significant portion
}