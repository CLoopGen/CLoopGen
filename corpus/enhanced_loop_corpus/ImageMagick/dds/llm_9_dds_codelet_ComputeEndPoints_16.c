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
for (i = 0; i < 4; i++) {
    size_t error = 0;
    const DDSSourceBlock *src_r = &lookup[0][color[0]].sources[i % 2];
    const DDSSourceBlock *src_g = &lookup[1][color[1]].sources[i % 2];
    const DDSSourceBlock *src_b = &lookup[2][color[2]].sources[i % 2];
    
    error += ((size_t)src_r->error) * ((size_t)src_r->error);
    error += ((size_t)src_g->error) * ((size_t)src_g->error);
    error += ((size_t)src_b->error) * ((size_t)src_b->error);

    if (error <= maxError) {
        start->x = (float)src_r->start / 31.F;
        start->y = (float)src_g->start / 63.F;
        start->z = (float)src_b->start / 31.F;
        end->x = (float)src_r->end / 31.F;
        end->y = (float)src_g->end / 63.F;
        end->z = (float)src_b->end / 31.F;
        *index = (unsigned char)i;
        maxError = error;
    }
}
}
