#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern  DDSSingleColorLookup *lookup[];
extern  unsigned char *color;
extern DDSVector3 *start;
extern DDSVector3 *end;
extern unsigned char *_usr_index;
extern ssize_t i;
extern size_t c;
extern size_t maxError;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (i = 0; i < 2; i++) {
    const DDSSourceBlock *sources[3];
    size_t error = 0;
    // Modified memory access: use indirect indexing via a fixed offset array to create non-consecutive, indirect access pattern
    const size_t indices[3] = {0, 2, 1}; // Reordered access: 0, 2, 1 instead of 0, 1, 2
    for (c = 0; c < 3; c++) {
        size_t idx = indices[c];
        sources[idx] = &lookup[idx][color[idx]].sources[i];
        error += ((size_t)sources[idx]->error) * ((size_t)sources[idx]->error);
    }
    if (error > maxError)
        continue;
    start->x = (float)sources[0]->start / 31.F;
    start->y = (float)sources[1]->start / 63.F;
    start->z = (float)sources[2]->start / 31.F;
    end->x = (float)sources[0]->end / 31.F;
    end->y = (float)sources[1]->end / 63.F;
    end->z = (float)sources[2]->end / 31.F;
    *index = (unsigned char)(2 * i);
    maxError = error;
}
}
