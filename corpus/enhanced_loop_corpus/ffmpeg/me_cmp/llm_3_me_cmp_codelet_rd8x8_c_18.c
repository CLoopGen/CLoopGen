#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *scantable;
extern int16_t (*temp);
extern int i;
extern int last;
extern int run;
extern int bits;
extern int level;
extern int start_i;
extern  int esc_length;
extern uint8_t *length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access the scantable with a fixed stride (e.g., every 2nd element) to create non-unit stride access.
    // This changes data access locality and may affect cache performance.
    const int stride = 2;
    int end = last;
    // Adjust loop bound to ensure we don't exceed array limits due to striding
    for (i = start_i; i < end; i += stride) {
        int j = scantable[i]; // Still indirect but less frequent and strided
        level = temp[j];
        if (level) {
            level += 64;
            if ((level & (~127)) == 0)
                bits += length[((run) * 128 + (level))];
            else
                bits += esc_length;
            run = 0;
        } else
            run++;
    }
    // Note: Remaining iterations (if any) not covered by stride are ignored,
    // reflecting realistic strided processing trade-offs.
}
