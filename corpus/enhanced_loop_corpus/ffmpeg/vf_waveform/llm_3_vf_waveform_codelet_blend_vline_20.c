#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int height;
extern int linesize;
extern float o1;
extern float o2;
extern int v;
extern int step;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Indexed) Memory Access via Offset Array
    // Use an array of offsets to simulate indirect addressing, mimicking irregular access patterns
    // Assume offset_table provides the correct byte offsets for each iteration
    int *offset_table = (int*)malloc((height / step) * sizeof(int));
    if (!offset_table) return; // Handle allocation failure
    for (int i = 0; i < height / step; i++) {
        offset_table[i] = i * step * linesize; // Simulate original line strides
    }
    uint8_t *base = dst;
    for (y = 0; y < height; y += step) {
        int idx = y / step;
        base[offset_table[idx]] = v * o1 + base[offset_table[idx]] * o2;
    }
    free(offset_table);
}
