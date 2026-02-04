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
    // Access elements with a fixed stride (e.g., every 2nd element) over the scantable and temp arrays.
    // This creates a strided access pattern which may affect cache performance.
    const int stride = 2;
    for (i = start_i; i < last; i += stride) {
        int j = scantable[i];  // Still use indirect access but with strided indices
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
    // Handle remaining element if last - start_i is odd
    if ((last - start_i) % 2 == 1 && start_i < last) {
        int j = scantable[last - 1];
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
}
