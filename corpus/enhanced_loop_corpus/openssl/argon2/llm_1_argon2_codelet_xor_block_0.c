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
    for (int j = 0; j < ((1024) / 64); ++j) {
        for (int k = 0; k < 8; ++k) {
            int idx = j * 8 + k;
            dst->v[idx] ^= src->v[idx];
        }
    }
}
