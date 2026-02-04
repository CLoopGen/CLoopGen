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
    // Introduce loop-carried dependency by reusing previous iteration's maxError as initial threshold
    size_t localMaxError = maxError;
    for (c = 0; c < 3; c++) {
        sources[c] = &lookup[c][color[c]].sources[i];
        error += ((size_t)sources[c]->error) * ((size_t)sources[c]->error);
    }
    // Modify control flow: only update if strictly less than current maxError (introduces WAW on maxError)
    if (error >= localMaxError)
        continue;
    // Update outputs only when new best found, creating write-after-write dependency with prior valid write
    float start_x = (float)sources[0]->start / 31.F;
    float start_y = (float)sources[1]->start / 63.F;
    float start_z = (float)sources[2]->start / 31.F;
    float end_x = (float)sources[0]->end / 31.F;
    float end_y = (float)sources[1]->end / 63.F;
    float end_z = (float)sources[2]->end / 31.F;
    // Batch updates to reduce partial updates (eliminates intermediate state visibility)
    start->x = start_x;
    start->y = start_y;
    start->z = start_z;
    end->x = end_x;
    end->y = end_y;
    end->z = end_z;
    *index = (unsigned char)(2 * i);
    maxError = error; // WAW dependency: only written when improvement occurs
}
}
