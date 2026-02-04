#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;
extern int j;
extern int level;
extern int last_non_zero;
extern int start_i;
extern  int *qmat;
extern  uint8_t *scantable;
extern unsigned int threshold1;
extern unsigned int threshold2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Modify access pattern to step through the loop with a stride (e.g., stride of 2),
    // then handle remaining elements in a second pass if needed.
    // Here we do a backward strided traversal, processing even indices first, then odd if necessary.
    int stride = 2;
    int offset = (63 - start_i) % stride;
    int i_strided;

    // First pass: strided access (backward with step size)
    for (i_strided = 63; i_strided >= start_i; i_strided -= stride) {
        j = scantable[i_strided];
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = i_strided;
            goto exit_loop;  // Break out cleanly without using while
        } else {
            block[j] = 0;
        }
    }

    // Second pass: handle intermediate indices (odd positions if stride=2)
    for (i_strided = 63 - offset; i_strided >= start_i; i_strided--) {
        if ((63 - i_strided) % stride == 0) continue;  // Skip already processed
        j = scantable[i_strided];
        level = block[j] * qmat[j];
        if (((unsigned int)(level + threshold1)) > threshold2) {
            last_non_zero = i_strided;
            break;
        } else {
            block[j] = 0;
        }
    }
exit_loop:;
}
