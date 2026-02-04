#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int out_palette[4];
extern int out_alpha[4];
extern int i;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping array (reverse order)
    int index_map[4] = {3, 2, 1, 0}; // Reverse traversal order
    
    for (i = 0; i < 4; i++) {
        int idx = index_map[i]; // Indirect access via index map
        
        out_palette[idx] = selected[idx] ? (selected[idx] - 1) & 15 : 0;
        out_alpha[idx] = !selected[idx] ? 0 : selected[idx] < 17 ? 128 : 255;
    }
}
