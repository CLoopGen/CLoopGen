#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int x;
extern int y;
extern int i;
extern int j;
extern uint32_t *dst;
extern  int dst_linesize;
extern  uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++)
    for (x = 0; x < 16; x++) {
        uint32_t pixel = pal[y * 16 + x];
        int base_offset = (y * dst_linesize + x) * size;
        for (j = 0; j < size; j++) {
            int dst_idx = base_offset + j * dst_linesize;
            for (i = 0; i < size; i++) {
                dst[dst_idx + i] = pixel;
            }
        }
    }
}
