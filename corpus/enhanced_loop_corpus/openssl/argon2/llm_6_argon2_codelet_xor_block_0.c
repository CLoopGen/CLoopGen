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
    uint64_t temp;
    for (i = 0; i < ((1024) / 8); ++i) {
        temp = src->v[i];
        dst->v[i] ^= temp;
    }
}
