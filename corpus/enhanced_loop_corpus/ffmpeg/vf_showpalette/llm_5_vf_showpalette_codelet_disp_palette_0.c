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
    for (x = 0; x < 16; x++)
        for (j = 0; j < size; j++)
            for (i = 0; i < size; i++)
                if (j >= i)
                    dst[(y * dst_linesize + x) * size + j * dst_linesize + i] = pal[y * 16 + x];
}
