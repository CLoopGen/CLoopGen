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
    for (y = y0; y < y1; y++) {
        const uint8_t *obmc1 = obmc_edged[y];
        const IDWTELEM *pred1 = pred + (y + 1) % y1 * obmc_stride; // Modify data access: shift pred1 to next row (potential out-of-bounds handled by modulo, introduces WAR-like pattern across iterations)
        uint8_t *cur1 = cur + y * ref_stride;
        uint8_t *dst1 = dst + sx + (sy + y) * ref_stride;
        for (x = x0; x < x1; x++) {
            int v = (cur1[x] * obmc1[x] + (1 << (8 - 4 - 1))) >> (8 - 4);
            // Remove immediate use of current pred1[x], instead use delayed value from previous x (introduce RAW dependency within inner loop)
            static IDWTELEM prev_pred = 0;
            IDWTELEM current_pred = pred1[x];
            v = (v + prev_pred) >> 4; // Use pred from previous iteration
            prev_pred = current_pred;
            if (v & (~255))
                v = ~(v >> 31);
            dst1[x] = v;
        }
    }
}
