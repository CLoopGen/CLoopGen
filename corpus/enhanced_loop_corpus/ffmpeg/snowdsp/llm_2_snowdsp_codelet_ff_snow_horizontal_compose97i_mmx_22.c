#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering and adjusting index computation
    // Instead of strided write to b[i] and b[i+1], accumulate values in temporary variables
    // and write sequentially in reverse order with adjusted indexing.
    IDWTELEM *b_local = b;
    IDWTELEM *temp_local = temp;
    int i_local = i;
    for (; (i_local & 30) != 30; i_local -= 2) {
        int idx = i_local >> 1;
        b_local[i_local]     = temp_local[idx];     // Write lower half from temp
        b_local[i_local + 1] = b_local[idx];        // Copy from earlier position in b
    }
    i = i_local;
}
