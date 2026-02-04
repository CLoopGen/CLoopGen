#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

typedef struct PutByteContext {
    uint8_t *buffer;
    uint8_t *buffer_end;
    uint8_t *buffer_start;
    int eof;
} PutByteContext;

typedef struct InterBlock {
    int w;
    int h;
    int size;
    int xor;
} InterBlock;

typedef struct FMVCContext {
    GetByteContext gb;
    PutByteContext pb;
    uint8_t *buffer;
    size_t buffer_size;
    uint8_t *pbuffer;
    size_t pbuffer_size;
    ptrdiff_t stride;
    int bpp;
    int yb;
    int xb;
    InterBlock *blocks;
    unsigned int nb_blocks;
} FMVCContext;

extern FMVCContext *s;
extern int y;
extern int x;
extern unsigned int block;
extern int k;
extern int l;
extern  uint32_t *src;
extern uint32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (block = 0 , y = 0; y < s->yb; y++) {
    int block_h = s->blocks[block].h;
    uint32_t *rect = dst;
    for (x = 0; x < s->xb; x++) {
        int block_w = s->blocks[block].w;
        uint32_t *row = dst;
        block_h = s->blocks[block].h;

        if (s->blocks[block].xor) {
            // Use strided access: process column-major within the block
            for (l = 0; l < block_w; l++) { // outer loop over width (columns)
                uint32_t *col_src = src + l;
                uint32_t *col_dst = dst + l;
                for (k = 0; k < block_h; k++) {
                    col_dst[k * s->stride] ^= col_src[k * block_w]; // strided read and write down the column
                }
            }
            // Advance src by total block size
            src += block_h * block_w;
            dst = row + block_w; // move dst horizontally
        }
        dst = &row[block_w];
        ++block;
    }
    dst = &rect[block_h * s->stride];
}
}
