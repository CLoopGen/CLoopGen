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
    for (c = 0; c < 3; c++) {
        sources[c] = &lookup[c][color[c]].sources[i];
        error += ((size_t)sources[c]->error) * ((size_t)sources[c]->error);
    }
    if (error > maxError)
        continue;
    float inv_31 = 1.0F / 31.F;
    float inv_63 = 1.0F / 63.F;
    start->x = (float)sources[0]->start * inv_31;
    start->y = (float)sources[1]->start * inv_63;
    start->z = (float)sources[2]->start * inv_31;
    end->x = (float)sources[0]->end * inv_31;
    end->y = (float)sources[1]->end * inv_63;
    end->z = (float)sources[2]->end * inv_31;
    *index = (unsigned char)(2 * i);
    maxError = error;
}
}
