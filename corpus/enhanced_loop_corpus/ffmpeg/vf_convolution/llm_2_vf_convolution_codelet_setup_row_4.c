#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int radius;
extern  uint8_t *c[];
extern  uint8_t *src;
extern int stride;
extern int x;
extern int w;
extern int y;
extern int bpc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < radius * 2 + 1; i++) {
        int idx = x + i - radius;
        idx = (idx < 0) ? -idx : idx;
        idx = (idx >= w) ? 2 * w - 1 - idx : idx;
        // Use consecutive memory access by precomputing offset and accessing through a base pointer
        size_t offset = idx * bpc + y * stride;
        c[i] = &src[offset];
    }
}
