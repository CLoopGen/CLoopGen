#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint32;
typedef unsigned short uint16;

uint32 *cp;
uint32 x;
uint32 w = 1048576; // Process ~1M elements for ~0.01 sec runtime
uint16 *wr;
uint16 *wg;
uint16 *wb;
uint16 *wa;
uint32 r;
uint32 g;
uint32 b;
uint32 a;

void init_vars() {
    wr = (uint16*)aligned_alloc(16, w * sizeof(uint16));
    wg = (uint16*)aligned_alloc(16, w * sizeof(uint16));
    wb = (uint16*)aligned_alloc(16, w * sizeof(uint16));
    wa = (uint16*)aligned_alloc(16, w * sizeof(uint16));
    cp = (uint32*)aligned_alloc(16, w * sizeof(uint32));

    for (uint32 i = 0; i < w; ++i) {
        wr[i] = (uint16)((i * 0x9E37) & 0xFFFF);
        wg[i] = (uint16)(((i + 100) * 0x9E37) & 0xFFFF);
        wb[i] = (uint16)(((i + 200) * 0x9E37) & 0xFFFF);
        wa[i] = (uint16)(((i + 300) * 0x9E37) & 0xF000); // High bits for >>4 to yield meaningful alpha
    }
}