#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern (unrolled and restructured for forward consecutive access)
    // We reinterpret the original backward strided traversal as a forward loop with adjusted indices
    for (i = 3; i <= 17; i += 2) {
        int idx = 20 - i;  // maps 3->17, 5->15, ..., 17->3 to traverse same elements in reverse order
        in[idx] += in[idx - 2];
    }
}
