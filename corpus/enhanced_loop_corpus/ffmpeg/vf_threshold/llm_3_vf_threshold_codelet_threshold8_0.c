#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern  uint8_t *threshold;
extern  uint8_t *min;
extern  uint8_t *max;
extern uint8_t *out;
extern ptrdiff_t ilinesize;
extern ptrdiff_t tlinesize;
extern ptrdiff_t flinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t olinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Consecutive memory access via pointer arithmetic to improve locality
uint8_t *in_row = in;
uint8_t *th_row = threshold;
uint8_t *min_row = min;
uint8_t *max_row = max;
uint8_t *out_row = out;

for (y = 0; y < h; y++) {
    uint8_t *in_ptr = in_row;
    uint8_t *th_ptr = th_row;
    uint8_t *min_ptr = min_row;
    uint8_t *max_ptr = max_row;
    uint8_t *out_ptr = out_row;

    for (x = 0; x < w; x++) {
        // Fully sequential and consecutive access using local pointers
        *out_ptr++ = (*in_ptr++ < *th_ptr++) ? *min_ptr++ : *max_ptr++;
    }

    in_row += ilinesize;
    th_row += tlinesize;
    min_row += flinesize;
    max_row += slinesize;
    out_row += olinesize;
}
}
