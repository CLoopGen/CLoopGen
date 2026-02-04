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
for (y = 0; y < 8; y++)
    for (x = 0; x < 8; x++)
        for (j = 0; j < size; j += 2)
            for (i = 0; i < size; i += 2) {
                uint32_t val = pal[y * 2 * 16 + x * 2];
                int idx = (y * 2 * dst_linesize + x * 2) * size + j * dst_linesize + i;
                dst[idx] = val;
                if (i + 1 < size) dst[idx + 1] = val;
                if (j + 1 < size) dst[idx + dst_linesize] = val;
                if (i + 1 < size && j + 1 < size) dst[idx + dst_linesize + 1] = val;
            }
}
