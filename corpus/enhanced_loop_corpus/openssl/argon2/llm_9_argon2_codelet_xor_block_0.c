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
    for (i = 0; i < ((1024) / 16); ++i) {
        dst->v[2*i] ^= src->v[2*i];
        dst->v[2*i + 1] ^= src->v[2*i + 1];
    }
}
