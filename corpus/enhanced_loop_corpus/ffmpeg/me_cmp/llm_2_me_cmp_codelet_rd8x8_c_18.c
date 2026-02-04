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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of indirect access via scantable[i], process temp array in sequential order.
    // We assume that 'last - start_i' elements are to be processed, and map level directly from temp[j] 
    // where j is now a consecutive index starting from start_i.
    for (i = start_i; i < last; i++) {
        int j = i; // Direct consecutive access instead of indirect through scantable
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
