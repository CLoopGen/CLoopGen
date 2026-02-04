#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern uint8_t (*obmc_edged)[32];
extern  int obmc_stride;
extern  int ref_stride;
extern uint8_t *dst;
extern IDWTELEM *pred;
extern uint8_t *cur;
extern int sx;
extern int sy;
extern int x0;
extern int _usr_y0;
extern int x1;
extern int _usr_y1;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0
#define y1 _usr_y1



void loop(){
if (y0 < y1 && x0 < x1) {
    const int total_elements = (y1 - y0) * (x1 - x0);
    int idx = 0;
    for (int i = 0; i < total_elements; i++) {
        y = y0 + i / (x1 - x0);
        x = x0 + i % (x1 - x0);
        const uint8_t *obmc1 = obmc_edged[y];
        const IDWTELEM *pred1 = pred + y * obmc_stride;
        uint8_t *cur1 = cur + y * ref_stride;
        uint8_t *dst1 = dst + sx + (sy + y) * ref_stride;
        int v = (cur1[x] * obmc1[x] + (1 << (8 - 4 - 1))) >> (8 - 4);
        v = (v + pred1[x]) >> 4;
        if (v & (~255))
            v = ~(v >> 31);
        dst1[x] = v;
    }
}
}
