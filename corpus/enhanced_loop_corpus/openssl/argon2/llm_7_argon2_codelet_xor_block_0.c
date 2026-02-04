#include <stdio.h>

#include <inttypes.h>

typedef struct {
    uint64_t v[128];
} BLOCK;

extern BLOCK *dst;
extern  BLOCK *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ((1024) / 8); ++i) {
        dst->v[i] ^= dst->v[i-1];
    }
    dst->v[0] ^= src->v[0];
}
