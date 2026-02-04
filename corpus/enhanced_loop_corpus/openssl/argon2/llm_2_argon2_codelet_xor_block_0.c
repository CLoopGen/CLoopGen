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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < ((1024) / 8); i += 2) {
        dst->v[i] ^= src->v[i];
        if (i + 1 < ((1024) / 8)) {
            dst->v[i + 1] ^= src->v[i + 1];
        }
    }
}
