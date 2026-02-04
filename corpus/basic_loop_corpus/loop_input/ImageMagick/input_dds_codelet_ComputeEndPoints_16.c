#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct _DDSSourceBlock {
    unsigned char start;
    unsigned char end;
    unsigned char error;
} DDSSourceBlock;

typedef struct _DDSSingleColorLookup {
    DDSSourceBlock sources[2];
} DDSSingleColorLookup;

typedef struct _DDSVector3 {
    float x;
    float y;
    float z;
} DDSVector3;

DDSSingleColorLookup *lookup[3];
unsigned char *color;
DDSVector3 *start;
DDSVector3 *end;
unsigned char *_usr_index;
ssize_t i;
size_t c;
size_t maxError;

#define index _usr_index

void init_vars() {
    const size_t color_size = 256 * (1 << 10); // 256KB of color data
    color = (unsigned char*)calloc(color_size, sizeof(unsigned char));
    if (!color) exit(1);

    for (size_t idx = 0; idx < color_size; ++idx) {
        color[idx] = idx % 256;
    }

    for (c = 0; c < 3; ++c) {
        lookup[c] = (DDSSingleColorLookup*)calloc(color_size, sizeof(DDSSingleColorLookup));
        if (!lookup[c]) exit(1);
        for (size_t idx = 0; idx < color_size; ++idx) {
            lookup[c][idx].sources[0].start = (unsigned char)(idx % 32);
            lookup[c][idx].sources[0].end = (unsigned char)((idx + 16) % 32);
            lookup[c][idx].sources[0].error = (unsigned char)(abs((int)(idx % 16) - 8));
            lookup[c][idx].sources[1].start = (unsigned char)((idx + 8) % 32);
            lookup[c][idx].sources[1].end = (unsigned char)((idx + 24) % 32);
            lookup[c][idx].sources[1].error = (unsigned char)(abs((int)(idx % 16) - 4));
        }
    }

    start = (DDSVector3*)calloc(1, sizeof(DDSVector3));
    end = (DDSVector3*)calloc(1, sizeof(DDSVector3));
    if (!start || !end) exit(1);

    index = (unsigned char*)calloc(1, sizeof(unsigned char));
    if (!index) exit(1);

    i = 0;
    c = 0;
    maxError = SIZE_MAX;
}