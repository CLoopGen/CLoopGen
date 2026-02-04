#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char palette_buffer[768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated static indexing)
    int indices[768];
    for (int temp_i = 0; temp_i < 768; temp_i++) {
        indices[temp_i] = temp_i; // Simulate potential reordering; here it's sequential for correctness
    }
    for (i = 0; i < 768; i++) {
        int idx = indices[i]; // Indirect access via index table
        if (palette_buffer[idx] > 63) {
            palette_scale = 0;
            break;
        }
    }
}
